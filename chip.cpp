#include "chip.h"

Chip::Chip(QWidget *parent) : QGraphicsView(parent)
{
    this->setDragMode(QGraphicsView::RubberBandDrag);
    QObject::connect(this, SIGNAL(rubberBandChanged(QRect,QPointF,QPointF)), this, SLOT(rubberBandChangedToSelected(QRect)));
}

void Chip::rubberBandChangedToSelected(QRect rubberBandRect)
{
    if (rubberBandRect.isNull())
        emit rubberBandSelected();
}

void Chip::setScalePercent(int percent)
{
    this->resetTransform();
    this->scale(percent * 0.01, percent * 0.01);
}
