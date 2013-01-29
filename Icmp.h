// Icmp.h: interface for the CIcmp class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ICMP_H__9C924670_C74C_4DAB_A81A_41DBD526BFC6__INCLUDED_)
#define AFX_ICMP_H__9C924670_C74C_4DAB_A81A_41DBD526BFC6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "common.h"

#include "IcmpPacket.h"
#include "IPPacket.h"

#include "ClassLib\sockets.h"
//#include "dbgHelp\BugsLayerutil.h"

class CIcmp 
{
private:
  CSocket m_Socket;
  ULONG StartTimeTick;

  DWORD FillResp(PBYTE pRecvBuffer, 
                 int cbReceived, 
                 struct sockaddr_in* dest,
                 CIcmpReply* pIcmpReply);
public:
	CIcmp();
	virtual ~CIcmp();

  DWORD SendEcho(IPADDR      DestinationAddress,
                 PBYTE       RequestData,
                 WORD        RequestSize,
                 BYTE        Ttl,
                 BYTE        Tos,	
                 BYTE        Flags,
                 DWORD       Timeout,
                 CIcmpReply* pIcmpReply);

  DWORD GetSubnetMask(IPADDR DestinationAddress,
									    LPVOID ReplyBuffer,
									    DWORD  ReplySize,
									    DWORD  Timeout);

  DWORD GetTimeStamp(IPADDR DestinationAddress,
                     LPVOID ReplyBuffer,
									   DWORD  ReplySize,
									   DWORD  Timeout);

  DWORD Send(CIcmpPacket* pIcmpPacket,
             IPADDR       DestinationAddress,
             BYTE         Ttl,
             BYTE         Tos,
             BYTE         Flags,
             DWORD        Timeout,
             CIcmpReply*  pIcmpReply);

  DWORD TraceRoute(IPADDR DestinationAddress, 
                   DWORD Timeout,
                   BOOL fDNSResolution,
                   BYTE MaxHopNum,
                   LPBYTE lpData,
                   DWORD  dwDataSize);
                   
};

/*class CTracing
{
private:
  CIcmp m_Icmp;

  BYTE m_nCurrentHop;
  IPADDR m_DestinationAddress;
  DWORD m_dwTimeout;
  BOOL m_fDNS;
  BYTE m_nMaxHop;
  LPBYTE m_lpData;

  BOOL Terminated;
  //VOID WINAPI DoNothingApc(ULONG_PTR dwParam) { }

public:
  class CTraceResult
  {
  public:
    INADDR InetAddress;
    
  }


  BOOL SetParams(IPADDR DestinationAddress, 
                 DWORD dwTimeout,
                 BOOL fDNSResolve,
                 BYTE nMaxHop);
  BOOL Start()
  {
    //Create the reply buffer
    //set to zero the CurrentHop
    //Create the Thread
    //set Terminated to false
  };
  BOOL Stop();

  static DWORD WINAPI TraceThread(PVOID pvUnused)
  {
    while(!Terminated &&
  }
};*/

#endif // !defined(AFX_ICMP_H__9C924670_C74C_4DAB_A81A_41DBD526BFC6__INCLUDED_)
