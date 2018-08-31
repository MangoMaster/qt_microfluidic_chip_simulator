#include "chipmodel.h"
#include "cube.h"
#include "calculate.h"
#include "randomizer.h"
#include <cassert>

ChipModel::ChipModel(QObject *parent)
    : QGraphicsScene(parent), pen(Qt::white), brush(Qt::blue)
{
    pen.setWidth(0.5);

    this->setNewChip(5, QVector<int>({1, 2}), QVector<int>({1, 2, 3}));
}

void ChipModel::setNewChip(int num, const QVector<int> &inputs, const QVector<int> &outputs)
{
    assert(inputs.size() == 2);
    assert(outputs.size() == 3);
    this->num = num;
    this->inputs = inputs;
    std::sort(this->inputs.begin(), this->inputs.end());
    this->outputs = outputs;
    std::sort(this->outputs.begin(), this->outputs.end());
    this->cubes.clear();
    this->cubes.reserve(2 * num * num - 2 * num + 5);
    this->clear();

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
            this->cubes.push_back(cube);
            this->addItem(cube);
        }
    // cube (横向)
    for (int i = 0; i < num - 1; ++i)
        for (int j = 1; j <= num; ++j)
        {
            Cube *cube = new Cube(startWidth + i * singleGap + singleWidth, startHeight + j * singleGap - singleWidth, singleGap - singleWidth, singleWidth);
            this->cubes.push_back(cube);
            this->addItem(cube);
        }
    // inputs
    for (int i = 0; i <= 1; ++i)
    {
        Cube *cube = new Cube(startWidth + (this->inputs[i] - 1) * singleGap, startHeight, singleWidth, singleGap - singleWidth);
        this->cubes.push_back(cube);
        this->addItem(cube);
    }
    // outputs
    for (int i = 0; i <= 2; ++i)
    {
        Cube *cube = new Cube(startWidth + (this->outputs[i] - 1) * singleGap, startHeight + num * singleGap, singleWidth, singleGap - singleWidth);
        this->cubes.push_back(cube);
        this->addItem(cube);
    }
}

void ChipModel::calculateChip()
{
    assert(cubes.size() == 2 * num * num - 2 * num + 5);

    std::vector<double> diameters;
    for (auto cubePointer : cubes)
        diameters.push_back(cubePointer->getDiameter());
    this->results = caluconspeed(num, diameters, inputs[0], inputs[1], outputs[0], outputs[1], outputs[2]);
    // convert std::vector to QVector
    QVector<double> qResults;
    for (auto result : this->results)
        qResults.push_back(result);

    emit resultChanged(qResults);
}

void ChipModel::randomChip(double percent)
{
    Randomizer randomizer(percent);
    for (int i = 0; i < 2 * num * num - 2 * num; ++i)
        cubes[i]->setThrough(randomizer.random());
    calculateChip();
}
