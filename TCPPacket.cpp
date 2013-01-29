// TCPPacket.cpp: implementation of the CTCPPacket class.
//
//////////////////////////////////////////////////////////////////////

#include "TCPPacket.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTCPPacket::CTCPPacket()
{

}

CTCPPacket::~CTCPPacket()
{

}

WORD CTCPPacket::Checksum(PWORD pData, int nBytes)
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
