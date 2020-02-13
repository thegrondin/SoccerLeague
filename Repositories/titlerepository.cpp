#include "titlerepository.h"
#include <sstream>
#include "../Database/querybuilder.h"


using namespace SoccerLeague::Repositories;
using namespace SoccerLeague::Database;

std::shared_ptr<Title> TitleRepository::update(const Title &item){
    return nullptr;
}

std::shared_ptr<Title> TitleRepository::add(const Title &item) {

    conn_.open();



    QSqlQuery query;

    if (item.getClub() && item.getClub()->getId() != 0) {



        query.prepare("INSERT INTO Titles (name, date, club_id)"
                      "VALUES (:name, :date, :club_id)");

        query.bindValue(":name", QVariant(item.getName()));
        query.bindValue(":date", QVariant(item.getDate()));
        query.bindValue(":club_id", QVariant(item.getClub()->getId()));
    }
    else {
        query.prepare("INSERT INTO Titles (name, date, coach_id)"
                      "VALUES (:name, :date, :coach_id)");

        query.bindValue(":name", QVariant(item.getName()));
        query.bindValue(":date", QVariant(item.getDate()));
        query.bindValue(":coach_id", QVariant(item.getCoach()->getId()));
    }

    query.exec();

    auto result = query.lastInsertId().toInt();

    conn_.close();

    return this->getById(result);

    /*
     *
     * conn_.open();

    QSqlQuery query;

    query.prepare("INSERT INTO Players (firstname, lastname, weight, birth_city, club_id)"
                  "VALUES (:firstname, :lastname, :weight, :birth_city, :club_id)");

    query.bindValue(":firstname", QVariant(item.getFirstname()));
    query.bindValue(":lastname", QVariant(item.getLastname()));
    query.bindValue(":weight", QVariant(item.getWeight()));
    query.bindValue("birth_city", QVariant(item.getBirthCity()));
    query.bindValue(":club_id", QVariant(item.getClub()->getId()));

    query.exec();

    auto result = query.lastInsertId().toInt();

    conn_.close();

    return this->getById(result);*/
}

bool TitleRepository::remove(const Title &item) {
    return false;
}

bool TitleRepository::removeById(const int &id) {

    conn_.open();

    QSqlQuery query;

    query.prepare("DELETE FROM Titles WHERE id=:id");

    query.bindValue(":id", QVariant(id));

    return query.exec();
}

std::shared_ptr<Title> TitleRepository::getById(const int &id) {

    return getAll(std::unordered_map<QString, QString> {std::make_pair("id", QString::number(id))})->at(0);

}

std::shared_ptr<Title> TitleRepository::getByProperty(const QString &propertyName) {
    return nullptr;
}

std::shared_ptr<QVector<std::shared_ptr<Title>>>
TitleRepository::getAll(const std::unordered_map<QString, QString> &filters) {
    conn_.open();

    auto res = conn_.get().lastError();

    if (conn_.get().isOpen()) {

        QString rawSelect = QueryBuilder::createSelect(basic_query_t {
           .tablename = "Titles",
           .columns = QVector<QString> {"id", "name", "date", "club_id", "coach_id"},
           .filters = filters,
           .additional_args = ""
        });

        QSqlQuery query;
        query.prepare(rawSelect);

        for (auto &filter : filters) {
            query.bindValue(":" + filter.first, filter.second);
        }

        query.exec();

        auto pTitles = QVector<std::shared_ptr<Title>>();

        while (query.next()) {

            auto pTitle = std::make_shared<Title>();
            auto pClub = std::make_shared<Club>();
            auto pCoach = std::make_shared<Coach>();

            pTitle->setId(query.value(0).toInt());
            pTitle->setName(query.value(1).toString());
            pTitle->setDate(query.value(2).toDate());

            if (query.value(3).toInt() != 0) {
                pClub->setId(query.value(3).toInt());
            }
            else {
                pCoach->setId(query.value(4).toInt());
            }

            pTitle->setClub(pClub);
            pTitle->setCoach(pCoach);

            pTitles.push_back(pTitle);
        }

        conn_.close();

        return std::make_shared<QVector<std::shared_ptr<Title>>>(pTitles);
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


std::shared_ptr<QVector<Title>> TitleRepository::getAll() { return nullptr;}

