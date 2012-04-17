#include "AudioPlayerWidget.h"

AudioPlayerWidget::AudioPlayerWidget(QWidget *parent) : QWidget(parent)
{
    //widget setap
    this->setFixedSize(435,100);


    // audio setup
    p_AudioOutput = new Phonon::AudioOutput(Phonon::MusicCategory);
    p_AudioObject = new Phonon::MediaObject();

    //control element setup  (setup of buttons for playing, pause, stope music and other)
    p_ReplayTrackButton = new MyCheckableButton(QPixmap(".\\replayTurnOn.png"), QPixmap(".\\replay.png"));
    p_ReplayTrackButton->SetSize(QSize(25,25));

    p_RandomPlayButton = new MyCheckableButton(QPixmap(".\\randomTurnOn.png"),QPixmap(".\\random.png"));
    p_RandomPlayButton->SetSize(QSize(25,25));

    p_VolumeButton = new MyCheckableButton();
    p_VolumeButton->SetSize(QSize(25,25));

    p_NextTrackButton = new QPushButton();
    p_NextTrackButton->setFlat(true);
    p_NextTrackButton->setFixedSize(30,30);
    p_NextTrackButton->setIconSize(QSize(26,26));
    p_NextTrackButton->setIcon(QIcon(QPixmap(".\\right.png")));
    connect(p_NextTrackButton,SIGNAL(clicked()),SLOT(NextTrackButtonClickSlot()));

    p_PrevTrackButton = new QPushButton();
    p_PrevTrackButton->setFlat(true);
    p_PrevTrackButton->setFixedSize(30,30);
    p_PrevTrackButton->setIconSize(QSize(26,26));
    p_PrevTrackButton->setIcon(QIcon(QPixmap(".\\left.png")));
    connect(p_PrevTrackButton,SIGNAL(clicked()),SLOT(PrevTracButtonClickSlot()));

    p_PlayPauseButton = new QPushButton();
    p_PlayPauseButton->setFlat(true);
    p_PlayPauseButton->setFixedSize(40,40);
    p_PlayPauseButton->setIconSize(QSize(36,36));
    p_PlayPauseButton->setIcon(QIcon(QPixmap(".\\play.png")));
    connect(p_PlayPauseButton ,SIGNAL(clicked()), SLOT(PlayPauseButtonClickSlot()));

    p_StopButton = new QPushButton();
    p_StopButton->setFlat(true);
    p_StopButton->setFixedSize(40,40);
    p_StopButton->setIconSize(QSize(36,36));
    p_StopButton->setIcon(QIcon(QPixmap(".\\stop.png")));
    connect(p_StopButton ,SIGNAL(clicked()), SLOT(StopButtonSlot()));

    p_SeekSlider  = new Phonon::SeekSlider();

    p_VolumeSlider = new Phonon::VolumeSlider();
    p_VolumeSlider->setAudioOutput(p_AudioOutput);
    p_VolumeSlider->setMuteVisible(false);
    //p_VolumeSlider->setMaximumHeight(40);

    //Layouts setap
    QHBoxLayout *p_HControlElementsLayout = new QHBoxLayout();
    p_HControlElementsLayout->setSpacing(0);
    p_HControlElementsLayout->addWidget(p_ReplayTrackButton);
    p_HControlElementsLayout->addWidget(p_PrevTrackButton);
    p_HControlElementsLayout->addWidget(p_PlayPauseButton);
    p_HControlElementsLayout->addWidget(p_StopButton);
    p_HControlElementsLayout->addWidget(p_NextTrackButton);
    p_HControlElementsLayout->addWidget(p_RandomPlayButton);

    p_playerLayout = new QGridLayout();
    p_playerLayout->setSpacing(0);
    //p_playerLayout->addWidget(p_SeekSlider,1,0,1,10);
    p_playerLayout->addLayout(p_HControlElementsLayout,0,2,1,4);
    p_playerLayout->addWidget(p_VolumeSlider,0,8,1,2);
    this->setLayout(p_playerLayout);

    p_ConectedPlayList = NULL;   //playlist didnt connected
}

