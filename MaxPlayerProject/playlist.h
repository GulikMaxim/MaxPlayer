#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <QtCore>

/*! \class  Playlist
    \brief  Contains all information about playlist

    Include list of tracks object
*/

class Playlist
{
    QList<QString> songsUrlsList; /*!< songs urls*/
    QString name;   /*!< playlist name*/
    int quantitySongsUrls;  /*!< quantity of songs*/
    QDateTime creationDate; /*!< date of creation playlist*/

public:
    Playlist(); /*! Constructor */

    /*! \brief sets playlist name
        \param playlist name
    */
    void SetName(QString name);
    QString GetName();  /*!< \return playlist name*/

    /*! \brief saves songs urls
        \param list list of songs urls
    */
    void SetSongsUrlsList(QList<QString> list);
    QList<QString> GetSongsUrlsList();  /*!< \return songs urls*/
    QDateTime GetCreationDate();    /*!< \return creation date*/

    /*! \brief sets creation date
        \param date creation date
    */
    void SetCreationDate(QDateTime date);
    int GetQuantitySongsUrls(); /*!< \return quantity of tracks in playlist */

    /*! \brief saves playlist songs urls in file
        \param path puth of file
    */
    void SaveTo(QString path);

    /*! \brief read playlist form file
        \param path puth of file
        \param playlistName name of playlist
        \param isReadSongsUrls if it have true state - read all information with songs, else - only name, date and track quantity
    */
    void ReadFrom(QString path, QString playlistName,bool isReadSongsUrls = true);
    bool isEmpty(); /*!< \return return true if playlist is empty*/

};

#endif // PLAYLIST_H
