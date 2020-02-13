#include "titleservice.h"

using namespace SoccerLeague::Repositories;
using namespace SoccerLeague::Models;
using namespace SoccerLeague::Services;

std::shared_ptr<Title> TitleService::getTitle(const int& id) {

    return titleRepository_.getById(id);
}

void TitleService::saveFromClub(const Title &title) {

    titleRepository_.add(title);
}
