#include "chipmodel.h"
#include "cube.h"
#include "calculate.h"
#include "randomizer.h"
#include "selectedcubedialog.h"
#include "ui_selectedcubedialog.h"
#include <QInputDialog>
#include <QGraphicsWidget>
#include <cassert>
#include <QDebug>

ChipModel::ChipModel(QObject *parent)
    : QGraphicsScene(parent), pen(Qt::white), brush(Qt::blue)
{
    pen.setWidth(0.5);

    this->newChip(5, QVector<int>({1, 2}), QVector<int>({1, 2, 3}));
}

void ChipModel::newChip(int num, const QVector<int> &inputs, const QVector<int> &outputs)
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
    this->setSceneRect(0, 0, 2 * startWidth + (num - 1) * Cube::SINGLE_MAX_WIDTH_HEIGHT + num * Cube::SINGLE_MIN_WIDTH_HEIGHT, 2 * startHeight + (num + 1) * Cube::SINGLE_MAX_WIDTH_HEIGHT + num * Cube::SINGLE_MIN_WIDTH_HEIGHT);
    // node
    for (int i = 0; i < num; ++i)
        for (int j = 1; j <= num; ++j)
        {
            this->addEllipse(startWidth + i * Cube::SINGLE_MAX_WIDTH_HEIGHT + i * Cube::SINGLE_MIN_WIDTH_HEIGHT, startHeight + j * Cube::SINGLE_MAX_WIDTH_HEIGHT + (j - 1) * Cube::SINGLE_MIN_WIDTH_HEIGHT, Cube::SINGLE_MIN_WIDTH_HEIGHT, Cube::SINGLE_MIN_WIDTH_HEIGHT, pen, brush);
        }
    // cube (纵向)
    for (int i = 0; i < num; ++i)
        for (int j = 1; j < num; ++j)
        {
            Cube *cube = new Cube(startWidth + i * Cube::SINGLE_MAX_WIDTH_HEIGHT + i * Cube::SINGLE_MIN_WIDTH_HEIGHT, startHeight + j * Cube::SINGLE_MAX_WIDTH_HEIGHT + j * Cube::SINGLE_MIN_WIDTH_HEIGHT, true);
            this->cubes.push_back(cube);
            this->addItem(cube);
        }
    // cube (横向)
    for (int i = 0; i < num - 1; ++i)
        for (int j = 1; j <= num; ++j)
        {
            Cube *cube = new Cube(startWidth + i * Cube::SINGLE_MAX_WIDTH_HEIGHT + (i + 1) * Cube::SINGLE_MIN_WIDTH_HEIGHT, startHeight + j * Cube::SINGLE_MAX_WIDTH_HEIGHT + (j - 1) * Cube::SINGLE_MIN_WIDTH_HEIGHT, false);
            this->cubes.push_back(cube);
            this->addItem(cube);
        }
    // inputs
    for (int i = 0; i <= 1; ++i)
    {
        Cube *cube = new Cube(startWidth + (this->inputs[i] - 1) * Cube::SINGLE_MAX_WIDTH_HEIGHT + (this->inputs[i] - 1) * Cube::SINGLE_MIN_WIDTH_HEIGHT, startHeight, true);
        this->cubes.push_back(cube);
        this->addItem(cube);
    }
    // outputs
    for (int i = 0; i <= 2; ++i)
    {
        Cube *cube = new Cube(startWidth + (this->outputs[i] - 1) * Cube::SINGLE_MAX_WIDTH_HEIGHT + (this->outputs[i] - 1) * Cube::SINGLE_MIN_WIDTH_HEIGHT, startHeight + num * Cube::SINGLE_MAX_WIDTH_HEIGHT + num * Cube::SINGLE_MIN_WIDTH_HEIGHT, true);
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

void ChipModel::randomChip()
{
    bool ok;
    double percent = QInputDialog::getDouble(nullptr, "Random", "Percentage:", 0.90, 0.00, 1.00, 2, &ok, Qt::Dialog, 0.05);
    if (!ok)
        return;
    Randomizer randomizer(percent);
    for (int i = 0; i < 2 * num * num - 2 * num; ++i)
        cubes[i]->setThrough(randomizer.random());
    calculateChip();
}

void ChipModel::rubberBandChip()
{
    if (selectedItems().empty())
        return;
    SelectedCubeDialog dialog(nullptr);
    if (dialog.exec() == QDialog::Accepted)
    {
        switch (dialog.ui->comboBox->currentIndex())
        {
        case 1:
            for (auto selectedItem : selectedItems())
            {
                Cube *selectedCube = dynamic_cast<Cube*>(selectedItem);
                selectedCube->setThrough(true);
            }
            break;
        case 2:
            for (auto selectedItem : selectedItems())
            {
                Cube *selectedCube = dynamic_cast<Cube*>(selectedItem);
                selectedCube->setThrough(false);
            }
            break;
        case 3:
            for (auto selectedItem : selectedItems())
            {
                Cube *selectedCube = dynamic_cast<Cube*>(selectedItem);
                selectedCube->setThrough(!selectedCube->getThrough());
            }
            break;
        default:
            break;
        }
        if (dialog.ui->checkBox->isChecked())
            for (auto selectedItem : selectedItems())
            {
                Cube *selectedCube = dynamic_cast<Cube*>(selectedItem);
                selectedCube->setDiameterHW(dialog.ui->spinBox->value());
            }
    }
}

