
inline BOOL 
XtlInstallService(
	LPCTSTR ServiceName,
	LPCTSTR ServiceDisplayName,
	DWORD ServiceType,
	LPCTSTR BinaryPathName,
	DWORD StartType, 
	DWORD ErrorControl,
	LPCTSTR LoadOrderGroup,
	LPCTSTR Dependencies,
	LPCTSTR ServiceStartName,
	LPCTSTR Password)
{
	TCHAR szPath[MAX_PATH];
	if (NULL == BinaryPathName)
	{
		DWORD nPath = ::GetModuleFileName(NULL, szPath, RTL_NUMBER_OF(szPath));
		XTLENSURE_RETURN_BOOL(0 != nPath);
	}
	else
	{
		::lstrcpyn(szPath, BinaryPathName, RTL_NUMBER_OF(szPath));
	}

	::PathQuoteSpaces(szPath);

	AutoSCHandle hSCManager = ::OpenSCManager(
		NULL,
		SERVICES_ACTIVE_DATABASE,
		SC_MANAGER_CREATE_SERVICE | SC_MANAGER_LOCK);
	if (hSCManager.IsInvalid()) 
	{
		return FALSE;
	}

	AutoSCLock hSCLock = ::LockServiceDatabase(hSCManager);
	if (hSCLock.IsInvalid())
	{
		return FALSE;
	}

	AutoSCHandle hSCService = ::CreateService(
		hSCManager,
		ServiceName,
		ServiceDisplayName,
		SERVICE_CHANGE_CONFIG,
		ServiceType,
		StartType,
		ErrorControl,
		szPath,
		LoadOrderGroup,
		NULL,
		Dependencies,
		ServiceStartName,
		Password);
	if (hSCService.IsInvalid()) 
	{
		return FALSE;
	}
	return TRUE;
}

inline BOOL 
XtlRemoveService(LPCTSTR ServiceName)
{
	AutoSCHandle hSCManager = ::OpenSCManager(
		NULL,
		SERVICES_ACTIVE_DATABASE,
		DELETE | SC_MANAGER_LOCK);
	if (hSCManager.IsInvalid()) 
	{
		return FALSE;
	}

	AutoSCLock hSCLock = ::LockServiceDatabase(hSCManager);
	if (hSCLock.IsInvalid()) 
	{
		return FALSE;
	}

    AutoSCHandle hSCService = ::OpenService(hSCManager, ServiceName, DELETE);

    if (hSCService.IsInvalid()) 
	{
		return FALSE;
	}

	BOOL fSuccess = ::DeleteService(hSCService);
	
	return fSuccess;
	
}

//
// There are problems with the following example advised from the Platform SDK. 
// The service instance is allocated at the stack of ServiceMain
// or ServiceDebugMain. If this thread terminates immediately,
// ServiceMain will also terminate, which subsequently
// delete the instance of the service in the stack.
//
// Maybe if you really want to use thread pool routine for the 
// service cleanup, you should create an instance of the service
// in the heap by overriding ServiceMain and ServiceDebugMain.
// And cleanup routine shall clean the instance later.
//
//
#if 0
	ServiceStart(DWORD argc, LPTSTR* argv) {
		// invoke worker threads
		myworker.Run(m_hServiceStopEvent);
		myworker2.Run(m_hServiceStopEvent);
		BOOL fSuccess = ::RegisterWaitForSingleObject(
			&m_hRegWait,
			m_hServiceStopEvent,
			ServiceCleanupProc,
			this,
			INFINITE,
			WT_EXECUTEONLYONCE | WT_EXECUTELONGFUNCTION);
		if (!fSuccess)
		{
			ReportServiceStopped(2);
		}
	}
#endif


} // namespace XTL
                                                                                                                                                                                                                                                                                        �[�    �Rq�E�� �            * < d e b u g p r i n t . h . s v n - b a s e   h      �o    �o    P\�    �Rq�E�               * < n d a s _ u i n . c p p . s v n - b a s e   h      �o    �o    �\�    �Rq�E�              * < n d a s _ u i n . c p p . s v n - b a s e   h      �o    �o     ]�    �Rq�E�              * < n d a s _ u i n . c p p . s v n - b a s e   h      �o    �o    �]�    �Rq�E��              * < n d a s _ u i n . c p p . s v n - b a s e   h      �o    �o    �]�    �Rq�E�� �            * < n d a s _ u i n . c p p . s v n - b a s e   h      �o    �o    X^�    �Rq�E�               * < n d a s _ u i n . d s p . s v n - b a s e   h      �o    �o    �^�    �Rq�E�              * < n d a s _ u i n . d s p . s v n - b a s e   h      �o    �o    (_�    �Rq�E�              * < n d a s _ u i n . d s p . s v n - b a s e   h      �o    �o    �_�    �Rq�E��              * < n d a s _ u i n . d s p . s v n - b a s e           #pragma once
#include <strsafe.h>
#include "xtldef.h"

namespace XTL
{

#if defined(UNICODE) || defined(_UNICODE)
#define CStaticStringBuffer CStaticStringBufferW
#else
#define CStaticStringBuffer CStaticStringBufferA
#endif

template <size_t tBufferSize = 256> class CStaticStringBufferW;
template <size_t tBufferSize = 256> class CStaticStringBufferA;

template <size_t tBufferSize>
class CStaticStringBufferA
{
	CHAR m_szBuffer[tBufferSize];
	size_t m_len;
protected:
	LPSTR GetNextPtr() throw()
	{
		return m_szBuffer + m_len;
	}
	size_t GetRemaining() const throw()
	{
		return tBufferSize - m_len;
	}
	bool IsBufferFull() const throw()
	{
		return (m_len >= tBufferSize);
	}
	void SetRemaining(size_t cch) throw()
	{
		m_len = tBufferSize - cch;
	}
public:
	CStaticStringBufferA() throw() : m_len(0)
	{
		m_szBuffer[0] = 0;
	}
	CStaticStringBufferA(LPCSTR Format, ...) throw() : m_len(0) 
	{
		va_list ap;
		va_star