#ifndef STADIUMREPOSITORY_H
#define STADIUMREPOSITORY_H

#include "irepository.h"
#include "../Models/stadium.h"
#include "connection.h"
#include <QVariant>

using namespace SoccerLeague::Models;

namespace SoccerLeague { namespace Repositories {

class StadiumRepository : public IRepository<Stadium>
{
private:
    Connection& conn_;
public:
    StadiumRepository(Connection& conn) : conn_(conn) {};
    ~StadiumRepository() {}
    std::shared_ptr<Stadium> update(const Stadium& item) override;
    std::shared_ptr<Stadium> add(const Stadium& item) override;
    bool remove(const Stadium& item) override;
    bool removeById(const int& id) override;
    std::shared_ptr<Stadium> getById(const int& id) override;
    std::shared_ptr<Stadium> getByProperty(const QString& propertyName) override;
    std::shared_ptr<QVector<Stadium>> getAll() override;
    std::shared_ptr<QVector<std::shared_ptr<Stadium>>> getAll(const std::unordered_map<QString, QString>& filters) override {}

};

}}
#endif // STADIUMREPOSITORY_H
