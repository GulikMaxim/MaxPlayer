#ifndef AudioPlayerWidget_H
#define AudioPlayerWidget_H

#include <QtGui>
#include <phonon>
#include <playlistwidget.h>
#include <mycheckablebutton.h>

class AudioPlayerWidget : public QWidget
{
    Q_OBJECT

    Phonon::MediaObject *p_AudioObject;
    Phonon::AudioOutput *p_AudioOutput;
    PlaylistWidget *p_ConectedPlayList;       // playlist that is play in player

    Phonon::SeekSlider *p_SeekSlider;
    Phonon::VolumeSlider *p_VolumeSlider;

    QPushButton *p_PlayPauseButton;
    QPushButton *p_StopButton;
    QPushButton *p_NextTrackButton;
    QPushButton *p_PrevTrackButton;    
    MyCheckableButton *p_ReplayTrackButton;
    MyCheckableButton *p_RandomPlayButton;
    MyCheckableButton *p_VolumeButton;

    QGridLayout *p_playerLayout;

public:
    AudioPlayerWidget(QWidget *parent = 0);
    AudioPlayerWidget(QList<QUrl> songList, QWidget *parent = 0);

    void SetMediaObject(Phonon::MediaObject *p_CurrentMediaObject);
    void ConnectPlaylist(PlaylistWidget *p_Playlist);    //connect with playlistwidget object

private:
    void SeekSliderMediaObjectSet();   //connect seekslider object with audio object
    //void SetCurrentActivePlaylistTrack();   //get selected object from playlist

signals:

public slots:
    void PlayPauseButtonClickSlot();
    void StopButtonSlot();
    void PlaylistTrackClickSlot();
    void TrackFinishedSlot();
    void NextTrackButtonClickSlot();
    void PrevTracButtonClickSlot();
    void VolumButtonClickSlot();
    
};

#endif // AudioPlayerWidget_H
