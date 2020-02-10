#include "querybuilder.h"

using namespace SoccerLeague::Database;

QString QueryBuilder::createSelect(const basic_query_t& query) {

    std::stringstream rawQuery;
    rawQuery << "SELECT";

    for (auto it = query.columns.begin(); it != query.columns.end(); ++it) {
        rawQuery << " " << it->toUtf8().constData();

        if (std::next(it) != query.columns.end()) {
            rawQuery << ",";
        }
    }

    rawQuery << " FROM " << query.tablename.toUtf8().constData() << " ";

    if (query.filters.size() != 0) {
        rawQuery << "WHERE ";
        for (auto it = query.filters.begin(); it != query.filters.end(); ++it) {
            rawQuery << it->first.toUtf8().constData() << "=:" << it->first.toUtf8().constData();

            if (std::next(it) != query.filters.end()) {
                rawQuery << ", ";
            }
        }
    }

    rawQuery << " " << query.additional_args.toUtf8().constData();

    return QString::fromStdString(rawQuery.str());
}
