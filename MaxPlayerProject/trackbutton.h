#ifndef TRACKBUTTON_H
#define TRACKBUTTON_H

#include <QtGui>
#include <phonon>

class TrackButton : public QPushButton
{
    Q_OBJECT

    Phonon::MediaObject *p_AudioObject;

    bool isPlayStatus;
    bool isActiveStatus;

    QLabel *p_ArtistNameLabel;
    QLabel *p_TrackNameLabel;
    QLabel *p_ActiveStatusLineLabel;
    QLabel *p_PlayStatusTriangleLabel;

public:
    explicit TrackButton(QWidget *parent = 0);

    bool PlayStatus();
    void SetActiveStatus(bool isActive);
    void SetPlayStatus(bool isPlay);
    void OpenTrack(QUrl trackUrl);
    Phonon::MediaObject* GetTrackObject();
    bool IsActive();
    bool IsPlay();

private:

signals:

public slots:

};

#endif // TRACKBUTTON_H
