#include "controller.h"
#include "ui_mainwindow.h"

Controller::Controller(MainWindow *mainWindow, NewChipDialog *newChipDialog, QObject *parent)
    : QObject(parent), mainWindow(mainWindow), newChipDialog(newChipDialog)
{
    control();
}

void Controller::control()
{
    QObject::connect(mainWindow->ui->action_New, SIGNAL(triggered(bool)), newChipDialog, SLOT(exec()));
}
