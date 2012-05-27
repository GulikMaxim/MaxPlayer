#ifndef PLAYLISTSLISTWIDGET_H
#define PLAYLISTSLISTWIDGET_H

/*! \class  PlaylistsListWidget
    \brief  Widget for view all playlist
*/

#include <QWidget>
#include <QtGui>
#include <playlistbutton.h>
#include <playlist.h>

class PlaylistsListWidget : public QScrollArea
{
    Q_OBJECT

    QString playlistsDirrectoryPath;  /*!< path for opening playlists */

    QList<PlaylistButton*> playlistButtonsList; /*!< list of playlists buttons*/
    QWidget *p_EmbeddablePlaylistListWidget;     /*!< embeddable widget in scroll area, which is SongsListWidget. It will include list of songs */

    QList<int> selectedPlaylistsIndexes;    /*!< seleted playlists indexes for working with group of playlists */

    bool multiSelectedMode; /*!< state of multiselected mode*/

public:
    /*! \brief Constructor
      \param parent parent widget
    */
    explicit PlaylistsListWidget(QWidget *parent = 0);

    bool IsMultiSelectedMode();     /*!< \return selected state*/

    /*! \brief sets multi selected mode
        \param state multi selected state

        If state is true - multiselected mode is active
    */
    void SetMultiSelectedMode(bool state);

    /*! \brief sets fixed width
        \param width width of playlist widget
    */
    void SetFixedWidth(int width);

    /*! \brief read playlists list from file
        \param path path on file with playlists urls
    */
    void ReadPlaylistsFrom(QString path);
    bool isEmpty(); /*! \return empty state*/
    int GetPlaylistIndex(Playlist *p_Playlist); /*!< \return playlist index*/
    int GetPlaylistIndex(QString playlistName); /*!< \return playlist name*/
    void Clear();   /*!< clear playlists list*/

    /*! \brief set path will be read playlists
        \param path path on file with playlists urls
    */
    void SetPlaylistDirrectoryPath(QString path);
    QString GetPlaylistDirrectoryPath();    /*!< \return read playilists file path*/
    void AddPlaylist(Playlist playlist);    /*!< adds playlist object on list*/

private:
    void FillInPlaylistsListWidget();
    
signals:
    void PlaylistChangedSignal();   /*!< calls when playlist was changed*/
    void PlaylistButtonClickedSignal(Playlist*);    /*!< calls when playlist button was clicked*/
    
public slots:
    void RemoveSelectedPlaylistsSlot(); /*!< remove selected playlist */

private slots:
    void PlaylistButtonClickSlot();    
};

#endif // PLAYLISTSLISTWIDGET_H
