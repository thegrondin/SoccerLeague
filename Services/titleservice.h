#ifndef TITLESERVICE_H
#define TITLESERVICE_H

#include "../Repositories/titlerepository.h"

using namespace SoccerLeague::Models;
using namespace SoccerLeague::Repositories;

namespace SoccerLeague { namespace Services {

    class TitleService
    {
    private:
        TitleRepository titleRepository_;
    public:
        TitleService(TitleRepository titleRepository) :
            titleRepository_(titleRepository) {} ;

        std::shared_ptr<Title> getTitle(const int& id);
        void saveFromClub(const Title&);
    };

}}
#endif // TITLESERVICE_H
