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

#ifdef _X86_
   void MethodEntered3(FunctionIDOrClientID function_id_or_client_id, COR_PRF_ELT_INFO elt_info);
   void MethodLeft3(FunctionIDOrClientID function_id_or_client_id, COR_PRF_ELT_INFO elt_info);
   void MethodTailcall3(FunctionIDOrClientID function_id_or_client_id, COR_PRF_ELT_INFO elt_info);
#elif defined _AMD64_
extern "C" 
{
   void MethodEntered3(FunctionIDOrClientID function_id_or_client_id, COR_PRF_ELT_INFO elt_info);
   void MethodLeft3(FunctionIDOrClientID function_id_or_client_id, COR_PRF_ELT_INFO elt_info);
   void MethodTailcall3(FunctionIDOrClientID function_id_or_client_id, COR_PRF_ELT_INFO elt_info);
}
#endif /* _X86_ */

