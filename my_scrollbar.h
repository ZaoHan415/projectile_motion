#ifndef MY_SCROLLBAR_H
#define MY_SCROLLBAR_H
#include <QLabel>
#include <QSlider>

class My_scrollBar : public QSlider
{
    Q_OBJECT
public:
    My_scrollBar(QWidget *parent = nullptr,QString _name = "");
    //using QSlider::setTickPosition;
private:
    QLabel *S_label;
    QString name;
public slots:
    void setLabel(int nowVal);
};


#endif // MY_SCROLLBAR_H
