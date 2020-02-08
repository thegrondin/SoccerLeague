#ifndef CLUB_H
#define CLUB_H

#include <QString>
#include <QDatetime>
#include <memory>
#include <QVector>

#include "basemodel.h"
#include "stadium.h"
#include "clubstaff.h"

/*
 * query.prepare("INSERT INTO Clubs (id, club_members_id, stadium_id, club_staff_id, history, color, created_at, city_name)"
                  "VALUES (:id, :club_effective_id, :statium_id, :club_staff_id, :history, :color, :created_at, :city_name)");*/

namespace SoccerLeague { namespace Models {

class Player;
class Club : public BaseModel
{
private:
    QVector<std::shared_ptr<Player>> clubEffective_;
    //Stadium stadium_;
    QVector<ClubStaff> clubStaff_;
    QString history_;
    QString color_;
    QDateTime createdAt_;
    QString cityName_;
public:

    Club(const int& id,
         const QVector<std::shared_ptr<Player>>& clubEffective,
         const Stadium& stadium,
         const QVector<ClubStaff>& clubStaff,
         const QString& history,
         const QString& color,
         const QDateTime& createdAt,
         const QString& cityName) :
        BaseModel(id),
        clubEffective_(clubEffective),
        //stadium_(stadium),
        clubStaff_(clubStaff),
        history_(history),
        color_(color),
        createdAt_(createdAt),
        cityName_(cityName) { }

    Club() : BaseModel(0) ,
        clubEffective_(QVector<std::shared_ptr<Player>>()),
       // stadium_(Stadium()),
        clubStaff_(QVector<ClubStaff>()),
        history_(QString()),
        color_(QString()),
        createdAt_(QDateTime()),
        cityName_(QString()) { }


    void setClubEffective(const QVector<std::shared_ptr<Player>>& clubEffective) {
        clubEffective_ = clubEffective;
    }

   /* Stadium getStadium() {
        return stadium_;
    }

    void setStadium(const Stadium& stadium) {
        stadium_ = stadium;
    }*/

    QVector<ClubStaff> getClubStaff() {
        return clubStaff_;
    }

    void setClubStaff(const QVector<ClubStaff>& clubStaff) {
        clubStaff_ = clubStaff;
    }

    QString getHistory() {
        return history_;
    }

    void setHistory(const QString& history) {
        history_ = history;
    }

    QString getColor() {
        return color_;
    }

    void setColor(const QString& color) {
        color_ = color;
    }

    QDateTime getCreatedAt() {
        return createdAt_;
    }

    void setCreatedAt(const QDateTime& createdAt) {
        createdAt_ = createdAt;
    }

    QString getCityName() {
        return cityName_;
    }

    void setCityName(const QString& cityName) {
        cityName_ = cityName;
    }

};

}}

#endif // CLUB_H
