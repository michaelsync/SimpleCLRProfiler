#include "stdafx.h"
#include "resource.h"


// 'module' attribute causes auto generation of all dll entry points (DllMain, DllRegister/UnregisterServer & etc).
// Add _ATL_ATTRIBUTES to preprocessor definitions.
[ 
   module(dll, 
   uuid = "{6F2AC9B8-C576-448C-B0F7-7D5A765B816D}",
   name = "SimpleProfilerHost",
   helpstring = "Simple Profiler Library",
   resource_name = "IDR_SIMPLE_PROFILER"
   ) 
]
class CSimpleProfilerHost {
public:
   // Override CAtlDllModuleT members here.
};



