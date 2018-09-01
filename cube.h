#ifndef CUBE_H
#define CUBE_H

#include <QGraphicsRectItem>
#include <QPen>
#include <QBrush>

class Cube : public QGraphicsRectItem
{
public:
    explicit Cube(QGraphicsItem *parent = nullptr);
    Cube(qreal x, qreal y, bool h_bigger_than_w, QGraphicsItem *parent = nullptr);
    static const double SINGLE_MAX_WIDTH_HEIGHT;
    static const double SINGLE_MIN_WIDTH_HEIGHT;
    static const int DIAMETER_DEFAULT;
    void setDiameterHW(int diam);
    int getDiameter() const { return this->diameter; }
    bool getThrough() const { return this->through; }
    void setThrough(bool value);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    // QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;

private:
    // size (used for viewing)
    // min(w, h) * 20 == diameter
    static const int HW_TO_DIAMETER;
    bool h_bigger_than_w; // 表示矩形的方向
    // size (used for calculating)
    int diameter = DIAMETER_DEFAULT; // diameter of cube, default 200, at least 20

    bool through = true;

    QPen pen = QPen(Qt::white);
    QBrush brush = THROUGH_BRUSH;
    static const QBrush THROUGH_BRUSH;
    static const QBrush THROUGH_NOT_BRUSH;
};

#endif // CUBE_H
