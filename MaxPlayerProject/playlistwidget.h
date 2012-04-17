#ifndef PLAYLISTWIDGET_H
#define PLAYLISTWIDGET_H

#include <QWidget>
#include <QtGui>
#include <trackbutton.h>
#include <phonon>

class PlaylistWidget : public QScrollArea
{
    Q_OBJECT

    QQueue <TrackButton*> tracksList;           // queue of mediaobjects for opening songs by urls
    //TrackButton *p_CurrentActiveTrack;
    int activTrackIndex;
    int playTrackIndex;

public:
    explicit PlaylistWidget(QQueue<QUrl> songListUrl, QWidget *parent = 0);
    void FillInTracksListWidget();
    void OpenTracks(QQueue<QUrl> songsUrls);
    TrackButton* GetActiveTrack();
    TrackButton* GetNextPlayTrack(bool randomGanneration = false);

    TrackButton* GetPlayTrack();
    int GetPlayTrackIndex();
    void SetPlayTrackIndex(int trackIndex);
    int GetTrackIndex(Phonon::MediaObject* p_PlayTrackObject);
    int GetTracksQuantity();
    
signals:
    void TrackButtonClickSignal();
    void trackFinishedSignal();
    
public slots:
    void TrackButtonClickSlot();
    
};

#endif // PLAYLISTWIDGET_H
