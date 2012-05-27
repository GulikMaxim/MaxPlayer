#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/*! \class MainWindow
    \brief main window of MaxPlayer

    Includes all widgets which necessary for work with player
*/

#include <QtGui>
#include <phonon>
#include <window.h>
#include <audioplayerwidget.h>
#include <playlistwidget.h>
#include <explorerwidget.h>
#include <aboutwidget.h>
#include <librarywidget.h>

class MainWindow : public Window
{
    Q_OBJECT

    QStackedWidget *p_ShiftingFieldWidgets; /*!< stack of widgets that shows at shifting field*/

    PlaylistWidget *p_PlaylistWidget;   /*!< playlist for work with current playlist*/
    ExplorerWidget *p_ExplorerWidget;   /*!< widget for work with filr system*/
    AboutWidget *p_AboutWidget;       /*!< widget for shaw about information*/
    LibraryWidget *p_LibraryWidget;     /*!< widget for work with saved playlists*/

    AudioPlayerWidget *p_AudioPlayerWidget; /*!< player widget */

    QPalette *p_MainPalette;    /*!< palette of program*/

    QPushButton *p_PlaylistButton;  /*!< button for open current playlist */
    QPushButton *p_LibraryButton;   /*!< button for open library of playlists */
    QPushButton *p_ExplorerButton;  /*!< button for open file explorer */
    QPushButton *p_AboutButton;     /*!< button for open about window */

public:
    /*! \brief Constructor
      \param parent parent widget
    */
    explicit MainWindow(QWidget *parent = 0);

     /*! \brief sets button text color
         \param p_Button pointer on button object
         \param color setting text color
     */
    void SetButtonTextColor(QPushButton* p_Button, const QColor & color);
    
signals:
    
private slots:
    void PlaylistButtonClickedSlot();   /*!< sets current the playlist widget*/
    void LibraryButtonClickedSlot();    /*!< sets current the library widget*/
    void ExplorerButtonClickedSlot();   /*!< sets current the explorer widget*/
    void AboutButtonClickedSlot();  /*!< sets current the about widget*/
    void AddSongsInPlaylistSlot();  /*!< add selected tracks in playlist and clear selection in file explorer*/
    void OpenSongsInPlaylistSlot(); /*!< open selected tracks in playlist and clear selection in file explorer*/

    /*! \brief open playlist
        \param p_Playlist pointer on opened playlist
    */
    void OpenPlaylistSlot(Playlist* p_Playlist);

    /*! \brief save current playlist
        \param playlistName name of saved playlist
    */
    void SavePlaylistSlot(QString playlistName);
    void SetEnabled();  /*!< sets mane window is anable*/
};

#endif // MAINWINDOW_H
