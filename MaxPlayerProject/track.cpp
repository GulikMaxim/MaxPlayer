#include "track.h"

Track::Track()
{
    p_AudioOutput = NULL;
    p_AudioObject = NULL;
}

Track::Track(QUrl trackUrl)
{
    Open(trackUrl);
}

//methods
void Track::Open(QUrl trackUrl)
{
    p_AudioObject = new Phonon::MediaObject();
    p_AudioObject->setCurrentSource(Phonon::MediaSource(trackUrl.toString()));

    p_AudioOutput = new Phonon::AudioOutput();
    Phonon::createPath(p_AudioObject,p_AudioOutput);    //connect audioObject with audiooutput

    this->MetadataRead();
}
void Track::MetadataRead()
{
    QEventLoop eventLoop; //for reading metadata
    QObject::connect(p_AudioObject, SIGNAL(metaDataChanged()), &eventLoop, SLOT(quit()));
    eventLoop.exec();  //cicle for reading metadata
    artist = p_AudioObject->metaData().value("ARTIST");
    title = p_AudioObject->metaData().value("TITLE");
    album = p_AudioObject->metaData().value("ALBUM");
    description = p_AudioObject->metaData().value("DESCRIPTION");
    date = p_AudioObject->metaData().value("DATE") ;
    genre = p_AudioObject->metaData().value("GENRE");
}
QString Track::GetArtist()
{
    return artist;
}
QString Track::GetTitle()
{
    return title;
}
QString Track::GetAlbum()
{
    return album;
}
QString Track::GetDescription()
{
    return description;
}
QString Track::GetDate()
{
    return date;
}
QString Track::GetGenre()
{
    return genre;
}
Phonon::AudioOutput* Track::GetAudioOutput()
{
    return p_AudioOutput;
}
Phonon::MediaObject* Track::GetAudioObject()
{
    return p_AudioObject;
}
