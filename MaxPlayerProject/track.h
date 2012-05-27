#ifndef TRACK_H
#define TRACK_H

/*! \class  Track
    \brief  Cantains all information about track
*/

#include <phonon>
#include <QtCore>

class Track
{    
    Phonon::AudioOutput *p_AudioOutput; /*!< audio output of track */
    Phonon::MediaObject *p_AudioObject; /*!< audio object of track */

    QString artist; /*!< artist name*/
    QString title;  /*!< track title*/
    QString album;  /*!< album name */
    QString description;  /*!< description about track*/
    QString date;  /*!< date of creation track*/
    QString genre;  /*!< genre of track*/

public:    
    Track();/*!< \brief Constructor*/

    /*! \brief Constructor
      \param trackUrl url of track for open it
    */
    Track(QUrl trackUrl);

    /*! \brief open track by url
      \param trackUrl url of track for open it
    */
    void Open(QUrl trackUrl);
    QString GetArtist();    /*!< \return artist name*/
    QString GetTitle();    /*!< \return title of track*/
    QString GetAlbum();    /*!< \return album name*/
    QString GetDescription();    /*!< \return description about track*/
    QString GetDate();    /*!< \return creation date of track*/
    QString GetGenre();    /*!< \return genre of track */
    Phonon::AudioOutput* GetAudioOutput();    /*!< \return audio object of track*/
    Phonon::MediaObject* GetAudioObject();    /*!< \return media object of track*/

private:
    void MetadataRead();
};

#endif // TRACK_H
