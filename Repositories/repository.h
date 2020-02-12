#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <QString>
#include <QVector>
#include <QVariant>
#include <memory>
#include <sstream>
#include "connection.h"
#include <QSqlQuery>
#include <functional>

using namespace SoccerLeague::Models;

namespace SoccerLeague { namespace Repositories {

struct WhereQuery {
public:
    QString key;
    QString condition;
    QString value;
};

template <typename T>
class Repository
{
private:
    std::string tableName_;
    Connection conn_;
public:
    Repository(const Connection& conn, const std::string& tablename) : tableName_(tablename), conn_(conn) {}
    void select(QVector<QString> columns, QVector<WhereQuery> where = QVector<WhereQuery>(), QString additionnalParams = "", std::function<void(const QSqlQuery&)> callback = NULL) {

        conn_.open();

        std::stringstream stream;

        stream << "SELECT ";

        for (auto it = columns.begin(); it != columns.end(); ++it) {

            stream << it->toUtf8().constData();

            if (std::next(it) != columns.end()) {
                stream << ", ";
            }
        }

        stream << " FROM " << tableName_;

        if (where.size() > 0) {

            stream << " WHERE ";

            for (auto it = where.begin(); it != where.end(); ++it) {

                stream << it->key.toUtf8().constData() << it->condition.toUtf8().constData() << ":" << it->key.toUtf8().constData();

                if (std::next(it) != where.end()) {
                    stream << " AND ";
                }
            }

        }

        stream << " " << additionnalParams.toUtf8().constData();

        QSqlQuery query;

        auto res = stream.str();

        query.prepare(QString::fromStdString(res));


        for (auto whereItem: where) {
            query.bindValue(":" + whereItem.key, whereItem.value);
        }

        query.exec();

        callback(query);

        conn_.close();

    }
    bool insert(QVector<QString> columns, QVector<QString> values) {

        conn_.open();

        std::stringstream stream;

        stream << "INSERT INTO " << tableName_;

        stream << " (";

        for (auto it = columns.begin(); it != columns.end(); ++it) {

            stream << it->toUtf8().constData();

            if (std::next(it) != columns.end()) {
                stream << ", ";
            }
        }

        stream << ") VALUES (";


        for (auto it = columns.begin(); it != columns.end(); ++it) {

            stream << ":" << it->toUtf8().constData();

            if (std::next(it) != columns.end()) {
                stream << ", ";
            }
        }

        stream << ")";

        auto rawQuery = stream.str();

        QSqlQuery query;
        query.prepare(QString::fromStdString(rawQuery));

        for (int i = 0; i < columns.length(); i++) {
            query.bindValue(":" + columns[i], values[i]);
        }

        bool result = query.exec();

        conn_.close();

        return result;
    }
    bool remove(WhereQuery where) {

        QSqlQuery query;
        query.prepare("DELETE FROM " + QString::fromStdString(tableName_) + " WHERE " + where.key + where.condition + ":condition_value");

        query.bindValue(":condition_value", where.value);

        auto success = query.exec();

        conn_.close();

        return success;


    }
    std::shared_ptr<T> update() {
        return nullptr;
    }
};

}}

#endif // REPOSITORY_H
