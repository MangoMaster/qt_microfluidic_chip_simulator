#include "chipmodel.h"
#include <cassert>

ChipModel::ChipModel(QObject *parent) : QGraphicsScene(parent)
{

}

void ChipModel::setNewChip(int num, const QVector<int> &inputs, const QVector<int> &outputs)
{
    assert(inputs.size() == 2);
    assert(outputs.size() == 3);
    this->num = num;
    this->inputs = inputs;
    this->outputs = outputs;
    this->diameters.fill(200, 2 * num * num - 2 * num + 5);
}
