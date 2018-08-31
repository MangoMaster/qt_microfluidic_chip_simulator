#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cassert>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->showMaximized();
    connect(this->ui->action_Exit, SIGNAL(triggered(bool)), qApp, SLOT(quit()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayResult(const QVector<double> &results)
{
    assert(results.size() == 3);
    this->ui->lcdNumber_3->display(results[0]);
    this->ui->lcdNumber_4->display(results[1]);
    this->ui->lcdNumber_5->display(results[2]);
}
