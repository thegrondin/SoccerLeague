#ifndef TITLESVIEWMODEL_H
#define TITLESVIEWMODEL_H

#include "../Services/clubservice.h"
#include "../Services/titleservice.h"

using namespace SoccerLeague::Services;
using namespace SoccerLeague::Models;

namespace SoccerLeague { namespace ViewModels {

class TitlesViewModel : public QObject
{
    Q_OBJECT
private:
    TitleService titleService_;

    std::shared_ptr<Title> currentTitle_;

    Q_PROPERTY(Title* title READ getTitle);
public:
    TitlesViewModel(TitleService titleService) :
        titleService_(titleService) {
        currentTitle_ = std::make_shared<Title>();
    };

signals:
    void titleSelectedEvent(const int &id);
    void titlesChangedEvent();
    void coachTitlesChangedEvent();

public slots:
    void setClub(const int& id) {
        currentTitle_->setCoach(std::make_shared<Coach>());
        currentTitle_->setClub(std::make_shared<Club>());
        currentTitle_->getClub()->setId(id);
    }

    void setCoach(const int& id) {
        currentTitle_->setClub(std::make_shared<Club>());
        currentTitle_->setCoach(std::make_shared<Coach>());
        currentTitle_->getCoach()->setId(id);
    }

public:
    Title* getTitle() {
        return currentTitle_.get();
    }

    Q_INVOKABLE void saveTitle() {
        auto result = titleService_.save(*currentTitle_.get());

        if (result->getClub() && result->getClub()->getId() != 0) {
            emit titlesChangedEvent();
        }
        else {
            emit coachTitlesChangedEvent();
        }

    }

    Q_INVOKABLE void clear() {
        currentTitle_ = std::make_shared<Title>();
    }

    Q_INVOKABLE void deleteTitle(const int& id) {
        titleService_.remove(id);
        emit titlesChangedEvent();
    }

};

}}

#endif // TITLESVIEWMODEL_H
