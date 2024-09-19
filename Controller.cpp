//
// Created by CxhPr on 24-9-15.
//

#include "Controller.h"
#include "Data/SDKcall.h"
#include <string>


Controller::Controller() {
    //_start_view = std::make_shared<StartView2>();
    _start_view3 = std::make_shared<StartView3>();
    _client = std::make_shared<Client>();
    SDKcall::GetSDKInstance();


    /*connect(_start_view->_join_meeting_btn, &QPushButton::clicked, this, [&] {
        const auto room_id = _start_view->_room_id->text();
        if (!room_id.isEmpty()) {
            SDKcall::GetSDKInstance().joinChannel(SDKcall::GetSDKInstance().token,room_id,1234);
        }
    });*/
    /*connect(&SDKcall::GetSDKInstance(), &SDKcall::on_join_channel_success, this, [&] {
        const auto local_hwnd = reinterpret_cast<HWND>(_start_view->_self_widget->winId());
        SDKcall::GetSDKInstance().LocalVideoPreview(local_hwnd, TRUE);
    });
    */

    /*connect(&SDKcall::GetSDKInstance(), &SDKcall::on_user_joined, this, [&] (int uid) {
        
    });*/

    connect(_start_view3.get(), &StartView3::create_meeting_signal, _client.get(), &Client::applyToken);
    connect(_client.get(), &Client::updated_token_and_uid, this, [&] {
        SDKcall::GetSDKInstance().joinChannel(
            SDKcall::GetSDKInstance().token,
            SDKcall::GetSDKInstance().RoomID,
            SDKcall::GetSDKInstance().uid
            );
    });
}
void Controller::ViewShow() const {
    _start_view3->show();
}

