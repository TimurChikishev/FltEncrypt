#include "appcore.h"
#include "QString"

#define STATUS_MESSAGE(_bool) _bool ? "Success" : "Failed"

AppCore::AppCore(QObject *parent) : QObject(parent)
{
    driverController = DriverController();
}

void AppCore::fltConnect()
{
    bool status = driverController.connect();
    emit connectSignal(status, STATUS_MESSAGE(status));
}


void AppCore::fltDisconnect()
{
    bool status = driverController.disconnect();
    emit disconnectSignal(status, STATUS_MESSAGE(status));
}
