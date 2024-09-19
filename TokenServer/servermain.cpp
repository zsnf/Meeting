//
// Created by CxhPr on 24-9-17.
//

#include <QCoreApplication>

#include "Server.h"

int main(int argc, char *argv[]) {
    QCoreApplication app{argc, argv};
    Server server;
    return QCoreApplication::exec();
}