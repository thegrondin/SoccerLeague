#include "stadiumrepository.h"


using namespace SoccerLeague::Repositories;

std::shared_ptr<Stadium> StadiumRepository::update(const Stadium &item){
    return nullptr;
}

std::shared_ptr<Stadium> StadiumRepository::add(const Stadium &item) {


    return nullptr;
}

bool StadiumRepository::remove(const Stadium &item) {
    return false;
}

bool StadiumRepository::removeById(const int &id) {
    return false;
}

std::shared_ptr<Stadium> StadiumRepository::getById(const int &id) {

    conn_.open();

    if (conn_.get()->isOpen()) {
        QSqlQuery query;


        query.prepare("SELECT id, capacity, terrain_quality, name, address FROM Stadiums WHERE id=:id LIMIT 1");
        query.bindValue(":id", QVariant(id));

        query.exec();

        query.first();


        std::shared_ptr<Stadium> pClub = std::make_shared<Stadium>();

        pClub->setId(query.value(0).toInt());
        pClub->setCapacity(query.value(1).toInt());
        pClub->setTerrainQuality(query.value(2).toString());
        pClub->setName(query.value(3).toString());
        pClub->setAddress(query.value(4).toString());

        conn_.close();

        return pClub;

    }

    return nullptr;

}

std::shared_ptr<Stadium> StadiumRepository::getByProperty(const QString &propertyName) {
    return nullptr;
}

std::shared_ptr<QVector<Stadium>> StadiumRepository::getAll() { return nullptr;}

