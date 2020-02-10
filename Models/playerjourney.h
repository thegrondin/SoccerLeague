#ifndef PLAYERJOURNEY_H
#define PLAYERJOURNEY_H

#include <memory>
#include "ModelsHeader.h"
#include <QString>
#include <QDateTime>
#include "basemodel.h"

namespace SoccerLeague { namespace Models {

class Club;
class Player;
class PlayerJourney : public QObject
{
    Q_OBJECT
private:
    int id_;
    std::shared_ptr<Club> club_;
    std::shared_ptr<Player> player_;
    QString staticClubName_;
    QDateTime startDate_;
    QDateTime endDate_;
private:
    Q_PROPERTY(Club* club READ getClub);
    Q_PROPERTY(QString staticClubName READ getStaticClubName WRITE setStaticClubName NOTIFY staticClubNameChanged);
    Q_PROPERTY(QDateTime startDate READ getStartDate WRITE setStartDate NOTIFY startDateChanged);
    Q_PROPERTY(QDateTime endDate READ getEndDate WRITE setEndDate NOTIFY endDateChanged);

signals:
    void staticClubNameChanged(const QString& staticName);
    void startDateChanged(const QDateTime& startDate);
    void endDateChanged(const QDateTime& endDate);

public:
    PlayerJourney(const int& id,
                  const QString& staticClubName,
                  const QDateTime& startDate,
                  const QDateTime& endDate):
        id_(id),
        staticClubName_(staticClubName),
        startDate_(startDate),
        endDate_(endDate) {}

    PlayerJourney() :
        id_(0),
        staticClubName_(QString()),
        startDate_(QDateTime()),
        endDate_(QDateTime()) {}

public:
    QString getStaticClubName() {return staticClubName_;}
    QDateTime getStartDate() {return startDate_;}
    QDateTime getEndDate() {return endDate_;}
    Club* getClub() {return club_.get();}
    Player* getPlayer() {return player_.get();}
    int getId() const { return id_; }

public:
    void setClub(const std::shared_ptr<Club>& club) {
        club_ = club;
    }

    void setPlayer(const std::shared_ptr<Player>& player) {
        player_ = player;
    }

    void setId(const int& id)  {
        id_ = id;
    }

public slots:
    void setStaticClubName(const QString staticClubName) {
        if (getStaticClubName() != staticClubName) {
            staticClubName_ = staticClubName;
            staticClubNameChanged(staticClubName);
        }
    }

    void setStartDate(const QDateTime startDate) {
        if (getStartDate() != startDate) {
            startDate_ = startDate;
            startDateChanged(startDate);
        }
    }

    void setEndDate(const QDateTime endDate) {
        if (getEndDate() != endDate) {
            endDate_ = endDate;
            endDateChanged(endDate);
        }
    }
};

}}

#endif // PLAYERJOURNEY_H
