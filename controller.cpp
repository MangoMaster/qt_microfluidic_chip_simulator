#include "controller.h"
#include "ui_mainwindow.h"

Controller::Controller(MainWindow *mainWindow, NewChipDialog *newChipDialog, ChipModel *chipModel, QObject *parent)
    : QObject(parent), mainWindow(mainWindow), newChipDialog(newChipDialog), chipModel(chipModel)
{
    control();
}

void Controller::control()
{
    mainWindow->ui->graphicsView->setScene(chipModel);
    QObject::connect(mainWindow->ui->action_New, SIGNAL(triggered(bool)), newChipDialog, SLOT(exec()));
    QObject::connect(newChipDialog, SIGNAL(accepted(int,QVector<int>,QVector<int>)), chipModel, SLOT(setNewChip(int,QVector<int>,QVector<int>)));
}
