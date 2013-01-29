
////////////////////////////////////////////////////////////////////////////////

#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H


class CEventHandler
{
public:
  virtual BOOL HandleEvent(HANDLE h) = 0;
  virtual HANDLE GetHandle() = 0;
};


#endif //EVENTHANDLER_H