//methods
void AudioPlayerWidget::SetMediaObject(Phonon::MediaObject *p_CurrentMediaObject)
{
   //disconnect(p_AudioObject,SIGNAL(finished()),this,SLOT(TracTrackFinishedSlot()));
   p_AudioObject = p_CurrentMediaObject;   
   connect(p_AudioObject,SIGNAL(finished()),SLOT(TrackFinishedSlot()));
   Phonon::createPath(p_AudioObject,p_AudioOutput);     //connect audioobject with audiooutput
}
void AudioPlayerWidget::ConnectPlaylist(PlaylistWidget *p_Playlist)
{
    p_ConectedPlayList = p_Playlist;
    connect(p_ConectedPlayList,SIGNAL(TrackButtonClickSignal()),SLOT(PlaylistTrackClickSlot()));
}
void AudioPlayerWidget::SeekSliderMediaObjectSet()
{
    Phonon::State currentTrackState = p_AudioObject->state();

    p_AudioObject->pause();
    p_SeekSlider->setMediaObject(p_AudioObject);

    if(currentTrackState == Phonon::PlayingState)
    {
        p_AudioObject->play();
    }
    else
    {
        if(currentTrackState == Phonon::StoppedState)
        {
            p_AudioObject->stop();
        }
    }
    p_SeekSlider->show();
}
//slots
void AudioPlayerWidget::PlayPauseButtonClickSlot()
{
    //disconnect(p_AudioObject,SIGNAL(finished()),this,SLOT(TracTrackFinishedSlot()));

    TrackButton* p_ActiveTrack = p_ConectedPlayList->GetActiveTrack();
    Phonon::MediaObject *p_ActiveTrackObject = p_ActiveTrack->GetTrackObject();
    if(p_AudioObject != p_ActiveTrackObject)
    {
        p_AudioObject->stop();
        if(TrackButton* p_PrevPlayTrack = p_ConectedPlayList->GetPlayTrack())
        {
            p_PrevPlayTrack->SetPlayStatus(false);
        }

        this->SetMediaObject(p_ActiveTrackObject);
        p_ActiveTrack->SetPlayStatus(true);
        SeekSliderMediaObjectSet();    //connect seekslider object with audio object
        p_ConectedPlayList->SetPlayTrackIndex(p_ConectedPlayList->GetTrackIndex(p_ActiveTrackObject)); //save play track index
    }

    //change the icon of play-pause button and chage playing state
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
void AudioPlayerWidget::StopButtonSlot()
{
    p_AudioObject->stop();
}
void AudioPlayerWidget::PlaylistTrackClickSlot()
{
    TrackButton* p_ActiveTrack = p_ConectedPlayList->GetActiveTrack();
    Phonon::MediaObject *p_ActiveTrackObject = p_ActiveTrack->GetTrackObject();

    if(p_ActiveTrackObject == p_AudioObject && p_AudioObject->state() == Phonon::PlayingState)
    {
        p_PlayPauseButton->setIcon(QIcon(QPixmap(".\\pause.png")));
    }
    else
    {
        p_PlayPauseButton->setIcon(QIcon(QPixmap(".\\play.png")));
    }
}
void AudioPlayerWidget::TrackFinishedSlot()
{
    if(p_ConectedPlayList)
    {
        //disconnect(p_AudioObject,SIGNAL(finished()),this,SLOT(TracTrackFinishedSlot()));

        TrackButton* p_PrevTrack = p_ConectedPlayList->GetPlayTrack();
        p_PrevTrack->SetPlayStatus(false);

        TrackButton* p_NextTrack = p_ConectedPlayList->GetNextPlayTrack();
        p_NextTrack->SetPlayStatus(true);
        this->SetMediaObject(p_NextTrack->GetTrackObject());
        SeekSliderMediaObjectSet();

        p_PlayPauseButton->setIcon(QIcon(QPixmap(".\\pause.png")));
        p_AudioObject->play();
    }
    else
    {
        //plalist didnt conected
    }
}
void AudioPlayerWidget::NextTrackButtonClickSlot()
{
    if(p_ConectedPlayList)
    {
        //disconnect(p_AudioObject,SIGNAL(finished()),this,SLOT(TracTrackFinishedSlot()));

        TrackButton* p_PrevTrack = p_ConectedPlayList->GetPlayTrack();
        p_PrevTrack->SetPlayStatus(false);
        p_PrevTrack->GetTrackObject()->stop();

        TrackButton* p_NextTrack = p_ConectedPlayList->GetNextPlayTrack();
        p_NextTrack->SetPlayStatus(true);
        this->SetMediaObject(p_NextTrack->GetTrackObject());
        SeekSliderMediaObjectSet();

        p_PlayPauseButton->setIcon(QIcon(QPixmap(".\\pause.png")));
        p_AudioObject->play();
    }
    else
    {
        //plalist didnt conected
    }
}
void AudioPlayerWidget::PrevTracButtonClickSlot()
{
    if(p_ConectedPlayList)
    {
        //disconnect(p_AudioObject,SIGNAL(finished()),this,SLOT(TracTrackFinishedSlot()));

        TrackButton* p_PrevTrack = p_ConectedPlayList->GetPlayTrack();
        p_PrevTrack->SetPlayStatus(false);
        p_PrevTrack->GetTrackObject()->stop();
        int prevTrackIndex = p_ConectedPlayList->GetPlayTrackIndex();

        if(prevTrackIndex)   // set play index by back track
        {
            p_ConectedPlayList->SetPlayTrackIndex(prevTrackIndex-1);

        }
        else
        {
            p_ConectedPlayList->SetPlayTrackIndex(p_ConectedPlayList->GetTracksQuantity());
        }

        TrackButton* p_BackTrack = p_ConectedPlayList->GetPlayTrack();  // get play track by setting index
        p_BackTrack->SetPlayStatus(true);
        this->SetMediaObject(p_BackTrack->GetTrackObject());
        SeekSliderMediaObjectSet();

        p_PlayPauseButton->setIcon(QIcon(QPixmap(".\\pause.png")));
        p_AudioObject->play();
    }
    else
    {
        //plalist didnt conected
    }
}
void AudioPlayerWidget::VolumButtonClickSlot()
{

}
