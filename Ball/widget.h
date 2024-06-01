#ifndef WIDGET_H
#define WIDGET_H

#include "ball.h"
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void setBall(Ball *ball);
    void setBorder(Border *border);
protected:
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *event);

private:
    Ui::Widget *ui;
    Ball *m_ball;
    Border *m_border;
    int m_timer;
};
#endif // WIDGET_H
