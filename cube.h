#ifndef CUBE_H
#define CUBE_H

#include <QGraphicsRectItem>
#include <QPen>
#include <QBrush>

class Cube : public QGraphicsRectItem
{
public:
    explicit Cube(QGraphicsItem *parent = nullptr);
    Cube(qreal x, qreal y, qreal w, qreal h, QGraphicsItem *parent = nullptr);
    int getDiameter() const { return this->diameter; }
    void setDiameter(int diameter) { this->diameter = diameter; }
    static const int DIAMETER_DEFAULT;
    bool getThrough() const { return this->through; }
    void setThrough(bool value);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

private:
    int diameter = DIAMETER_DEFAULT; // diameter of cube, default 200, at least 20
    bool through = true;

    QPen pen = QPen(Qt::white);
    QBrush brush = THROUGH_BRUSH;
    static const QBrush THROUGH_BRUSH;
    static const QBrush THROUGH_NOT_BRUSH;
};

#endif // CUBE_H
