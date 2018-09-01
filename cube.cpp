#include "cube.h"
#include <QGraphicsSceneMouseEvent>
#include <QInputDialog>

const int Cube::HW_TO_DIAMETER = 20;
const int Cube::DIAMETER_DEFAULT = 200;
const double Cube::SINGLE_MAX_WIDTH_HEIGHT = 80;
const double Cube::SINGLE_MIN_WIDTH_HEIGHT = 10;
const QBrush Cube::THROUGH_BRUSH = QBrush(Qt::blue);
const QBrush Cube::THROUGH_NOT_BRUSH = QBrush();

Cube::Cube(QGraphicsItem *parent)
    : QGraphicsRectItem(parent)
{
    pen.setWidth(0.5);
    this->setPen(pen);
    this->setBrush(brush);
    this->setFlag(QGraphicsItem::ItemIsSelectable);
}

Cube::Cube(qreal x, qreal y, bool h_bigger_than_w, QGraphicsItem *parent)
    : QGraphicsRectItem(parent), h_bigger_than_w(h_bigger_than_w)
{
    if (h_bigger_than_w)
        this->QGraphicsRectItem::setRect(x, y, SINGLE_MIN_WIDTH_HEIGHT, SINGLE_MAX_WIDTH_HEIGHT);
    else
        this->QGraphicsRectItem::setRect(x, y, SINGLE_MAX_WIDTH_HEIGHT, SINGLE_MIN_WIDTH_HEIGHT);
    pen.setWidth(0.5);
    this->setPen(pen);
    this->setBrush(brush);
    this->setFlag(QGraphicsItem::ItemIsSelectable);
}

void Cube::setThrough(bool value)
{
    if (value)
    {
        this->through = true;
        if (h_bigger_than_w)
            this->diameter = HW_TO_DIAMETER * this->rect().width();
        else
            this->diameter = HW_TO_DIAMETER * this->rect().height();
        this->setBrush(THROUGH_BRUSH);
    }
    else
    {
        this->through = false;
        this->diameter = 0;
        this->setBrush(THROUGH_NOT_BRUSH);
    }
}

void Cube::setDiameterHW(int diam)
{
    if (this->through) // not through => this->diameter == 0
        this->diameter = diam;
    if (h_bigger_than_w)
    {
        double w = diam / HW_TO_DIAMETER;
        double x = this->rect().x() + this->rect().width() / 2 - w / 2;
        this->setRect(x, this->rect().y(), w, this->rect().height());
    }
    else
    {
        double h = diam / HW_TO_DIAMETER;
        double y = this->rect().y() + this->rect().height() / 2 - h / 2;
        this->setRect(this->rect().x(), y, this->rect().width(), h);
    }
}

void Cube::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    switch(event->button())
    {
    case Qt::LeftButton:
        this->setThrough(!this->getThrough());
        break;
    case Qt::RightButton:
    {
        bool ok;
        int diam = QInputDialog::getInt(nullptr, "", "Cube length:",
                                        (h_bigger_than_w ? HW_TO_DIAMETER * this->rect().width() : HW_TO_DIAMETER * this->rect().height()),
                                        20, 1600, 10, &ok);
        if (ok)
            this->setDiameterHW(diam);
    }
        break;
    default:
        break;
    }
    QGraphicsRectItem::mousePressEvent(event);
}
