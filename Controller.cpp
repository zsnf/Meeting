//
// Created by CxhPr on 24-9-15.
//

#include "Controller.h"
#include "Data/SDKcall.h"
#include <string>
QString token {"007eJxTYHD9E3N62znhlQlvl51IkK71X6m7oObcrTUP/PYYRd/96t6twJCSYmCRmGaZaJliaGZiYZmWZGBuYGlkaWmcmmJqkGKQutXsZVpDICPDya5jrIwMEAji8zAkZ6TmVWQm5qVnlGYyMAAAXaomIw=="};

Controller::Controller() {
    _start_view = std::make_shared<StartView2>();
    SDKcall::GetSDKInstance();


    connect(_start_view->_join_meeting_btn, &QPushButton::clicked, this, [&] {
        const auto room_id = _start_view->_room_id->text();
        if (!room_id.isEmpty()) {
            SDKcall::GetSDKInstance().joinChannel(token,room_id,1234);
        }
    });
    connect(&SDKcall::GetSDKInstance(), &SDKcall::on_join_channel_success, this, [&] {
        const auto local_hwnd = reinterpret_cast<HWND>(_start_view->_self_widget->winId());
        SDKcall::GetSDKInstance().LocalVideoPreview(local_hwnd, TRUE);
    });

    connect(&SDKcall::GetSDKInstance(), &SDKcall::on_user_joined, this, [&] (int uid) {

    });
}
void Controller::ViewShow() const {
    _start_view->show();
}
