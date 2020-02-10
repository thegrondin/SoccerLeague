#ifndef PLAYERREPOSITORY_H
#define PLAYERREPOSITORY_H

#include "irepository.h"
#include "Models/player.h"
#include <QString>
#include <QVariant>
#include "connection.h"

using namespace SoccerLeague::Models;

namespace SoccerLeague { namespace Repositories {

class PlayerRepository : public IRepository<Player>
{
private:
    Connection &conn_;
public:
    PlayerRepository(Connection& conn) : conn_(conn) {}
    ~PlayerRepository() {}
    std::shared_ptr<Player> update(const Player& item) override;
    std::shared_ptr<Player> add(const Player& item) override;
    bool remove(const Player& item) override;
    bool removeById(const int& id) override;
    std::shared_ptr<Player> getById(const int& id) override;
    std::shared_ptr<Player> getByProperty(const QString& propertyName) override;
    std::shared_ptr<QVector<Player>> getAll() override;
    std::shared_ptr<QVector<std::shared_ptr<Player>>> getAll(const std::unordered_map<QString, QString> &filters) override;
};

}}
#endif // PLAYERJOURNEYREPOSITORY_H
