#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <cassert>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->showMaximized();
    QObject::connect(this->ui->action_Exit, SIGNAL(triggered(bool)), qApp, SLOT(quit()));
    QObject::connect(this->ui->action_Help, SIGNAL(triggered(bool)), this, SLOT(helpDialog()));
    QObject::connect(this->ui->action_About, SIGNAL(triggered(bool)), this, SLOT(aboutDialog()));
    QObject::connect(this->ui->actionAbout_Qt, SIGNAL(triggered(bool)), qApp, SLOT(aboutQt()));
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

void MainWindow::helpDialog()
{
    QMessageBox::information(this, "Help",
                             "    New (Ctrl+N) a chip to set rows/columns & inputs/outputs.\n"
                             "    Click a cube to let it enabled/disabled.\n"
                             "    Right click a cube to set its length.\n"
                             "    Rubber band drag cubes to let them enabled/disabled & set their length.\n"
                             "    Random cubes enabled/disabled with a percentage.\n"
                             "    Run (Ctrl+R) and get results at the bottom.\n"
                             "    Drag the slider on the right to set chip's scale.\n"
                             "    Exit (Ctrl+Q).\n",
                             QMessageBox::Ok);
}

void MainWindow::aboutDialog()
{
    QMessageBox::about(this, "About",
                       "Microfluidic Chip Simulator, version 1.0.0\n"
                       "Copyright (c) 2018 weijd. All rights reserved.\n"
                       "MIT License\n\n"
                       "    Based on the calculating program from Copyright (c) 2018 Regents of the Tsinghua University, Hailong Yao, and Weiqing Ji.\n"
                       "    Based on Qt 5.11.1.\n");
}
