#ifndef COACH_H
#define COACH_H
#include "ModelsHeader.h"
#include <memory>
#include <QString>

namespace SoccerLeague { namespace Models {

class Record;
class League;
class Title;
class Coach : public QObject
{
   Q_OBJECT
private:
    int id_;
    QString firstname_;
    QString lastname_;
    QString graduationLocation_;
    std::shared_ptr<QVector<std::shared_ptr<Title>>> titles_;
    std::shared_ptr<League> league_;

private:
    Q_PROPERTY(QString firstname READ getFirstname WRITE setFirstname NOTIFY firstnameChanged);
    Q_PROPERTY(QString lastname READ getLastname WRITE setLastname NOTIFY lastnameChanged);
    Q_PROPERTY(QString graduationLocation READ getGraduationLocation WRITE setGraduationLocation NOTIFY graduationLocationChanged);

signals:
    void firstnameChanged(const QString& arg);
    void lastnameChanged(const QString& arg);
    void graduationLocationChanged(const QString& arg);

public:
    Coach(const int& id,
          const QString& firstname,
          const QString& lastname,
          const QString& graduationLocation) :
        id_(id),
        firstname_(firstname),
        lastname_(lastname),
        graduationLocation_(graduationLocation) {};

    Coach() :
        id_(0),
        firstname_(""),
        lastname_(""),
        graduationLocation_("") {}

public:
    int getId() {return id_;}
    QString getFirstname() {return firstname_;}
    QString getLastname() {return lastname_;}
    QString getGraduationLocation() {return graduationLocation_;}
    std::shared_ptr<League> getLeague() {return league_;}
    std::shared_ptr<QVector<std::shared_ptr<Title>>> getTitles() {return titles_;}

public:
    void setTitles(const std::shared_ptr<QVector<std::shared_ptr<Title>>>& titles) {
        titles_ = titles;
    }

    void setLeague(const std::shared_ptr<League>& league) {
        league_ = league;
    }

    void setId(const int& id) {
        id_ = id;
    }

public slots:

    void setFirstname(const QString& firstname) {
        if (getFirstname() != firstname) {
            firstname_ = firstname;
            firstnameChanged(firstname);
        }
    }

    void setLastname(const QString& lastname) {
        if (getLastname() != lastname) {
            lastname_ = lastname;
            lastnameChanged(lastname);
        }
    }

    void setGraduationLocation(const QString& graduationLocation) {
        if (getGraduationLocation() != graduationLocation) {
            graduationLocation_ = graduationLocation;
            graduationLocationChanged(graduationLocation);
        }
    }

};

}}
#endif // COACH_H
