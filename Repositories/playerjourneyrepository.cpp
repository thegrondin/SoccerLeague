#include "playerjourneyrepository.h"
#include <sstream>
#include "../Database/querybuilder.h"
/*ClubsRepository::ClubsRepository()
{

}

ClubsRepository::~ClubsRepository() {

}*/

/**

    /*
     * QSqlQuery testquery;

    testquery.exec("SELECT * from TEST");

    while (testquery.next()) {
        int id = testquery.value(0).toInt();
        QString name = testquery.value(1).toString();
        qDebug() << id << name;
    }*/

    /*
     * query.prepare("INSERT INTO person (id, forename, surname) "
                  "VALUES (:id, :forename, :surname)");
    query.bindValue(":id", 1001);
    query.bindValue(":forename", "Bart");
    query.bindValue(":surname", "Simpson");
    query.exec();*/

using namespace SoccerLeague::Repositories;
using namespace SoccerLeague::Database;

std::shared_ptr<PlayerJourney> PlayerJourneyRepository::update(const PlayerJourney &item){
    return nullptr;
}

std::shared_ptr<PlayerJourney> PlayerJourneyRepository::add(const PlayerJourney &item) {

    return nullptr;
}

bool PlayerJourneyRepository::remove(const PlayerJourney &item) {
    return false;
}

bool PlayerJourneyRepository::removeById(const int &id) {
    return false;
}


bool PlayerJourneyRepository::removeWhere(const std::pair<QString, QString>& filter) {

    conn_.open();

    QSqlQuery query;
    query.prepare("DELETE FROM PlayerJourneys WHERE :condition_key=:condition_value");

    query.bindValue(":condition_key", filter.first);
    query.bindValue(":condition_value", filter.second);

    auto success = query.exec();

    conn_.close();

    return success;

}

std::shared_ptr<PlayerJourney> PlayerJourneyRepository::getById(const int &id) {

    return getAll(std::unordered_map<QString, QString> {std::make_pair("id", QString::number(id))})->at(0);

}

std::shared_ptr<QVector<std::shared_ptr<PlayerJourney>>>
PlayerJourneyRepository::getAll(const std::unordered_map<QString, QString> &filters) {
    conn_.open();

    if (conn_.get().isOpen()) {

        QString rawSelect = QueryBuilder::createSelect(basic_query_t {
           .tablename = "PlayerJourneys",
           .columns = QVector<QString> {"id", "static_club_name", "start_date", "end_date", "club_id", "player_id"},
           .filters = filters,
           .additional_args = ""
        });

        QSqlQuery query;
        query.prepare(rawSelect);

        for (auto &filter : filters) {
            query.bindValue(":" + filter.first, filter.second);
        }

        query.exec();

        std::shared_ptr<QVector<std::shared_ptr<PlayerJourney>>> pPlayerJourneys = std::make_shared<QVector<std::shared_ptr<PlayerJourney>>>();

        while (query.next()) {

            std::shared_ptr<PlayerJourney> pPlayerJourney = std::make_shared<PlayerJourney>();
            std::shared_ptr<Club> pClub = std::make_shared<Club>();
            std::shared_ptr<Player> pPlayer = std::make_shared<Player>();

            pPlayerJourney->setId(query.value(0).toInt());
            pPlayerJourney->setStaticClubName(query.value(1).toString());
            pPlayerJourney->setStartDate(query.value(2).toDateTime());
            pPlayerJourney->setEndDate(query.value(3).toDateTime());

            pClub->setId(query.value(4).toInt());
            pPlayer->setId(query.value(5).toInt());

            pPlayerJourney->setClub(pClub);
            pPlayerJourney->setPlayer(pPlayer);

            pPlayerJourneys->push_back(pPlayerJourney);
        }
        conn_.close();
        return pPlayerJourneys;
    }

    return nullptr;
}

std::shared_ptr<PlayerJourney> PlayerJourneyRepository::getByProperty(const QString &propertyName) {
    return nullptr;
}

std::shared_ptr<QVector<PlayerJourney>> PlayerJourneyRepository::getAll() { return nullptr;}


