#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include <phonon>

class MainWindow : public QWidget
{
    Q_OBJECT

    Phonon::MediaObject *p_AudioObject;
    Phonon::AudioOutput *p_AudioOutput;
    Phonon::SeekSlider *p_SeekSlider;
    Phonon::VolumeSlider *p_VolumeSlider;
    QGridLayout playerLayout;

    QPushButton *p_PlayPauseButton;

public:
    explicit MainWindow(QWidget *parent = 0);


private:
    void ControlElementsSetup();     //setup of buttons for playing, pause and stope music
    void AudioSetup();
    
signals:
    
public slots:
    void PlayPauseSlot();
};

#endif // MAINWINDOW_H
