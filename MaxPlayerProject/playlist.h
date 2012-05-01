#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <QtCore>

class Playlist
{
    QList<QString> songsUrlsList;
    QString name;
    int quantitySongsUrls;
    QDateTime creationDate;

public:
    Playlist();

    void SetName(QString name);
    QString GetName();
    void SetSongsUrlsList(QList<QString> list);
    QList<QString> GetSongsUrlsList();
    QDateTime GetCreationDate();
    void SetCreationDate(QDateTime date);
    int GetQuantitySongsUrls();
    void SaveTo(QString path);
    void ReadFrom(QString path, QString playlistName,bool isReadSongsUrls = true);

};

#endif // PLAYLIST_H
