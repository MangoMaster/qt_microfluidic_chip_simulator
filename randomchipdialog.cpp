#include "randomchipdialog.h"
#include "ui_randomchipdialog.h"

RandomChipDialog::RandomChipDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RandomChipDialog)
{
    ui->setupUi(this);
}

RandomChipDialog::~RandomChipDialog()
{
    delete ui;
}

void RandomChipDialog::accept()
{
    emit accepted(this->ui->doubleSpinBox->value());
    QDialog::accept();
}
