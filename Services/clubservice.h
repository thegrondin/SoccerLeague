#ifndef CLUBSERVICE_H
#define CLUBSERVICE_H

#include "../Repositories/clubsrepository.h"
#include "../Repositories/stadiumrepository.h"
#include <memory>
#include <QVector>
#include <QString>

using namespace SoccerLeague::Models;
using namespace SoccerLeague::Repositories;

namespace SoccerLeague { namespace Services {

    class ClubService
    {
    private:
        ClubsRepository clubRepository_;
        StadiumRepository stadiumRepository_;
    public:
        ClubService(ClubsRepository clubRepository,
                    StadiumRepository stadiumRepository):
            clubRepository_(clubRepository),
            stadiumRepository_(stadiumRepository) {}

        std::shared_ptr<Club> getClub(const int& );
        std::shared_ptr<QVector<Club>> getClubs();
    };
}}


#endif // CLUBSERVICE_H
