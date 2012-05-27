#ifndef LIBRARYWIDGET_H
#define LIBRARYWIDGET_H


/*! \class  LibraryWidget
    \brief  Necessary to wark with playlists

    Include explorer field, buttons for delete or save playlist
  */

#include <QtGui>
#include <playlistslistwidget.h>
#include <titlewidget.h>
#include <mycheckablebutton.h>
#include <pixmapbutton.h>
#include <enterlinedialogwindow.h>

class LibraryWidget : public TitleWidget
{
    Q_OBJECT

    PlaylistsListWidget* p_PlaylistsList; /*!< widget for view list of playlists*/

    PixmapButton *p_SavePlaylistButton; /*!< button for playlist save*/
    MyCheckableButton* p_LibraryMenuButton; /*!< library menu button */
    QCheckBox* p_MultiSellectionCheckBox;   /*!< for establishes multiply state*/

    PixmapButton* p_DeletePlaylistsButton;  /*!< button for deleting playlists*/

    /*! \brief dialog window for playlist name input

      Needs while save a playlist
    */
    EnterLineDialogWindow *p_EnterNameDialogWindow;

public:
    /*! \brief Constructor
      \param parent parent widget
    */
    explicit LibraryWidget(QWidget *parent = 0);

    /*! \brief Open menu
      \param openStatus menu state

      if state = true menu will have show state, else hide state
    */
    void OpenMenu(bool openStatus);

    /*! \brief Open playlists
      \param songsUrls urls of saved playlist

      Creats playlists list and opens saved playlists by urls
    */
    void OpenPlaylists(QList<QUrl> songsUrls);    
    void Clear();   /*!< clearsplaylists list*/

    /*! \brief for getting playlists list

      \return list of playlists
    */
    PlaylistsListWidget* GetPlaylistsListWidget();

signals:    
    void SavePlaylistButtonClickedSignal(QString playlistName); /*!< calls when playlist saved*/
    void DialogWindowShowSignal(bool showState);    /*!< calls when dialog window for save name was showed*/
    
public slots:

private slots:
    void LibraryMenuButtonClickSlot();  /*!< opens menu*/
    void MultiSellectionCheckBoxChangeSlot();   /*!< turn on or turn off multi selection mode*/
    void PlaylistsListChangedSlot();   /*!< change backgroung if playlists list is empty */
    void SavePlaylistButtonClickedSlot();   /*!< save playlist*/
    void CheckingPlaylistNameSlot(QString playlistName);    /*!< cheking saved playlist name to the presents to the list*/
    
};

#endif // LIBRARYWIDGET_H
