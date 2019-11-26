#ifndef GRAPHICSITEMLINEGRAPH_H
#define GRAPHICSITEMLINEGRAPH_H

#include <QObject>
#include <QGraphicsItem>
#include <QPointF>
#include <QLineF>
#include <QVector>
#include <QPainter>
#include <QPen>
#include <QRectF>

class GraphicsItemLineGraph : public QGraphicsItem
{
    //Q_OBJECT
public:
    explicit GraphicsItemLineGraph(QGraphicsItem *parent = nullptr);
    void addPoint(const QPointF& p);
    void addPoint(double x = 0,double y = 0);
    void addPoint(int x,int y);
    void clear(quint32 size = (-1u));
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    QRectF boundingRect() const override;
signals:

public slots:
private:
    QVector<QLineF> lineList;
    QVector<QPointF> pointList;
    QPointF max_point;
    void drawCircle(QPainter*painter, qreal x,qreal y,qreal r);
    int penWidth = 0;

};

#endif // GRAPHICSITEMLINEGRAPH_H
