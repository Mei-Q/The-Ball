#include "ball.h"
#include "border.h"
#include "QPainter"
Ball::Ball(QWidget *parent)
    : QWidget{parent}
{}
void Ball::updatePosition(const Border &border) {
    dy+=gravity;
    m_y += dy; //移动
    if (m_y + radius >= border.rect().bottom())// 碰到下边界
    {
        m_y = border.rect().bottom() - radius;
        bounce(); // 反弹机制
    } else if (m_y - radius <= border.rect().top())// 碰到上边界
    {

        m_y = border.rect().top() + radius;
        bounce(); // 反弹
    }
}
void Ball::bounce() {
    dy = -dy * scale; //速度反向并乘以粘连系数
}
QRectF Ball::drawball() const {
    return QRectF(m_x - radius, m_y - radius, 2 * radius, 2 * radius);
}

