#include "coachservice.h"

using namespace SoccerLeague::Models;
using namespace SoccerLeague::Repositories;
using namespace SoccerLeague::Services;

std::shared_ptr<Coach> CoachService::getCoach(const int& id) {

    std::shared_ptr<Coach> coach = coachRepository_.getById(id);


    auto filter = std::unordered_map<QString, QString> {
        std::make_pair("coach_id", QString::number(id))
    };

    coach->setTitles(titleRepository_.getAll(filter));

    coach->setLeague(leagueRepository_.getById(coach->getLeague()->getId()));

    return coach;
}

std::shared_ptr<QVector<std::shared_ptr<Coach>>> CoachService::getCoaches() {

    return coachRepository_.getAll(std::unordered_map<QString, QString>());

}

void CoachService::save(const Coach& coach) {

    coachRepository_.add(coach);
}

bool CoachService::remove(const int& id) {
    coachRepository_.removeById(id);

    return true;
}
