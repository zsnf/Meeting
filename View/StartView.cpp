//
// Created by CxhPr on 24-9-15.
//

#include "StartView.h"

#include "../Data/SDKcall.h"

StartView2::StartView2() {
    this->resize(800,600);
    auto *layout = new QHBoxLayout;
    layout->addWidget(_room_id);
    layout->addWidget(_join_meeting_btn);

    auto hlayout2 = new QHBoxLayout;
    hlayout2->addWidget(_self_widget);
    hlayout2->addWidget(_other_widget);

    auto vlayout = new QVBoxLayout{this};
    vlayout->addLayout(layout);
    vlayout->addLayout(hlayout2);

}

StartView2::~StartView2() = default;

StartView3::StartView3() {
    this->resize(200,200);
    _main_layout->addWidget(_create_meeting_btn);
    _main_layout->addWidget(_join_meeting_btn);
    _main_layout->addWidget(_setting_btn);

    connect(_create_meeting_btn, &QPushButton::clicked, this, &StartView3::show_create_meeting_dialog);
}

StartView3::~StartView3() = default;

void StartView3::show_create_meeting_dialog() {
    bool ok;
    const int number = QInputDialog::getInt(this, tr("Enter a RoomID"),
                                            tr("RoomID:"), 0, 0, 100000, 1, &ok);
    if (ok) {
        // 用户点击OK并输入一个整数
        emit create_meeting_signal(QString::number(number));
    }
}

