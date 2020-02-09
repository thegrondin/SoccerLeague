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
#include "Repositories/clubsrepository.h"
#include <memory>
#include <QApplication>

using namespace SoccerLeague::Models;
using namespace SoccerLeague::Repositories;

int main(int argc, char *argv[])
{


    Connection conn("QSQLITE", "C:\\Users\\tomto\\Documents\\SoccerLeague\\soccerleague.db");
  //  ClubsRepository repo(conn);

  //  std::shared_ptr<Club> club = repo.getById(1);


    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication app(argc, argv);

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("clubViewModelContext", new ClubsViewModel(Club()));

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.load(url);

    return app.exec();
}
