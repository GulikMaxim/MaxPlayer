#include "AudioPlayerWidget.h"

AudioPlayerWidget::AudioPlayerWidget(QWidget *parent) : QWidget(parent)
{
    //widget setap
    this->setFixedSize(435,100);

    AudioSetup();
    ControlElementsSetup();
}

//methods
void AudioPlayerWidget::ControlElementsSetup()
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
    p_PlayPauseButton->setFixedSize(40,40);
    p_PlayPauseButton->setIconSize(QSize(36,36));
    p_PlayPauseButton->setIcon(QIcon(QPixmap(".\\play.png")));
    connect(p_PlayPauseButton ,SIGNAL(clicked()), SLOT(PlayPauseButtonClickSlot()));

    QPushButton *p_StopButton = new QPushButton();
    p_StopButton->setFlat(true);
    p_StopButton->setFixedSize(40,40);
    p_StopButton->setIconSize(QSize(36,36));
    p_StopButton->setIcon(QIcon(QPixmap(".\\stop.png")));
    connect(p_StopButton ,SIGNAL(clicked()), p_AudioObject, SLOT(stop()));

    //p_SeekSlider  = new Phonon::SeekSlider();

    p_VolumeSlider = new Phonon::VolumeSlider();
    p_VolumeSlider->setAudioOutput(p_AudioOutput);
    //p_VolumeSlider->setMaximumHeight(40);

    //Layouts setap
    QHBoxLayout *p_HControlElementsLayout = new QHBoxLayout();
    p_HControlElementsLayout->setSpacing(0);
    p_HControlElementsLayout->addWidget(p_PrevTrackButton);
    p_HControlElementsLayout->addWidget(p_PlayPauseButton);
    p_HControlElementsLayout->addWidget(p_StopButton);
    p_HControlElementsLayout->addWidget(p_NextTrackButton);

    p_playerLayout = new QGridLayout();
    p_playerLayout->setSpacing(0);
    //p_playerLayout->addWidget(p_SeekSlider,1,0,1,10);
    p_playerLayout->addLayout(p_HControlElementsLayout,0,2,1,4);
    p_playerLayout->addWidget(p_VolumeSlider,0,8,1,2);
    this->setLayout(p_playerLayout);
}
void AudioPlayerWidget::AudioSetup()
{
    p_AudioOutput = new Phonon::AudioOutput(Phonon::MusicCategory);
    p_AudioObject = new Phonon::MediaObject();
}
void AudioPlayerWidget::SetMediaObject(Phonon::MediaObject *p_CurrentMediaObject)
{
   p_AudioObject = p_CurrentMediaObject;
   Phonon::createPath(p_AudioObject,p_AudioOutput);     //connect audioobject with audiooutput
   //p_SeekSlider->setMediaObject(p_CurrentMediaObject);
}
void AudioPlayerWidget::ConnectPlaylist(PlaylistWidget *p_Playlist)
{
    p_ConectedPlayList = p_Playlist;
    //p_AudioObject = p_ConectedPlayList->GetCurrentActiveTrackMediaObject();
}

//slots
void AudioPlayerWidget::PlayPauseButtonClickSlot()
{    
    Phonon::MediaObject *p_CurrenActiveTrackObject = p_ConectedPlayList->GetCurrentActiveTrackMediaObject();
    if(p_AudioObject != p_CurrenActiveTrackObject)
    {
        this->SetMediaObject(p_CurrenActiveTrackObject);
    }

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
