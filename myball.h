#ifndef MYBALL_H
#define MYBALL_H

#include <QWidget>
//#include "widget.h"

class MyBall:public QWidget
{
    Q_OBJECT
public:
    MyBall(QWidget *parent = nullptr);
     //~MyBall();
    void paintBall(QWidget *parent);
    void update(int );
    void initialize();

private:
    double x, y, vx, vy, gravity;
    double vx0 = 0.8,vy0 = -0.0;
    QWidget *parent;
    int angle;
public slots:
    void set_angle(int a);

};

#endif // MYBALL_H
