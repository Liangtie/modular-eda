#include <QApplication>
#include <QLabel>
#include <QMainWindow>
#include <iostream>
#include <string>

#include <qapplication.h>
#include <qmainwindow.h>

auto main(int argc, char** argv) -> int
{
    QApplication app(argc, argv);

    QLabel w("Hello EDA!");

    w.show();
    return app.exec();
}
