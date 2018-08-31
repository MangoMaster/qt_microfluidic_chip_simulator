#ifndef RANDOMCHIPDIALOG_H
#define RANDOMCHIPDIALOG_H

#include <QDialog>

namespace Ui {
class RandomChipDialog;
}

class RandomChipDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RandomChipDialog(QWidget *parent = 0);
    ~RandomChipDialog();

signals:
    void accepted(double percent);

public slots:
    void accept() override;

private:
    Ui::RandomChipDialog *ui;
};

#endif // RANDOMCHIPDIALOG_H
