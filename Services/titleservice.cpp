#include "titleservice.h"

using namespace SoccerLeague::Repositories;
using namespace SoccerLeague::Models;
using namespace SoccerLeague::Services;

std::shared_ptr<Title> TitleService::getTitle(const int& id) {

    return titleRepository_.getById(id);
}

std::shared_ptr<Title> TitleService::save(const Title &title) {

   return titleRepository_.add(title);
}


void TitleService::remove(const int& id) {

    titleRepository_.removeById(id);
}
