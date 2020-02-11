#include "leaguerepository.h"
#include <sstream>
#include "../Database/querybuilder.h"

using namespace SoccerLeague::Repositories;
using namespace SoccerLeague::Database;

std::shared_ptr<League> LeagueRepository::update(const League &item){
    return nullptr;
}

std::shared_ptr<League> LeagueRepository::add(const League &item) {

    return nullptr;
}

bool LeagueRepository::remove(const League &item) {
    return false;
}

bool LeagueRepository::removeById(const int &id) {
    return false;
}

std::shared_ptr<League> LeagueRepository::getById(const int &id) {

    return getAll(std::unordered_map<QString, QString> {std::make_pair("id", QString::number(id))})->at(0);

}

std::shared_ptr<QVector<std::shared_ptr<League>>>
LeagueRepository::getAll(const std::unordered_map<QString, QString> &filters) {
    conn_.open();

    auto res = conn_.get().lastError();

    if (conn_.get().isOpen()) {

        QString rawSelect = QueryBuilder::createSelect(basic_query_t {
           .tablename = "Leagues",
           .columns = QVector<QString> {"id", "name"},
           .filters = filters,
           .additional_args = ""
        });

        QSqlQuery query;
        query.prepare(rawSelect);

        for (auto &filter : filters) {
            query.bindValue(":" + filter.first, filter.second);
        }

        query.exec();

        auto pLeagues = QVector<std::shared_ptr<League>>();

        while (query.next()) {

            auto pLeague = std::make_shared<League>();

            pLeague->setId(query.value(0).toInt());
            pLeague->setName(query.value(1).toString());

            pLeagues.push_back(pLeague);
        }

        conn_.close();

        return std::make_shared<QVector<std::shared_ptr<League>>>(pLeagues);
    }
    conn_.close();

    return nullptr;
}

std::shared_ptr<League> LeagueRepository::getByProperty(const QString &propertyName) {
    return nullptr;
}

std::shared_ptr<QVector<League>> LeagueRepository::getAll() { return nullptr;}


