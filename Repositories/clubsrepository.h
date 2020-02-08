#ifndef CLUBSREPOSITORY_H
#define CLUBSREPOSITORY_H

#include "irepository.h"
#include "Models/club.h"

using namespace SoccerLeague::Models;

class ClubsRepository : public IRepository<Club>
{
public:
    ClubsRepository();
    ~ClubsRepository();
    Club update(const Club& item) override;
    Club add(const Club& item) override;
    bool remove(const Club& item) override;
    bool removeById(const int& id) override;
    Club getById(const int& id) override;
    Club getByProperty(const QString& propertyName) override;
};

#endif // CLUBSREPOSITORY_H
