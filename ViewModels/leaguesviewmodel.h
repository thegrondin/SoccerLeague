#ifndef LEAGUESVIEWMODEL_H
#define LEAGUESVIEWMODEL_H

#include "../Services/leagueservice.h"
#include <memory>
#include <QDebug>
#include <QList>
#include <QObject>
#include <QVariantList>
#include <QAbstractListModel>


using namespace SoccerLeague::Services;

class league_list_model : public QObject  {
    Q_OBJECT
public:
    int getId() {return id_;}
    QString getName() {return name_;}
    void setId(const int& id) {id_ = id;}
    void setName(const QString& name) {name_ = name;}
    league_list_model(const int& id, const QString& name) : id_(id), name_(name) {}
private:

    Q_PROPERTY(int id READ getId)
    Q_PROPERTY(QString name READ getName)


    int id_;
    QString name_;
};


class ClubListModel : public QObject  {
    Q_OBJECT
public:
    int getId() {return id_;}
    QString getCityName() {return cityname_;}
    void setId(const int& id) {id_ = id;}
    void setCityName(const QString& cityname) {cityname_ = cityname;}
    ClubListModel(const int& id, const QString& cityname) : id_(id), cityname_(cityname) {}
private:

    Q_PROPERTY(int id READ getId)
    Q_PROPERTY(QString cityName READ getCityName)

    int id_;
    QString cityname_;
};

class LeaguesViewModel : public QObject
{
    Q_OBJECT
private:
    LeagueService leagueService_;

    std::shared_ptr<League> currentLeague_;
    std::shared_ptr<QVector<std::shared_ptr<League>>> leagues_;

    Q_PROPERTY(QList<league_list_model*> leagues READ getLeagues);
    Q_PROPERTY(QList<ClubListModel*> clubs READ getClubs);

    Q_PROPERTY(QString clubAmount READ getClubAmount);
    Q_PROPERTY(QString leagueName READ getLeagueName);
public:
    LeaguesViewModel(const LeagueService& leagueService) :
        leagueService_(leagueService) {

        leagues_ = leagueService_.getLeagues();
    }

    QList<league_list_model*> getLeagues() {

        QList<league_list_model*> datalist;

        for (auto league : *leagues_ ) {
            datalist.append(new league_list_model(league->getId(), league->getName()));
        }

        return datalist;
    }

    QList<ClubListModel*> getClubs() {

        QList<ClubListModel*> datalist;

        for (auto club : *currentLeague_->getClubs() ) {
            datalist.append(new ClubListModel(club->getId(), club->getCityName()));
        }

        return datalist;
    }

    QString getClubAmount() {

        return QString::number(currentLeague_->getClubs()->length());
    }

    QString getLeagueName() {
        return currentLeague_->getName();
    }

    Q_INVOKABLE void selectLeague(const int& id) {
        currentLeague_ = leagueService_.getLeague(id);
    }
};

#endif // LEAGUESVIEWMODEL_H
