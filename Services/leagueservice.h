#ifndef LEAGUESERVICE_H
#define LEAGUESERVICE_H

#include "../Repositories/clubsrepository.h"
#include "../Repositories/coachrepository.h"
#include "../Repositories/leaguerepository.h"

using namespace SoccerLeague::Models;
using namespace SoccerLeague::Repositories;

namespace SoccerLeague { namespace Services {

    class LeagueService
    {
    private:
        ClubsRepository clubRepository_;
        CoachRepository coachRepository_;
        LeagueRepository leagueRepository_;
    public:
        LeagueService(ClubsRepository clubRepository,
                      CoachRepository coachRepository,
                      LeagueRepository leagueRepository):
            clubRepository_(clubRepository),
            coachRepository_(coachRepository),
            leagueRepository_(leagueRepository) {};


        std::shared_ptr<League> getLeague(const int&);
        std::shared_ptr<QVector<std::shared_ptr<League>>> getLeagues();
    };

}}

#endif // LEAGUESERVICE_H
