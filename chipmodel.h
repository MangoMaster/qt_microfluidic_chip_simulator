#ifndef CHIPMODEL_H
#define CHIPMODEL_H

#include <QGraphicsScene>

class ChipModel : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit ChipModel(QObject *parent = nullptr);

signals:

public slots:
    void setNewChip(int num, const QVector<int> &inputs, const QVector<int> &outputs);

private:
    int num; // num of rows/columns
    QVector<int> inputs; // column num of input cubes
    QVector<int> outputs; // column num of output cubes
    QVector<int> diameters; // diameters of cubes, default 200, at least 20
};

#endif // CHIPMODEL_H
