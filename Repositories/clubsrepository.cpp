#include "clubsrepository.h"

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

Club ClubsRepository::update(const Club &item){
    return Club();
}

Club ClubsRepository::add(const Club &item) {

    QSqlQuery query;
    query.prepare("INSERT INTO Clubs (id, club_members_id, stadium_id, club_staff_id, history, color, created_at, city_name)"
                  "VALUES (:id, :club_effective_id, :statium_id, :club_staff_id, :history, :color, :created_at, :city_name)");

    //query.bindValue(":id", item.)
    // ...
    return Club();
}

bool ClubsRepository::remove(const Club &item) {
    return false;
}

bool ClubsRepository::removeById(const int &id) {
    return false;
}

Club ClubsRepository::getById(const int &id) {
    return Club();
}

Club ClubsRepository::getByProperty(const QString &propertyName) {
    return Club();
}

