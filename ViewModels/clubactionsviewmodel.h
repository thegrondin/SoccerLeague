#ifndef CLUBACTIONSVIEWMODEL_H
#define CLUBACTIONSVIEWMODEL_H


#include "../Services/clubservice.h"
#include "../Services/stadiumservice.h"
#include <memory>
#include <QList>
#include <QComboBox>

using namespace SoccerLeague::Services;

namespace SoccerLeague { namespace ViewModels {


class StadeComboBoxModel : public QObject {
    Q_OBJECT
public:
    int id_;
    QString name_;
    StadeComboBoxModel(const int& id, const QString& name) : id_(id), name_(name) {}

    int getId () {return id_;}
    QString getName() {return name_;}
private:
    Q_PROPERTY(int id READ getId);
    Q_PROPERTY(QString name READ getName);

};

class ClubActionsViewModel : public QObject
{
    Q_OBJECT
private:

    ClubService clubService_;
    StadiumService stadiumService_;

    std::shared_ptr<Club> club_;
    std::shared_ptr<QVector<std::shared_ptr<Stadium>>> stadiums_;

    Q_PROPERTY(Club* club READ getClub);
    Q_PROPERTY(QList<Stadium*> stades READ getStades);


signals:
    void clubSavedEvent();

public:
    ClubActionsViewModel(const ClubService& clubService,
                         const StadiumService& stadiumService) :
        clubService_(clubService),
        stadiumService_(stadiumService)
    {
        club_ = std::make_shared<Club>();
        stadiums_ = stadiumService_.getStadiums();
    }


    Club* getClub() {
        return club_.get();
    }

     QList<Stadium*> getStades() {

        QList<Stadium*> datalist;

        auto pStadiums = stadiums_.get();

        for (auto it = pStadiums->begin(); it != pStadiums->end(); ++it) {
            datalist.append(it->get());
        }

        return datalist;
    }

    Q_INVOKABLE void saveClub() {
        clubService_.save(*club_);
        emit clubSavedEvent();
    }

    Q_INVOKABLE void clear() {
        club_ = std::make_shared<Club>();
    }

    Q_INVOKABLE void setLeague(const int& id) {
        auto league = std::make_shared<League>();
        league->setId(id);
        club_->setLeague(league);
    }

     Q_INVOKABLE void selectStadium(Stadium* selectedStadium) {

        club_->setStadium(std::make_shared<Stadium>(Stadium(selectedStadium->getId())));
     }
};

}}

#endif // CLUBACTIONSVIEWMODEL_H
