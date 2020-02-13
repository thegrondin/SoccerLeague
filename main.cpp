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
#include "Services/stadiumservice.h"
#include "ViewModels/playeractionsviewmodel.h"
#include <QSqlQuery>
#include "Repositories/titlerepository.h"
#include "ViewModels/titlesviewmodel.h"
#include "Repositories/repository.h"
#include "Repositories/titlerepository.h"
#include "Services/titleservice.h"
#include "ViewModels/coachviewmodel.h"
#include "Services/coachservice.h"

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

    /*Repository<Player> repoTest(conn, "Players");
    QVector<std::shared_ptr<Player>> playersTest = QVector<std::shared_ptr<Player>>();

    repoTest.select(QVector<QString> {"firstname"}, QVector<WhereQuery>() = { WhereQuery {"id", "=", "7"}}, "", [&playersTest](QSqlQuery query) {


        while (query.next()) {
            std::shared_ptr<Player> p = std::make_shared<Player>();

            p->setFirstname(query.value(0).toString());

            playersTest.push_back(p);
        }
    });

    QVector<QString> columns = {"firstname", "lastname", "weight", "birth_city", "club_id"};
    QVector<QString> values = {"Thomas", "Dion-Tremblay", "5050", "Mississipi", "3"};
    //bool result = repoTest.insert(columns, values);

    auto testing = playersTest;


    return -1;*/

    ClubsRepository clubRepo(conn);
    PlayerRepository playerRepo(conn);
    PlayerJourneyRepository playerJourneyRepo(conn);
    StadiumRepository stadiumRepo(conn);
    CoachRepository coachRepo(conn);
    LeagueRepository leagueRepo(conn);
    TitleRepository titleRepo(conn);


    PlayerService playerService(clubRepo, playerJourneyRepo, playerRepo);
    ClubService clubService(clubRepo, stadiumRepo, playerRepo, titleRepo);
    LeagueService leagueService(clubRepo, coachRepo, leagueRepo);
    StadiumService stadiumService(stadiumRepo);
    TitleService titleService(titleRepo);
    CoachService coachService(leagueRepo, titleRepo, coachRepo);

    PlayerViewModel* playerViewModel = new PlayerViewModel(playerService);
    ClubsViewModel* clubsViewModel = new ClubsViewModel(clubService);
    LeaguesViewModel* leagueViewModel = new LeaguesViewModel(leagueService);
    ClubActionsViewModel* clubActionsViewModel = new ClubActionsViewModel(clubService, stadiumRepo);
    PlayerActionsViewModel* playerActionsViewModel = new PlayerActionsViewModel(playerService);
    TitlesViewModel* titleViewModel = new TitlesViewModel(titleService);
    CoachViewModel* coachViewModel = new CoachViewModel(coachService);

    QObject::connect(&(*clubActionsViewModel), SIGNAL(clubSavedEvent()), &(*leagueViewModel), SLOT(refreshClubs()));
    QObject::connect(&(*playerActionsViewModel), SIGNAL(playersUpdatedEvent()), &(*playerViewModel), SLOT(refreshPlayers()));

    QObject::connect(&(*clubsViewModel), SIGNAL(clubSelectedEvent(int)), &(*playerViewModel), SLOT(setPlayersFromClubId(int)));
    QObject::connect(&(*clubsViewModel), SIGNAL(clubSelectedEvent(int)), &(*playerActionsViewModel), SLOT(setClub(int)));
    QObject::connect(&(*clubsViewModel), SIGNAL(clubSelectedEvent(int)), &(*titleViewModel), SLOT(setClub(int)));

    QObject::connect(&(*coachViewModel), SIGNAL(coachSelectedEvent(int)), &(*titleViewModel), SLOT(setCoach(int)));

    QObject::connect(&(*titleViewModel), SIGNAL(titlesChangedEvent()), &(*clubsViewModel), SLOT(refreshCurrent()));
    QObject::connect(&(*titleViewModel), SIGNAL(coachTitlesChangedEvent()), &(*coachViewModel), SLOT(refreshTitles()));


    engine.rootContext()->setContextProperty("leagueViewModelContext", leagueViewModel);
    engine.rootContext()->setContextProperty("clubViewModelContext", clubsViewModel);
    engine.rootContext()->setContextProperty("clubActionsViewModelContext", clubActionsViewModel);
    engine.rootContext()->setContextProperty("playersViewModelContext", playerViewModel);
    engine.rootContext()->setContextProperty("playerActionsViewModelContext", playerActionsViewModel);
    engine.rootContext()->setContextProperty("TitlesViewModelContext", titleViewModel);
    engine.rootContext()->setContextProperty("coachViewModelContext", coachViewModel);


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
    delete playerActionsViewModel;
    delete titleViewModel;
    delete coachViewModel;

    return exec;
}
