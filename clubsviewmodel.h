#ifndef CLUBVIEWMODEL_H
#define CLUBVIEWMODEL_H

#include <QObject>
#include "Models/club.h"
#include <QVector>

using namespace SoccerLeague::Models;

class ClubsViewModel: public QObject
{
    Q_OBJECT
private:
    Club clubView_;
    QVector<Club> clubs_;
    //Q_PROPERTY(QVector<ClubView> clubs READ getClubs WRITE addClub NOTIFY clubsChangeg)
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged);
public:
    explicit ClubsViewModel(const Club& view) {
        clubView_ = view;
    }
    virtual ~ClubsViewModel() {}
    QString getName() {
        return "";
        //return clubView_.getName();
    }
    QVector<Club> getClubs() {
        return clubs_;
    }
public slots:
    void setName(QString& arg) {
       /* if (clubView_.getName() != arg) {
            clubView_.setName(arg);
            nameChanged(arg);
        }*/
    }
    /*void setClubs(QVector<ClubView> clubs) {
        if (clubs != clubs_) {
            // TODO: optimize this
        }
    }*/
signals:
void nameChanged(QString& arg);

};

#endif // CLUBVIEWMODEL_H
