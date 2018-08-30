#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "mainwindow.h"
#include "newchipdialog.h"

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(MainWindow *mainWindow, NewChipDialog *newChipDialog, QObject *parent = nullptr);

signals:

public slots:

private:
    MainWindow *mainWindow;
    NewChipDialog *newChipDialog;

    void control();
};

#endif // CONTROLLER_H
