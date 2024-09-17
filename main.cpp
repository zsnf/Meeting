#include <QApplication>
#include <QPushButton>

#include "Controller.h"
#include "View/StartView.h"
#include <QWidget>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    const Controller controller;
    controller.ViewShow();
    return QApplication::exec();
}
