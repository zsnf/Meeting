//
// Created by CxhPr on 24-9-15.
//

#ifndef SETTINGVIEW_H
#define SETTINGVIEW_H

#include <QListWidget>
#include <QStackedWidget>
#include <QObject>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>

class SettingView final : public QWidget{
    Q_OBJECT
public:
    SettingView();

private:
    QListWidget *_setting_list { new QListWidget{this} };
    QStackedWidget *_setting_stack { new QStackedWidget{this} };
    QLabel* _setting_title { new QLabel{"设置", this}};
};



#endif //SETTINGVIEW_H
