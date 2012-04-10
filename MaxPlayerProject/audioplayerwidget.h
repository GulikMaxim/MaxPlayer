#ifndef AudioPlayerWidget_H
#define AudioPlayerWidget_H

#include <QtGui>
#include <phonon>
#include <playlistwidget.h>

class AudioPlayerWidget : public QWidget
{
    Q_OBJECT

    Phonon::MediaObject *p_AudioObject;
    Phonon::AudioOutput *p_AudioOutput;
    PlaylistWidget *p_ConectedPlayList;       // playlist that is play in player

    Phonon::SeekSlider *p_SeekSlider;
    Phonon::VolumeSlider *p_VolumeSlider;
    QPushButton *p_PlayPauseButton;

    QGridLayout *p_playerLayout;

public:
    AudioPlayerWidget(QWidget *parent = 0);
    AudioPlayerWidget(QList<QUrl> songList, QWidget *parent = 0);
    void SetMediaObject(Phonon::MediaObject *p_CurrentMediaObject);
    void ConnectPlaylist(PlaylistWidget *p_Playlist);

private:
    void ControlElementsSetup();     //setup of buttons for playing, pause and stope music
    void AudioSetup();

signals:

public slots:
    void PlayPauseButtonClickSlot();
    
};

#endif // AudioPlayerWidget_H
