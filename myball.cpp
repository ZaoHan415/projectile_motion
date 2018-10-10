#include "myball.h"
#include <QPainter>
#include <cmath>
MyBall::MyBall(QWidget *_parent):
    QWidget (_parent)
{
    initialize();
    parent = _parent;
    //connect(parent,SIGNAL(set_angle(int)),this,SLOT(set_angle(int )));
}

void MyBall::initialize()
{
    x=100.0;
    y=600.0;
    vx = vx0;
    vy = vy0;
    gravity = 0.0005;   //with /msec^2
}

void MyBall::paintBall(QWidget *parent)
{
    QRectF rectangle(x, y, 10, 10);
    QPainter painter(parent);
    painter.setPen(Qt::red);
    painter.drawArc(rectangle,0,5760);
    painter.setPen(Qt::blue);
    QLineF line(x+5,y+5,x+5+vx*100,y+5+vy*100);
    painter.drawLine(line);
}

void MyBall::update(int m_sec)
{
    if(x>1000||x<0)
    {
        vx=-vx;
        if(x>1000) x = 1000;
        else x = 0;
    }
    else if(y>700||y<0)
    {
        if(y>700) y = 700;
                else y = 0;
        vy=-vy;
    }
    x += vx*m_sec;
    y += vy*m_sec;
    vy += gravity*m_sec;
}

void MyBall::set_angle(int now_angle)
{
    double v0 = sqrt(vx0*vx0+vy0*vy0);
    angle = now_angle;
    vx0 = v0 * cos( (angle) * M_PI / 100.0) ;
    vy0 = -v0 * sin( (angle) * M_PI / 100.0) ;
    initialize();
    parent->update();
}
