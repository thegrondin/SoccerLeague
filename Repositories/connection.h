#ifndef CONNECTION_H
#define CONNECTION_H

#include <QString>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <memory>

namespace SoccerLeague { namespace Models {

class Connection
{
private:
    QSqlDatabase database;
    QString driver_;
    QString path_;
public:
    Connection(const QString&, const QString&);
    void recreate() {
        const QString Driver(driver_);

        if (!QSqlDatabase::isDriverAvailable(Driver)) {
            throw QSqlError::ConnectionError;
        }

         database.setDatabaseName(path_);
    }
    void open();
    void close();
    QSqlDatabase get();
};
}}
#endif // CONNECTION_H
