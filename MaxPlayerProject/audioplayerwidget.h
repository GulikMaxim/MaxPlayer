#ifndef AudioPlayerWidget_H
#define AudioPlayerWidget_H

#include <QtGui>
#include <phonon>
#include <playlistwidget.h>
#include <mycheckablebutton.h>
#include <window.h>
#include <titlewidget.h>
#include <track.h>
#include <pixmapbutton.h>

class AudioPlayerWidget : public QWidget
{
    Q_OBJECT

    Phonon::MediaObject *p_AudioObject;
    Phonon::AudioOutput *p_AudioOutput;
    SongsListWidget *p_ConectedSongsList;       // songs list that is play in player

    Phonon::SeekSlider *p_SeekSlider;
    Phonon::VolumeSlider *p_VolumeSlider;

    PixmapButton *p_PlayPauseButton;
    PixmapButton *p_StopButton;
    PixmapButton *p_NextTrackButton;
    PixmapButton *p_PrevTrackButton;
    MyCheckableButton *p_ReplayTrackButton;
    MyCheckableButton *p_RandomPlayButton;    
    MyCheckableButton *p_VolumeButton;
    MyCheckableButton *p_SeekSliderButton;

    TitleWidget *p_VolumeSliderWidget;
    TitleWidget *p_SeekSliderWidget;

public:
    AudioPlayerWidget(QWidget *parent = 0);
    AudioPlayerWidget(QList<QUrl> songList, QWidget *parent = 0);

    void SetMediaObject(Phonon::MediaObject *p_Object);
    void ConnectPlaylist(PlaylistWidget *p_Playlist);    //connect with playlistwidget object
    void SetAudioOutput(Phonon::AudioOutput *p_Output);
    void ConnectTrack(Track* p_Track);

private:
    void SeekSliderMediaObjectSet(Phonon::MediaObject *p_Object);   //connect seekslider object with audio object

signals:

public slots:
    void PlayPauseButtonClickSlot();
    void StopButtonSlot();
    void PlaylistTrackClickSlot();
    void PlayNextTrackSlot();
    void PrevTracButtonClickSlot();
    void VolumButtonClickSlot();
    void SeekSliderButtonClickSlot();
    void RandomPlayButtonClickeSlot();
    void ReplayButtonClickSlot();
    
};

#endif // AudioPlayerWidget_H
