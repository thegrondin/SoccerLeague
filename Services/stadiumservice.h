#ifndef STADIUMSERVICE_H
#define STADIUMSERVICE_H

#include "../Repositories/stadiumrepository.h"

using namespace SoccerLeague::Models;
using namespace SoccerLeague::Repositories;

namespace SoccerLeague { namespace Services {

    class StadiumService
    {
    private:
        StadiumRepository stadiumRepository_;
    public:
        StadiumService(StadiumRepository stadiumRepository):
            stadiumRepository_(stadiumRepository) {};


        std::shared_ptr<Stadium> getStadium(const int&);
        std::shared_ptr<QVector<std::shared_ptr<Stadium>>> getStadiums();
    };

}}
#endif // STADIUMSERVICE_H
