#ifndef TRACKBUTTON_H
#define TRACKBUTTON_H

#include <QtGui>
#include <track.h>

class TrackButton : public QPushButton
{
    Q_OBJECT

    Track *p_Track;

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
    Track* GetTrack();
    bool IsActive();
    bool IsPlay();

private:

signals:

public slots:

};

#endif // TRACKBUTTON_H
