#include "clubsrepository.h"
#include<QDebug>
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

std::shared_ptr<Club> ClubsRepository::update(const Club &item){
    return nullptr;
}

std::shared_ptr<Club> ClubsRepository::add(const Club &item) {

    conn_.open();

    QSqlQuery query;
    query.prepare("INSERT INTO Clubs (stadium_id, history, color, created_at, city_name)"
                  "VALUES (:id, :statium_id, :history, :color, :created_at, :city_name)");

    query.bindValue(":statium_id", QVariant(item.getStadium()->getId()));
    query.bindValue(":history", QVariant(item.getHistory()));
    query.bindValue(":color", QVariant(item.getColor()));
    query.bindValue(":created_at", QVariant(item.getCreatedAt()));
    query.bindValue(":city_name", QVariant(item.getCityName()));

    query.exec();

    conn_.close();

    return this->getById(item.getId());
}

bool ClubsRepository::remove(const Club &item) {
    return false;
}

bool ClubsRepository::removeById(const int &id) {
    return false;
}

std::shared_ptr<Club> ClubsRepository::getById(const int &id) {

    conn_.open();

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

    return nullptr;

}

std::shared_ptr<Club> ClubsRepository::getByProperty(const QString &propertyName) {
    return nullptr;
}

std::shared_ptr<QVector<Club>> ClubsRepository::getAll() { return nullptr;}

