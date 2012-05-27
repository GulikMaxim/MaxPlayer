#include "playlistslistwidget.h"

PlaylistsListWidget::PlaylistsListWidget(QWidget *parent) :
    QScrollArea(parent)
{
    //widget setup
    this->setFixedSize(416,524);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setFrameStyle(QFrame::Box | QFrame::Raised);

    //embeddable widget setup
    p_EmbeddablePlaylistListWidget = new QWidget();
    p_EmbeddablePlaylistListWidget->setFixedSize(414,522);
    this->setWidget(p_EmbeddablePlaylistListWidget);

    SetMultiSelectedMode(false);
}

//methods
void PlaylistsListWidget::SetFixedWidth(int width)
{
    this->setFixedWidth(width);
    p_EmbeddablePlaylistListWidget->setFixedWidth(width-2);
}
bool PlaylistsListWidget::IsMultiSelectedMode()
{
    if(multiSelectedMode)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void PlaylistsListWidget::SetMultiSelectedMode(bool state)
{
    multiSelectedMode = state;
    if(selectedPlaylistsIndexes.size())
    {
        if(!state)
        {
            foreach(int selectedPlaylistIndex, selectedPlaylistsIndexes)
            {
                playlistButtonsList[selectedPlaylistIndex]->SetActiveStatus(false);
            }
            selectedPlaylistsIndexes.clear();

            selectedPlaylistsIndexes<<0;   // set select track on first track
        }
        else
        {
            playlistButtonsList[0]->SetActiveStatus(true);
        }
    }
}
void PlaylistsListWidget::ReadPlaylistsFrom(QString path)
{
    playlistsDirrectoryPath = path;

    //save name of saving playlist
    QFile allPlaylistsFile(playlistsDirrectoryPath+"AllPlaylists.txt");
    if(!allPlaylistsFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        //file didn't open
    }
    else
    {
        QTextStream readStream(&allPlaylistsFile);
        while(!readStream.atEnd())
        {
            QString playlistName;
            playlistName = readStream.readLine();
            if(playlistName.size())
            {
                Playlist *p_Playlist = new Playlist();
                p_Playlist->ReadFrom(path,playlistName,false);

                PlaylistButton *p_PlaylistButton = new PlaylistButton(/*p_EmbeddablePlaylistListWidget*/);
                p_PlaylistButton->SetPlaylist(p_Playlist);

                connect(p_PlaylistButton,SIGNAL(clicked()),SLOT(PlaylistButtonClickSlot()));

                playlistButtonsList<<p_PlaylistButton;
            }
        }
        selectedPlaylistsIndexes<<0;
    }
    allPlaylistsFile.close();

    this->FillInPlaylistsListWidget();

    emit PlaylistChangedSignal();
}
void PlaylistsListWidget::FillInPlaylistsListWidget()
{
    p_EmbeddablePlaylistListWidget->setFixedHeight(522);
    if(!this->isEmpty())
    {
        QPoint playlistButtonPosition(5,5);    //first track position in start filling
        foreach(PlaylistButton* p_PlaylistButton, playlistButtonsList)
        {
            p_PlaylistButton->setParent(p_EmbeddablePlaylistListWidget);
            p_PlaylistButton->move(playlistButtonPosition);
            playlistButtonPosition.setX(playlistButtonPosition.x()+ 205);
            if(playlistButtonPosition.x() > 400)
            {
                playlistButtonPosition.setX(5);
                playlistButtonPosition.setY(playlistButtonPosition.y()+ 122);
            }
            if(playlistButtonPosition.y()>p_EmbeddablePlaylistListWidget->height())
            {
                p_EmbeddablePlaylistListWidget->setFixedHeight(playlistButtonPosition.y());
            }
        }
    }
}
bool PlaylistsListWidget::isEmpty()
{
    if(playlistButtonsList.size())
    {
        return false;
    }
    else
    {
        return true;
    }
}
void PlaylistsListWidget::Clear()
{
    foreach(PlaylistButton *p_RemovePlaylistButton,playlistButtonsList)
    {
        delete p_RemovePlaylistButton;
    }
    playlistButtonsList.clear();

    emit PlaylistChangedSignal();
}
int PlaylistsListWidget::GetPlaylistIndex(Playlist *p_Playlist)
{
    int currentPlaylistIndex=0;
    foreach(PlaylistButton* p_PlaylistButton,playlistButtonsList)
    {
        if(p_PlaylistButton->GetPlaylist() == p_Playlist)
            break;
        currentPlaylistIndex++;
    }
    if(currentPlaylistIndex > playlistButtonsList.size()-1)
    {
        return -1;
    }
    else
    {
        return currentPlaylistIndex;
    }
}
int PlaylistsListWidget::GetPlaylistIndex(QString playlistName)
{
    int currentPlaylistIndex=0;
    foreach(PlaylistButton* p_PlaylistButton,playlistButtonsList)
    {
        if(p_PlaylistButton->GetPlaylist()->GetName() == playlistName)
            break;
        currentPlaylistIndex++;
    }
    if(currentPlaylistIndex > playlistButtonsList.size()-1)
    {
        return -1;
    }
    else
    {
        return currentPlaylistIndex;
    }
}
void PlaylistsListWidget::SetPlaylistDirrectoryPath(QString path)
{
    playlistsDirrectoryPath = path;
}
QString PlaylistsListWidget::GetPlaylistDirrectoryPath()
{
    return playlistsDirrectoryPath;
}
void PlaylistsListWidget::AddPlaylist(Playlist playlist)
{
    PlaylistButton *p_PlaylistButton = new PlaylistButton(p_EmbeddablePlaylistListWidget);
    p_PlaylistButton->SetPlaylist(&playlist);
    connect(p_PlaylistButton,SIGNAL(clicked()),SLOT(PlaylistButtonClickSlot()));
    playlistButtonsList<<p_PlaylistButton;

    //refresh playlistslist
    this->Clear();
    this->ReadPlaylistsFrom(this->playlistsDirrectoryPath);
}
//slots
void PlaylistsListWidget::PlaylistButtonClickSlot()
{
    PlaylistButton* p_ClickedPlaylistButton = (PlaylistButton*)sender();
    if(this->IsMultiSelectedMode())
    {
        int selectedPlaylistIndex = this->GetPlaylistIndex(p_ClickedPlaylistButton->GetPlaylist());
        if(p_ClickedPlaylistButton->IsActive())
        {
            if(selectedPlaylistsIndexes.size() != 1)   //minimum one track must be selected forever
            {
                selectedPlaylistsIndexes.removeOne(selectedPlaylistIndex);
                p_ClickedPlaylistButton->SetActiveStatus(false);
            }
        }
        else
        {
            selectedPlaylistsIndexes<<selectedPlaylistIndex;
            p_ClickedPlaylistButton->SetActiveStatus(true);
        }
    }
    else
    {
        //open playlist
        Playlist* p_ClickedButtonPlaylist = p_ClickedPlaylistButton->GetPlaylist();
        if(p_ClickedButtonPlaylist->isEmpty())
        {
            p_ClickedButtonPlaylist->ReadFrom(playlistsDirrectoryPath,p_ClickedButtonPlaylist->GetName());
        }

        emit PlaylistButtonClickedSignal(p_ClickedButtonPlaylist);
    }
}
void PlaylistsListWidget::RemoveSelectedPlaylistsSlot()
{
    //remove playlists
    foreach(int removedPlaylistIndex,selectedPlaylistsIndexes)
    {
        PlaylistButton* p_RemovePlaylistButton = playlistButtonsList[removedPlaylistIndex];

        //deleteFile
        QFile deletePlaylistFile(playlistsDirrectoryPath+p_RemovePlaylistButton->GetPlaylist()->GetName()+".plst");
        if(!deletePlaylistFile.open(QIODevice::ReadWrite))
        {
            //file didn't open
        }
        else
        {
            deletePlaylistFile.remove();
        }

        playlistButtonsList[removedPlaylistIndex] = NULL;
        delete p_RemovePlaylistButton;
    }
    playlistButtonsList.removeAll(NULL);
    selectedPlaylistsIndexes.clear();

    //rewrite all Playlists file
    QFile allPlaylistsFile(playlistsDirrectoryPath+"AllPlaylists.txt");
    if(!allPlaylistsFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
    {
        //file didn't open
    }
    else
    {
        QString endLine;

#ifdef Q_OS_WIN
        endLine = QString("\r\n");
#else
        endLine = QString('\n');
#endif

        QTextStream writeStream(&allPlaylistsFile);
        foreach(PlaylistButton* p_PlaylistButton, playlistButtonsList)
        {
            writeStream<<p_PlaylistButton->GetPlaylist()->GetName()<<endLine;
        }
        allPlaylistsFile.close();
    }
    FillInPlaylistsListWidget();


    if(!this->isEmpty())
    {
        selectedPlaylistsIndexes<<0;   // set select playlist on first
        playlistButtonsList[0]->SetActiveStatus(true);
    }

    emit PlaylistChangedSignal();
}
