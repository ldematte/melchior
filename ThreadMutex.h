#ifndef THREAD_MUTEX_H
#define THREAD_MUTEX_H

#pragma once

#include "common.h"

class CThreadMutex: public CRITICAL_SECTION
{
public:
  CThreadMutex()
  {
    InitializeCriticalSection(this);
  }

  ~CThreadMutex()
  {
    DeleteCriticalSection(this);
  }

  void Acquire()
  {
    EnterCriticalSection(this);
  }

  void Release()
  {
    LeaveCriticalSection(this);
  }

  BOOL TryAcquire()
  {
    return TryEnterCriticalSection(this);
  }
};

class CThreadMutexGuard
{
private:
  CThreadMutex* m_pLock;
  bool m_bOwner;


  CThreadMutexGuard (const CThreadMutexGuard&);
  CThreadMutexGuard& operator= (const  CThreadMutexGuard&);
  CThreadMutexGuard();

public:

  CThreadMutexGuard(CThreadMutex &lock)
    : m_pLock(&lock), m_bOwner(false)
  {
    m_pLock->Acquire();

    m_bOwner = true;
  }

  ~CThreadMutexGuard()
  {
    if (m_bOwner) m_pLock->Release();
  }
};



#endif //THREAD_MUTEX_H