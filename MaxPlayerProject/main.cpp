#include <phonon>
#include <QtGui>
#include <mainwindow.h>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow *p_MaxPlayer = new MainWindow();
    p_MaxPlayer->show();

    return a.exec();
}
