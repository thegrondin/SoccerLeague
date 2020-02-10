#include "playerrepository.h"
#include <sstream>
#include "../Database/querybuilder.h"

using namespace SoccerLeague::Repositories;
using namespace SoccerLeague::Database;

std::shared_ptr<Player> PlayerRepository::update(const Player &item){
    return nullptr;
}

std::shared_ptr<Player> PlayerRepository::add(const Player &item) {

    return nullptr;
}

bool PlayerRepository::remove(const Player &item) {
    return false;
}

bool PlayerRepository::removeById(const int &id) {
    return false;
}

std::shared_ptr<Player> PlayerRepository::getById(const int &id) {

    //return nullptr;
    return getAll(std::unordered_map<QString, QString> {std::make_pair("id", QString::number(id))})->at(0);

}

std::shared_ptr<QVector<std::shared_ptr<Player>>>
PlayerRepository::getAll(const std::unordered_map<QString, QString> &filters) {
    conn_.open();

    auto res = conn_.get().lastError();

    if (conn_.get().isOpen()) {

        QString rawSelect = QueryBuilder::createSelect(basic_query_t {
           .tablename = "Players",
           .columns = QVector<QString> {"id", "firstname", "lastname", "weight", "birth_city", "club_id"},
           .filters = filters,
           .additional_args = ""
        });

        QSqlQuery query;
        query.prepare(rawSelect);

        for (auto &filter : filters) {
            query.bindValue(":" + filter.first, filter.second);
        }

        query.exec();

        auto pPlayers = QVector<std::shared_ptr<Player>>();

        while (query.next()) {

            auto pClub = std::make_shared<Club>();
            auto pPlayer = std::make_shared<Player>();

            auto test = query.value(0).toInt();

            pPlayer->setId(test);
            pPlayer->setFirstname(query.value(1).toString());
            pPlayer->setLastname(query.value(2).toString());
            pPlayer->setWeight(query.value(3).toFloat());
            pPlayer->setBirthCity(query.value(4).toString());

            pClub->setId(query.value(5).toInt());

            pPlayer->setClub(pClub);

            pPlayers.push_back(pPlayer);
        }

        conn_.close();

        return std::make_shared<QVector<std::shared_ptr<Player>>>(pPlayers);
        //return nullptr;
    }
    conn_.close();

    return nullptr;
}

std::shared_ptr<Player> PlayerRepository::getByProperty(const QString &propertyName) {
    return nullptr;
}

std::shared_ptr<QVector<Player>> PlayerRepository::getAll() { return nullptr;}


