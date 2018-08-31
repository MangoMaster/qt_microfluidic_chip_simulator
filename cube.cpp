#include "cube.h"

const int Cube::DIAMETER_DEFAULT = 200;
const QBrush Cube::THROUGH_BRUSH = QBrush(Qt::blue);
const QBrush Cube::NOT_THROUGH_BRUSH = QBrush();

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

void Cube::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (this->through)
    {
        this->through = false;
        this->diameter = 0;
        this->setBrush(NOT_THROUGH_BRUSH);
    }
    else
    {
        this->through = true;
        this->diameter = DIAMETER_DEFAULT;
        this->setBrush(THROUGH_BRUSH);
    }
    QGraphicsRectItem::mousePressEvent(event);
}


