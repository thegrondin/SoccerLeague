#include "connection.h"

using namespace SoccerLeague::Models;

Connection::Connection(const QString& driver, const QString& path)
{
    const QString Driver(driver);

    if (!QSqlDatabase::isDriverAvailable(Driver)) {
        throw QSqlError::ConnectionError;
    }

    database = std::make_shared<QSqlDatabase>(QSqlDatabase::addDatabase(Driver));
    database->setDatabaseName(path);
}

void Connection::open() {
    database->open();
}

void Connection::close() {
    database->close();
}

std::shared_ptr<QSqlDatabase> Connection::get() {
    return database;
}
