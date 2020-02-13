#include "playerservice.h"
#include <QDebug>

using namespace SoccerLeague::Services;


std::shared_ptr<Player> PlayerService::getPlayer(const int & id) {

    std::shared_ptr<Player> player = playerRepository_.getById(id);
    player->setClub(clubRepository_.getById(player->getClub()->getId()));
    auto journeys = playerJourneyRepository_.getAll(
                std::unordered_map<QString, QString> {
                    std::make_pair("player_id", QString::number(player->getId()))
                });
    player->setJourney(journeys);
    return player;
}

std::shared_ptr<QVector<std::shared_ptr<Player>>> PlayerService::getPlayers() {
return nullptr;
}

std::shared_ptr<QVector<std::shared_ptr<Player>>> PlayerService::getPlayersFromClub(const int& id) {

    auto filter = std::unordered_map<QString, QString> {
        std::make_pair("club_id", QString::number(id))
    };

    return playerRepository_.getAll(filter);
}


bool PlayerService::remove(const int& id) {

    playerJourneyRepository_.removeWhere(std::make_pair("player_id", QString::number(id)));

    return playerRepository_.removeWhere(std::make_pair("id", QString::number(id)));

}

void PlayerService::save(const Player& player) {

    playerRepository_.add(player);
}
