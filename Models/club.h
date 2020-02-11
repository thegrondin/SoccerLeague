#ifndef CLUB_H
#define CLUB_H

#include <QString>
#include <QDateTime>
#include <memory>
#include <QVector>

#include "ModelsHeader.h"

#include "basemodel.h"
#include "stadium.h"
#include "clubstaff.h"
#include "title.h"



namespace SoccerLeague { namespace Models {

class Player;
class League;
class Club : public QObject
{
    Q_OBJECT
private:
    int id_;
    std::shared_ptr<QVector<std::shared_ptr<Player>>> clubEffective_;
    std::shared_ptr<Stadium> stadium_;
    std::shared_ptr<League> league_;
    QVector<Staff> clubStaff_;
    QVector<Title> titles_;
    QString history_;
    QString color_;
    QDateTime createdAt_;
    QString cityName_;

    Q_PROPERTY(QString color READ getColor WRITE setColor NOTIFY colorChanged);
    Q_PROPERTY(QDateTime createdAt READ getCreatedAt WRITE setCreatedAt NOTIFY createAtChanged);
    Q_PROPERTY(QString cityName READ getCityName WRITE setCityName NOTIFY cityNameChanged);
    Q_PROPERTY(QString history READ getHistory WRITE setHistory NOTIFY historyChanged);
    Q_PROPERTY(Stadium* stadium READ getStadium);

signals:
    void historyChanged(const QString& arg);
    void colorChanged(const QString& arg);
    void createAtChanged(const QDateTime& arg);
    void cityNameChanged(const QString& arg);

public:

    Club(const int& id,
         const QString& history,
         const QString& color,
         const QDateTime& createdAt,
         const QString& cityName) :
        id_(id),
        history_(history),
        color_(color),
        createdAt_(createdAt),
        cityName_(cityName) { }

    Club() : id_(0),
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

    QDateTime getCreatedAt() const {
        return createdAt_;
    }

    QString getCityName() const {
        return cityName_;
    }

    int getId() const  {
        return id_;
    }
    void setId(const int& id)  {
        id_ = id;
    }

    std::shared_ptr<League> getLeague() const {
        return league_;
    }

    void setLeague(const std::shared_ptr<League>& league) {
        league_ = league;
    }

public slots:

    void setColor(const QString& color) {
        if (getColor() != color) {
             color_ = color;
            colorChanged(color);
        }
    }

    void setHistory(const QString& history) {
        if (getHistory() != history) {
             history_ = history;
            historyChanged(history);
        }

    }

    void setCityName(const QString& cityName) {
        if (getCityName() != cityName) {
             cityName_ = cityName;
            cityNameChanged(cityName);
        }
    }

    void setCreatedAt(const QDateTime& createdAt) {
        if (getCreatedAt() != createdAt) {
             createdAt_ = createdAt;
            createAtChanged(createdAt);
        }
    }

};

}}

#endif // CLUB_H
