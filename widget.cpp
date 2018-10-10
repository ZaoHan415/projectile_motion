#include "widget.h"
#include <QTimer>
#include "my_scrollbar.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent)
{
    angle_select = new My_scrollBar(this,"angle");
    angle_select->setGeometry(0,200,50,200);
    m_ball = new MyBall(this);
    pause_button = new QPushButton(this);
    start_button = new QPushButton(this);
    pause_button->setText("Resume");
    start_button->setText("ReStart");
    start_button->setGeometry(0,20,100,20);
    connect(start_button,SIGNAL(clicked()),this,SLOT(restart()));
    connect(pause_button,SIGNAL(clicked()),this,SLOT(pause_resume()));
    setFixedSize(1000,800);
    connect(angle_select,&My_scrollBar::valueChanged,m_ball,&MyBall::set_angle);

}

void Widget::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == m_timerId)
    {
        m_ball->update(time_step);
        update();
    }
}

void Widget::paintEvent(QPaintEvent *)
{
    m_ball->paintBall(this);
}

void Widget::pause_resume()
{
    if(is_running)
    {
        killTimer(m_timerId);
        pause_button->setText("Resume");
        is_running = false;
    }
    else
    {
        m_timerId = startTimer(time_step);
        pause_button->setText("Pause");
        is_running = true;
    }
}

void Widget::restart()
{
    //m_ball->set_angle(angle_select->value());
    m_ball->initialize();
    if(is_running) pause_resume();
    update();
}
