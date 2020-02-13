#ifndef COACHVIEWMODEL_H
#define COACHVIEWMODEL_H

#include "../Services/coachservice.h"
#include <memory>

using namespace SoccerLeague::Services;

class CoachViewModel : public QObject
{
    Q_OBJECT
private:
    CoachService coachService_;

    std::shared_ptr<QVector<std::shared_ptr<Coach>>> coaches_;
    std::shared_ptr<Coach> currentCoach_;

    Q_PROPERTY(Coach* coach READ getCoach NOTIFY refreshCoach);
    Q_PROPERTY(QList<Coach*> coaches READ getCoaches NOTIFY refreshCoaches);
    Q_PROPERTY(QList<Title*> titles READ getTitles NOTIFY titlesChanged);

signals:
    void refreshCoaches();
    void titlesChanged();
    void refreshCoach();
    void coachSelectedEvent(const int& id);

public slots:
    void refreshTitles() {
        currentCoach_ = coachService_.getCoach(currentCoach_->getId());
        titlesChanged();
    }

public:
    CoachViewModel(CoachService coachService) :
        coachService_(coachService)
    {
        coaches_ = coachService_.getCoaches();
        currentCoach_ = std::make_shared<Coach>();
    };

    QList<Coach*> getCoaches() {
        QList<Coach*> datalist;

        for (auto coach : *coaches_) {
            datalist.append(coach.get());
        }

        return datalist;
    }

    Coach* getCoach() {
        return currentCoach_.get();
    }

    QList<Title*> getTitles() {
        QList<Title*> datalist;

        for (auto title : *currentCoach_->getTitles()) {
            datalist.append(title.get());
        }

        return datalist;
    }

    Q_INVOKABLE void saveCoach() {
        auto league = std::make_shared<League>();
        league->setId(1);
        currentCoach_->setLeague(league);
        coachService_.save(*currentCoach_.get());
        coaches_ = coachService_.getCoaches();
        emit refreshCoaches();
    }

    Q_INVOKABLE void clear() {
        currentCoach_ = std::make_shared<Coach>();
    }

    Q_INVOKABLE void deleteCoach(const int& id) {
        coachService_.remove(id);
        coaches_ = coachService_.getCoaches();
        emit refreshCoaches();

    }

    Q_INVOKABLE void selectCoach(const int& id) {
        currentCoach_ = coachService_.getCoach(id);
        emit refreshCoach();
        emit coachSelectedEvent(id);
    }
};

#endif // COACHVIEWMODEL_H
