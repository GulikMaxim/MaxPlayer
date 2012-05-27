#ifndef PLAYLISTWIDGET_H
#define PLAYLISTWIDGET_H

#include <QWidget>
#include <QtGui>
#include <SongsListWidget.h>
#include <mycheckablebutton.h>
#include <titlewidget.h>
#include <pixmapbutton.h>
#include <playlist.h>

class PlaylistWidget : public TitleWidget
{
    Q_OBJECT

private:
    SongsListWidget *p_SongList;

    PixmapButton *p_DeleteTracksButton;
    PixmapButton *p_LeaveTracksButton;
    QCheckBox *p_MultiSellectionCheckBox;
    MyCheckableButton* p_PlayListMenuButton;

public:
    explicit PlaylistWidget(QWidget *parent = 0);

    SongsListWidget* GetSongsList();
    void OpenMenu(bool openStatus);
    
signals:

public slots:
    void PlaylistMenuButtonClickSlot();
    void MultiSellectionCheckBoxChangeSlot();
    void Clear();

private slots:
    void SongListChangedSlot();

    
};

#endif // PLAYLISTWIDGET_H
