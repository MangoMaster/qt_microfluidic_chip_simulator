#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "mainwindow.h"
#include "newchipdialog.h"
#include "chipmodel.h"

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(MainWindow *mainWindow, NewChipDialog *newChipDialog, ChipModel *chipModel, QObject *parent = nullptr);

signals:

public slots:

private:
    MainWindow *mainWindow;
    NewChipDialog *newChipDialog;
    ChipModel *chipModel;

    void control();
};

#endif // CONTROLLER_H
