// Scheduler.h: interface for the CScheduler class.
//
//////////////////////////////////////////////////////////////////////

#ifndef SCHEDULER_H
#define SCHEDULER_H

#pragma once

#include "common.h"

class CScheduler  
{
private:
  ////////////////////////// Class Members ////////////////////////////

  HANDLE* m_hThreads;
  DWORD   m_dwThreadNum;


  //////////////////////// Thread entry point /////////////////////////

  static DWORD WINAPI SvcRun(PVOID pvArgs)
  {
    CScheduler* this_obj = static_cast<CScheduler*>(pvArgs);

    this_obj->Dispatch();
  }

public:
	CScheduler(DWORD dwThreadNum = 0)
  {
    if (dwThreadNum == 0)
    {
      CSystemInfo si;
      m_dwThreadNum = si.dwNumberOfProcessors;
    }
    else m_dwThreadNum = dwThreadNum;

    m_hThreads = new HANDLE[m_dwThreadNum];

    for (DWORD i = 0; i < m_dwThreadNum; ++i)
    {
      DWORD dwThreadId;

      m_hThreads[i] = CreateThread(NULL, 0, CScheduler::SvcRun, this, 0, &dwThreadId);
    
      ASSERT(m_hThreads[i] != NULL);
      TRACE(TEXT("Creato Scheduler Thread: Handle 0x%x, Id %i"), m_hThreads[i], dwThreadId);
      
      CloseHandle(m_hThreads[i]);
    }
  }

  void Dispatch()
  {

  }

  void Insert(MethodRequest)
  {
    
  }

  virtual ~CScheduler();

};

#endif //SCHEDULER_H
