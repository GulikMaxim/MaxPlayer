#ifndef LIBRARYWIDGET_H
#define LIBRARYWIDGET_H

#include <QtGui>
#include <playlistslistwidget.h>
#include <titlewidget.h>
#include <mycheckablebutton.h>
#include <pixmapbutton.h>

class LibraryWidget : public TitleWidget
{
    Q_OBJECT

public:
    explicit LibraryWidget(QWidget *parent = 0);

    PlaylistsListWidget* p_PlaylistsList;

    MyCheckableButton* p_LibraryMenuButton;
    QCheckBox* p_MultiSellectionCheckBox;

    PixmapButton* p_DeletePlaylistsButton;

    //methods
    PlaylistsListWidget* GetPlaylistsList();
    void OpenMenu(bool openStatus);
    void OpenPlaylists(QList<QUrl> songsUrls);
    void Clear();
    
signals:
    
public slots:

private slots:
    void LibraryMenuButtonClickSlot();
    void MultiSellectionCheckBoxChangeSlot();
    void PlaylistsListChangedSlot();
    
};

#endif // LIBRARYWIDGET_H
