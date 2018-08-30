#ifndef NEWCHIPDIALOG_H
#define NEWCHIPDIALOG_H

#include <QDialog>

namespace Ui {
class NewChipDialog;
}

class NewChipDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewChipDialog(QWidget *parent = 0);
    ~NewChipDialog();

signals:
    void accepted(int num, const QVector<int> &inputs, const QVector<int> &outputs);

public slots:
    void accept() override;

private:
    Ui::NewChipDialog *ui;
};

#endif // NEWCHIPDIALOG_H
