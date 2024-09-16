//
// Created by CxhPr on 24-9-15.
//

#include "Controller.h"

Controller::Controller() {
    _setting = std::make_unique<Setting>();
    _start_view = std::make_unique<StartView>();
}

void Controller::ViewShow() const {
    _start_view->show();
}
