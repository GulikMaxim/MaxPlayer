#include "AudioPlayerWidget.h"

AudioPlayerWidget::AudioPlayerWidget(QWidget *parent) : QWidget(parent)
{
    //widget setap
    this->setFixedSize(430,100);

    // audio setup
    p_AudioOutput = new Phonon::AudioOutput(Phonon::MusicCategory);
    p_AudioObject = new Phonon::MediaObject();

    //control element setup  (setup of buttons for playing, pause, stope music and other)
    p_SeekSliderButton = new MyCheckableButton(QPixmap(".\\SeekSliderTurnOn.png"),QPixmap(".\\SeekSlider.png"),this);
    p_SeekSliderButton->SetSize(QSize(25,25));
    p_SeekSliderButton->move(25,23);

    p_VolumeButton = new MyCheckableButton(QPixmap(".\\volumeTurnOn.png"),QPixmap(".\\volume.png"),this);
    p_VolumeButton->SetSize(QSize(25,25));
    p_VolumeButton->move(290,23);
    connect(p_VolumeButton,SIGNAL(clicked()),SLOT(VolumButtonClickSlot()));

    p_NextTrackButton = new PixmapButton(QPixmap(".\\right.png"),QSize(30,30),this);
    p_NextTrackButton->move(240,20);
    connect(p_NextTrackButton,SIGNAL(clicked()),SLOT(PlayNextTrackSlot()));

    p_PrevTrackButton = new PixmapButton(QPixmap(".\\left.png"),QSize(30,30),this);
    p_PrevTrackButton->move(70,20);   //115,20
    connect(p_PrevTrackButton,SIGNAL(clicked()),SLOT(PrevTracButtonClickSlot()));

    p_PlayPauseButton = new PixmapButton(QPixmap(".\\play.png"),QSize(40,40),this);
    p_PlayPauseButton->move(120,15);
    connect(p_PlayPauseButton ,SIGNAL(clicked()), SLOT(PlayPauseButtonClickSlot()));

    p_StopButton = new PixmapButton(QPixmap(".\\stop.png"),QSize(40,40),this);
    p_StopButton->move(180,15);
    connect(p_StopButton ,SIGNAL(clicked()), SLOT(StopButtonSlot()));

    p_ReplayTrackButton = new MyCheckableButton(QPixmap(".\\replayTurnOn.png"), QPixmap(".\\replay.png"),this);
    p_ReplayTrackButton->move(335,23);
    p_ReplayTrackButton->SetSize(QSize(25,25));
    connect(p_ReplayTrackButton,SIGNAL(clicked()),SLOT(ReplayButtonClickSlot()));

    p_RandomPlayButton = new MyCheckableButton(QPixmap(".\\randomTurnOn.png"),QPixmap(".\\random.png"),this);
    p_RandomPlayButton->move(380,23);
    p_RandomPlayButton->SetSize(QSize(25,25));
    connect(p_RandomPlayButton,SIGNAL(clicked()),SLOT(RandomPlayButtonClickeSlot()));


    //volume window setup
    p_VolumeSliderWidget = new TitleWidget(this);
    p_VolumeSliderWidget->SetTitleText(QString("Volume"));
    p_VolumeSliderWidget->setFixedSize((QSize(150,50)));
    p_VolumeSliderWidget->move(315,8);
    p_VolumeSliderWidget->hide();
    p_VolumeSliderWidget->TitleMove(QPoint(10,4));
    p_VolumeSliderWidget->SetTitleFont(QFont("Bauhaus 93",9,QFont::Normal));
    connect(p_SeekSliderButton,SIGNAL(clicked()),SLOT(VolumButtonClickSlot()));

    p_VolumeSlider = new Phonon::VolumeSlider(p_VolumeSliderWidget);
    p_VolumeSlider->setAudioOutput(p_AudioOutput);
    p_VolumeSlider->setMuteVisible(false);
    p_VolumeSlider->move(10,22);
    p_VolumeSlider->setFixedWidth(100);

    //seek slider window setup
    p_SeekSliderWidget = new TitleWidget(this);
    p_SeekSliderWidget->SetTitleText(QString("Seek slider"));
    p_SeekSliderWidget->setFixedSize((QSize(330,50)));
    p_SeekSliderWidget->move(50,8);
    p_SeekSliderWidget->hide();
    p_SeekSliderWidget->TitleMove(QPoint(10,4));
    p_SeekSliderWidget->SetTitleFont(QFont("Bauhaus 93",9,QFont::Normal));    
    connect(p_SeekSliderButton,SIGNAL(clicked()),SLOT(SeekSliderButtonClickSlot()));

    p_SeekSlider  = new Phonon::SeekSlider(p_SeekSliderWidget);
    p_SeekSlider->setFixedWidth(320);
    p_SeekSlider->move(10,22);

    //
    p_ConectedSongsList = NULL;   //playlist didnt connected
}

