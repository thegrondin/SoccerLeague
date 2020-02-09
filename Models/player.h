#ifndef PLAYER_H
#define PLAYER_H

#include <memory>

#include "basemodel.h"
#include <QString>
#include <QFloat16>
#include <QVector>
#include "playerjourney.h"
#include "ModelsHeader.h"
#include "memory"

namespace SoccerLeague { namespace Models {

class Club;
class Player : public BaseModel
{
private:
QString firstname_;
QString lastname_;
qfloat16 weight_;
QString birthCity_;
QVector<std::shared_ptr<PlayerJourney>> journey_;
std::weak_ptr<Club> club_;
public:
    Player(const int& id,
           const QString& firtname,
           const QString& lastname,
           const qfloat16& weight,
           const QString& birthCity,
           const QVector<std::shared_ptr<PlayerJourney>>& journey) :
        BaseModel(id),
        firstname_(firtname),
        lastname_(lastname),
        weight_(weight),
        birthCity_(birthCity),
        journey_(journey){};

    Player() :
        BaseModel(0),
        firstname_(QString()),
        lastname_(QString()),
        weight_(0.0),
        birthCity_(QString()),
        journey_(QVector<std::shared_ptr<PlayerJourney>>()){}

    QString getFirstname() {return firstname_;}
    QString getLastname() {return lastname_;}
    qfloat16 getWeight() {return weight_;}
    QString getBirthCity() {return birthCity_;}
    QVector<std::shared_ptr<PlayerJourney>> getJourney() {return journey_;}
    Club &getClub() { return *club_.lock().get(); }

    void setClub(std::weak_ptr<Club> club) {
        club_ = club;
    }

    void setFirtname(const QString& firtname) {
        firstname_ = firtname;
    }

    void setLastname(const QString& lastname) {
        lastname_ = lastname;
    }

    void setWeight(const qfloat16& weight) {
        weight_ = weight;
    }

    void setJourney(const QVector<std::shared_ptr<PlayerJourney>>& journey) {
        journey_ = journey;
    }
};

}}
#endif // PLAYER_H
