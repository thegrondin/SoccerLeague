#ifndef CLUBSREPOSITORY_H
#define CLUBSREPOSITORY_H

#include "irepository.h"
#include "Models/club.h"
#include <QString>
#include <QVariant>
#include "connection.h"

using namespace SoccerLeague::Models;

namespace SoccerLeague { namespace Repositories {

class ClubsRepository : public IRepository<Club>
{
private:
    Connection &conn_;
public:
    ClubsRepository(Connection& conn) : conn_(conn) {}
    ~ClubsRepository() {}
    std::shared_ptr<Club> update(const Club& item) override;
    std::shared_ptr<Club> add(const Club& item) override;
    bool remove(const Club& item) override;
    bool removeById(const int& id) override;
    std::shared_ptr<Club> getById(const int& id) override;
    std::shared_ptr<Club> getByProperty(const QString& propertyName) override;
    std::shared_ptr<QVector<Club>> getAll() override;
    std::shared_ptr<QVector<std::shared_ptr<Club>>> getAll(const std::unordered_map<QString, QString>& filters) override {}
};

}}

#endif // CLUBSREPOSITORY_H
