#ifndef LEAGUE_H
#define LEAGUE_H

#include <QString>
#include <memory>
#include "ModelsHeader.h"

namespace SoccerLeague { namespace Models {

    class Club;
    class Coach;
    class League : public QObject
    {
        Q_OBJECT

    private:
        int id_;
        std::shared_ptr<QVector<std::shared_ptr<Club>>> clubs_;
        std::shared_ptr<QVector<std::shared_ptr<Coach>>> coaches_;
        QString name_;

    private:
        Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged);

    signals:
        void nameChanged(const QString& arg);
    public:
        League(const int& id,
               const QString& name) :
            id_(id),
            name_(name) {};

        League() : id_(0), name_("") {}

        int getId() {return id_;}
        QString getName() {return name_;}
        std::shared_ptr<QVector<std::shared_ptr<Club>>> getClubs() {return clubs_;}
        std::shared_ptr<QVector<std::shared_ptr<Coach>>> getCoaches() {return coaches_;}

    public:
        void setId(const int& id) { id_ = id;}
        void setClubs(const std::shared_ptr<QVector<std::shared_ptr<Club>>> clubs) {
            clubs_ = clubs;
        }

        void setCoaches(const std::shared_ptr<QVector<std::shared_ptr<Coach>>> coaches) {
            coaches_ = coaches;
        }

    public slots:
        void setName(const QString& name) {
            if (getName() != name) {
                name_ = name;
                nameChanged(name);
            }
        }
    };
}}

#endif // LEAGUE_H
