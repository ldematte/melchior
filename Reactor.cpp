// Reactor.cpp: implementation of the CReactor class.
//
//////////////////////////////////////////////////////////////////////

#include "Reactor.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


CReactor::~CReactor()
{

}

void CReactor::HandleEvents()
{
  while(!bTerminated)
  {
    DWORD dwRetval = ::WaitForMultipleObjectsEx(m_dwHandlesNum, 
                               m_handles, FALSE, INFINITE, TRUE);

    if(dwRetval >= WAIT_OBJECT_0 && dwRetval < WAIT_OBJECT_0 + m_dwHandlesNum)
       //(dwRetval >= WAIT_ADANDONED_0 && dwRetval < WAIT_ADANDONED_0 + m_dwHandlesNum) 
    {
      DWORD dwIndex = dwRetval - WAIT_OBJECT_0;
      GetHandler(dwIndex)->HandleEvent(m_handles[dwIndex]);
    }
  }
}

BOOL CReactor::RegisterHandler(CEventHandler* eh)
{
  CThreadMutexGuard Guard(m_Lock);
  
  if (m_dwHandlesNum == m_dwMaxHandles)
    return FALSE;

  m_eh[m_dwHandlesNum] = eh;
  m_handles[m_dwHandlesNum] = eh->GetHandle();

  ++m_dwHandlesNum;

  return TRUE;
}

BOOL CReactor::RemoveHandler(HANDLE h)
{
  CThreadMutexGuard Guard(m_Lock);

  for (DWORD i = 0; i < m_dwHandlesNum; ++i)
  {
    if (h == m_handles[i])
    {
      for (DWORD j = i; j < m_dwHandlesNum; ++j)
        m_handles[j] = m_handles[j + 1];

      return TRUE;
    }
  }
  return FALSE;
}

