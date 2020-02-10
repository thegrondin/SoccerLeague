#ifndef PLAYERSERVICE_H
#define PLAYERSERVICE_H

#include "../Repositories/clubsrepository.h"
#include "../Repositories/playerjourneyrepository.h"
#include "../Repositories/playerrepository.h"

using namespace SoccerLeague::Models;
using namespace SoccerLeague::Repositories;

namespace SoccerLeague { namespace Services {

    class PlayerService
    {
    private:
        ClubsRepository clubRepository_;
        PlayerJourneyRepository playerJourneyRepository_;
        PlayerRepository playerRepository_;
    public:
        PlayerService(ClubsRepository clubRepository,
                      PlayerJourneyRepository playerJourneyRepository,
                      PlayerRepository playerRepository):
            clubRepository_(clubRepository),
            playerJourneyRepository_(playerJourneyRepository),
            playerRepository_(playerRepository) {};


        std::shared_ptr<Player> getPlayer(const int&);
        std::shared_ptr<QVector<std::shared_ptr<Player>>> getPlayers();
    };

}}
#endif // PLAYERSERVICE_H
