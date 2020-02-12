#ifndef TITLEREPOSITORY_H
#define TITLEREPOSITORY_H

#include "irepository.h"
#include "../Models/title.h"
#include "connection.h"
#include <QVariant>

using namespace SoccerLeague::Models;

namespace SoccerLeague { namespace Repositories {

class TitleRepository : public IRepository<Title>
{
private:
    Connection& conn_;
public:
    TitleRepository(Connection& conn) : conn_(conn) {};
    ~TitleRepository() {}
    std::shared_ptr<Title> update(const Title& item) override;
    std::shared_ptr<Title> add(const Title& item) override;
    bool remove(const Title& item) override;
    bool removeById(const int& id) override;
    std::shared_ptr<Title> getById(const int& id) override;
    std::shared_ptr<Title> getByProperty(const QString& propertyName) {};
    std::shared_ptr<QVector<Title>> getAll() override;
    std::shared_ptr<QVector<std::shared_ptr<Title>>> getAll(const std::unordered_map<QString, QString> &filters) override;

};

}}
#endif // TITLEREPOSITORY_H
