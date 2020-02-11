#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
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
#include "ViewModels/clubsviewmodel.h"
#include "Services/clubservice.h"
#include "Services/leagueservice.h"
#include "ViewModels/leaguesviewmodel.h"
#include "Repositories/coachrepository.h"
#include "Repositories/leaguerepository.h"
#include "ViewModels/clubactionsviewmodel.h"


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

    Connection conn("QSQLITE", "/home/thomas/TestScrollDesktopApplication/soccerleague.db");
    ClubsRepository clubRepo(conn);
    PlayerRepository playerRepo(conn);
    PlayerJourneyRepository playerJourneyRepo(conn);
    StadiumRepository stadiumRepo(conn);
    CoachRepository coachRepo(conn);
    LeagueRepository leagueRepo(conn);

    PlayerService playerService(clubRepo, playerJourneyRepo, playerRepo);
    ClubService clubService(clubRepo, stadiumRepo, playerRepo);
    LeagueService leagueService(clubRepo, coachRepo, leagueRepo);

    PlayerViewModel* playerViewModel = new PlayerViewModel(playerService);
    ClubsViewModel* clubsViewModel = new ClubsViewModel(clubService);
    LeaguesViewModel* leagueViewModel = new LeaguesViewModel(leagueService);
    ClubActionsViewModel* clubActionsViewModel = new ClubActionsViewModel(clubService);

    QObject::connect(&(*clubActionsViewModel), SIGNAL(clubSavedEvent()), &(*leagueViewModel), SLOT(refreshClubs()));

    engine.rootContext()->setContextProperty("leagueViewModelContext", leagueViewModel);
    engine.rootContext()->setContextProperty("clubViewModelContext", clubsViewModel);
    engine.rootContext()->setContextProperty("clubActionsViewModelContext", clubActionsViewModel);

    //engine.rootContext()->setContextProperty("playerViewModelContext", playerViewModel);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.load(url);

    int exec = app.exec();

    delete playerViewModel;
    delete clubsViewModel;
    delete leagueViewModel;
    delete clubActionsViewModel;

    return exec;
}
