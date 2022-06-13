#ifndef APPCORE_H
#define APPCORE_H

#include <QObject>
#include "domain/driver/drivercontroller.h"
#include "utils/Utils.h"

class AppCore : public QObject
{
    Q_OBJECT
public:
    explicit AppCore(QObject *parent = 0);

private:
    DriverController driverController;

signals:
    void connectSignal(bool status, QString message);
    void disconnectSignal(bool status, QString message);

public slots:
    void fltConnect();
    void fltDisconnect();
};

#endif // APPCORE_H
