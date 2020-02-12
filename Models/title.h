#ifndef TITLE_H
#define TITLE_H

#include "QString"
#include "QDateTime"
#include <memory>
#include "ModelsHeader.h"

namespace SoccerLeague { namespace Models {
class Title
{
private:
    int id_;
    QString name_;
    QDate date_;
    std::shared_ptr<Club> club_;
    std::shared_ptr<Coach> coach_;
    std::shared_ptr<Player> player_;

private:
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged);
    Q_PROPERTY(QDate date READ getDate WRITE setDate NOTIFY dateChanged);

signals:
    void nameChanged(const QString& name);
    void dateChanged(const QDate& date);

public:
    Title(const int& id, QString& name, const QDate& date) : id_(id), name_(name), date_(date)
    { }


    Title() : id_(0), name_(""), date_(QDate()) {}

    QString getName() {return name_;}
    QDate getDate() {return date_;}
    int getId() {return id_;}

    void setId(const int& id) {id_=id;}
    void setClub(const std::shared_ptr<Club>& club) {club_ = club;}
    void setCoach(const std::shared_ptr<Coach>& coach) {coach_ = coach;}

public slots:
    void setName(const QString& name) {
        if (getName() != name) {
            name_ = name;
            nameChanged(name);
        }
    }

    void setDate(const QDate& date) {
        if (getDate() != date) {
            date_ = date;
            dateChanged(date);
        }
    }
};
}}

#endif // TITLE_H
