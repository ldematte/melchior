// Reactor.h: interface for the CReactor class.
//
//////////////////////////////////////////////////////////////////////

#ifndef REACTOR_H
#define REACTOR_H

#pragma once

#include "common.h"
#include "EventHandler.h"
#include "ThreadMutex.h"

class CReactor  
{
private:
  HANDLE* m_handles;
  CEventHandler** m_eh;
  DWORD m_dwMaxHandles;
  DWORD m_dwHandlesNum;

  HANDLE m_hThread;

  BOOL bTerminated;

  CThreadMutex m_Lock;

  inline CEventHandler* GetHandler(DWORD dwIndex)
  {
    CThreadMutexGuard Guard(m_Lock);
    return m_eh[dwIndex];
  }

  static DWORD WINAPI SvcRun(PVOID pvArgs)
  {
    CReactor* this_obj = static_cast<CReactor*>(pvArgs);

    this_obj->HandleEvents();
  }

public:
  CReactor(DWORD dwMaxHandles): bTerminated(FALSE), 
                                m_dwHandlesNum(0) 
  {
    if (dwMaxHandles == 0 || dwMaxHandles > MAXIMUM_WAIT_OBJECTS)
      m_dwMaxHandles = MAXIMUM_WAIT_OBJECTS;
    else
      m_dwMaxHandles = dwMaxHandles;

    m_handles = new HANDLE[dwMaxHandles];
    m_eh = new CEventHandler*[dwMaxHandles];

    DWORD dwThreadId;

    m_hThread = CreateThread(NULL, 0, CReactor::SvcRun, this, 0, &dwThreadId);
    
    assert(m_hThread != NULL);
    TRACE(TEXT("Creato Reactor Thread: Handle 0x%x, Id %i"), m_hThread, dwThreadId);

    CloseHandle(m_hThread);
  }

	virtual ~CReactor();

  void HandleEvents();
  BOOL RegisterHandler(CEventHandler* eh);
  BOOL RemoveHandler(HANDLE h);

};

#endif //REACTOR_H