#ifndef PLAYLISTBUTTON_H
#define PLAYLISTBUTTON_H

/*! \class  PlaylistButton
    \brief  Widget for working with one playlist

    View all infirmation about playlist. Can be active
*/


#include <QWidget>
#include <QtGui>
#include <playlist.h>

class PlaylistButton : public QPushButton
{
    Q_OBJECT

    Playlist *p_Playlist;   /*!< playlist objeck*/

    bool isActiveStatus;    /*!< active state of playlist */

    QLabel *p_NameLabel;    /*!< playlist name label*/
    QLabel *p_QuantityTracksLabel;  /*!< quantity of tracks label*/
    QLabel *p_CreationDateLabel;    /*!< creation date label*/
    QLabel *p_TitleQuntityLabel;

    QLabel *p_UnderlineQuntityLabel;
    QLabel *p_TitleCreationDateLabel;
    QLabel *p_UnderlineCreationDateLabel;
    QLabel *p_UnderlineNameLabel;
    QLabel *p_TitleNameLabel;

    QLabel *p_BackgroundLabel;  /*!< need for opportunity to set a frame on playlistButton */

    QLabel *p_ActiveStatusLineLabel;    /*!< line for view activ state*/
public:
    /*! \brief Constructor
      \param parent parent widget
    */
    explicit PlaylistButton(QWidget *parent = 0);
    
    /*! \brief sets activ status
      \param isActive active status
    */
    void SetActiveStatus(bool status);

    /*! \brief open playlist by url
      \param playlistUrl url of playlist
    */
    void OpenPlayList(QUrl playlistUrl);

    /*! \brief sets playlist information
      \param p_Playlist poimter on playlist object
    */
    void SetPlaylist(Playlist *p_Playlist);
    Playlist* GetPlaylist();    /*!< \return pointer on playlist object*/
    bool IsActive();    /*!< \return active status*/

signals:
    
public slots:
    
};

#endif // PLAYLISTBUTTON_H
