#include "widget.h"
#include "splash.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget *w = new Widget;
    splash s(w);
    s.show();

    return a.exec();
}
