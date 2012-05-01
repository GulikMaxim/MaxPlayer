#ifndef TRACK_H
#define TRACK_H

#include <phonon>
#include <QtCore>

class Track
{    
    Phonon::AudioOutput *p_AudioOutput;
    Phonon::MediaObject *p_AudioObject;

    QString artist;
    QString title;
    QString album;
    QString description;
    QString date;
    QString genre;

public:
    Track();
    Track(QUrl trackUrl);
    void Open(QUrl trackUrl);
    QString GetArtist();
    QString GetTitle();
    QString GetAlbum();
    QString GetDescription();
    QString GetDate();
    QString GetGenre();
    Phonon::AudioOutput* GetAudioOutput();
    Phonon::MediaObject* GetAudioObject();

private:
    void MetadataRead();
};

#endif // TRACK_H
