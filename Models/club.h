#ifndef CLUB_H
#define CLUB_H

#include <QString>
#include <QDatetime>
#include <memory>
#include <QVector>

#include "ModelsHeader.h"

#include "basemodel.h"
#include "stadium.h"
#include "clubstaff.h"
#include "title.h"


/*
 * query.prepare("INSERT INTO Clubs (id, club_members_id, stadium_id, club_staff_id, history, color, created_at, city_name)"
                  "VALUES (:id, :club_effective_id, :statium_id, :club_staff_id, :history, :color, :created_at, :city_name)");*/

namespace SoccerLeague { namespace Models {


class Club : public BaseModel
{
    Q_OBJECT
private:
    std::shared_ptr<QVector<std::shared_ptr<Player>>> clubEffective_;
    std::shared_ptr<Stadium> stadium_;
    QVector<Staff> clubStaff_;
    QVector<Title> titles_;
    QString history_;
    QString color_;
    QDateTime createdAt_;
    QString cityName_;

    Q_PROPERTY(QString history READ getHistory WRITE setHistory NOTIFY historyChanged);
    Q_PROPERTY(Stadium* stadium READ getStadium);

signals:
    void historyChanged(const QString& arg);
public:

    Club(const int& id,
         const QString& history,
         const QString& color,
         const QDateTime& createdAt,
         const QString& cityName) :
        BaseModel(id),
        history_(history),
        color_(color),
        createdAt_(createdAt),
        cityName_(cityName) { }

    Club() : BaseModel(0),
        history_(QString()),
        color_(QString()),
        createdAt_(QDateTime()),
        cityName_(QString()) { }

    QVector<Title> getTitles() const {
        return titles_;
    }

    void setTitles(const QVector<Title>& titles) {
        titles_ = titles;
    }

    std::shared_ptr<QVector<std::shared_ptr<Player>>> getClubEffective() const  {
        return clubEffective_;
    }

    void setClubEffective(const std::shared_ptr<QVector<std::shared_ptr<Player>>>& clubEffective) {
        clubEffective_ = clubEffective;
    }

    Stadium* getStadium() const {
        return stadium_.get();
    }

    void setStadium(const std::shared_ptr<Stadium>& stadium) {
        stadium_ = stadium;
    }

    QVector<Staff> getClubStaff() const {
        return clubStaff_;
    }

    void setClubStaff(const QVector<Staff>& clubStaff) {
        clubStaff_ = clubStaff;
    }

    QString getHistory() const {
        return history_;
    }


    QString getColor() const {
        return color_;
    }

    void setColor(const QString& color) {
        color_ = color;
    }

    QDateTime getCreatedAt() const {
        return createdAt_;
    }

    void setCreatedAt(const QDateTime& createdAt) {
        createdAt_ = createdAt;
    }

    QString getCityName() const {
        return cityName_;
    }

    void setCityName(const QString& cityName) {
        cityName_ = cityName;
    }

public slots:
    void setHistory(const QString& history) {
        if (getHistory() != history) {
             history_ = history;
            historyChanged(history);
        }

    }

};

}}

#endif // CLUB_H
