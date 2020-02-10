#ifndef PLAYER_H
#define PLAYER_H

#include <memory>

#include "basemodel.h"
#include <QString>
#include <QFloat16>
#include <QVector>
#include "ModelsHeader.h"
#include "memory"
#include <qDebug>
#include <iostream>

namespace SoccerLeague { namespace Models {

    class Club;
    class PlayerJourney;
    class Player : public QObject
    {
        Q_OBJECT
    private:
        int id_;
        QString firstname_;
        QString lastname_;
        qfloat16 weight_;
        QString birthCity_;
        std::shared_ptr<QVector<std::shared_ptr<PlayerJourney>>> journey_;
        std::shared_ptr<Club> club_;

    private:
        Q_PROPERTY(QString firstname READ getFirstname WRITE setFirstname NOTIFY firstnameChanged );
        Q_PROPERTY(QString lastname READ getLastname WRITE setLastname NOTIFY lastnameChanged);
        Q_PROPERTY(QString birthCity READ getBirthCity WRITE setBirthCity NOTIFY birthCityChanged);
        Q_PROPERTY(qfloat16 weight READ getWeight WRITE setWeight NOTIFY weightChanged);

    signals:
        void firstnameChanged(const QString& firstname);
        void lastnameChanged(const QString& lastname);
        void birthCityChanged(const QString& birthCity);
        void weightChanged(const qfloat16& weight);


    public:
        Player(const int& id,
               const QString& firtname,
               const QString& lastname,
               const qfloat16& weight,
               const QString& birthCity) :
            id_(id),
            firstname_(firtname),
            lastname_(lastname),
            weight_(weight),
            birthCity_(birthCity) {};

        Player() :
            id_(0),
            firstname_(QString()),
            lastname_(QString()),
            weight_(0.0),
            birthCity_(QString()),
            journey_(std::shared_ptr<QVector<std::shared_ptr<PlayerJourney>>>()){}

        QString getFirstname() {return firstname_;}
        QString getLastname() {return lastname_;}
        qfloat16 getWeight() {return weight_;}
        QString getBirthCity() {return birthCity_;}
        std::shared_ptr<QVector<std::shared_ptr<PlayerJourney>>> getJourney() {return journey_;}
        std::shared_ptr<Club> getClub() { return club_; }
        int getId() const  { return id_; }

        void setId(const int& id) { id_ = id; }
        void setClub(std::shared_ptr<Club> club) {
            club_ = club;
        }

        void setJourney(const std::shared_ptr<QVector<std::shared_ptr<PlayerJourney>>>& journey) {
            journey_ = journey;
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

        void setWeight(const qfloat16& weight) {
            if (getWeight() != weight) {
                weight_ = weight;
                weightChanged(weight);
            }
        }

        void setBirthCity(const QString& birthCity) {
            if (getBirthCity() != birthCity) {
                birthCity_ = birthCity;
                birthCityChanged(birthCity);
            }
        }
    };

}}
#endif // PLAYER_H
