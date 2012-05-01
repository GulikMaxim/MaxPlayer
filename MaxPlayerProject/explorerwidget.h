#ifndef EXPLORERWIDGET_H
#define EXPLORERWIDGET_H

#include <QWidget>
#include <qfiledialog.h>
#include <window.h>
#include <mycheckablebutton.h>
#include <titlewidget.h>
#include <pixmapbutton.h>

class ExplorerWidget : public TitleWidget
{
    Q_OBJECT
private:
    QDirModel *p_DirModel;
    QTreeView *p_TreeView;

    QList<QUrl> selectedSongs;

    MyCheckableButton *p_ExplorerMenuButton;
    PixmapButton *p_AddSongsInPlaylistButton;
public:
    explicit ExplorerWidget(QWidget *parent = 0);

    void OpenMenu(bool openStatus);
    QList<QUrl> GetSelectedSongs();
    void ClearSelection();
    
signals:
    void AddSongsInPlaylistSignal();
    
public slots:
    void ExplorerMenuButtonClickSlot();
    //void ElementClickedSlot(QModelIndex index);
    void AddSongsInPlaylistButtonClickSlot();
    
};

#endif // EXPLORERWIDGET_H
