#ifndef PLAYLISTSLISTWIDGET_H
#define PLAYLISTSLISTWIDGET_H

#include <QWidget>
#include <QtGui>
#include <playlistbutton.h>

class PlaylistsListWidget : public QScrollArea
{
    Q_OBJECT

    QString playlistsDirrectoryPath;

    QList<PlaylistButton*> playlistButtonsList;
    QWidget *p_EmbeddablePlaylistListWidget;     // embeddable widget in scroll area, which is SongsListWidget. It will include list of songs

    QList<int> selectedPlaylistsIndexes;    //seleted playlists indexes for working with group of playlists

    bool multiSelectedMode; // state of multi selected mode

public:
    explicit PlaylistsListWidget(QWidget *parent = 0);

    bool IsMultiSelectedMode();
    void SetMultiSelectedMode(bool state);
    void SetFixedWidth(int width);
    void ReadPlaylistsFrom(QString path);
    bool isEmpty();
    int GetPlaylistIndex(Playlist *p_Playlist);
    void Clear();
    void SetPlaylistDirrectoryPath(QString path);
    QString GetPlaylistDirrectoryPath();

private:
    void FillInPlaylistsListWidget();
    
signals:
    void PlaylistChangedSignal();
    
public slots:
    void RemoveSelectedPlaylistsSlot();

private slots:
    void PlaylistButtonClickSlot();
    
};

#endif // PLAYLISTSLISTWIDGET_H
