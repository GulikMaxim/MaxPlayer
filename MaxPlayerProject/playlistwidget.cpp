#include "playlistwidget.h"

PlaylistWidget::PlaylistWidget(QQueue<QUrl> songListUrls,QWidget *parent) : QScrollArea(parent)
{
    //widget setup
    this->setFixedSize(435,350);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);

    //song list widget setup
    p_TrackListWidget = new QWidget();
    p_TrackListWidget->setWindowFlags(Qt::FramelessWindowHint);

    OpenTracks(songListUrls);
    FillInTracksListWidget();

    this->setWidget(p_TrackListWidget);
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
        connect(p_TrackButton,SIGNAL(clicked()),SLOT(TrackButtonClickSlot()));
    }

    p_CurrentActiveTrack = tracksList[0];  // set first track current
    p_CurrentActiveTrack->SetActiveStatus(true);
}
Phonon::MediaObject* PlaylistWidget::GetCurrentActiveTrackMediaObject()
{
    return p_CurrentActiveTrack->GetTrackObject();
}
//slots
void PlaylistWidget::TrackButtonClickSlot()
{
    p_CurrentActiveTrack->SetActiveStatus(false);
    p_CurrentActiveTrack = (TrackButton*)sender();
    p_CurrentActiveTrack->SetActiveStatus(true);
}
