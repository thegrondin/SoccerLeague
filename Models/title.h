#ifndef TITLE_H
#define TITLE_H

#include "QString"
#include "QDateTime"

namespace SoccerLeague { namespace Models {
class Title
{
private:
    QString name_;
    QDateTime date_;
public:
    Title(const QString& name, const QDateTime& date) : name_(name), date_(date)
    { }

    QString getName() {return name_;}
    QDateTime getDate() {return date_;}
};
}}

#endif // TITLE_H
