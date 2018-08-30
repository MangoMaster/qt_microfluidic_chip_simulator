#include "mainwindow.h"
#include "newchipdialog.h"
#include "controller.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    NewChipDialog d;
    Controller(&w, &d);
    w.show();

    return a.exec();
}
