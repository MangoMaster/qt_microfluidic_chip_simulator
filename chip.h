#ifndef CHIP_H
#define CHIP_H

#include <QGraphicsView>

class Chip : public QGraphicsView
{
    Q_OBJECT
public:
    explicit Chip(QWidget *parent = nullptr);

signals:
    void rubberBandSelected();

public slots:
    void rubberBandChangedToSelected(QRect rubberBandRect);
    void setScalePercent(int percent);
};

#endif // CHIP_H
