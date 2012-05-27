#ifndef EXPLORERWIDGET_H
#define EXPLORERWIDGET_H

/*! \class  ExplorerWidget
    \brief  Necessary for work with file explorer

    Include explorer field, buttons for adding or open tracks in playlist
  */

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
    QDirModel *p_DirModel;  /*!< data model of file explorer*/
    QTreeView *p_TreeView;  /*!< tree view of file explorer*/

    QList<QUrl> selectedSongs;  /*!< list of selected songs urls*/

    /*! \brief menu button

      Open or close menu
    */
    MyCheckableButton *p_ExplorerMenuButton;

    /*! \brief open songs button

      Creat new playlist with selected songs
    */
    PixmapButton *p_OpenSongsInPlaylistButton;

    /*! \brief add songs button

      Add selected songs in current playlist
    */
    PixmapButton *p_AddSongsInPlaylistButton;
public:

    /*! \brief Constructor
      \param parent parent widget
    */
    explicit ExplorerWidget(QWidget *parent = 0);

    /*! \brief Open menu
      \param openStatus menu state

      if state = true menu will have show state, else hide state
    */
    void OpenMenu(bool openStatus);

    /*! \brief for getting the list of selected songs

      \return list of selected songs
    */
    QList<QUrl> GetSelectedSongs();

    void ClearSelection(); /*!< clears the selection list*/

private:
    
signals:
    void OpenSongsInPlaylistSignal();   /*! calls when open songsbutton cliked */
    void AddSongsInPlaylistSignal();    /*! calls when add songs button cliked */
    
public slots:
    void ExplorerMenuButtonClickSlot(); /*!< opens menu*/
    void OpenSongsInPlaylistButtonClickSlot();  /*!< open songs in playlist*/
    void AddSongsInPlaylistButtonClickSlot();   /*!< add songs in playlist*/
    
};

#endif // EXPLORERWIDGET_H
