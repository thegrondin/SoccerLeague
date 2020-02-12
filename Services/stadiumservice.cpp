#include "stadiumservice.h"


using namespace SoccerLeague::Services;


std::shared_ptr<Stadium> StadiumService::getStadium(const int & id) {

    return stadiumRepository_.getById(id);
}

std::shared_ptr<QVector<std::shared_ptr<Stadium>>> StadiumService::getStadiums() {

    return stadiumRepository_.getAll(std::unordered_map<QString, QString>());
}
