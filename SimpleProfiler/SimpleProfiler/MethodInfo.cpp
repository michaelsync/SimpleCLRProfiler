#include "stdafx.h"

#include "MethodInfo.h"
#include "Tracing.h"



MethodInfo::MethodInfo() : token(0), threadId(NULL), signature(NULL), signatureLength(0)
{
}

MethodInfo::~MethodInfo()
{
}

HRESULT  MethodInfo::Create(ICorProfilerInfo* profilerInfo, FunctionID functionId)
{
   CComPtr<IMetaDataImport> metadataImport;

   HRESULT hr = profilerInfo->GetTokenAndMetaDataFromFunction(functionId, IID_IMetaDataImport, reinterpret_cast<IUnknown**>(&metadataImport), &token);
   if (FAILED(hr)) 
   {
      Trace_f(L"Failed to query IMetaDataImport interface (%s)", _com_error(hr).ErrorMessage());
      return hr;
   }

   mdTypeDef typeDefinition = mdTokenNil;
   ULONG methodNameLength = 0;
   ULONG classNameLength = 0;
   DWORD attributes = 0;

   signatureLength = 0;
   signature = NULL;

   hr = metadataImport->GetMethodProps(token, &typeDefinition, NULL, 0, &methodNameLength, &attributes, NULL, NULL, NULL, NULL);
   if (FAILED(hr)) 
   {
      Trace_f(L"Failed to query method name length (%s)", _com_error(hr).ErrorMessage());
      return hr;
   }

   methodName.resize(methodNameLength - 1);
   hr = metadataImport->GetMethodProps(token, &typeDefinition, (WCHAR*)methodName.c_str(), methodNameLength, &methodNameLength, &attributes, &signature, &signatureLength, NULL, NULL);
   if (FAILED(hr)) 
   {
      Trace_f(L"Failed to query method name (%s)", _com_error(hr).ErrorMessage());
      return hr;
   } 

   hr = metadataImport->GetTypeDefProps(typeDefinition, NULL, 0, &classNameLength, NULL, NULL);
   if (FAILED(hr)) 
   {
      Trace_f(L"Failed to query class name length (%s)", _com_error(hr).ErrorMessage());
      return hr;
   }

   className.resize(classNameLength - 1);
   hr = metadataImport->GetTypeDefProps(typeDefinition, (WCHAR*)className.c_str(), classNameLength, &classNameLength, NULL, NULL);
   if (FAILED(hr)) 
   {
      Trace_f(L"Failed to query class name (%s)", _com_error(hr).ErrorMessage());
      return hr;
   }

   return S_OK;
}