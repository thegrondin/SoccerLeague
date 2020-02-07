#ifndef CLUBVIEW_H
#define CLUBVIEW_H

#include <QString>

class ClubView
{
private:
    QString name;
public:
    ClubView() {
        name = "Default club.";
    }
    virtual ~ClubView() {}
    QString getName() const {
        return name;
    }
    void setName(const QString& value) {
        name = value;
    }
};

#endif // CLUBVIEW_H
