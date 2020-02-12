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

        std::shared_ptr<QVector<std::shared_ptr<Player>>> players_;
        std::shared_ptr<Player> currentPlayer_;
        int currentClubId_;

        Q_PROPERTY(Player* player READ getPlayer NOTIFY playerChanged);
        Q_PROPERTY(QList<Player*> players READ getPlayers NOTIFY playersChanged);
    signals:
        void playerChanged(const int& arg);
        void playersChanged(const int& arg);
    public slots:
        void setPlayersFromClubId(const int& clubId) {
            players_ = playerService_.getPlayersFromClub(clubId);
            playersChanged(clubId);
            currentClubId_ = clubId;
        }

        void refreshPlayers() {
            players_ = playerService_.getPlayersFromClub(currentClubId_);
            playersChanged(currentClubId_);
        }
    public:

        PlayerViewModel(const PlayerService& playerService) :
            playerService_(playerService)
        {
            players_ = std::make_shared<QVector<std::shared_ptr<Player>>>();
            currentPlayer_ = std::make_shared<Player>();

        }

        QList<Player*> getPlayers () {
            QList<Player*> datalist;

            auto pPlayers = players_.get();

            for (auto it = pPlayers->begin(); it != pPlayers->end(); ++it) {
                datalist.append(it->get());
            }

            return datalist;
        }

        Player* getPlayer() {
            return currentPlayer_.get();
        }


        Q_INVOKABLE void selectPlayer(const int& id) {
            currentPlayer_ = playerService_.getPlayer(id);
        }
    };

}}

#endif // PLAYERVIEWMODEL_H
