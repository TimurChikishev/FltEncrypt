#include "drivercontroller.h"

DriverController::DriverController(){}

DriverController::~DriverController()
{
    disconnect();
}

bool DriverController::connect()
{
    if(port != NULL) return false;

    char * inputBuffer = QString(COMMUNICATE_ATTEMPT).toLocal8Bit().data();
    char outputBuffer[6] = { 0 };

    HRESULT connect_status = FilterConnectCommunicationPort(
                PORT_NAME,
                ZERO,
                NULL,
                ZERO,
                NULL,
                &port
                );

    bool control_status = sendMessage(inputBuffer, outputBuffer);

    return IS_ERROR(connect_status) && control_status;
}

bool DriverController::disconnect()
{
    bool status = CloseHandle(port);

    if (status) port = NULL;

    return status;
}


bool DriverController::sendMessage(char * inputBuffer, char * outputBuffer)
{
    DWORD byteReturned = 0;

    HRESULT status = FilterSendMessage(
                port,
                inputBuffer,
                strlen(inputBuffer),
                &outputBuffer,
                strlen(outputBuffer),
                &byteReturned
                );

    return status == S_OK && strcmp(outputBuffer, COMMUNICATE_SUCCESS) == 0;
}
