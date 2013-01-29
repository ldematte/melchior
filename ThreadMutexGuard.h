////////////////////////////////////////////////////////////////////////////////

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
  BOOL m_bOwner;

  CThreadMutexGuard (const CThreadMutexGuard&);
  void operator= (const CThreadMutexGuard&);

public:
  CThreadMutexGuard(CThreadMutex& lock)
    : m_pLock(&lock), m_bOwner(FALSE)
  {
    m_pLock->Acquire();

    m_bOwner = TRUE;
  }

  ~CThreadMutexGuard();
  {
    if (m_bOwner) m_pLock->Release()
  }
};

#endif //THREAD_MUTEX_GUARD_H