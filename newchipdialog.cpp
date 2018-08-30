#include "newchipdialog.h"
#include "ui_newchipdialog.h"
#include <QMessageBox>

NewChipDialog::NewChipDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewChipDialog)
{
    ui->setupUi(this);
}

NewChipDialog::~NewChipDialog()
{
    delete ui;
}

void NewChipDialog::accept()
{
    // check value does not overflow
    if (this->ui->spinBox_2->value() > this->ui->spinBox->value()
            || this->ui->spinBox_3->value() > this->ui->spinBox->value()
            || this->ui->spinBox_4->value() > this->ui->spinBox->value()
            || this->ui->spinBox_5->value() > this->ui->spinBox->value()
            || this->ui->spinBox_6->value() > this->ui->spinBox->value())
    {
        QMessageBox::warning(this, "Error", "Input/Output column(s) overflow.");
        return;
    }
    // check value does not equal
    if (this->ui->spinBox_2->value() == this->ui->spinBox_3->value()
            || this->ui->spinBox_4->value() == this->ui->spinBox_5->value()
            || this->ui->spinBox_4->value() == this->ui->spinBox_6->value()
            || this->ui->spinBox_5->value() == this->ui->spinBox_6->value())
    {
        QMessageBox::warning(this, "Error", "Input/Output columns are same.");
        return;
    }
    QVector<int> inputs;
    inputs.push_back(this->ui->spinBox_2->value());
    inputs.push_back(this->ui->spinBox_3->value());
    QVector<int> outputs;
    outputs.push_back(this->ui->spinBox_4->value());
    outputs.push_back(this->ui->spinBox_5->value());
    outputs.push_back(this->ui->spinBox_6->value());
    emit accepted(this->ui->spinBox->value(), inputs, outputs);
    QDialog::accept();
}
