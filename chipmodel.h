#ifndef CHIPMODEL_H
#define CHIPMODEL_H

#include <QGraphicsScene>
#include "cube.h"

class ChipModel : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit ChipModel(QObject *parent = nullptr);

signals:
    void resultChanged(const QVector<double> &results);

public slots:
    void setNewChip(int num, const QVector<int> &inputs, const QVector<int> &outputs);
    void calculateChip();
    void randomChip(double percent = 0.9);

private:
    int num; // num of rows/columns
    QVector<int> inputs; // column num of input cubes
    QVector<int> outputs; // column num of output cubes
    std::vector<Cube*> cubes;
    std::vector<double> results;

    QPen pen;
    QBrush brush;
};

#endif // CHIPMODEL_H
