#ifndef SONGSLISTWIDGET_H
#define SONGSLISTWIDGET_H

#include <QWidget>
#include <QtGui>
#include <trackbutton.h>
#include <phonon>

class SongsListWidget : public QScrollArea
{
    Q_OBJECT

    QList<TrackButton*> trackButtonsList;
    QWidget *p_EmbeddableListSongWidget;     // embeddable widget in scroll area, which is SongsListWidget. It will include list of songs

    QList<int> selectedTracksIndexes;    //seleted tracks indexes for working with group of tracks
    int playTrackIndex;

    bool multiSelectedMode; // state of multi selected mode

public:
    explicit SongsListWidget(QList<QUrl> songListUrl, QWidget *parent = 0);
    explicit SongsListWidget(QWidget *parent);
    TrackButton* GetSelectedTrack();
    TrackButton* GetNextPlayTrack(bool randomGanneration = false);
    TrackButton* GetPlayTrack();
    int GetPlayTrackIndex();
    void SetPlayTrackIndex(int trackIndex);
    int GetTrackIndex(Phonon::MediaObject* p_PlayTrackObject);
    int GetTracksQuantity();
    bool IsMultiSelectedMode();
    void SetMultiSelectedMode(bool state);
    void SetFixedWidth(int width);    
    void OpenTracks(QList<QUrl> songsUrls);
    void Clear();
    bool isEmpty();

private:
    void FillInTracksListWidget();
    
signals:
    void TrackButtonClickSignal();
    void songListChangedSignal();
    
public slots:
    void TrackButtonClickSlot();
    void RemoveSelectedTracksSlot();
    void LeaveSelectedTracksSlot();
    
};

#endif // SONGSLISTWIDGET_H
