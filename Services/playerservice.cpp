#include "playerservice.h"
#include <QDebug>

using namespace SoccerLeague::Services;


std::shared_ptr<Player> PlayerService::getPlayer(const int & id) {

    qDebug() << "0";

    std::shared_ptr<Player> player = playerRepository_.getById(id);

    qDebug() << "1";

    player->setClub(clubRepository_.getById(player->getClub()->getId()));

    qDebug() << "2";

    auto journeys = playerJourneyRepository_.getAll(
                std::unordered_map<QString, QString> {
                    std::make_pair("player_id", QString::number(player->getId()))
                });
    player->setJourney(journeys);

    qDebug() << "3";

    return player;
}

std::shared_ptr<QVector<std::shared_ptr<Player>>> PlayerService::getPlayers() {
return nullptr;
}
