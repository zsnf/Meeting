//
// Created by CxhPr on 24-9-15.
//

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <memory>
#include "View/StartView.h"

class Controller final : public QObject{
    Q_OBJECT
public:
    Controller();
    void ViewShow() const;
private:
    std::shared_ptr<StartView2> _start_view{};
};



#endif //CONTROLLER_H
