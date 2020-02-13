#include "leagueservice.h"


using namespace SoccerLeague::Services;


std::shared_ptr<League> LeagueService::getLeague(const int & id) {

    std::shared_ptr<League> league = leagueRepository_.getById(id);

    auto filter = std::unordered_map<QString, QString> {
        std::make_pair("league_id", QString::number(league->getId()))
    };

    league->setClubs(clubRepository_.getAll(filter));
    league->setCoaches(coachRepository_.getAll(filter));

    return league;
}

std::shared_ptr<QVector<std::shared_ptr<League>>> LeagueService::getLeagues() {

    return leagueRepository_.getAll(std::unordered_map<QString, QString>());
}


