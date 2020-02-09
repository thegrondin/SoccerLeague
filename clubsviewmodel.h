#ifndef CLUBVIEWMODEL_H
#define CLUBVIEWMODEL_H

#include <QObject>
#include "Models/club.h"
#include <QVector>
#include "Repositories/clubsrepository.h"
#include "Repositories/stadiumrepository.h"
#include "Services/clubservice.h"
#include "memory"
#include <QMessageBox>
using namespace SoccerLeague::Models;
using namespace SoccerLeague::Repositories;
using namespace SoccerLeague::Services;

class ClubsViewModel: public QObject
{
    Q_OBJECT
private:
    std::shared_ptr<Club> clubView_;
    //QVector<Club> clubs_;
    //Q_PROPERTY(QVector<ClubView> clubs READ getClubs WRITE addClub NOTIFY clubsChangeg)
    //Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged);
   // Q_PROPERTY(QString history READ clubView.getHistory())
    Q_PROPERTY(Club* club READ getClub)
public:
    explicit ClubsViewModel(const Club& view) {
        Connection conn("QSQLITE", "C:\\Users\\tomto\\Documents\\SoccerLeague\\soccerleague.db");
        ClubsRepository repo1(conn);
        StadiumRepository repo2(conn);

        ClubService service(repo1, repo2);
       clubView_ = service.getClub(1);
    }
    virtual ~ClubsViewModel() {}
    Club* getClub() {
        return clubView_.get();
    }

    Q_INVOKABLE void executeBtn() // clear command
       {


            QMessageBox msgBox;
           msgBox.setText(clubView_->getStadium()->getAddress());
           msgBox.exec();
       }
    //QString getName() {
   //     return "";
        //return clubView_.getName();
    //}
    //QVector<Club> getClubs() {
    //    return clubs_;
    //}
//public slots:
   // void setName(QString& arg) {
       /* if (clubView_.getName() != arg) {
            clubView_.setName(arg);
            nameChanged(arg);
        }*/
    //}
    /*void setClubs(QVector<ClubView> clubs) {
        if (clubs != clubs_) {
            // TODO: optimize this
        }
    }*/
//signals:
//void nameChanged(QString& arg);

};

#endif // CLUBVIEWMODEL_H
