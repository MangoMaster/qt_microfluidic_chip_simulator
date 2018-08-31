#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "mainwindow.h"
#include "newchipdialog.h"
#include "randomchipdialog.h"
#include "chipmodel.h"

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(MainWindow *mainWindow, NewChipDialog *newChipDialog, RandomChipDialog *randomChipDialog, ChipModel *chipModel, QObject *parent = nullptr);

signals:

public slots:

private:
    MainWindow *mainWindow;
    NewChipDialog *newChipDialog;
    RandomChipDialog *randomChipDialog;
    ChipModel *chipModel;

    void control();
};

#endif // CONTROLLER_H
