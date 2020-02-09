#ifndef IREPOSITORY_H
#define IREPOSITORY_H

#include <QString>
#include <QSqlQuery>
#include <memory>
#include <QVector>

namespace SoccerLeague { namespace Repositories {

template<typename T>
class IRepository
{
public:
    virtual ~IRepository() {}
    virtual std::shared_ptr<T> update(const T& item) = 0;
    virtual std::shared_ptr<T> add(const T& item) = 0;
    virtual bool remove(const T& item) = 0;
    virtual bool removeById(const int& id) = 0;
    virtual std::shared_ptr<T> getById(const int& id) = 0;
    virtual std::shared_ptr<T> getByProperty(const QString& propertyName) = 0;
    virtual std::shared_ptr<QVector<T>> getAll() = 0;
};

}}

#endif // IREPOSITORY_H
