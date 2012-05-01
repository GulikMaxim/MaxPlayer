#ifndef PLAYLISTWIDGET_H
#define PLAYLISTWIDGET_H

#include <QWidget>
#include <QtGui>
#include <SongsListWidget.h>
#include <mycheckablebutton.h>
#include <titlewidget.h>
#include <pixmapbutton.h>

class PlaylistWidget : public TitleWidget
{
    Q_OBJECT

private:
    SongsListWidget *p_SongList;


    PixmapButton *p_DeleteTracksButton;
    PixmapButton *p_SavePlaylistButton;
    PixmapButton *p_LeaveTracksButton;
    QCheckBox *p_MultiSellectionCheckBox;
    MyCheckableButton* p_PlayListMenuButton;

public:
    explicit PlaylistWidget(QWidget *parent = 0);

    SongsListWidget* GetSongsList();
    void OpenMenu(bool openStatus);
    void OpenTracks(QList<QUrl> songsUrls);
    
signals:

public slots:
    void PlaylistMenuButtonClickSlot();
    void MultiSellectionCheckBoxChangeSlot();
    void Clear();

private slots:
    void SongListChangedSlot();

    
};

#endif // PLAYLISTWIDGET_H
