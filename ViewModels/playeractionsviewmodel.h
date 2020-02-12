#ifndef PLAYERACTIONSVIEWMODEL_H
#define PLAYERACTIONSVIEWMODEL_H


#include "../Services/playerservice.h"
#include <memory>
#include <QList>
#include <QComboBox>

using namespace SoccerLeague::Services;

namespace SoccerLeague { namespace ViewModels {


class PlayerActionsViewModel : public QObject
{
    Q_OBJECT
private:

    PlayerService playerService_;

    std::shared_ptr<Player> player_;

    Q_PROPERTY(Player* player READ getPlayer);

signals:
    void playersUpdatedEvent();

public slots:
    void setClub(const int& id) {
        auto club = std::make_shared<Club>();
        club->setId(id);
        player_->setClub(club);
    }
public:
    PlayerActionsViewModel(const PlayerService& playerService) :
        playerService_(playerService)
    {
        player_ = std::make_shared<Player>();
    }


    Player* getPlayer() {
        return player_.get();
    }


     Q_INVOKABLE void deletePlayer(const int& id) {
        playerService_.remove(id);
        emit playersUpdatedEvent();
     }

    Q_INVOKABLE void savePlayer() {
        playerService_.save(*player_);
        emit playersUpdatedEvent();
    }

    Q_INVOKABLE void clear() {
        player_ = std::make_shared<Player>();
    }
};

}}
#endif // PLAYERACTIONSVIEWMODEL_H
