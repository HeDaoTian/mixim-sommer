//
// Copyright 2004 Andras Varga
//
// This library is free software, you can redistribute it and/or modify
// it under  the terms of the GNU Lesser General Public License
// as published by the Free Software Foundation;
// either version 2 of the License, or any later version.
// The library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
// See the GNU Lesser General Public License for more details.
//

#ifndef __TELNETAPP_H_
#define __TELNETAPP_H_

#include <vector>
#include <omnetpp.h>
#include "TCPGenericCliAppBase.h"


/**
 * Basic Telnet application. The server app should be TCPGenericSrvApp.
 */
class TelnetApp : public TCPGenericCliAppBase
{
  public:
    Module_Class_Members(TelnetApp, TCPGenericCliAppBase, 0);

    /** Redefined to schedule a connect(). */
    virtual void initialize();

    /** Redefined. */
    virtual void handleTimer(cMessage *msg) = 0;

    /** Redefined. */
    virtual void socketEstablished(int connId, void *yourPtr);

    /** Redefined. */
    virtual void socketDataArrived(int connId, void *yourPtr, cMessage *msg, bool urgent);

    /** Redefined to start another session after a delay. */
    virtual void socketClosed(int connId, void *yourPtr);

    /** Redefined to reconnect after a delay. */
    virtual void socketFailure(int connId, void *yourPtr, int code);
};

#endif


