#include "stadiumrepository.h"
#include <sstream>
#include "../Database/querybuilder.h"

using namespace SoccerLeague::Repositories;
using namespace SoccerLeague::Database;

std::shared_ptr<Stadium> StadiumRepository::update(const Stadium &item){
    return nullptr;
}

std::shared_ptr<Stadium> StadiumRepository::add(const Stadium &item) {


    return nullptr;
}

bool StadiumRepository::remove(const Stadium &item) {
    return false;
}

bool StadiumRepository::removeById(const int &id) {
    return false;
}

std::shared_ptr<Stadium> StadiumRepository::getById(const int &id) {

    return getAll(std::unordered_map<QString, QString> {std::make_pair("id", QString::number(id))})->at(0);

}

std::shared_ptr<QVector<std::shared_ptr<Stadium>>>
StadiumRepository::getAll(const std::unordered_map<QString, QString> &filters) {
    conn_.open();

    auto res = conn_.get().lastError();

    if (conn_.get().isOpen()) {

        QString rawSelect = QueryBuilder::createSelect(basic_query_t {
           .tablename = "Stadiums",
           .columns = QVector<QString> {"id", "capacity", "terrain_quality", "name", "address"},
           .filters = filters,
           .additional_args = ""
        });

        QSqlQuery query;
        query.prepare(rawSelect);

        for (auto &filter : filters) {
            query.bindValue(":" + filter.first, filter.second);
        }

        query.exec();

        auto pStadiums = QVector<std::shared_ptr<Stadium>>();

        while (query.next()) {

            auto pStadium = std::make_shared<Stadium>();

            pStadium->setId(query.value(0).toInt());
            pStadium->setCapacity(query.value(1).toInt());
            pStadium->setTerrainQuality(query.value(2).toString());
            pStadium->setName(query.value(3).toString());
            pStadium->setAddress(query.value(4).toString());

            pStadiums.push_back(pStadium);
        }

        conn_.close();

        return std::make_shared<QVector<std::shared_ptr<Stadium>>>(pStadiums);
    }
    conn_.close();

    return nullptr;
}

/*std::shared_ptr<Stadium> StadiumRepository::getById(const int &id) {

    conn_.open();

    if (conn_.get().isOpen()) {
        QSqlQuery query;


        query.prepare("SELECT id, capacity, terrain_quality, name, address FROM Stadiums WHERE id=:id LIMIT 1");
        query.bindValue(":id", QVariant(id));

        query.exec();

        query.first();


        std::shared_ptr<Stadium> pClub = std::make_shared<Stadium>();

        pClub->setId(query.value(0).toInt());
        pClub->setCapacity(query.value(1).toInt());
        pClub->setTerrainQuality(query.value(2).toString());
        pClub->setName(query.value(3).toString());
        pClub->setAddress(query.value(4).toString());

        conn_.close();

        return pClub;

    }

    return nullptr;

}*/

std::shared_ptr<Stadium> StadiumRepository::getByProperty(const QString &propertyName) {
    return nullptr;
}

std::shared_ptr<QVector<Stadium>> StadiumRepository::getAll() { return nullptr;}

