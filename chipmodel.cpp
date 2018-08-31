#include "chipmodel.h"
#include "cube.h"
#include <cassert>

ChipModel::ChipModel(QObject *parent)
    : QGraphicsScene(parent), pen(Qt::white), brush(Qt::blue)
{
    pen.setWidth(0.5);
    //this->setBackgroundBrush(QBrush(Qt::gray));
}

void ChipModel::setNewChip(int num, const QVector<int> &inputs, const QVector<int> &outputs)
{
    assert(inputs.size() == 2);
    assert(outputs.size() == 3);
    this->num = num;
    this->inputs = inputs;
    this->outputs = outputs;
    this->diameters.fill(200, 2 * num * num - 2 * num + 5);
    this->clear();

    // QList<QGraphicsView *> views = this->views();
    int startWidth = 50;
    int startHeight = 50;
    double singleGap = 80;
    double singleWidth = 10;
    this->setSceneRect(0, 0, startWidth * 2 + singleGap * (num - 1) + singleWidth, startHeight * 2 + singleGap * (num + 1) - singleWidth);
    // node
    for (int i = 0; i < num; ++i)
        for (int j = 1; j <= num; ++j)
        {
            this->addEllipse(startWidth + i * singleGap, startHeight + j * singleGap - singleWidth, singleWidth, singleWidth, pen, brush);
        }
    // cube (纵向)
    for (int i = 0; i < num; ++i)
        for (int j = 1; j < num; ++j)
        {
            Cube *cube = new Cube(startWidth + i * singleGap, startHeight + j * singleGap, singleWidth, singleGap - singleWidth);
            this->addItem(cube);
        }
    // cube (横向)
    for (int i = 0; i < num - 1; ++i)
        for (int j = 1; j <= num; ++j)
        {
            Cube *cube = new Cube(startWidth + i * singleGap + singleWidth, startHeight + j * singleGap - singleWidth, singleGap - singleWidth, singleWidth);
            this->addItem(cube);
        }
    // inputs
    for (int i = 0; i <= 1; ++i)
    {
        Cube *cube = new Cube(startWidth + (inputs[i] - 1) * singleGap, startHeight, singleWidth, singleGap - singleWidth);
        this->addItem(cube);
    }
    // outputs
    for (int i = 0; i <= 2; ++i)
    {
        Cube *cube = new Cube(startWidth + (outputs[i] - 1) * singleGap, startHeight + num * singleGap, singleWidth, singleGap - singleWidth);
        this->addItem(cube);
    }
}
