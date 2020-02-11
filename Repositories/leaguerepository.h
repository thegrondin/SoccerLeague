#ifndef LEAGUEREPOSITORY_H
#define LEAGUEREPOSITORY_H

#include "irepository.h"
#include "../Models/league.h"
#include "connection.h"
#include <QVariant>

using namespace SoccerLeague::Models;

namespace SoccerLeague { namespace Repositories {

class LeagueRepository : public IRepository<League>
{
    private:
        Connection& conn_;
    public:
        LeagueRepository(Connection& conn) : conn_(conn) {};
        ~LeagueRepository() {}
        std::shared_ptr<League> update(const League& item) override;
        std::shared_ptr<League> add(const League& item) override;
        bool remove(const League& item) override;
        bool removeById(const int& id) override;
        std::shared_ptr<League> getById(const int& id) override;
        std::shared_ptr<League> getByProperty(const QString& propertyName) override;
        std::shared_ptr<QVector<League>> getAll() override;
        std::shared_ptr<QVector<std::shared_ptr<League>>> getAll(const std::unordered_map<QString, QString> &filters) override;

    };
}}
#endif // LEAGUEREPOSITORY_H
