#ifndef BORDER_H
#define BORDER_H

#include <QWidget>

class Border : public QWidget
{
    Q_OBJECT
public:
    explicit Border(QWidget *parent = nullptr);
    Border(int x, int y, int width, int height):m_rect(x,y,width,height){}
    QRectF rect() const;
private:
    QRectF m_rect;

signals:
};

#endif // BORDER_H
