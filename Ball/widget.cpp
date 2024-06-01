#include "widget.h"
#include "border.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPushButton>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget),m_ball(nullptr), m_border(nullptr),m_timer(startTimer(20))
{
    ui->setupUi(this);
    setFixedSize(800,600);
    setWindowTitle("小球运动");
}

Widget::~Widget()
{
    delete ui;
}
void Widget::setBall(Ball *ball) {
    m_ball = ball;
}
void Widget::setBorder(Border *border) {
    m_border = border;
}
void Widget::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    if (m_ball) {
        painter.setBrush(Qt::red);
        painter.drawEllipse(m_ball->drawball());

    }
    if (m_border) {
        painter.setBrush(Qt::NoBrush);
        painter.setPen(Qt::black);
        painter.drawRect(m_border->rect());
    }
}
void Widget::timerEvent(QTimerEvent *event) {
    if (event->timerId() == m_timer) {
        if (m_ball && m_border) {
            m_ball->updatePosition(*m_border);
            update(); // 更新绘制
        }
    }
}
