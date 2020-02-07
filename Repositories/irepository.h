#ifndef IREPOSITORY_H
#define IREPOSITORY_H

#include <QString>
#include <QSqlQuery>

template<typename T>
class IRepository
{
public:
    virtual ~IRepository();
    virtual T update(const T& item) = 0;
    virtual T add(const T& item) = 0;
    virtual bool remove(const T& item) = 0;
    virtual bool removeById(const int& id) = 0;
    virtual T getById(const int& id) = 0;
    virtual T getByProperty(const QString& propertyName) = 0;
};

#endif // IREPOSITORY_H
