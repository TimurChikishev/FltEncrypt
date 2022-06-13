#ifndef DRIVERCONTROLLER_H
#define DRIVERCONTROLLER_H

#include <QObject>
#include "windows.h"
#include "fltuser.h"
#include "qstring.h"
#include "utils/Utils.h"

#define PORT_NAME L"\\FLT_ENCRYPT_PORT"
#define COMMUNICATE_SUCCESS "SUCCESS"
#define COMMUNICATE_ATTEMPT "ATTEMPT TO COMMUNICATE"

class DriverController
{
public:
    DriverController();
    ~DriverController();

    bool connect();
    bool disconnect();
    bool sendMessage(char * inputBuffer, char * outputBuffer);

private:
    HANDLE port = NULL;
};

#endif // DRIVERCONTROLLER_H
