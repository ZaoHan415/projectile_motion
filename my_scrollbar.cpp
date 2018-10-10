#include "my_scrollbar.h"

My_scrollBar::My_scrollBar(QWidget *parent,QString _name):
    QSlider(parent)
{
    setRange(0,100);
    setTickPosition(My_scrollBar::TicksBelow);
    S_label = new QLabel(parent);
    S_label->setFixedSize(100,10);
    name = _name;
    S_label->setText(name + ":"+QString::number(value(),10));
    connect(this,SIGNAL(valueChanged(int )),this,SLOT(setLabel(int )));
}

void My_scrollBar::setLabel(int nowVal)
{
    S_label->setText(name + ":"+QString::number(nowVal,10));
}

