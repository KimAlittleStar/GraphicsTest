#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QSpinBox>
#include <QHBoxLayout>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "graphicsitemlinegraph.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private:
    QVBoxLayout vertical;
    QHBoxLayout bottonLayout;
    QSpinBox axisX;
    QSpinBox axisY;
    QLabel labelX;
    QLabel labelY;
    QGraphicsView imgview;
    QGraphicsScene scene;
    GraphicsItemLineGraph lg;
public slots:
    void whenAxisChange(int value);


};
#endif // WIDGET_H
