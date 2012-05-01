#ifndef PLAYLISTBUTTON_H
#define PLAYLISTBUTTON_H

#include <QWidget>
#include <QtGui>
#include <playlist.h>

class PlaylistButton : public QPushButton
{
    Q_OBJECT

    Playlist *p_Playlist;

    bool isActiveStatus;

    QLabel *p_NameLabel;
    QLabel *p_QuantityTracksLabel;
    QLabel *p_CreationDateLabel;
    QLabel *p_TitleQuntityLabel;

    QLabel *p_UnderlineQuntityLabel;
    QLabel *p_TitleCreationDateLabel;
    QLabel *p_UnderlineCreationDateLabel;
    QLabel *p_UnderlineNameLabel;
    QLabel *p_TitleNameLabel;

    QLabel *p_BackgroundLabel;          //need for opportunity to set a frame on playlistButton

    QLabel *p_ActiveStatusLineLabel;

public:
    explicit PlaylistButton(QWidget *parent = 0);
    
    void SetActiveStatus(bool status);
    void OpenPlayList(QUrl playlistUrl);
    void SetPlaylist(Playlist *p_Playlist);
    Playlist* GetPlaylist();
    bool IsActive();

signals:
    
public slots:
    
};

#endif // PLAYLISTBUTTON_H
