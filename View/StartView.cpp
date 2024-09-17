//
// Created by CxhPr on 24-9-15.
//

#include "StartView.h"

AvatarLabel::AvatarLabel(QWidget *parent) {
    setParent(parent);
}

void AvatarLabel::mousePressEvent(QMouseEvent *event) {
    if(event->button() == Qt::LeftButton) {
        setAvatar();
    }
}

void AvatarLabel::setAvatar() {
    const QString file_name = QFileDialog::getOpenFileName(
        nullptr,
        tr("选择头像"),
        "",
        tr("图片文件 (*.png *.jpg *.bmp)")

    );
    if(file_name.isEmpty()) return;
    else {
        const auto avatar = QPixmap{file_name};
        this->setPixmap(avatar.scaled(this->size()));
    }
}

NameLabel::NameLabel(QWidget *parent) {
    setText(tr("昵称"));
    setParent(parent);
}

void NameLabel::mousePressEvent(QMouseEvent *event) {
    if(event->button() == Qt::LeftButton) {
        setName();
    }
}

void NameLabel::setName() {
    bool ok{};
    const QString name = QInputDialog::getText(
        nullptr,
        tr("输入昵称"),
        tr("请输入昵称"),
        QLineEdit::Normal,
        tr(""),
        &ok
    );
    if(ok && !name.isEmpty()) {
        this->setText(name);
    }
}

StartView::StartView() {
    this->resize(300,400);
    this->setWindowTitle("Meeting");
    _avatar->setGeometry(0,0, 100,100);
    _name->setGeometry(100,70,200,30);
    _setting_btn->setGeometry(0,100,300,30);
    connect(_setting_btn, &QPushButton::clicked, this, &StartView::do_setting);

    _join_meeting_btn->setGeometry(0,130,300,30);
}

StartView::~StartView() = default;

void StartView::do_join_meeting() {
}

void StartView::do_setting() const {
    _setting_view->show();
}

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
