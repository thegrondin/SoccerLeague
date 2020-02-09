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
    std::shared_ptr<QSqlDatabase> database;
public:
    Connection(const QString&, const QString&);
    void open();
    void close();
    std::shared_ptr<QSqlDatabase> get();
};
}}
#endif // CONNECTION_H
