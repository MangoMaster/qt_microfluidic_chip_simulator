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
    void newChip(int num, const QVector<int> &inputs, const QVector<int> &outputs);
    void calculateChip();
    void randomChip();
    void rubberBandChip();

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
