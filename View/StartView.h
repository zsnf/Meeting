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
#include <QDialog>

#include "SettingView.h"

class StartView2 final : public QWidget{
public:
    StartView2();
    ~StartView2() override;


    QLineEdit* _room_id { new QLineEdit{this} };
    QPushButton* _join_meeting_btn{ new QPushButton{ "加入会议", this} };
    QWidget* _self_widget{ new QWidget{this} };
    QWidget* _other_widget{ new QWidget{this} };

};

class StartView3 final : public QWidget {
    Q_OBJECT
public:
    StartView3();
    ~StartView3() override;

private:
    QPushButton* _create_meeting_btn{ new QPushButton{ "创建会议", this} };
    QPushButton* _join_meeting_btn{ new QPushButton{ "加入会议", this} };
    QPushButton* _setting_btn{ new QPushButton{"设置", this} };
    QVBoxLayout* _main_layout{ new QVBoxLayout{this} };

private slots:
    void show_create_meeting_dialog();

    signals:
    void create_meeting_signal(const QString& RoomID);
};



#endif //STARTVIEW_H
