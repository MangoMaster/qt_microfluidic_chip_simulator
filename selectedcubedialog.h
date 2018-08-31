#ifndef SELECTEDCUBEDIALOG_H
#define SELECTEDCUBEDIALOG_H

#include <QDialog>

namespace Ui {
class SelectedCubeDialog;
}

class SelectedCubeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SelectedCubeDialog(QWidget *parent = 0);
    ~SelectedCubeDialog();
    friend class ChipModel;

private:
    Ui::SelectedCubeDialog *ui;
};

#endif // SELECTEDCUBEDIALOG_H
