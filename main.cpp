#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include "clubsviewmodel.h"
#include "Models/club.h"
#include "Models/player.h"
#include <QQmlContext>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>

using namespace SoccerLeague::Models;

int main(int argc, char *argv[])
{




    const QString Driver("QSQLITE");

    if (!QSqlDatabase::isDriverAvailable(Driver)) {
        return -1;
    }

    QSqlDatabase db = QSqlDatabase::addDatabase(Driver);

    //TODO: NEED RELATIVE PATH IN THE FUTURE
    db.setDatabaseName("/home/thomas/TestScrollDesktopApplication/soccerleague.db");
    db.open();

    /*QSqlQuery testquery;

    testquery.exec("SELECT * from TEST");

    while (testquery.next()) {
        int id = testquery.value(0).toInt();
        QString name = testquery.value(1).toString();
        qDebug() << id << name;
    }*/

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

  //  engine.rootContext()->setContextProperty("clubViewModelContext", new ClubsViewModel(Club()));

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.load(url);

    return app.exec();
}
