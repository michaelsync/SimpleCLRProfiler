#include "stdafx.h"
#include "SimpleProfilerCallbackImpl.h"


SimpleProfilerCallbackImpl::SimpleProfilerCallbackImpl() 
{

}

SimpleProfilerCallbackImpl::~SimpleProfilerCallbackImpl() 
{

}

STDMETHODIMP SimpleProfilerCallbackImpl::Initialize(IUnknown* pICorProfilerInfoUnk) 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::Shutdown()
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::AppDomainCreationStarted(AppDomainID appDomainID) 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::AppDomainCreationFinished(AppDomainID appDomainID, HRESULT hrStatus) 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::AppDomainShutdownStarted(AppDomainID appDomainID) 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::AppDomainShutdownFinished(AppDomainID appDomainID, HRESULT hrStatus) 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::AssemblyLoadStarted(AssemblyID assemblyID) 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::AssemblyLoadFinished(AssemblyID assemblyID, HRESULT hrStatus) 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::AssemblyUnloadStarted(AssemblyID assemblyID) 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::AssemblyUnloadFinished(AssemblyID assemblyID, HRESULT hrStatus) 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::ModuleLoadStarted(ModuleID moduleID) 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::ModuleLoadFinished(ModuleID moduleID, HRESULT hrStatus) 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::ModuleUnloadStarted(ModuleID moduleID) 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::ModuleUnloadFinished(ModuleID moduleID, HRESULT hrStatus) 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::ModuleAttachedToAssembly(ModuleID moduleID, AssemblyID assemblyID) 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::ClassLoadStarted(ClassID classID) 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::ClassLoadFinished(ClassID classID, HRESULT hrStatus)
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::ClassUnloadStarted(ClassID classID) 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::ClassUnloadFinished(ClassID classID, HRESULT hrStatus) 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::FunctionUnloadStarted(FunctionID functionID) 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::JITCompilationStarted(FunctionID functionID, BOOL fIsSafeToBlock) 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::JITCompilationFinished(FunctionID functionID, HRESULT hrStatus, BOOL fIsSafeToBlock) 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::JITCachedFunctionSearchStarted(FunctionID functionID, BOOL* pbUseCachedFunction) 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::JITCachedFunctionSearchFinished(FunctionID functionID, COR_PRF_JIT_CACHE result) 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::JITFunctionPitched(FunctionID functionID) 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::JITInlining(FunctionID callerID, FunctionID calleeID, BOOL* pfShouldInline) 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::ThreadCreated(ThreadID threadID) 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::ThreadDestroyed(ThreadID threadID) 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::ThreadAssignedToOSThread(ThreadID managedThreadID, DWORD osThreadID) 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::RemotingClientInvocationStarted() 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::RemotingClientSendingMessage(GUID* pCookie, BOOL fIsAsync) 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::RemotingClientReceivingReply(GUID* pCookie, BOOL fIsAsync) 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::RemotingClientInvocationFinished() 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::RemotingServerReceivingMessage(GUID* pCookie, BOOL fIsAsync) 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::RemotingServerInvocationStarted() 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::RemotingServerInvocationReturned() 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::RemotingServerSendingReply(GUID* pCookie, BOOL fIsAsync) 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::UnmanagedToManagedTransition(FunctionID functionID, COR_PRF_TRANSITION_REASON reason) 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::ManagedToUnmanagedTransition(FunctionID functionID, COR_PRF_TRANSITION_REASON reason) 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::RuntimeSuspendStarted(COR_PRF_SUSPEND_REASON suspendReason) 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::RuntimeSuspendFinished()
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::RuntimeSuspendAborted()
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::RuntimeResumeStarted() 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::RuntimeResumeFinished() 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::RuntimeThreadSuspended(ThreadID threadid) 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::RuntimeThreadResumed(ThreadID threadid) 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::MovedReferences(ULONG cmovedObjectIDRanges, ObjectID oldObjectIDRangeStart[], ObjectID newObjectIDRangeStart[], ULONG cObjectIDRangeLength[]) 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::ObjectAllocated(ObjectID objectID, ClassID classID) 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::ObjectsAllocatedByClass(ULONG classCount, ClassID classIDs[], ULONG objects[]) 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::ObjectReferences(ObjectID objectID, ClassID classID, ULONG cObjectRefs, ObjectID objectRefIDs[]) 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::RootReferences(ULONG cRootRefs, ObjectID rootRefIDs[])
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::ExceptionThrown(ObjectID thrownObjectID) 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::ExceptionSearchFunctionEnter(FunctionID functionID) 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::ExceptionSearchFunctionLeave() 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::ExceptionSearchFilterEnter(FunctionID functionID) 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::ExceptionSearchFilterLeave() 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::ExceptionSearchCatcherFound(FunctionID functionID) 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::ExceptionCLRCatcherFound() 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::ExceptionCLRCatcherExecute() 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::ExceptionOSHandlerEnter(FunctionID functionID) 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::ExceptionOSHandlerLeave(FunctionID functionID) 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::ExceptionUnwindFunctionEnter(FunctionID functionID) 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::ExceptionUnwindFunctionLeave() 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::ExceptionUnwindFinallyEnter(FunctionID functionID) 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::ExceptionUnwindFinallyLeave() 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::ExceptionCatcherEnter(FunctionID functionID, ObjectID objectID) 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::ExceptionCatcherLeave() 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::COMClassicVTableCreated(ClassID wrappedClassID, REFGUID implementedIID, void* pVTable, ULONG cSlots) 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::COMClassicVTableDestroyed(ClassID wrappedClassID, REFGUID implementedIID, void* pVTable) 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::ThreadNameChanged(ThreadID threadId, ULONG cchName, WCHAR name[])
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::GarbageCollectionStarted(int cGenerations, BOOL generationCollected[], COR_PRF_GC_REASON reason) 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::SurvivingReferences(ULONG cSurvivingObjectIDRanges, ObjectID objectIDRangeStart[], ULONG cObjectIDRangeLength[]) 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::GarbageCollectionFinished() 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::FinalizeableObjectQueued(DWORD finalizerFlags, ObjectID objectID) 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::RootReferences2(ULONG cRootRefs, ObjectID rootRefIds[], COR_PRF_GC_ROOT_KIND rootKinds[], COR_PRF_GC_ROOT_FLAGS rootFlags[], UINT_PTR rootIds[]) 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::HandleCreated(GCHandleID handleId, ObjectID initialObjectId) 
{
   return S_OK;
}

STDMETHODIMP SimpleProfilerCallbackImpl::HandleDestroyed(GCHandleID handleId) 
{
   return S_OK;
}


STDMETHODIMP SimpleProfilerCallbackImpl::InitializeForAttach(IUnknown* pCorProfilerInfoUnk, void* pvClientData, UINT cbClientData) 
{ 
   return S_OK; 
}


STDMETHODIMP SimpleProfilerCallbackImpl::ProfilerAttachComplete() 
{ 
   return S_OK; 
}


STDMETHODIMP SimpleProfilerCallbackImpl::ProfilerDetachSucceeded() 
{
   return S_OK; 
}