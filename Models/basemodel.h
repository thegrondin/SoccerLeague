#ifndef BASEMODEL_H
#define BASEMODEL_H

#include "imodel.h"
    #include <QObject>

namespace SoccerLeague { namespace Models {

class BaseModel : public QObject
{

private:
    int id_;
public:
    int getId() const  {
        return id_;
    }
    void setId(const int& id)  {
        id_ = id;
    }
    BaseModel(const int& id) : id_(id) {}
};

}}

#endif // BASEMODEL_H
