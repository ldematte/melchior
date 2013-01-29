// IcmpPacket.cpp: implementation of the CIcmpPacket class.
//
//////////////////////////////////////////////////////////////////////

#include "IcmpPacket.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CIcmpPacket::CIcmpPacket(BYTE    cbIcmpType,
                         PBYTE   pIcmpData,
                         int     nBytes)
{
  m_pPacket = new BYTE[nBytes + sizeof(ICMPHEADER)];
  PICMPHEADER IcmpHeader = (PICMPHEADER)m_pPacket;

  IcmpHeader->Type = cbIcmpType;
  IcmpHeader->Code = 0;
  IcmpHeader->CheckSum = 0;
  IcmpHeader->Id =(USHORT) GetCurrentProcessId();
  IcmpHeader->Seq = 0;

  if (pIcmpData == NULL)
    nBytes = 0;

  if (nBytes != 0)
  {
    PBYTE pUserData = m_pPacket + sizeof(ICMPHEADER);
    CopyMemory(pUserData, pIcmpData, nBytes);
  }

  dwSize = sizeof(ICMPHEADER) + nBytes;
  IcmpHeader->CheckSum = Checksum((PWORD)m_pPacket, sizeof(ICMPHEADER) + nBytes);
}

CIcmpPacket::~CIcmpPacket()
{
  delete[] m_pPacket;
}

WORD CIcmpPacket::Checksum(PWORD pData, int nBytes)
{
	DWORD dwSum;
	
	/*
	 * Our algorithm is simple, using a 32-bit accumulator (sum),
	 * we add sequential 16-bit words to it, and at the end, fold back
	 * all the carry bits from the top 16 bits into the lower 16 bits.
	 */

	dwSum = 0;
	while (nBytes > 1)
  {
		dwSum += *pData++;
		nBytes -= sizeof(WORD);
	}

	/* mop up an odd byte, if necessary */
	
  if (nBytes == 1)
  {		
		dwSum = *(PBYTE)pData;   /* one byte only */
	}

	/*
	 * Add back carry outs from top 16 bits to low 16 bits.
	 */

	dwSum  = (dwSum >> 16) + (dwSum & 0xffff);  /* add high-16 to low-16 */
	dwSum += (dwSum >> 16);                     /* add carry */
	return ( (USHORT)(~dwSum) );                /* ones-complement, then truncate to 16 bits */
}

