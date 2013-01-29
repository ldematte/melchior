// Icmp.cpp: implementation of the CIcmp class.
//
//////////////////////////////////////////////////////////////////////

#include "Icmp.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CIcmp::CIcmp(): m_Socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)
{
}

CIcmp::~CIcmp()
{  
}

DWORD CIcmp::Send(CIcmpPacket* pIcmpPacket,
                  IPADDR       DestinationAddress,
                  BYTE         Ttl,
                  BYTE         Tos,
                  BYTE         Flags,
                  DWORD        Timeout,
                  CIcmpReply*  pIcmpReply)
{
  struct sockaddr_in saDest,saFrom;
	int cbWritten;
  int bStatus;
    
  DWORD dwFromLen = sizeof(saFrom);
  
  bStatus = setsockopt(m_Socket,IPPROTO_IP,IP_TOS,(char *) &Tos,sizeof(Tos));
  
  if (bStatus == INVALID_SOCKET) 
    return m_Socket.GetLastError();
	
  setsockopt(m_Socket,IPPROTO_IP,IP_TTL,(char *) &Ttl,sizeof(Ttl));
  setsockopt(m_Socket,IPPROTO_IP,IP_DONTFRAGMENT,(char *)&Flags,sizeof(Flags));

	// Bisogna settare il timeout del socket altrimenti in caso di mancata ricezione
	// rimarrebbe bloccato in eterno

	setsockopt(m_Socket,SOL_SOCKET,SO_RCVTIMEO,(char*)&Timeout,sizeof(Timeout));
	setsockopt(m_Socket,SOL_SOCKET,SO_SNDTIMEO,(char*)&Timeout,sizeof(Timeout));

	saDest.sin_addr.s_addr = DestinationAddress;
	saDest.sin_family = AF_INET;
	
  
	StartTimeTick = GetTickCount();
	
	// Spediamo il pacchetto
	cbWritten = sendto(m_Socket, 
                     (const char*)pIcmpPacket->Data(), 
                     pIcmpPacket->Size(), 0,
                     (struct sockaddr *)&saDest, 
                     sizeof(saDest));
	
  if (cbWritten == SOCKET_ERROR)
		return m_Socket.GetLastError();

  // Attendiamo risposta fino al timeout
  
  BYTE RecvBuffer[2048];
  //TODO: Fix dimension

  int cbReceived = recvfrom(m_Socket,
                            (char *)RecvBuffer, sizeof(RecvBuffer), 0,
                            (struct sockaddr *)&saFrom, (int*)&dwFromLen);
	
  if (cbReceived == SOCKET_ERROR)
	  return m_Socket.GetLastError();

  return FillResp(RecvBuffer, cbReceived, &saFrom, pIcmpReply);
}

DWORD CIcmp::FillResp(PBYTE pRecvBuffer, 
                      int cbReceived, 
                      struct sockaddr_in* dest, 
                      CIcmpReply* pIcmpReply)
{
  PIPHEADER    pIPHeader;
  PICMPHEADER  pIcmpHeader;
	DWORD        dwIPHeaderLenght;
	int          nSize;

	pIPHeader       = (PIPHEADER) pRecvBuffer;
	dwIPHeaderLenght= pIPHeader->cbHeaderLen * 4;
	pIcmpHeader     = (PICMPHEADER) (pRecvBuffer + dwIPHeaderLenght);
	
  pIcmpReply->Address       = dest->sin_addr.s_addr;
	pIcmpReply->RoundTripTime = GetTickCount() - StartTimeTick;
	pIcmpReply->Ttl           = pIPHeader->cbTtl;
	pIcmpReply->Tos           = pIPHeader->cbTOS;
	pIcmpReply->Flags         = pIPHeader->fNotFragment;

	
	nSize = cbReceived - 
          dwIPHeaderLenght - 
          sizeof(ICMPHEADER);  //+sizeof(LONG);
	
  pIcmpReply->DataSize = (WORD)nSize;
  pIcmpReply->Type     = pIcmpHeader->Type;

	if ((pIcmpHeader->Type == ICMP_REPLY_ECHO) ||
      (pIcmpHeader->Type == ICMP_REPLY_SUBNET)||
		  (pIcmpHeader->Type == ICMP_REPLY_GETLOCALTIME))
		return ERROR_SUCCESS;
	
	// pIcmpHeader->Type == ICMP_ERROR_DEST_UNREACHABLE
  // pIcmpHeader->Type == ICMP_ERROR_TIME_EXPIRED
	
  return pIcmpHeader->Code;
}

DWORD CIcmp::SendEcho(IPADDR      DestinationAddress,
                      PBYTE       RequestData,
                      WORD        RequestSize,
                      BYTE        Ttl,
                      BYTE        Tos,	
                      BYTE        Flags,
                      DWORD       Timeout,
                      CIcmpReply* pIcmpReply)
{
  CIcmpPacket IcmpPacket(ICMP_SEND_ECHO,
                         RequestData,
                         RequestSize);

  return Send(&IcmpPacket, DestinationAddress,
              Ttl, Tos, Flags, Timeout, pIcmpReply);
}

DWORD CIcmp::TraceRoute(IPADDR DestinationAddress, 
                        DWORD Timeout,
                        BOOL fDNSResolution,
                        BYTE MaxHopNum,
                        LPBYTE lpData,
                        DWORD  dwDataSize)
{
  assert(dwDataSize >= MaxHopNum * sizeof(CIcmpReply));
  assert(lpData);
  assert(!IsBadWritePtr(lpData, dwDataSize));


  if (dwDataSize < MaxHopNum * sizeof(CIcmpReply) ||
      lpData == NULL                              ||
      IsBadWritePtr(lpData, dwDataSize))
      
    return ERROR_INSUFFICIENT_BUFFER;

  CIcmpReply** lplpIcmpReply = (CIcmpReply**)lpData;
  
  BYTE i = 1;
  BOOL Finished = FALSE;

  while(i < MaxHopNum && !Finished)
  {
    SendEcho(DestinationAddress, 
             NULL, 0, i, 0, 0, 
             1000, lplpIcmpReply[i]);
    
    if (lplpIcmpReply[i]->Address == DestinationAddress)
      Finished = TRUE;

    ++i;
  }

  return ERROR_SUCCESS;
}