//methods
void AudioPlayerWidget::SetMediaObject(Phonon::MediaObject *p_Object)
{
   p_AudioObject->stop();
   if(p_ConectedSongsList->GetPlayTrack())
   {
       disconnect(p_AudioObject,SIGNAL(finished()),this,SLOT(PlayNextTrackSlot()));
   }
   p_AudioObject = p_Object;
   SeekSliderMediaObjectSet(p_AudioObject);
   connect(p_AudioObject,SIGNAL(finished()),SLOT(PlayNextTrackSlot()));
   while(p_AudioObject->state() == Phonon::LoadingState){};  //wait while audio object will ready for play
}
void AudioPlayerWidget::ConnectPlaylist(PlaylistWidget *p_Playlist)
{
    p_ConectedSongsList = p_Playlist->GetSongsList();
    connect(p_ConectedSongsList,SIGNAL(TrackButtonClickSignal()),SLOT(PlaylistTrackClickSlot()));

}
void AudioPlayerWidget::SeekSliderMediaObjectSet(Phonon::MediaObject *p_Object)
{
    p_Object->pause();
    p_SeekSlider->setMediaObject(p_Object);
}
void AudioPlayerWidget::SetAudioOutput(Phonon::AudioOutput *p_Output)
{
    qreal currentVolume = p_AudioOutput->volume();
    p_Output->setVolume(currentVolume);
    p_AudioOutput = p_Output;
    p_VolumeSlider->setAudioOutput(p_Output);
}
void AudioPlayerWidget::ConnectTrack(Track* p_Track)
{
    SetMediaObject(p_Track->GetAudioObject());
    SetAudioOutput(p_Track->GetAudioOutput());
}

