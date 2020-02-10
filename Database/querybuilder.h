#ifndef QUERYBUILDER_H
#define QUERYBUILDER_H

#include <QString>
#include <QVector>
#include <unordered_map>
#include <sstream>

namespace SoccerLeague { namespace Database  {

    struct basic_query_t {
        QString tablename;
        QVector<QString> columns;
        std::unordered_map<QString, QString> filters;
        QString additional_args;
    };

    class QueryBuilder
    {
    public:
        static QString createSelect(const basic_query_t&);
    };

}}
#endif // QUERYBUILDER_H
