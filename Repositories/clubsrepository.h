#ifndef CLUBSREPOSITORY_H
#define CLUBSREPOSITORY_H

#include "irepository.h"
#include "clubview.h"

class ClubsRepository : public IRepository<ClubView>
{
public:
    ClubsRepository();
    ~ClubsRepository();
    ClubView update(const ClubView& item) override;
    ClubView add(const ClubView& item) override;
    bool remove(const ClubView& item) override;
    bool removeById(const int& id) override;
    ClubView getById(const int& id) override;
    ClubView getByProperty(const QString& propertyName) override;
};

#endif // CLUBSREPOSITORY_H
