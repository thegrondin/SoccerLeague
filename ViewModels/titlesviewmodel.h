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

public slots:
    void setClub(const int& id) {
        currentTitle_->setClub(std::make_shared<Club>());
        currentTitle_->getClub()->setId(id);
    }

public:
    Title* getTitle() {
        return currentTitle_.get();
    }

    Q_INVOKABLE void saveTitle() {
        titleService_.saveFromClub(*currentTitle_.get());
        emit titlesChangedEvent();
    }

    Q_INVOKABLE void clear() {
        currentTitle_ = std::make_shared<Title>();
    }

};

}}

#endif // TITLESVIEWMODEL_H
