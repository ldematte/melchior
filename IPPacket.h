// IPPacket.h: interface for the CIPPacket class.
//
//////////////////////////////////////////////////////////////////////

#ifndef IPPACKET_H
#define IPPACKET_H

#pragma once

#include "common.h"

typedef struct tagIPHEADER
{
  	BYTE  cbHeaderLen:4;         
	  BYTE  cbVersion:4;       
	  BYTE  cbTOS;            
    WORD  wTotalLen;
    WORD  wPacketId;         
    WORD  fMoreFragments:1;
    WORD  fNotFragment:1;
    WORD  fReserved:1;
    WORD  FragmentOffset:13;
	  BYTE  cbTtl; 
	  BYTE  cbNextProtocol;           
	  WORD  wChecksum;       
    DWORD dwSourceIP;
    DWORD dwDestIP;
} IPHEADER, *PIPHEADER;


class CIPPacket
{
public:
  

	CIPPacket();
	virtual ~CIPPacket();

};

#endif //IPPACKET_H
