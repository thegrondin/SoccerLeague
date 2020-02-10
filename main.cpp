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
#include <memory>
#include <QApplication>
#include "Services/playerservice.h"
#include "Database/querybuilder.h"
#include "Repositories/clubsrepository.h"
#include "Repositories/playerjourneyrepository.h"
#include "Repositories/playerrepository.h"
#include "ViewModels/playerviewmodel.h"
#include <iostream>

using namespace SoccerLeague::Models;
using namespace SoccerLeague::Repositories;
using namespace SoccerLeague::Database;
using namespace SoccerLeague::ViewModels;

int main(int argc, char *argv[])
{



    //Connection conn("QSQLITE", "C:\\Users\\tomto\\Documents\\SoccerLeague\\soccerleague.db");
  //  ClubsRepository repo(conn);

  //  std::shared_ptr<Club> club = repo.getById(1);


    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication app(argc, argv);

    QQmlApplicationEngine engine;

    Connection conn("QSQLITE", "C:\\Users\\tomto\\Documents\\SoccerLeague\\soccerleague.db");
    ClubsRepository clubRepo(conn);
    PlayerRepository playerRepo(conn);
    PlayerJourneyRepository playerJourneyRepo(conn);

    PlayerService playerService(clubRepo, playerJourneyRepo, playerRepo);
    PlayerViewModel* playerViewModel = new PlayerViewModel(playerService);

    //engine.rootContext()->setContextProperty("clubViewModelContext", new ClubsViewModel(Club()));
    engine.rootContext()->setContextProperty("playerViewModelContext", playerViewModel);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.load(url);

    int exec = app.exec();

    delete playerViewModel;

    return exec;
}
