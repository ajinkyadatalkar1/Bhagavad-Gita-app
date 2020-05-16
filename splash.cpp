#include "splash.h"
#include <QImage>
#include <QPixmap>
#include <QBrush>
#include <QTimer>

splash::splash(QWidget *w)
{
/*    QPixmap *bkgnd = new QPixmap(":/splash.png");
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(*bkgnd));
    this->setPalette(palette);*/

    setStyleSheet("background-image: url(:/splash.png);background-repeat: no-repeat;background-attachment: fixed;background-position: center;background-color: red;");

    QTimer *timer = new QTimer();

    connect(timer,&QTimer::timeout,[=](){
        w->show();
        timer->stop();
    });
    timer->start(3000);
}
