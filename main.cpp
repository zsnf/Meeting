#include <QApplication>
#include <QPushButton>

#include "Controller.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    Controller controller{};
    controller.ViewShow();
    return QApplication::exec();
}
