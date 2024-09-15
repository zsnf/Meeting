//
// Created by CxhPr on 24-9-15.
//

#ifndef STARTVIEW_H
#define STARTVIEW_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QMouseEvent>
#include <QFileDialog>
#include <QString>
#include <QInputDialog>
#include <QObject>

#include "SettingView.h"


class AvatarLabel final : public QLabel{
public:
    explicit AvatarLabel(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *event) override;
private:
    void setAvatar();
};

class NameLabel final : public QLabel {
public:
    explicit NameLabel(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *event) override;
private:
    void setName();
};

class StartView final : public QWidget{
public:
    StartView();
    ~StartView() override;
    StartView(const StartView&) = delete;

private:
    AvatarLabel *_avatar{ new AvatarLabel{this} };
    NameLabel *_name{ new NameLabel{this} };
    QPushButton *_setting_btn{ new QPushButton{"设置", this} };
    QPushButton *_join_meeting_btn{ new QPushButton{ "加入会议", this} };
    SettingView *_setting_view{ new SettingView };
public slots:
    void do_join_meeting();
    void do_setting() const;
};



#endif //STARTVIEW_H
