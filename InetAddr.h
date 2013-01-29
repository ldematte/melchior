// InetAddr.h: interface for the CInetAddr class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_INETADDR_H__5A4723FF_6B0B_4F9C_A3AA_7241A6F5CB8C__INCLUDED_)
#define AFX_INETADDR_H__5A4723FF_6B0B_4F9C_A3AA_7241A6F5CB8C__INCLUDED_

#include "common.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ClassLib\sockets.h"


class CInetAddr  
{
private:
  ULONG m_ulAddr;
public:
  CInetAddr() : m_ulAddr(0) { }
  CInetAddr(ULONG ulAddr)
  {
    m_ulAddr = htonl(ulAddr);
  }

  BOOL LookUp(LPTSTR szAddr)
  {
    assert(szAddr != NULL);
    
    if (szAddr == NULL)
      return FALSE;

#ifdef UNICODE
    CHAR szTemp[1024];
	size_t converted = 0;
    wcstombs_s(&converted, szTemp, 1024, szAddr, 1024);

    m_ulAddr = inet_addr(szTemp);
#else

    m_ulAddr = inet_addr(szAddr);
#endif

    if (m_ulAddr == INADDR_NONE)
    {
      struct hostent* HostInf;
#ifdef UNICODE
      HostInf = gethostbyname(szTemp);
#else
      HostInf = gethostbyname(szAddr);
#endif
     
      if (HostInf == NULL)
        return FALSE;

      m_ulAddr = *((PULONG)HostInf->h_addr_list[0]);
    }
    return TRUE;
  }
  
  operator ULONG()
  {
    return m_ulAddr;
  }
};

#endif // !defined(AFX_INETADDR_H__5A4723FF_6B0B_4F9C_A3AA_7241A6F5CB8C__INCLUDED_)
