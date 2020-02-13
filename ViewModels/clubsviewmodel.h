#ifndef CLUBSVIEWMODEL_H
#define CLUBSVIEWMODEL_H

#include "../Services/clubservice.h"
#include <memory>
#include <QStringListModel>

using namespace SoccerLeague::Services;

namespace SoccerLeague { namespace ViewModels {


    // Transferer PlayerList to playerViewModel
    class PlayerListModel : public QObject  {
        Q_OBJECT
    public:
        int getId() {return id_;}
        QString getFirstname() {return firstname_;}
        QString getLastname() {return lastname_;}

        void setId(const int& id) {id_ = id;}
        void setFirstname(const QString& firstname) {firstname_ = firstname;}
        void setLastname(const QString& lastname) {lastname_ = lastname;}
        PlayerListModel(const int& id, const QString& firstname, const QString& lastname) : id_(id), firstname_(firstname), lastname_(lastname) {}
    private:

        Q_PROPERTY(int id READ getId)
        Q_PROPERTY(QString firstname READ getFirstname)
        Q_PROPERTY(QString lastname READ getLastname)

        int id_;
        QString firstname_;
        QString lastname_;

    };


    class ClubsViewModel : public QObject
    {
        Q_OBJECT

    private:
        ClubService clubsService_;

        std::shared_ptr<QVector<std::shared_ptr<Club>>> clubs_;
        std::shared_ptr<Club> currentClub_;

        Q_PROPERTY(QStringListModel* clubs READ getClubs);
        Q_PROPERTY(Club* club READ getClub NOTIFY clubChanged);
        Q_PROPERTY(QList<PlayerListModel*> players READ getPlayers);
        Q_PROPERTY(QList<Title*> titles READ getTitles NOTIFY clubChanged);

    signals:
        void clubSelectedEvent(const int& id);
        void clubChanged();
    public slots:
        void refreshCurrent() {
            currentClub_ = clubsService_.getClub(currentClub_->getId());
            clubChanged();
        }

    public:

        ClubsViewModel(const ClubService& clubService) :
            clubsService_(clubService)
        {
            clubs_ = clubsService_.getClubs();
        }

        QStringListModel* getClubs() {
            QStringListModel *model = new QStringListModel();
            QStringList strClubList;

            for (auto club : *clubs_) {
                strClubList << "Club " + QString::number(club->getId()) + " - " + club->getCityName();
            }

            model->setStringList(strClubList);

            return model;
        }

        QList<PlayerListModel*> getPlayers() {

            QList<PlayerListModel*> datalist;

            for (auto player : *currentClub_->getClubEffective() ) {
                datalist.append(new PlayerListModel(player->getId(), player->getFirstname(), player->getLastname()));
            }

            return datalist;
        }

        QList<Title*> getTitles() {
            QList<Title*> datalist;

            for (auto title : *currentClub_->getTitles()) {
                datalist.append(title.get());
            }

            return datalist;
        }

        Club* getClub() {
            return currentClub_.get();
        }

        Q_INVOKABLE void selectClub(const int& id) {
            currentClub_ = clubsService_.getClub(id);
            emit clubSelectedEvent(id);
        }





    };

}}

#endif // PLAYERVIEWMODEL_H
