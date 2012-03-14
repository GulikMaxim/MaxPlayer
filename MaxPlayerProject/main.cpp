#include <phonon/MediaObject>
#include <phonon/AudioOutput>
#include <mainwindow.h>

using namespace Phonon;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow *p_MaxPlayer = new MainWindow();
    p_MaxPlayer->show();

    
    return a.exec();
}
