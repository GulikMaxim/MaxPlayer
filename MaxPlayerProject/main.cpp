#include <phonon>
#include <QtGui>
#include <mainwindow.h>
//#include <window.h>
//#include <audioplayerwidget.h>
#include <mycheckablebutton.h>

//#include <trackbutton.h>
//using namespace Phonon;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //MyCheckableButton *p = new MyCheckableButton();
    //p->show();

    //TrackButton *p_b = new TrackButton();
    //p_b->setPlayStatus(true);
    //p_b->show();
    //Phonon::SeekSlider sk;
    //sk.setStyle(new QCleanlooksStyle);
    //sk.show();
    //QSlider *p_button = new QSlider();
    //p_button->setStyle(new QMotifStyle);
    //p_button->show();

//    AudioPlayerWidget *p = new AudioPlayerWidget();
//    Phonon::MediaObject *m = new Phonon::MediaObject();
//    m->setCurrentSource(Phonon::MediaSource(QString("D:\\Sound\\01. Black - Wonderful Life.mp3")));
//    QLabel *l = new QLabel(m->metaData().value("ARTIST"));
//    p->SetMediaObject(m);
//    l->show();
//    p->show();

    MainWindow *p_MaxPlayer = new MainWindow();
    p_MaxPlayer->show();

    //Window *p_MaxPlayer = new Window();
    //p_MaxPlayer->show();
    //PlaylistWidget * pl = new PlaylistWidget();
    //pl->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //pl->setWindowFlags(Qt::FramelessWindowHint);
    //pl->setPalette(QPalette(Qt::cyan,Qt::black));
    //pl->show();
    //AudioPlayerWidget *P_PLA = new AudioPlayerWidget();
    //P_PLA->show();

//    QWidget *p_wi = new QWidget();
//    QPalette *pal = new QPalette();
//    pal->setBrush(p_wi->backgroundRole(),QBrush(QPixmap("background.jpg")));
//    p_wi->setPalette(*pal);
//    p_wi->setAutoFillBackground(true);
//    p_wi->show();

    
    return a.exec();
}
