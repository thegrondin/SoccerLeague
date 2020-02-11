#include "coachrepository.h"
#include <sstream>
#include "../Database/querybuilder.h"

using namespace SoccerLeague::Repositories;
using namespace SoccerLeague::Database;

std::shared_ptr<Coach> CoachRepository::update(const Coach &item){
    return nullptr;
}

std::shared_ptr<Coach> CoachRepository::add(const Coach &item) {

    return nullptr;
}

bool CoachRepository::remove(const Coach &item) {
    return false;
}

bool CoachRepository::removeById(const int &id) {
    return false;
}

std::shared_ptr<Coach> CoachRepository::getById(const int &id) {

    //return nullptr;
    return getAll(std::unordered_map<QString, QString> {std::make_pair("id", QString::number(id))})->at(0);

}

std::shared_ptr<QVector<std::shared_ptr<Coach>>>
CoachRepository::getAll(const std::unordered_map<QString, QString> &filters) {
    conn_.open();

    auto res = conn_.get().lastError();

    if (conn_.get().isOpen()) {

        QString rawSelect = QueryBuilder::createSelect(basic_query_t {
           .tablename = "Coaches",
           .columns = QVector<QString> {"id", "firstname", "lastname", "graduation_location", "league_id"},
           .filters = filters,
           .additional_args = ""
        });

        QSqlQuery query;
        query.prepare(rawSelect);

        for (auto &filter : filters) {
            query.bindValue(":" + filter.first, filter.second);
        }

        query.exec();

        auto pCoaches = QVector<std::shared_ptr<Coach>>();

        while (query.next()) {

            auto pLeague = std::make_shared<League>();
            auto pCoach = std::make_shared<Coach>();

            pCoach->setId(query.value(0).toInt());
            pCoach->setFirstname(query.value(1).toString());
            pCoach->setLastname(query.value(2).toString());
            pCoach->setGraduationLocation(query.value(3).toString());

            pLeague->setId(query.value(4).toInt());

            pCoach->setLeague(pLeague);

            pCoaches.push_back(pCoach);
        }

        conn_.close();

        return std::make_shared<QVector<std::shared_ptr<Coach>>>(pCoaches);
    }
    conn_.close();

    return nullptr;
}

std::shared_ptr<Coach> CoachRepository::getByProperty(const QString &propertyName) {
    return nullptr;
}

std::shared_ptr<QVector<Coach>> CoachRepository::getAll() { return nullptr;}

