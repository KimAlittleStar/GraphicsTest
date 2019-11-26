#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    axisX.setMaximum(65535);
    axisY.setMaximum(65535);
    axisX.setMinimum(0);
    axisY.setMinimum(0);
    labelX.setText("X:");
    labelY.setText("Y:");
    axisX.setMaximumSize(80,25);
    axisY.setMaximumSize(80,25);
    labelX.setMaximumSize(70,25);
    labelY.setMaximumSize(70,25);
    this->setLayout(&vertical);
    axisX.setValue(100);
    axisY.setValue(100);
    bottonLayout.addWidget(&labelX);
    bottonLayout.addWidget(&axisX);
    bottonLayout.addWidget(&labelY);
    bottonLayout.addWidget(&axisY);
    vertical.addWidget(&imgview);
    vertical.addLayout(&bottonLayout);

    lg.addPoint(0*(1080/255),0*(1080/255));
    lg.addPoint(90*(1080/255),50*(1080/255));
    lg.addPoint(255*(1080/255),255*(1080/255));
    scene.addItem(&lg);
    imgview.setScene(&scene);
    connect(&axisX,SIGNAL(valueChanged(int)),this,SLOT(whenAxisChange(int)));
    connect(&axisY,SIGNAL(valueChanged(int)),this,SLOT(whenAxisChange(int)));
}

Widget::~Widget()
{
}

void Widget::whenAxisChange(int value)
{
    imgview.scale(axisX.value()/100.0,axisY.value()/100.0);
    imgview.update();
}

