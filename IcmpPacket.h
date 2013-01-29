// IcmpPacket.h: interface for the CIcmpPacket class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ICMPPACKET_H__B22F7856_5961_43FA_AD5A_FAE47C12B756__INCLUDED_)
#define AFX_ICMPPACKET_H__B22F7856_5961_43FA_AD5A_FAE47C12B756__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "common.h"

typedef DWORD IPADDR;


#define ICMP_SEND_ECHO	8
#define ICMP_REPLY_ECHO 0
#define ICMP_REQUEST_SUBNET	17
#define ICMP_REPLY_SUBNET	18
#define ICMP_GETLOCALTIME	13
#define ICMP_REPLY_GETLOCALTIME 14
#define ICMP_ERROR_TIME_EXPIRED 11
#define ICMP_ERROR_DEST_UNREACHABLE 3


//Codici di errore per la risposta ICMP  tipo 3

#define ERROR_NET_UNREACH				0
#define ERROR_HOST_UNREACH				1
#define ERROR_PROTOCOL_UNREACH			2
#define ERROR_PORT_UNREACH				3
#define ERROR_FRAGMENT_BIT_SET			4
#define ERROR_PATH_FAULT				5
#define ERROR_DEST_NET_UNKNOW			6
#define ERROR_DEST_HOST_UNKNOW			7
#define ERROR_HOST_FAULT				8
#define ERROR_COMM_NET_NOT_ALLOW		9
#define ERROR_COMM_HOST_NOT_ALLOW		10
#define ERROR_NET_UNREACH_BY_SERVICE	11
#define ERROR_HOST_UNREACH_BY_SERVICE	12

//Codici di errore per la risposta ICMP tipo 11

#define ERROR_TTL_EXPIRED				0
#define ERROR_TIME_REASSEM_EXPIRED		1

#include "ClassLib\sockets.h"

typedef struct tagICMPHEADER
{
    BYTE    Type;
    BYTE    Code; 
    USHORT  CheckSum;
    USHORT  Id;
    USHORT  Seq;
}ICMPHEADER, *PICMPHEADER;


class CIcmpPacket  
{
private:

  PBYTE      m_pPacket;
  DWORD      dwSize;

  WORD Checksum(PWORD pData, int nBytes);
  
public:
	CIcmpPacket(BYTE    cbIcmpType,
              PBYTE   pIcmpData,
              int     nBytes);

	virtual ~CIcmpPacket();

  const PBYTE Data()
  {
    return m_pPacket;
  }

  DWORD Size() const
  {
    return dwSize;
  }

};

class CIcmpReply
{
public:
    IPADDR  Address;         // Replying address
    DWORD   Status;          // Reply IP_STATUS
    BYTE    Type;            // Type of ICMP Reply
    ULONG   RoundTripTime;   // RTT in milliseconds    
    BYTE    Ttl;             // Time To Live
    BYTE    Tos;             // Type Of Service
    BYTE    Flags;           // IP header flags
    WORD    DataSize;        // Reply data size in bytes
    //PVOID   Data;            // Pointer to the reply data
};

#endif // !defined(AFX_ICMPPACKET_H__B22F7856_5961_43FA_AD5A_FAE47C12B756__INCLUDED_)
