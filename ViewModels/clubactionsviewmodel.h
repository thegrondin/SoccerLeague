#ifndef CLUBACTIONSVIEWMODEL_H
#define CLUBACTIONSVIEWMODEL_H


#include "../Services/clubservice.h"
#include <memory>
#include <QList>

using namespace SoccerLeague::Services;

namespace SoccerLeague { namespace ViewModels {


class StadeComboBoxModel : QObject {
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
    std::shared_ptr<Club> club_;

    Q_PROPERTY(Club* club READ getClub);
    Q_PROPERTY(QList<StadeComboBoxModel*> stades READ getStades);

signals:
    void clubSavedEvent();

public:
    ClubActionsViewModel(const ClubService& clubService) :
        clubService_(clubService) {
        club_ = std::make_shared<Club>();
    }


    Club* getClub() {
        return club_.get();
    }

    QList<StadeComboBoxModel*> getStades() {

        QList<StadeComboBoxModel*> datalist;

        //for (auto stade : *)
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
};

}}

#endif // CLUBACTIONSVIEWMODEL_H
