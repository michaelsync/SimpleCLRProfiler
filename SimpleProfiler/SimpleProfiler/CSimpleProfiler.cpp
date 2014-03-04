#include "stdafx.h"

#include <string>
#include <algorithm>
#include <iterator>
#include <regex>

#include <set>
#include <vector>

using std::vector;
using std::set;
using std::wregex;
using std::wsregex_token_iterator;

#include "Tracing.h"
#include "CSimpleProfiler.h"
#include "GlobalStaticCallbacks.h"
#include "MethodInfo.h"



CComPtr<ICorProfilerInfo3> CSimpleProfiler::profilerInfo3;
set<wstring> excludedClasses;



CSimpleProfiler::CSimpleProfiler()
{
   Trace_f(L"CSimpleProfiler::CSimpleProfiler()\n");
}

CSimpleProfiler::~CSimpleProfiler()
{
   Trace_f(L"CSimpleProfiler::~CSimpleProfiler()\n");
}

STDMETHODIMP CSimpleProfiler::Initialize(IUnknown* ICorProfilerInfoUnknown)
{
   Trace_f(L"CSimpleProfiler::Initialize()\n");

   // Exclude runtime libraries that we don't want to trace.
   excludedClasses.insert(L"System");
   excludedClasses.insert(L"SyncTextReader");
   excludedClasses.insert(L"SyncTextWriter");
   excludedClasses.insert(L"NullStream");
   excludedClasses.insert(L"StreamWriterBufferedDataLost");
   excludedClasses.insert(L"EvidenceLockHolder");
   excludedClasses.insert(L"Microsoft.Win32");

   return monitorEnterLeave(ICorProfilerInfoUnknown);
}

STDMETHODIMP CSimpleProfiler::Shutdown()
{
   Trace_f(L"CSimpleProfiler::Shutdown()\n");
   return S_OK;
}

HRESULT CSimpleProfiler::monitorEnterLeave(IUnknown* ICorProfilerInfoUnknown) 
{
   HRESULT hr = E_FAIL;

   if (ICorProfilerInfoUnknown != NULL)
   {
      hr = ICorProfilerInfoUnknown->QueryInterface(__uuidof(ICorProfilerInfo3), reinterpret_cast<void**>(&profilerInfo3));
      if (SUCCEEDED(hr))
      {
         hr = profilerInfo3->SetEventMask((DWORD)(COR_PRF_MONITOR_ENTERLEAVE | COR_PRF_ENABLE_FRAME_INFO | COR_PRF_ENABLE_FUNCTION_ARGS));
         if (SUCCEEDED(hr)) 
            hr = registerGlobalCallbacks();
         else
            Trace_f(L"Failed to set event mask: COR_PRF_MONITOR_ENTERLEAVE | COR_PRF_ENABLE_FRAME_INFO | COR_PRF_ENABLE_FUNCTION_ARGS");
      }
   }

   return hr;
}

HRESULT CSimpleProfiler::registerGlobalCallbacks() 
{
   HRESULT hr = profilerInfo3->SetEnterLeaveFunctionHooks3WithInfo(
      (FunctionEnter3WithInfo*)MethodEntered3, 
      (FunctionEnter3WithInfo*)MethodLeft3, 
      (FunctionEnter3WithInfo*)MethodTailcall3);

   if (FAILED(hr))
      Trace_f(L"Failed to register global callbacks (%s)", _com_error(hr).ErrorMessage());

   return S_OK;
}

void CSimpleProfiler::OnEnterWithInfo(FunctionID functionId, COR_PRF_ELT_INFO eltInfo)
{
   MethodInfo info;
   HRESULT hr = info.Create(profilerInfo3, functionId);
   if (FAILED(hr)) 
      Trace_f(L"Enter() failed to create MethodInfo object (%s)", _com_error(hr).ErrorMessage());

   if (!tracingEnabledForScope(info.className, info.methodName))
      return; // Skip classes we are not interested in.

   Trace_f(L"[%d] Entering %s.%s", info.threadId, info.className.c_str(), info.methodName.c_str());
}

void CSimpleProfiler::OnLeaveWithInfo(FunctionID functionId, COR_PRF_ELT_INFO eltInfo)
{
   MethodInfo info;
   HRESULT hr = info.Create(profilerInfo3, functionId);
   if (FAILED(hr)) 
      Trace_f(L"Enter() failed to create MethodInfo object (%s)", _com_error(hr).ErrorMessage());

   if (!tracingEnabledForScope(info.className, info.methodName))
      return;

   Trace_f(L"[%d] Leaving %s.%s", info.threadId, info.className.c_str(), info.methodName.c_str());
}

void CSimpleProfiler::TailcallWithInfo(FunctionID functionId, COR_PRF_ELT_INFO eltInfo)
{

}

bool CSimpleProfiler::tracingEnabledForScope(const wstring& className, const wstring& methodName)
{
   wstring fullName = className + L"." + methodName;
   vector<wstring> methodTokens;   
   wregex separatedByComma(L"[^.]+");

   copy(wsregex_token_iterator(fullName.begin(), fullName.end(), separatedByComma), wsregex_token_iterator(), back_inserter(methodTokens));

   for (set<wstring>::const_iterator it = excludedClasses.begin(); it != excludedClasses.end(); ++ it)
   {
      vector<wstring> namespaceTokens;
      wstring nameSpace = *it;
      copy(wsregex_token_iterator(nameSpace.begin(), nameSpace.end(), separatedByComma), wsregex_token_iterator(), back_inserter(namespaceTokens));

      for (size_t i = 0; i < namespaceTokens.size(); ++ i)
      {
         if (namespaceTokens[i] == methodTokens[i])
         {
            return false; // Matches excluded scope.
         }
      }
   }

   return true;
}