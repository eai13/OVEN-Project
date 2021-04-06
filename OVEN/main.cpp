#include "mainwindow.h"

#include <QApplication>

uint8_t restart_flag;

int main(int argc, char *argv[])
{
    restart_flag = argc;
    std::cout << (uint16_t)restart_flag << std::endl;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
