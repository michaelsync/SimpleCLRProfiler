//
//
//   The MIT License (MIT)
//
//   Copyright © 2014 Dmitry Mukhin (dmukhin@appneta.com)
//
//   Permission is hereby granted, free of charge, to any person obtaining a copy
//   of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//   copies of the Software, and to permit persons to whom the Software is
//   furnished to do so, subject to the following conditions:
//
//   The above copyright notice and this permission notice shall be included in
//   all copies or substantial portions of the Software.
//
//   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//   THE SOFTWARE.
//
//

#pragma once

#include "SimpleProfilerCallbackImpl.h"

#include "stdafx.h"

[
   coclass,
   threading(both),
   vi_progid("SimpleProfiler"),
   progid("SimpleProfiler.1"),
   version(1.0),
   uuid("{68130646-C19E-459E-8BF4-5137ED7B3FD7}"),
   helpstring("Simple CLR Profiler class")
]
class CSimpleProfiler : public SimpleProfilerCallbackImpl
{
public:
   CSimpleProfiler();
   ~CSimpleProfiler();

   static void OnEnterWithInfo(FunctionID functionId, COR_PRF_ELT_INFO eltInfo);
   static void OnLeaveWithInfo(FunctionID functionId, COR_PRF_ELT_INFO eltInfo);
   static void TailcallWithInfo(FunctionID functionId, COR_PRF_ELT_INFO eltInfo);

   STDMETHOD(Initialize)(IUnknown *pICorProfilerInfoUnk);
   STDMETHOD(Shutdown)();

private:
   HRESULT monitorEnterLeave(IUnknown* ICorProfilerInfoUnknown);
   HRESULT registerGlobalCallbacks();

   static bool tracingEnabledForScope(const wstring& className, const wstring& methodName);

   static CComPtr<ICorProfilerInfo3> profilerInfo3;
};