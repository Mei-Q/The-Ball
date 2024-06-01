#include "border.h"
#include "widget.h"
#include "ball.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    Ball ball(400,100,50,1,0.95); // 小球初始位置、半径和速度
    Border border(350,0,100,550); // 边界框大小

    w.setBall(&ball);
    w.setBorder(&border);
    w.show();
    return a.exec();
}
