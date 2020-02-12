#include "clubsrepository.h"
#include<QDebug>

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

std::shared_ptr<Club> ClubsRepository::update(const Club &item){
    return nullptr;
}

std::shared_ptr<Club> ClubsRepository::add(const Club &item) {

    conn_.open();

    QSqlQuery query;
    query.prepare("INSERT INTO Clubs (stadium_id, history, color, created_at, city_name, league_id)"
                  "VALUES (:statium_id, :history, :color, :created_at, :city_name, :league_id)");


    query.bindValue(":history", QVariant(item.getHistory()));
    query.bindValue(":color", QVariant(item.getColor()));
    query.bindValue(":created_at", QVariant(item.getCreatedAt()));
    query.bindValue(":city_name", QVariant(item.getCityName()));

    //query.bindValue(":league_id", QVariant(item.get))

    if (item.getStadium()) {
        query.bindValue(":statium_id", QVariant(item.getStadium()->getId()));
    }
    else {
        query.bindValue(":statium_id", QVariant());
    }
   // auto le = item.getLeague()->getId();
    query.bindValue(":league_id", QVariant(item.getLeague()->getId()));

    query.exec();

    auto result = query.lastInsertId().toInt();
    conn_.close();

    return this->getById(result);
}

bool ClubsRepository::remove(const Club &item) {
    return false;
}

bool ClubsRepository::removeById(const int &id) {


    conn_.open();

    QSqlQuery query;
    query.prepare("DELETE FROM Clubs WHERE id=:id");

    query.bindValue(":id", id);

    auto success = query.exec();

    conn_.close();

    return success;
}

std::shared_ptr<Club> ClubsRepository::getById(const int &id) {

    //return nullptr;
    return getAll(std::unordered_map<QString, QString> {std::make_pair("id", QString::number(id))})->at(0);

}

std::shared_ptr<QVector<std::shared_ptr<Club>>>
ClubsRepository::getAll(const std::unordered_map<QString, QString> &filters) {

    conn_.open();

    auto res = conn_.get().lastError();

    if (conn_.get().isOpen()) {
        //query.prepare("SELECT id, history, color, created_at, city_name, stadium_id FROM Clubs WHERE id=:id LIMIT 1");
        QString rawSelect = QueryBuilder::createSelect(basic_query_t {
           .tablename = "Clubs",
           .columns = QVector<QString> {"id", "history", "color", "created_at", "city_name", "stadium_id", "league_id"},
           .filters = filters,
           .additional_args = ""
        });

        QSqlQuery query;
        query.prepare(rawSelect);

        for (auto &filter : filters) {
            query.bindValue(":" + filter.first, filter.second);
        }

        query.exec();

        auto pClubs = QVector<std::shared_ptr<Club>>();

        while (query.next()) {


            std::shared_ptr<Club> pClub = std::make_shared<Club>();
            std::shared_ptr<Stadium> pStadium = std::make_shared<Stadium>();

            pClub->setId(query.value(0).toInt());
            pClub->setHistory(query.value(1).toString());
            pClub->setColor(query.value(2).toString());
            pClub->setCreatedAt(query.value(3).toDateTime());
            pClub->setCityName(query.value(4).toString());

            pStadium->setId(query.value(5).toInt());

            pClub->setStadium(pStadium);

            pClubs.push_back(pClub);
        }

        conn_.close();

        return std::make_shared<QVector<std::shared_ptr<Club>>>(pClubs);
        //return nullptr;
    }
    conn_.close();

    return nullptr;


   /* conn_.open();

    if (conn_.get().isOpen()) {
        QSqlQuery query;

        qDebug() << conn_.get().databaseName();

        query.prepare("SELECT id, history, color, created_at, city_name, stadium_id FROM Clubs WHERE id=:id LIMIT 1");
        query.bindValue(":id", id);

        query.exec();

        query.first();

        std::shared_ptr<Club> pClub = std::make_shared<Club>();
        std::shared_ptr<Stadium> pStadium = std::make_shared<Stadium>();

        pClub->setId(query.value(0).toInt());
        pClub->setHistory(query.value(1).toString());
        pClub->setColor(query.value(2).toString());
        pClub->setCreatedAt(query.value(3).toDateTime());
        pClub->setCityName(query.value(4).toString());

        pStadium->setId(query.value(5).toInt());

        pClub->setStadium(pStadium);

        conn_.close();

        return pClub;

    }

    return nullptr;*/

}

std::shared_ptr<Club> ClubsRepository::getByProperty(const QString &propertyName) {
    return nullptr;
}

std::shared_ptr<QVector<Club>> ClubsRepository::getAll() { return nullptr;}

