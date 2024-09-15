#include <QApplication>
#include <QPushButton>
#include "View/StartView.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    StartView view{};
    view.show();
    return QApplication::exec();
}
