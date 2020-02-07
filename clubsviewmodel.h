#ifndef CLUBVIEWMODEL_H
#define CLUBVIEWMODEL_H

#include <QObject>
#include "clubview.h"
#include <QVector>

class ClubsViewModel: public QObject
{
    Q_OBJECT
private:
    ClubView clubView_;
    QVector<ClubView> clubs_;
    //Q_PROPERTY(QVector<ClubView> clubs READ getClubs WRITE addClub NOTIFY clubsChangeg)
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged);
public:
    explicit ClubsViewModel(const ClubView& view) {
        clubView_ = view;
    }
    virtual ~ClubsViewModel() {}
    QString getName() {
        return clubView_.getName();
    }
    QVector<ClubView> getClubs() {
        return clubs_;
    }
public slots:
    void setName(QString& arg) {
        if (clubView_.getName() != arg) {
            clubView_.setName(arg);
            nameChanged(arg);
        }
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
