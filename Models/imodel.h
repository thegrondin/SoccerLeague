#ifndef IMODEL_H
#define IMODEL_H

namespace SoccerLeague { namespace Models {

class IModel
{
public:
    virtual ~IModel();
    virtual int getId();
    virtual void setId(const int& id);
};

}}
#endif // IMODEL_H
