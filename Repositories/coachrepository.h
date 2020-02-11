#ifndef COACHREPOSITORY_H
#define COACHREPOSITORY_H

#include "irepository.h"
#include "Models/coach.h"
#include <QString>
#include <QVariant>
#include "connection.h"

using namespace SoccerLeague::Models;

namespace SoccerLeague { namespace Repositories {

class CoachRepository : public IRepository<Coach>
{
private:
    Connection &conn_;
public:
    CoachRepository(Connection& conn) : conn_(conn) {}
    ~CoachRepository() {}
    std::shared_ptr<Coach> update(const Coach& item) override;
    std::shared_ptr<Coach> add(const Coach& item) override;
    bool remove(const Coach& item) override;
    bool removeById(const int& id) override;
    std::shared_ptr<Coach> getById(const int& id) override;
    std::shared_ptr<Coach> getByProperty(const QString& propertyName) override;
    std::shared_ptr<QVector<Coach>> getAll() override;
    std::shared_ptr<QVector<std::shared_ptr<Coach>>> getAll(const std::unordered_map<QString, QString> &filters) override;
};

}}

#endif // COACHREPOSITORY_H
