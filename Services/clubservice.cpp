#include "clubservice.h"

using namespace SoccerLeague::Repositories;
using namespace SoccerLeague::Services;
using namespace SoccerLeague::Models;


std::shared_ptr<Club> ClubService::getClub(const int& id) {

    std::shared_ptr<Club> club = clubRepository_.getById(id);

    auto filter = std::unordered_map<QString, QString> {
        std::make_pair("club_id", QString::number(club->getId()))
    };

    club->setClubEffective(playerRepository_.getAll(filter));

    club->setStadium(stadiumRepository_.getById(club->getStadium()->getId()));

    return club;
}

std::shared_ptr<QVector<std::shared_ptr<Club>>> ClubService::getClubs() {

    return clubRepository_.getAll(std::unordered_map<QString, QString>());
}

void ClubService::save(const Club& club) {

    clubRepository_.add(club);

}

bool ClubService::remove(const int& id) {

    playerRepository_.removeWhere(std::make_pair("club_id", QString::number(id)));

    return clubRepository_.removeById(id);
}
