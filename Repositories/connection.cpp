#include "connection.h"
#include <QDebug>

using namespace SoccerLeague::Models;

Connection::Connection(const QString& driver, const QString& path)
{


    const QString Driver(driver);

    if (!QSqlDatabase::isDriverAvailable(Driver)) {
        throw QSqlError::ConnectionError;
    }

    database = QSqlDatabase::addDatabase(Driver);
    driver_ = Driver;
    path_ = path;
    database.setDatabaseName(path);
}

void Connection::open() {

    qDebug() << "OPEN";

    //database.close();
    //QSqlDatabase::removeDatabase( "qt_sql_default_connection");
      //recreate();
    database.open();
}

void Connection::close() {

    qDebug() << "CLOSE";


    database.close();
    //QSqlDatabase::removeDatabase("qt_sql_default_connection");

}

QSqlDatabase Connection::get() {
    return database;
}
