#include "stdafx.h"

#include "GlobalStaticCallbacks.h"
#include "CSimpleProfiler.h"


extern "C" void __stdcall EnterMethodStub(FunctionID function_id, COR_PRF_ELT_INFO elt_info)
{
   CSimpleProfiler::OnEnterWithInfo(function_id, elt_info);    
} 


extern "C" void __stdcall LeaveMethodStub(FunctionID function_id, COR_PRF_ELT_INFO elt_info)
{
   CSimpleProfiler::OnLeaveWithInfo(function_id, elt_info);    
}


extern "C" void __stdcall MethodTailcallStub(FunctionID function_id, COR_PRF_ELT_INFO elt_info)
{
   CSimpleProfiler::TailcallWithInfo(function_id, elt_info);    
}

#ifdef _X86_
void __declspec(naked) MethodEntered3(FunctionIDOrClientID function_id_or_client_id, COR_PRF_ELT_INFO elt_info) 
{
   __asm 
   {
      push eax
      push ecx
      push edx
      push [esp + 16]
      call EnterMethodStub
      pop edx
      pop ecx
      pop eax
      ret 4
   }
}


void __declspec(naked) MethodLeft3(FunctionIDOrClientID function_id_or_client_id, COR_PRF_ELT_INFO elt_info) 
{
   __asm 
   {
      push eax
      push ecx
      push edx
      push [esp + 16]
      call LeaveMethodStub
      pop edx
      pop ecx
      pop eax
      ret 4
   }
}


void __declspec(naked) MethodTailcall3(FunctionIDOrClientID function_id_or_client_id, COR_PRF_ELT_INFO elt_info) 
{
   __asm 
   {
      push eax
      push ecx
      push edx
      push [esp + 16]
      call MethodTailcallStub
      pop edx
      pop ecx
      pop eax
      ret 4
   }
}
#elif defined (_AMD64_)
   // Bodies are in GlobalStaticCallbacks.x64.asm (cannot use inline assembly on x64).
#endif /* X_86_*/
