#ifndef BALL_H
#define BALL_H

#include <QWidget>

class Border;
class Ball : public QWidget
{
    Q_OBJECT
public:
    explicit Ball(QWidget *parent = nullptr);
    Ball(int m_x,int m_y,int mradius,float vy,float mscale):m_x(m_x),m_y(m_y),dy(vy),radius(mradius),scale(mscale){}
    void updatePosition(const Border &border);
    void bounce();//反弹
    QRectF drawball() const;




private:
    int m_x;
    int m_y;//小球的位置
    int dy;//竖直方向速度
    int radius;//小球半径
    float scale;//粘连系数
    float gravity=3;//模拟重力加速度
signals:
};

#endif // BALL_H
