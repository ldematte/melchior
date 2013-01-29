#ifndef DEMA_COMMON_H
#define DEMA_COMMON_H

#pragma once

#define UNICODE
#define _UNICODE

#ifndef _WINDOWS_
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#undef WIN32_LEAN_AND_MEAN
#endif

#include <tchar.h>
#include <stdio.h>
#define TRACE _tprintf

#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

#include <ws2tcpip.h>

#define SIO_RCVALL  0x98000001
#define MAX_IP_SIZE 65535

#include <assert.h>

#endif