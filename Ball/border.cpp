#include "border.h"

Border::Border(QWidget *parent)
    : QWidget{parent}
{}
QRectF Border::rect() const {
    return m_rect;
}
