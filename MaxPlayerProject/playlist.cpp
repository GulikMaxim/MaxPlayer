#include "playlist.h"

Playlist::Playlist()
{
    name=QString("Not specifide");
    quantitySongsUrls = 0;
}

//methods
void Playlist::SetName(QString name)
{
    Playlist::name= name;
}
QString Playlist::GetName()
{
    return name;
}
void Playlist::SetSongsUrlsList(QList<QString> list)
{
    quantitySongsUrls = 0;
    foreach(QString songUrl,list)
    {
        songsUrlsList<<songUrl;
        quantitySongsUrls++;
    }
}
QList<QString> Playlist::GetSongsUrlsList()
{
    return songsUrlsList;
}
int Playlist::GetQuantitySongsUrls()
{
    return quantitySongsUrls;
}
QDateTime Playlist::GetCreationDate()
{
    return creationDate;
}
void Playlist::SetCreationDate(QDateTime date)
{
    creationDate = date;
}
void Playlist::SaveTo(QString path)
{
    QString endLine;
#ifdef Q_OS_WIN
    endLine = QString("\r\n");
#else
    endLine = QString('\n');
#endif

    //save name of saving playlist
    QFile allPlaylistsFile(path+"AllPlaylists.txt");
    if(!allPlaylistsFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
    {
        //file didn't open
    }
    else
    {
        QTextStream writeStream(&allPlaylistsFile);
        writeStream<<name<<endLine;
        allPlaylistsFile.close();
    }
    allPlaylistsFile.close();

    //save information from playlist object
    QFile playlistFile(path+name+".plst");
    if(!playlistFile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        //file didn't open
    }
    else
    {
        QTextStream writeStream(&playlistFile);
        writeStream<<creationDate.toString()<<endLine;
        writeStream<<name<<endLine;
        writeStream<<quantitySongsUrls<<endLine;
        foreach(QString songUrl, songsUrlsList)
        {
            writeStream << songUrl <<endLine;
        }
        playlistFile.close();
    }
}
void Playlist::ReadFrom(QString path, QString playlistName, bool isReadSongsUrls)
{
    //save information from playlist object
    QFile playlistFile(path+playlistName+".plst");
    if(!playlistFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        //file didn't open
    }
    else
    {
        QTextStream readStream(&playlistFile);

        QString dateString;
        dateString =readStream.readLine();
        creationDate = QDateTime::fromString(dateString);

        this->name =dateString =readStream.readLine();
        this->quantitySongsUrls = readStream.readLine().toInt();
        if(isReadSongsUrls)
        {
            while(!readStream.atEnd())
            {
                QString songPath;
                songPath=dateString =readStream.readLine();
                if(songPath.size())
                {
                    songsUrlsList<<songPath;
                }
            }
        }
        playlistFile.close();
    }
}
