#ifndef SOCKETS_H_
#define SOCKETS_H_

#include "common.h"


class CSocket
{
private:
  SOCKET m_socket;

  bool Init(int af, int type, int protocol)
  {
    if ((m_socket = socket(af, type, protocol)) == SOCKET_ERROR)
      return false;
  
    return true;
  }

public:
  CSocket(int af, int type, int protocol)
  {
    Init(af, type, protocol);
  }

  operator SOCKET() const
  {
    return m_socket;
  }

  DWORD GetLastError()
  {
#ifdef WIN32
    return WSAGetLastError();
#else
    return errno;
#endif
  }
};

#endif //SOCKETS_H_
