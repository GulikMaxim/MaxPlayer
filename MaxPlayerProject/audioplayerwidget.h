#ifndef AudioPlayerWidget_H
#define AudioPlayerWidget_H

/*! \class AudioPlayerWidget
  \brief Widget for playing one track

    Need for manage the audio track. Include stop, play, pause, switch to another track buttons;
    random and loop playback tracks buttons; display seek slider and volume slider buttons;
    Also include such widgets, us seek slider to display and edit play status,
    and volume slader to display and edit volume status.
    It can connected the PlaylistWidget for playing the list of tracks.
  */

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

    Phonon::MediaObject *p_AudioObject; /*!< play track audio object*/
    Phonon::AudioOutput *p_AudioOutput; /*!< play track audio output*/
    SongsListWidget *p_ConectedSongsList;   /*!< songs list that is play in player*/

    Phonon::SeekSlider *p_SeekSlider;   /*!<  seek slider to displaying and editing track play status */
    Phonon::VolumeSlider *p_VolumeSlider; /*!<  volume slader for display and editing audio output volume status */

    PixmapButton *p_PlayPauseButton; /*!< button to play track*/
    PixmapButton *p_StopButton; /*!< button to stop track*/
    PixmapButton *p_NextTrackButton;    /*!< button to switch another track from the conneted playlist*/
    PixmapButton *p_PrevTrackButton;    /*!< button to switch previous track from the conneted playlist */
    MyCheckableButton *p_ReplayTrackButton; /*!< button to set the loop playback*/
    MyCheckableButton *p_RandomPlayButton;  /*!< button to set random playback*/
    MyCheckableButton *p_VolumeButton;  /*!< button to display or hide volume slider widget*/
    MyCheckableButton *p_SeekSliderButton; /*!< button to display or hide  play status seek slider widget*/

    TitleWidget *p_VolumeSliderWidget; /*!< display play track stus*/
    TitleWidget *p_SeekSliderWidget;   /*!< display volume status*/

public:
    /*! \brief Constructor
        \param parent parent widget
      */
    AudioPlayerWidget(QWidget *parent = 0);

    /*! \brief connecting widget with playlist widget
        \param p_Object set by the object pointer

        connecting widget with playlist widget for play list of tracks
    */
    void ConnectPlaylist(PlaylistWidget *p_Playlist);

    /*! \brief connect track with player widget
        \param p_Track conect track pointer
    */
    void ConnectTrack(Track* p_Track);

private:    
    void SetAudioOutput(Phonon::AudioOutput *p_Output);
    void SetMediaObject(Phonon::MediaObject *p_Object);
    void SeekSliderMediaObjectSet(Phonon::MediaObject *p_Object);   //connect seekslider object with audio object

signals:

public slots:
    void PlayPauseButtonClickSlot();    /*!< sets play or pause track state */
    void StopButtonSlot();  /*!< sets stop track */
    void PlaylistTrackClickSlot();  /*!< gets selected track from playlist */
    void PlayNextTrackSlot();   /*!< sets next track from playlist in player */
    void PrevTracButtonClickSlot(); /*!< sets previous play track from playlist in player */
    void VolumButtonClickSlot();    /*!< display or hide volum slider widget */
    void SeekSliderButtonClickSlot();   /*!< display or hide track seek slider widget*/
    void RandomPlayButtonClickeSlot();  /*!< turn on or turn off random playback*/
    void ReplayButtonClickSlot();   /*!< turn on or turn off loop playback*/
    
};

#endif // AudioPlayerWidget_H
