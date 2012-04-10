#ifndef PLAYLISTWIDGET_H
#define PLAYLISTWIDGET_H

#include <QWidget>
#include <QtGui>
#include <trackbutton.h>

class PlaylistWidget : public QScrollArea
{
    Q_OBJECT

    QWidget *p_TrackListWidget;     //for distlay list of track buttons
    QQueue <TrackButton*> tracksList;           // queue of mediaobjects for opening songs by urls
    TrackButton *p_CurrentActiveTrack;

public:
    explicit PlaylistWidget(QQueue<QUrl> songListUrl, QWidget *parent = 0);
    void FillInTracksListWidget();
    void OpenTracks(QQueue<QUrl> songsUrls);
    Phonon::MediaObject* GetCurrentActiveTrackMediaObject();
    
signals:
    
public slots:
    void TrackButtonClickSlot();
    
};

#endif // PLAYLISTWIDGET_H
