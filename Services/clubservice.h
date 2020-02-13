#ifndef CLUBSERVICE_H
#define CLUBSERVICE_H

#include "../Repositories/clubsrepository.h"
#include "../Repositories/stadiumrepository.h"
#include "../Repositories/playerrepository.h"
#include "../Repositories/titlerepository.h"
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
        PlayerRepository playerRepository_;
        TitleRepository titleRepository_;
    public:
        ClubService(ClubsRepository clubRepository,
                    StadiumRepository stadiumRepository,
                    PlayerRepository playerRepository,
                    TitleRepository titleRepository):
            clubRepository_(clubRepository),
            stadiumRepository_(stadiumRepository),
            playerRepository_(playerRepository),
            titleRepository_(titleRepository) {}

        std::shared_ptr<Club> getClub(const int& );
        std::shared_ptr<QVector<std::shared_ptr<Club>>> getClubs();
        bool remove(const int&);
        void save(const Club& club);
    };
}}


#endif // CLUBSERVICE_H
