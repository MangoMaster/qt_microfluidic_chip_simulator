#include "cube.h"

const int Cube::DIAMETER_DEFAULT = 200;
const QBrush Cube::THROUGH_BRUSH = QBrush(Qt::blue);
const QBrush Cube::THROUGH_NOT_BRUSH = QBrush();

Cube::Cube(QGraphicsItem *parent)
    : QGraphicsRectItem(parent)
{
    pen.setWidth(0.5);
}

Cube::Cube(qreal x, qreal y, qreal w, qreal h, QGraphicsItem *parent)
    : QGraphicsRectItem(x, y, w, h, parent)
{
    this->setPen(pen);
    this->setBrush(brush);
}

void Cube::setThrough(bool value)
{
    if (value)
    {
        this->through = true;
        this->diameter = DIAMETER_DEFAULT;
        this->setBrush(THROUGH_BRUSH);
    }
    else
    {
        this->through = false;
        this->diameter = 0;
        this->setBrush(THROUGH_NOT_BRUSH);
    }
}

void Cube::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->setThrough(this->getThrough());
    QGraphicsRectItem::mousePressEvent(event);
}



