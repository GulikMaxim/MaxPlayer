#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{
    //main window setup
    this->setMinimumSize(500,100);
    this->setPalette(QPalette(this->backgroundRole(),Qt::white));
    this->setWindowTitle("MaxPLayer");

    AudioSetup();
    ControlElementsSetup();
}

//methods
void MainWindow::ControlElementsSetup()
{
    QPushButton *p_NextTrackButton = new QPushButton();
    p_NextTrackButton->setFlat(true);
    p_NextTrackButton->setFixedSize(30,30);
    p_NextTrackButton->setIconSize(QSize(26,26));
    p_NextTrackButton->setIcon(QIcon(QPixmap(".\\right.png")));

    QPushButton *p_PrevTrackButton = new QPushButton();
    p_PrevTrackButton->setFlat(true);
    p_PrevTrackButton->setFixedSize(30,30);
    p_PrevTrackButton->setIconSize(QSize(26,26));
    p_PrevTrackButton->setIcon(QIcon(QPixmap(".\\left.png")));

    p_PlayPauseButton = new QPushButton();
    p_PlayPauseButton->setFlat(true);    
    p_PlayPauseButton->setFixedSize(60,60);
    p_PlayPauseButton->setIconSize(QSize(56,56));
    p_PlayPauseButton->setIcon(QIcon(QPixmap(".\\play.png")));
    connect(p_PlayPauseButton ,SIGNAL(clicked()), SLOT(PlayPauseSlot()));

    QPushButton *p_StopButton = new QPushButton();
    p_StopButton->setFlat(true);
    p_StopButton->setFixedSize(40,40);
    p_StopButton->setIconSize(QSize(36,36));
    p_StopButton->setIcon(QIcon(QPixmap(".\\stop.png")));
    connect(p_StopButton ,SIGNAL(clicked()), p_AudioObject, SLOT(stop()));

    p_SeekSlider  = new Phonon::SeekSlider();
    p_SeekSlider->setMediaObject(p_AudioObject);

    p_VolumeSlider = new Phonon::VolumeSlider();
    p_VolumeSlider->setAudioOutput(p_AudioOutput);
    //p_VolumeSlider->setMaximumHeight(40);

    //Layouts setap
    QHBoxLayout *p_HControlElementsLayout = new QHBoxLayout();
    p_HControlElementsLayout->addWidget(p_PrevTrackButton);
    p_HControlElementsLayout->addWidget(p_PlayPauseButton);
    p_HControlElementsLayout->addWidget(p_StopButton);
    p_HControlElementsLayout->addWidget(p_NextTrackButton);

    playerLayout.addWidget(p_SeekSlider,0,0,2,10);
    playerLayout.addLayout(p_HControlElementsLayout,0,11,1,4);
    playerLayout.addWidget(p_VolumeSlider,1,11,1,4);

    this->setLayout(&playerLayout);
}
void MainWindow::AudioSetup()
{
    p_AudioObject = new Phonon::MediaObject();
    p_AudioOutput = new Phonon::AudioOutput(Phonon::MusicCategory);

    Phonon::createPath(p_AudioObject,p_AudioOutput);

    p_AudioObject->setCurrentSource(Phonon::MediaSource("d:\\the_beatles_-_yesterday.mp3"));
}

//slots
void MainWindow::PlayPauseSlot()
{
    if(p_AudioObject->state() == Phonon::PlayingState)
    {
        p_PlayPauseButton->setIcon(QIcon(QPixmap(".\\play.png")));
        p_AudioObject->pause();
    }
    else
    {
        p_PlayPauseButton->setIcon(QIcon(QPixmap(".\\pause.png")));
        p_AudioObject->play();
    }
}
