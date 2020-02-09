#include "clubservice.h"

using namespace SoccerLeague::Repositories;
using namespace SoccerLeague::Services;
using namespace SoccerLeague::Models;


std::shared_ptr<Club> ClubService::getClub(const int& id) {



    std::shared_ptr<Club> club = clubRepository_.getById(id);

    club->setStadium(stadiumRepository_.getById(club->getStadium()->getId()));

    return club;
}

std::shared_ptr<QVector<Club>> ClubService::getClubs() {
    return nullptr;
}
