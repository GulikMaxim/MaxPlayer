#include <QtGui>
#include "widget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLabel *l = new QLabel("This is my project");
    l->show();
    
    return a.exec();
}
