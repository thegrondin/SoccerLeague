#ifndef STADIUM_H
#define STADIUM_H

#include "basemodel.h"
#include <QString>

namespace SoccerLeague { namespace Models {

class Stadium : public BaseModel
{
    Q_OBJECT
private:
    int capacity_;
    QString terrainQuality_;
    QString name_;
    QString address_;

private:
    Q_PROPERTY(int capacity READ getCapacity WRITE setCapacity NOTIFY capacityChanged);
    Q_PROPERTY(QString terrainQuality READ getTerrainQuality WRITE setTerrainQuality NOTIFY terrainQualityChanged);
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged);
    Q_PROPERTY(QString address READ getAddress WRITE setAddress NOTIFY addressChanged);

signals:
    void capacityChanged(const int& capacity);
    void terrainQualityChanged(const QString& terrainQuality);
    void nameChanged(const QString& name);
    void addressChanged(const QString& address);

public:
    Stadium(const int& id,
            const int& capacity,
            const QString& terrainQuality,
            const QString& name,
            const QString& address) :
      BaseModel(id),
      capacity_(capacity),
      terrainQuality_(terrainQuality),
      name_(name),
      address_(address) { }

    Stadium() :
        BaseModel(0),
        capacity_(0),
        terrainQuality_(QString()),
        name_(QString()),
        address_(QString()) {}

    int getCapacity() { return capacity_; }
    QString getTerrainQuality() { return terrainQuality_; }
    QString getName() { return name_; }
    QString getAddress() { return address_; }

public slots:
    void setCapacity(const int& capacity) {
        if (getCapacity() != capacity) {
            capacity_ = capacity;
            capacityChanged(capacity);
        }
    }

    void setTerrainQuality(const QString& terrainQuality) {
        if (getTerrainQuality() != terrainQuality) {
            terrainQuality_ = terrainQuality;
            terrainQualityChanged(terrainQuality);
        }
    }

    void setName(const QString& name) {
        if (getName() != name) {
            name_ = name;
            nameChanged(name);
        }
    }
    void setAddress(const QString& address) {
        if (getAddress() != address) {
            address_ = address;
            addressChanged(address);
        }
    }

};

}}
#endif // STADIUM_H
