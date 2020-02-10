#ifndef PLAYERJOURNEYREPOSITORY_H
#define PLAYERJOURNEYREPOSITORY_H

#include "irepository.h"
#include "Models/playerjourney.h"
#include <QString>
#include <QVariant>
#include "connection.h"

using namespace SoccerLeague::Models;

namespace SoccerLeague { namespace Repositories {

class PlayerJourneyRepository : public IRepository<PlayerJourney>
{
private:
    Connection &conn_;
public:
    PlayerJourneyRepository(Connection& conn) : conn_(conn) {}
    ~PlayerJourneyRepository() {}
    std::shared_ptr<PlayerJourney> update(const PlayerJourney& item) override;
    std::shared_ptr<PlayerJourney> add(const PlayerJourney& item) override;
    bool remove(const PlayerJourney& item) override;
    bool removeById(const int& id) override;
    std::shared_ptr<PlayerJourney> getById(const int& id) override;
    std::shared_ptr<PlayerJourney> getByProperty(const QString& propertyName) override;
    std::shared_ptr<QVector<PlayerJourney>> getAll() override;
    std::shared_ptr<QVector<std::shared_ptr<PlayerJourney>>> getAll(const std::unordered_map<QString, QString> &filters) override;
};

}}
#endif // PLAYERJOURNEYREPOSITORY_H
