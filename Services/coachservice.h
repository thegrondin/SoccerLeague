#ifndef COACHSERVICE_H
#define COACHSERVICE_H


//std::shared_ptr<QVector<std::shared_ptr<Record>>> titles_;
//std::shared_ptr<League> league_;
#include "../Repositories/leaguerepository.h"
#include "../Repositories/titlerepository.h"
#include "../Repositories/coachrepository.h"


using namespace SoccerLeague::Models;
using namespace SoccerLeague::Repositories;

namespace SoccerLeague { namespace Services {

    class CoachService
    {
    private:
        LeagueRepository leagueRepository_;
        TitleRepository titleRepository_;
        CoachRepository coachRepository_;

    public:
        CoachService(LeagueRepository leagueRepository,
                     TitleRepository titleRepository,
                     CoachRepository coachRepository):
            leagueRepository_(leagueRepository),
            titleRepository_(titleRepository),
            coachRepository_(coachRepository) {}

        std::shared_ptr<Coach> getCoach(const int& );
        std::shared_ptr<QVector<std::shared_ptr<Coach>>> getCoaches();
        bool remove(const int&);
        void save(const Coach& club);
    };
}}

#endif // COACHSERVICE_H
