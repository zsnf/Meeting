//
// Created by CxhPr on 24-9-15.
//

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <memory>

#include "Data/Client.h"
#include "View/StartView.h"

class Controller final : public QObject{
    Q_OBJECT
public:
    Controller();
    void ViewShow() const;

private:
    std::shared_ptr<StartView2> _start_view{};
    std::shared_ptr<StartView3> _start_view3{};
    std::shared_ptr<Client> _client{};
    void JoinByToken(const QString& token);
};



#endif //CONTROLLER_H
