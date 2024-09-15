//
// Created by CxhPr on 24-9-15.
//

#include "SettingView.h"

SettingView::SettingView() {
    this->resize(800,600);
    this->setWindowTitle("设置");
    _setting_title->setGeometry(0,0,800,100);
    _setting_title->setAlignment(Qt::AlignCenter);

    _setting_list->addItem("选项1");
    _setting_list->addItem("选项2");
    _setting_list->addItem("选项3");

    const auto h_layout = new QHBoxLayout;
    h_layout->addWidget(_setting_list);
    h_layout->addWidget(_setting_stack);

    const auto v_layout = new QVBoxLayout;
    v_layout->addWidget(_setting_title);
    v_layout->addLayout(h_layout);

    connect(_setting_list, &QListWidget::currentRowChanged, _setting_stack, &QStackedWidget::setCurrentIndex);
    this->setLayout(v_layout);

}
