#include "stdafx.h"
#include "Tracing.h"

void Trace_f(const wstring& format, ...)
{
   wchar_t buffer[TRACE_BUFFER_SIZE];

   va_list args;
   va_start(args, format);  
   _vsnwprintf_s<TRACE_BUFFER_SIZE>(buffer, TRACE_BUFFER_SIZE - 2, format.c_str(), args); // Truncates if buffer is not big enough.
   va_end(args);

   ::OutputDebugStringW(buffer);
}