#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

#include <QObject>
#include <QtGui>
#include <phonon>

class AudioPlayer : public QWidget
{
    Q_OBJECT

    Phonon::MediaObject *p_AudioObject;
    Phonon::AudioOutput *p_AudioOutput;
    Phonon::SeekSlider *p_SeekSlider;
    Phonon::VolumeSlider *p_VolumeSlider;
    QGridLayout *p_playerLayout;

    QPushButton *p_PlayPauseButton;

public:
    AudioPlayer(QWidget *parent = 0);
    AudioPlayer(QList<QUrl> songList, QWidget *parent = 0);
    QGridLayout* getLayout();
    void setSongsList(QList<QUrl> songList);


private:
    void ControlElementsSetup();     //setup of buttons for playing, pause and stope music
    void AudioSetup();


signals:

public slots:
    void PlayPauseSlot();
    
};

#endif // AUDIOPLAYER_H
