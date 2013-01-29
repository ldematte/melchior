// TCPPacket.h: interface for the CTCPPacket class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TCPPACKET_H__EB0383E3_25FD_42A2_B1BA_6264964B12D8__INCLUDED_)
#define AFX_TCPPACKET_H__EB0383E3_25FD_42A2_B1BA_6264964B12D8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CmnHdr.h"

class CTCPPacket  
{
private:
  
  WORD Checksum(PWORD pData, int nBytes);

public:
	CTCPPacket();
	virtual ~CTCPPacket();

};

#endif // !defined(AFX_TCPPACKET_H__EB0383E3_25FD_42A2_B1BA_6264964B12D8__INCLUDED_)
