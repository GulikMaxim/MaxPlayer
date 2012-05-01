#include <phonon>
#include <QtGui>
#include <mainwindow.h>

#include <playlistbutton.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow *p_MaxPlayer = new MainWindow();
    p_MaxPlayer->show();
//    PlaylistButton *pl = new PlaylistButton();
//    pl->SetActiveStatus(true);
//    pl->show();

    return a.exec();
}
