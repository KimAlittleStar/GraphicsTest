#include "graphicsitemlinegraph.h"
#include <QBrush>

GraphicsItemLineGraph::GraphicsItemLineGraph(QGraphicsItem *parent) : QGraphicsItem(parent)
{

}

void GraphicsItemLineGraph::addPoint(const QPointF& p)
{
    pointList.append(p);
    if(p.x() > max_point.x())
    {
        max_point.rx() = p.x();
    }
    if(p.y() > max_point.y())
    {
        max_point.ry() = p.y();
    }
    if(pointList.size() > 1)
    {
        QLineF line(pointList[pointList.size()-2],pointList[pointList.size()-1]);
        lineList.append(line);
    }
}
void GraphicsItemLineGraph::addPoint(double x ,double y)
{
    addPoint(QPointF(x,y));
}
void GraphicsItemLineGraph::addPoint(int x,int y)
{
    addPoint(QPointF(x,y));
}

void GraphicsItemLineGraph::drawCircle(QPainter*painter, qreal x,qreal y,qreal r)
{
    QBrush b1 = painter->brush();
    QBrush b2 = b1;
    b2.setColor(painter->pen().color());
    b2.setStyle(Qt::SolidPattern);
    painter->setBrush(b2);
    penWidth = painter->pen().width();
    painter->drawRoundedRect(static_cast<int>(x-r) ,
                             static_cast<int>(y-r),
                             static_cast<int>(2*r),
                             static_cast<int>(2*r),
                             r,r);
    painter->setBrush(b1);
}

void GraphicsItemLineGraph::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QBrush b1 = painter->brush();
    QBrush b2 = b1;
    b2.setColor("yellow");
    b2.setStyle(Qt::SolidPattern);
    painter->setBrush(b2);
    painter->drawRect(0,0,static_cast<int>(max_point.x()),static_cast<int>(max_point.y()));
    painter->setBrush(b1);
    painter->drawLines(lineList);
    for(auto i:pointList)
    {
        drawCircle(painter,i.x(),i.y(),painter->pen().widthF()*3);
    }
}
QRectF GraphicsItemLineGraph::boundingRect() const
{
    QRectF ret(0-penWidth*3-1,
               0-penWidth*3-1,
               max_point.x()+penWidth*3+1,
               max_point.y()+penWidth*3+1);
    return  ret;
}