//slots
void AudioPlayerWidget::PlayPauseButtonClickSlot()
{
    if(p_ConectedSongsList)
    {
        TrackButton* p_SelectedTrackButton = p_ConectedSongsList->GetSelectedTrack();         //get selected track from playlist
        Phonon::MediaObject *p_SelectedTrackObject = p_SelectedTrackButton->GetTrack()->GetAudioObject();
        if(p_AudioObject != p_SelectedTrackObject)      //if selected track is played
        {
            this->ConnectTrack(p_SelectedTrackButton->GetTrack());         //set media object and audiooutput of selected track for playing
            p_SelectedTrackButton->SetPlayStatus(true);

            if(TrackButton* p_PrevPlayTrackButton = p_ConectedSongsList->GetPlayTrack())   // if before there was track then played
            {
                p_PrevPlayTrackButton->SetPlayStatus(false);
            }

            p_ConectedSongsList->SetPlayTrackIndex(p_ConectedSongsList->GetTrackIndex(p_SelectedTrackObject)); //save playing track index
        }
    }

    //change the icon of play-pause button and change playing state of track
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
    p_PlayPauseButton->setIcon(QIcon(QPixmap(".\\play.png")));
}
void AudioPlayerWidget::PlaylistTrackClickSlot()
{
    TrackButton* p_SelectedTrackButton = p_ConectedSongsList->GetSelectedTrack();
    Phonon::MediaObject *p_SelectedTrackObject = p_SelectedTrackButton->GetTrack()->GetAudioObject();

    if(p_SelectedTrackObject == p_AudioObject && p_AudioObject->state() == Phonon::PlayingState)
    {
        p_PlayPauseButton->setIcon(QIcon(QPixmap(".\\pause.png")));
    }
    else
    {
        p_PlayPauseButton->setIcon(QIcon(QPixmap(".\\play.png")));
    }
}
void AudioPlayerWidget::PlayNextTrackSlot()
{
    if(p_ConectedSongsList)
    {
        p_AudioObject->stop();
        if(p_ReplayTrackButton->isChecked())   //if turn on replay track state
        {            
            p_AudioObject->play();
        }
        else
        {
            Phonon::State  currentPlayState = p_AudioObject->state();  //save current playing state of track

            //set false play status for previous track and stop them
            TrackButton* p_PrevPlayTrackButton = p_ConectedSongsList->GetPlayTrack();
            p_PrevPlayTrackButton->SetPlayStatus(false);

            //set next tack play status and play them
            TrackButton* p_NextTrackButton;
            if(p_RandomPlayButton->isChecked())
            {
                p_NextTrackButton = p_ConectedSongsList->GetNextPlayTrack(true);
            }
            else
            {
                p_NextTrackButton = p_ConectedSongsList->GetNextPlayTrack(false);
            }
            p_NextTrackButton->SetPlayStatus(true);
            Track* p_NextTrack = p_NextTrackButton->GetTrack();
            this->ConnectTrack(p_NextTrack);

            if(currentPlayState == Phonon::PlayingState)
            {
                p_AudioObject->play();
                p_PlayPauseButton->setIcon(QIcon(QPixmap(".\\pause.png")));
            }
            p_ConectedSongsList->SetPlayTrackIndex(p_ConectedSongsList->GetTrackIndex(p_NextTrack->GetAudioObject()));
        }
    }
    else
    {
        //plalist didnt conected
    }
}
void AudioPlayerWidget::PrevTracButtonClickSlot()
{
    if(p_ConectedSongsList)
    {
        p_AudioObject->stop();
        Phonon::State  currentPlayState = p_AudioObject->state();  //save current playing state of track
        //set false play status for previous track and stop them
        TrackButton* p_PrevTrackButton = p_ConectedSongsList->GetPlayTrack();
        p_PrevTrackButton->SetPlayStatus(false);

        int prevTrackIndex = p_ConectedSongsList->GetPlayTrackIndex(); //specifies the index of
        if(prevTrackIndex)   // set play index for back track on playlist
        {
            p_ConectedSongsList->SetPlayTrackIndex(prevTrackIndex-1);
        }
        else
        {
            p_ConectedSongsList->SetPlayTrackIndex(p_ConectedSongsList->GetTracksQuantity());
        }

        //set next tack play status and play them
        TrackButton* p_NextTrackButton = p_ConectedSongsList->GetPlayTrack();
        p_NextTrackButton->SetPlayStatus(true);
        Track* p_NextTrack = p_NextTrackButton->GetTrack();
        this->ConnectTrack(p_NextTrack);

        if(currentPlayState == Phonon::PlayingState)
        {
            p_AudioObject->play();
            p_PlayPauseButton->setIcon(QIcon(QPixmap(".\\pause.png")));
        }

        p_ConectedSongsList->SetPlayTrackIndex(p_ConectedSongsList->GetTrackIndex(p_NextTrack->GetAudioObject()));
    }
    else
    {
        //plalist didnt conected
    }
}
void AudioPlayerWidget::VolumButtonClickSlot()
{
    if(p_VolumeButton->isChecked())
    {
        p_RandomPlayButton->hide();
        p_ReplayTrackButton->hide();

        p_VolumeSliderWidget->show();
    }
    else
    {
        p_RandomPlayButton->show();
        p_ReplayTrackButton->show();

        p_VolumeSliderWidget->hide();
    }
}
void AudioPlayerWidget::SeekSliderButtonClickSlot()
{
    if(p_SeekSliderButton->isChecked())
    {        
        p_PlayPauseButton->hide();
        p_StopButton->hide();
        p_NextTrackButton->hide();
        p_PrevTrackButton->hide();
        p_VolumeButton->hide();

        if(p_VolumeButton->isChecked()) //hide volume widget
        {
            emit p_VolumeButton->click();
        }

        p_RandomPlayButton->hide();
        p_ReplayTrackButton->hide();

        p_SeekSliderWidget->show();
    }
    else
    {
        p_PlayPauseButton->show();
        p_StopButton->show();
        p_NextTrackButton->show();
        p_PrevTrackButton->show();
        p_RandomPlayButton->show();
        p_ReplayTrackButton->show();
        p_VolumeButton->show();

        p_SeekSliderWidget->hide();
    }
}
void AudioPlayerWidget::RandomPlayButtonClickeSlot()
{
    if(p_ReplayTrackButton->isChecked())
    {
        p_ReplayTrackButton->SetCheckedState(false);
    }
}
void AudioPlayerWidget::ReplayButtonClickSlot()
{
    if(p_RandomPlayButton->isChecked())
    {
        p_RandomPlayButton->SetCheckedState(false);
    }
}
