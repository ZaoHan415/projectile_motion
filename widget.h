#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimerEvent>
#include <QPainter>
#include <QPushButton>
#include "myball.h"
#include "my_scrollbar.h"
class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
protected:
    void timerEvent(QTimerEvent *) override;
    void paintEvent(QPaintEvent *) override;
private:
    int time_step = 10; //with msec
    int m_timerId ; //the timer for frame control
    bool is_running = false;
    QPushButton *pause_button,*start_button;
    MyBall *m_ball;
    My_scrollBar * angle_select;
public slots:
    void pause_resume();
    void restart();
};

#endif // WIDGET_H
