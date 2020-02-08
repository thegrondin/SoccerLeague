#ifndef BASEMODEL_H
#define BASEMODEL_H

#include "imodel.h"

namespace SoccerLeague { namespace Models {

class BaseModel
{
private:
    int id_;
public:
    int getId()  {
        return id_;
    }
    void setId(const int& id)  {
        id_ = id;
    }
    BaseModel(const int& id) : id_(id) {}
};

}}

#endif // BASEMODEL_H
