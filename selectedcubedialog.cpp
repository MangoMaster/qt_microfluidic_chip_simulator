#include "selectedcubedialog.h"
#include "ui_selectedcubedialog.h"

SelectedCubeDialog::SelectedCubeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectedCubeDialog)
{
    ui->setupUi(this);
}

SelectedCubeDialog::~SelectedCubeDialog()
{
    delete ui;
}
