#ifndef PLAYERVIEWMODEL_H
#define PLAYERVIEWMODEL_H

#include "../Services/playerservice.h"
#include <memory>

using namespace SoccerLeague::Services;

namespace SoccerLeague { namespace ViewModels {

    class PlayerViewModel : public QObject
    {
        Q_OBJECT

    private:
        PlayerService playerService_;
        std::shared_ptr<Player> currentPlayer_;
        Q_PROPERTY(Player* player READ getPlayer)
    public:

        PlayerViewModel(const PlayerService& playerService) :
            playerService_(playerService)
        {
            currentPlayer_ = playerService_.getPlayer(1);
           // auto test = playerService_.getPlayer(1);
        }

        Player* getPlayer() {
            return currentPlayer_.get();
        }
    };

}}

#endif // PLAYERVIEWMODEL_H
