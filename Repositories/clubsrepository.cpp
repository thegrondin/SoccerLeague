#include "clubsrepository.h"

/*ClubsRepository::ClubsRepository()
{

}

ClubsRepository::~ClubsRepository() {

}*/

/**

    /*QSqlQuery testquery;

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

ClubView ClubsRepository::update(const ClubView &item){
    return ClubView();
}

ClubView ClubsRepository::add(const ClubView &item) {

    QSqlQuery query;
    query.prepare("INSERT INTO Clubs (id, club_effective_id, stadium_id, club_staff_id, history, color, created_at, city_name)"
                  "VALUES (:id, :club_effective_id, :statium_id, :club_staff_id, :history, :color, :created_at, :city_name)");

    //query.bindValue(":id", item.)
    // ...
    return ClubView();
}

bool ClubsRepository::remove(const ClubView &item) {
    return false;
}

bool ClubsRepository::removeById(const int &id) {
    return false;
}

ClubView ClubsRepository::getById(const int &id) {
    return ClubView();
}

ClubView ClubsRepository::getByProperty(const QString &propertyName) {
    return ClubView();
}

