#include "SongsListWidget.h"

SongsListWidget::SongsListWidget(QWidget *parent) : QScrollArea(parent)
{
    //widget setup
    this->setFixedSize(416,524);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setFrameStyle(QFrame::Box | QFrame::Raised);

    //embeddable widget setup
    p_EmbeddableListSongWidget = new QWidget();
    p_EmbeddableListSongWidget->setFixedSize(414,522);
    this->setWidget(p_EmbeddableListSongWidget);

    playTrackIndex = -1;     // no one track didnt play
    SetMultiSelectedMode(false);
}
SongsListWidget::SongsListWidget(QList<QUrl> songListUrls,QWidget *parent) : QScrollArea(parent)
{
    //widget setup
    this->setFixedSize(416,524);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setFrameStyle(QFrame::Box | QFrame::Raised);

    //embeddable widget setup
    p_EmbeddableListSongWidget = new QWidget();
    p_EmbeddableListSongWidget->setFixedSize(414,522);
    this->setWidget(p_EmbeddableListSongWidget);

    OpenTracks(songListUrls);
    playTrackIndex = -1;     // no one track didnt play

    SetMultiSelectedMode(false);
}
//methods
bool SongsListWidget::isEmpty()
{
    if(trackButtonsList.size())
    {
        return false;
    }
    else
    {
        return true;
    }
}
void SongsListWidget::Clear()
{
    foreach(TrackButton *p_RemoveTrackButton,trackButtonsList)
    {
        delete p_RemoveTrackButton;
    }
    trackButtonsList.clear();

    emit songListChangedSignal();
}
void SongsListWidget::FillInTracksListWidget()
{
    p_EmbeddableListSongWidget->setFixedHeight(522);
    if(!this->isEmpty())
    {
        QPoint trackPosition(3,1);    //first track position in start filling
        foreach(TrackButton* p_TrackButton, trackButtonsList)
        {
            p_TrackButton->setParent(p_EmbeddableListSongWidget);
            p_TrackButton->move(trackPosition);
            trackPosition.setY(trackPosition.y()+ 50);
            if(trackPosition.y()>p_EmbeddableListSongWidget->height())
            {
                p_EmbeddableListSongWidget->setFixedHeight(trackPosition.y());
            }
        }
    }
}
void SongsListWidget::OpenTracks(QList<QUrl> songsUrls)
{    
    if(songsUrls.size())
    {
        foreach(QUrl songUrl, songsUrls)
        {
            TrackButton *p_TrackButton = new TrackButton();
            p_TrackButton->OpenTrack(songUrl);
            trackButtonsList<<p_TrackButton;
            connect(p_TrackButton,SIGNAL(clicked()),SLOT(TrackButtonClickSlot()));
        }
        FillInTracksListWidget();

        selectedTracksIndexes<<0; // set first track in list current
        trackButtonsList[0]->SetActiveStatus(true);
    }

    emit songListChangedSignal();
}
TrackButton* SongsListWidget::GetSelectedTrack()
{
    return trackButtonsList[selectedTracksIndexes[0]];   //selected track indexes[0] - selected track without multiselected mode
}
TrackButton* SongsListWidget::GetNextPlayTrack(bool randomGanneration)
{
    TrackButton* p_NextTrack;
    int lastIndex = trackButtonsList.size()-1 ;
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
        if(lastIndex)  //more then one track
        {
            qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
            playTrackIndex= qrand()%(lastIndex+1);
            playTrackIndex--;  //in order to obtain a 0 index in the generation of random numbers
        }
    }
    p_NextTrack = trackButtonsList[playTrackIndex];
    return p_NextTrack;
}
int SongsListWidget::GetTracksQuantity()
{
    return trackButtonsList.size()-1;
}
TrackButton* SongsListWidget::GetPlayTrack()
{
    if(playTrackIndex != -1)    //  if player play not first track
    {
        return trackButtonsList[playTrackIndex];
    }
    else
    {
        return NULL;
    }
}
int SongsListWidget::GetTrackIndex(Phonon::MediaObject* p_PlayTrackObject)
{
    int currentPlayTrackIndex=0;
    foreach(TrackButton* p_TrackButton,trackButtonsList)
    {
        if(p_TrackButton->GetTrack()->GetAudioObject() == p_PlayTrackObject)
            break;
        currentPlayTrackIndex++;
    }
    return currentPlayTrackIndex;
}
int SongsListWidget::GetPlayTrackIndex()
{
    return playTrackIndex;
}
void SongsListWidget::SetPlayTrackIndex(int trackIndex)
{
    playTrackIndex = trackIndex;
}
void SongsListWidget::SetFixedWidth(int width)
{
    this->setFixedWidth(width);
    p_EmbeddableListSongWidget->setFixedWidth(width-2);
}
bool SongsListWidget::IsMultiSelectedMode()
{
    return multiSelectedMode;
}
void SongsListWidget::SetMultiSelectedMode(bool state)
{
    multiSelectedMode = state;
    if(selectedTracksIndexes.size())
    {
        if(!state)
        {
            foreach(int selectedTrackIndex, selectedTracksIndexes)
            {
                trackButtonsList[selectedTrackIndex]->SetActiveStatus(false);
            }
            selectedTracksIndexes.clear();

            selectedTracksIndexes<<0;   // set select track on first track
            trackButtonsList[0]->SetActiveStatus(true);
        }
    }
}
QList<TrackButton*> SongsListWidget::GetTrackButtonsList()
{
    return trackButtonsList;
}
//slots
void SongsListWidget::TrackButtonClickSlot()
{
    TrackButton* p_ClickedTrackButton = (TrackButton*)sender();
    if(this->IsMultiSelectedMode())
    {
        Track* p_Tr = p_ClickedTrackButton->GetTrack();
        Phonon::MediaObject* md =  p_Tr->GetAudioObject();
        int selectedTrackIndex = this->GetTrackIndex(md);
        if(p_ClickedTrackButton->IsActive())
        {
            if(selectedTracksIndexes.size() != 1)   //minimum one track must be selected forever
            {
                selectedTracksIndexes.removeOne(selectedTrackIndex);
                p_ClickedTrackButton->SetActiveStatus(false);
            }
        }
        else
        {
            selectedTracksIndexes<<selectedTrackIndex;
            p_ClickedTrackButton->SetActiveStatus(true);
        }
    }
    else
    {

        TrackButton* p_PreviousActiveTrack = this->GetSelectedTrack();
        p_PreviousActiveTrack->SetActiveStatus(false);
        p_ClickedTrackButton->SetActiveStatus(true);
        selectedTracksIndexes[0] = this->GetTrackIndex(p_ClickedTrackButton->GetTrack()->GetAudioObject());
        emit TrackButtonClickSignal();
    }
}
void SongsListWidget::RemoveSelectedTracksSlot()
{
    TrackButton* p_playTrackButton = NULL;
    if(playTrackIndex!= -1)    // if least one track is playing
    {
        p_playTrackButton = trackButtonsList[playTrackIndex];
    }

    //remove tracks
    foreach(int removedTrackIndex,selectedTracksIndexes)
    {
        TrackButton* p_RemoveTrackButton = trackButtonsList[removedTrackIndex];
        trackButtonsList[removedTrackIndex] = NULL;
        delete p_RemoveTrackButton;
    }
    trackButtonsList.removeAll(NULL);
    selectedTracksIndexes.clear();

    //refresh playlistwidget
    FillInTracksListWidget();
    if(!this->isEmpty())
    {
        if(p_playTrackButton)  // if found track, that played before remove
        {
            playTrackIndex = trackButtonsList.indexOf(p_playTrackButton);
        }
        if(playTrackIndex != -1)  // if play track didn't remove
        {
            trackButtonsList[playTrackIndex]->SetPlayStatus(true);
        }
        selectedTracksIndexes<<0;   // set select track on first
        trackButtonsList[0]->SetActiveStatus(true);
    }

    emit songListChangedSignal();
}
void SongsListWidget::LeaveSelectedTracksSlot()
{
    TrackButton* p_playTrackButton = NULL;
    if(playTrackIndex!= -1)    // if least one track is playing
    {
        p_playTrackButton = trackButtonsList[playTrackIndex];
    }
    //define the indexes of non-selected tracks
    qSort(selectedTracksIndexes);  //sort an astending order
    QList<int> notSelectedTracksIndexes;
    int selectedTrakIndex,notSelectedTrackIndex;
    for(selectedTrakIndex = 0,notSelectedTrackIndex = 0 ; notSelectedTrackIndex<trackButtonsList.size();notSelectedTrackIndex++)
    {
        if(selectedTrakIndex<(selectedTracksIndexes.size()))
        {
            if(notSelectedTrackIndex<selectedTracksIndexes[selectedTrakIndex])
            {
                notSelectedTracksIndexes<<notSelectedTrackIndex;
            }
            else
            {
                selectedTrakIndex++;
            }
        }
        else
        {
            notSelectedTracksIndexes<<notSelectedTrackIndex;
        }
    }
    // set no active status on selected tracks
    foreach(int selectedTrackIndex,selectedTracksIndexes)
    {
        TrackButton* p_selectedTrackButton = trackButtonsList[selectedTrackIndex];
        p_selectedTrackButton->SetActiveStatus(false);
    }

    //remove tracks
    foreach(int removedTrackIndex,notSelectedTracksIndexes)
    {
        TrackButton* p_RemoveTrackButton = trackButtonsList[removedTrackIndex];
        trackButtonsList[removedTrackIndex] = NULL;
        delete p_RemoveTrackButton;
    }
    trackButtonsList.removeAll(NULL);
    selectedTracksIndexes.clear();

    //refresh playlistwidget
    FillInTracksListWidget();
    if(p_playTrackButton)  // if found track, that played before remove
    {
        playTrackIndex = trackButtonsList.indexOf(p_playTrackButton);
    }
    if(playTrackIndex != -1)  // if play track didn't remove
    {
        trackButtonsList[playTrackIndex]->SetPlayStatus(true);
    }
    selectedTracksIndexes<<0;   // set select track on first
    trackButtonsList[0]->SetActiveStatus(true);
}
