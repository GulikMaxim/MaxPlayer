#include "playlistwidget.h"

PlaylistWidget::PlaylistWidget(QQueue<QUrl> songListUrls,QWidget *parent) : QScrollArea(parent)
{
    //widget setup
    this->setFixedSize(430,520);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
    QPalette *p_PlaylistPalette = new QPalette(Qt::cyan,Qt::black);               // set font's and backgrod colors
    p_PlaylistPalette->setBrush(this->backgroundRole(),QBrush(QPixmap("shifftingWidgetBackgraund.jpg")));
    this->setAutoFillBackground(true);
    this->setPalette(*p_PlaylistPalette);

    OpenTracks(songListUrls);
    FillInTracksListWidget();
    playTrackIndex = -1;     // no one track didnt play
}
//methods
void PlaylistWidget::FillInTracksListWidget()
{
   QPoint trackPosition(3,1);
   foreach(TrackButton* p_TrackButton, tracksList)
   {
       p_TrackButton->setParent(this);
       p_TrackButton->move(trackPosition);
       trackPosition.setY(trackPosition.y()+ 50);
   }
}
void PlaylistWidget::OpenTracks(QQueue<QUrl> songsUrls)
{
    foreach(QUrl songUrl, songsUrls)
    {
        TrackButton *p_TrackButton = new TrackButton();
        p_TrackButton->OpenTrack(songUrl);
        tracksList<<p_TrackButton;
        connect(p_TrackButton->GetTrackObject(),SIGNAL(finished()),SIGNAL(trackFinishedSignal));
        connect(p_TrackButton,SIGNAL(clicked()),SLOT(TrackButtonClickSlot()));
    }

    activTrackIndex = 0; // set first track in list current
    tracksList[0]->SetActiveStatus(true);
}
TrackButton* PlaylistWidget::GetActiveTrack()
{
    return tracksList[activTrackIndex];
}
TrackButton* PlaylistWidget::GetNextPlayTrack(bool randomGanneration)
{
    TrackButton* p_NextTrack;
    int lastIndex = tracksList.size()-1 ;
    if(!randomGanneration)
    {
        if(playTrackIndex!=lastIndex)
        {
            playTrackIndex++;
        }
        else
        {
            playTrackIndex=0;
        }
    }
    else
    {
        //random generation
    }
    p_NextTrack = tracksList[playTrackIndex];
    return p_NextTrack;
}
int PlaylistWidget::GetTracksQuantity()
{
    return tracksList.size()-1;
}
TrackButton* PlaylistWidget::GetPlayTrack()
{
    if(playTrackIndex != -1)    //  if player play not first track
    {
        return tracksList[playTrackIndex];
    }
    else
    {
        return NULL;
    }
}
int PlaylistWidget::GetTrackIndex(Phonon::MediaObject* p_PlayTrackObject)
{
    int currentPlayTrackIndex=0;
    foreach(TrackButton* p_Track,tracksList)
    {
        if(p_Track->GetTrackObject() == p_PlayTrackObject)
            break;
        currentPlayTrackIndex++;
    }
    return currentPlayTrackIndex;
}
int PlaylistWidget::GetPlayTrackIndex()
{
    return playTrackIndex;
}
void PlaylistWidget::SetPlayTrackIndex(int trackIndex)
{
    playTrackIndex = trackIndex;
}
//slots
void PlaylistWidget::TrackButtonClickSlot()
{
    TrackButton* p_PreviousActiveTrack = this->GetActiveTrack();    
    TrackButton* p_ClickedTrackButton = (TrackButton*)sender();
    p_PreviousActiveTrack->SetActiveStatus(false);
    p_ClickedTrackButton->SetActiveStatus(true);
    activTrackIndex = this->GetTrackIndex(p_ClickedTrackButton->GetTrackObject());

    emit TrackButtonClickSignal();
}
