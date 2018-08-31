#include "mainwindow.h"
#include "newchipdialog.h"
#include "chipmodel.h"
#include "controller.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    NewChipDialog d;
    RandomChipDialog d2;
    ChipModel m;
    Controller(&w, &d, &d2, &m);
    w.show();

    return a.exec();
}
