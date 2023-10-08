#include "mainwindow.h"
#include <ranges>
#include <span>
#include <string_view>
#include <vector>
#include <QApplication>
#include <numeric>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
