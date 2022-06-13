#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <ui/app/appcore.h>
#include <QQuickStyle>
#include <qqmlcontext.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    AppCore appCore;
    QQuickStyle::setStyle("Material");

    const QUrl url(u"qrc:/qml/main.qml"_qs);

    QQmlContext *context = engine.rootContext();
    context->setContextProperty("appCore", &appCore);


    engine.load(url);


    return app.exec();
}
