#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : Window(parent)
{
    //main window setup
    p_MainPalette = new QPalette(Qt::cyan,Qt::black);               // set font's and backgrod colors
    p_MainPalette->setBrush(this->backgroundRole(),QBrush(QPixmap("MainWindowBackground.jpg")));
    this->setAutoFillBackground(true);
    this->setPalette(*p_MainPalette);
    this->setFont(QFont("Bauhaus 93",10,QFont::Normal));
    this->SetSize(QSize(526,620));
    this->setStyle(new QPlastiqueStyle());

    this->setFrameStyle(QFrame::Sunken | QFrame::Box);
    this->setLineWidth(1);

    //Logo setup
    QLabel *p_TitleLabel = new QLabel(); //"                          MaxPLayer. Only music..."
    p_TitleLabel->setPixmap(QPixmap("MainLogo.png"));
    p_TitleLabel->move(300,0);
    p_TitleLabel->setParent(this);

    //control buttons setup
    p_PlaylistButton = new QPushButton("Playlist",this);
    p_PlaylistButton->setCheckable(true);
    p_PlaylistButton->setFlat(true);
    p_PlaylistButton->setFixedSize(80,60);
    p_PlaylistButton->move(3,30);
    p_PlaylistButton->setStyle(new QPlastiqueStyle());
    connect(p_PlaylistButton,SIGNAL(clicked()),SLOT(PlaylistButtonClickedSlot()));

    p_LibraryButton = new QPushButton("Library",this);
    p_LibraryButton->setCheckable(true);
    p_LibraryButton->setFlat(true);
    p_LibraryButton->setFixedSize(80,60);
    p_LibraryButton->move(3,90);
    p_LibraryButton->setStyle(new QPlastiqueStyle());
    connect(p_LibraryButton,SIGNAL(clicked()),SLOT(LibraryButtonClickedSlot()));

    p_ExplorerButton = new QPushButton("Explorer",this);
    p_ExplorerButton->setCheckable(true);
    p_ExplorerButton->setFlat(true);
    p_ExplorerButton->setFixedSize(80,60);
    p_ExplorerButton->move(3,150);
    p_ExplorerButton->setStyle(new QPlastiqueStyle());
    connect(p_ExplorerButton,SIGNAL(clicked()),SLOT(ExplorerButtonClickedSlot()));

    p_AboutButton = new QPushButton("About",this);
    p_AboutButton->setCheckable(true);
    p_AboutButton->setFlat(true);
    p_AboutButton->setFixedSize(80,60);
    p_AboutButton->move(3,210);
    p_AboutButton->setStyle(new QPlastiqueStyle());
    connect(p_AboutButton,SIGNAL(clicked()),SLOT(AboutButtonClickedSlot()));

    //Player widget setup
    p_AudioPlayerWidget = new AudioPlayerWidget();
    p_AudioPlayerWidget->setParent(this);
    p_AudioPlayerWidget->move(83,552);

    //Shifting widgets setup
    p_PlaylistWidget = new PlaylistWidget();
    p_LibraryWidget = new LibraryWidget();
    connect(p_LibraryWidget->GetPlaylistsListWidget(),SIGNAL(PlaylistButtonClickedSignal(Playlist*)),SLOT(OpenPlaylistSlot(Playlist*)));
    connect(p_LibraryWidget,SIGNAL(SavePlaylistButtonClickedSignal(QString)),SLOT(SavePlaylistSlot(QString)));
    connect(p_LibraryWidget,SIGNAL(DialogWindowShowSignal(bool)),SLOT(setDisabled(bool)));

    p_ExplorerWidget = new ExplorerWidget();
    connect(p_ExplorerWidget,SIGNAL(OpenSongsInPlaylistSignal()),SLOT(OpenSongsInPlaylistSlot()));
    connect(p_ExplorerWidget,SIGNAL(AddSongsInPlaylistSignal()),SLOT(AddSongsInPlaylistSlot()));

    p_AboutWidget = new AboutWidget();

    //Shifting widgets stack setup
    p_ShiftingFieldWidgets = new QStackedWidget(this);
    p_ShiftingFieldWidgets->setFixedSize(432,522);
    p_ShiftingFieldWidgets->move(83,30);
    p_ShiftingFieldWidgets->addWidget(p_PlaylistWidget);
    p_ShiftingFieldWidgets->addWidget(p_LibraryWidget);
    p_ShiftingFieldWidgets->addWidget(p_ExplorerWidget);
    p_ShiftingFieldWidgets->addWidget(p_AboutWidget);

    emit(p_PlaylistButton->click());  // work begin with playlist state
    p_AudioPlayerWidget->ConnectPlaylist(p_PlaylistWidget);    // connect playlist with player widget
}

//slots
void MainWindow::PlaylistButtonClickedSlot()
{
    if(p_LibraryButton->isChecked())    // cheking state of other buttons and change colors of them
    {
        p_LibraryButton->setChecked(false);
        SetButtonTextColor(p_LibraryButton,Qt::white);
    }
    else
    {
        if(p_ExplorerButton->isChecked())
        {
            p_ExplorerButton->setChecked(false);
            SetButtonTextColor(p_ExplorerButton,Qt::white);
        }
        else
        {
            if(p_AboutButton->isChecked())
            {
                p_AboutButton->setChecked(false);
                SetButtonTextColor(p_AboutButton,Qt::white);
            }
        }
    }

    if(p_PlaylistButton->isChecked())
    {
        this->SetButtonTextColor(p_PlaylistButton,Qt::black);
        p_ShiftingFieldWidgets->setCurrentWidget(p_PlaylistWidget);
    }
    else
    {
        p_PlaylistButton->setChecked(true);
    }
}
void MainWindow::LibraryButtonClickedSlot()
{
    if(p_PlaylistButton->isChecked())    // cheking state of other buttons and change colors of them
    {
        p_PlaylistButton->setChecked(false);
        SetButtonTextColor(p_PlaylistButton,Qt::white);
    }
    else
    {
        if(p_ExplorerButton->isChecked())
        {
            p_ExplorerButton->setChecked(false);
            SetButtonTextColor(p_ExplorerButton,Qt::white);
        }
        else
        {
            if(p_AboutButton->isChecked())
            {
                p_AboutButton->setChecked(false);
                SetButtonTextColor(p_AboutButton,Qt::white);
            }
        }
    }

    if(p_LibraryButton->isChecked())
    {
        SetButtonTextColor(p_LibraryButton,Qt::black);
        p_ShiftingFieldWidgets->setCurrentWidget(p_LibraryWidget);
    }
    else
    {
        p_LibraryButton->setChecked(true);
    }
}
void MainWindow::ExplorerButtonClickedSlot()
{
    if(p_PlaylistButton->isChecked())    // cheking state of other buttons and change colors of them
    {
        p_PlaylistButton->setChecked(false);
        SetButtonTextColor(p_PlaylistButton,Qt::white);
    }
    else
    {
        if(p_LibraryButton->isChecked())
        {
            p_LibraryButton->setChecked(false);
            SetButtonTextColor(p_LibraryButton,Qt::white);
        }
        else
        {
            if(p_AboutButton->isChecked())
            {
                p_AboutButton->setChecked(false);
                SetButtonTextColor(p_AboutButton,Qt::white);
            }
        }
    }

    if(p_ExplorerButton->isChecked())
    {
        SetButtonTextColor(p_ExplorerButton,Qt::black);
        p_ShiftingFieldWidgets->setCurrentWidget(p_ExplorerWidget);
    }
    else
    {
        p_ExplorerButton->setChecked(true);
    }
}
void MainWindow::AboutButtonClickedSlot()
{
    if(p_PlaylistButton->isChecked())    // cheking state of other buttons and change colors of them
    {
        p_PlaylistButton->setChecked(false);
        SetButtonTextColor(p_PlaylistButton,Qt::white);
    }
    else
    {
        if(p_LibraryButton->isChecked())
        {
            p_LibraryButton->setChecked(false);
            SetButtonTextColor(p_LibraryButton,Qt::white);
        }
        else
        {
            if(p_ExplorerButton->isChecked())
            {
                p_ExplorerButton->setChecked(false);
                SetButtonTextColor(p_ExplorerButton,Qt::white);
            }
        }
    }

    if(p_AboutButton->isChecked())
    {
        SetButtonTextColor(p_AboutButton,Qt::black);
        p_ShiftingFieldWidgets->setCurrentWidget(p_AboutWidget);
    }
    else
    {
        p_AboutButton->setChecked(true);
    }
}
void MainWindow::OpenSongsInPlaylistSlot()
{
    p_PlaylistWidget->Clear();
    p_PlaylistWidget->GetSongsList()->OpenTracks(p_ExplorerWidget->GetSelectedSongs());
    p_ExplorerWidget->ClearSelection();

    emit p_PlaylistButton->click();
}
void MainWindow::AddSongsInPlaylistSlot()
{
    p_PlaylistWidget->GetSongsList()->OpenTracks(p_ExplorerWidget->GetSelectedSongs());
    p_ExplorerWidget->ClearSelection();

    emit p_PlaylistButton->click();
}
void MainWindow::OpenPlaylistSlot(Playlist* p_Playlist)
{
    QStringList songsUrlsListInStrings= p_Playlist->GetSongsUrlsList();
    QList<QUrl> songsUrlsList;
    foreach(QString songPath, songsUrlsListInStrings)
    {
        songsUrlsList<<QUrl(songPath);
    }
    p_PlaylistWidget->Clear();
    p_PlaylistWidget->GetSongsList()->OpenTracks(songsUrlsList);

    emit p_PlaylistButton->click();
}
void MainWindow::SavePlaylistSlot(QString playlistName)
{
    //save information about current playlist
    Playlist currentPlaylist;
    currentPlaylist.SetName(playlistName);
    currentPlaylist.SetCreationDate(QDateTime::currentDateTime());
    QList<TrackButton*> trackButtonsList = p_PlaylistWidget->GetSongsList()->GetTrackButtonsList();
    QStringList songsUrlsInString;

    //save url of songs
    foreach(TrackButton* p_TrackButton,trackButtonsList)
    {
        songsUrlsInString<<p_TrackButton->GetTrackUrl().toString();
    }
    currentPlaylist.SetSongsUrlsList(songsUrlsInString);

    //save playlist
    currentPlaylist.SaveTo(p_LibraryWidget->GetPlaylistsListWidget()->GetPlaylistDirrectoryPath());

    //add playlist at playlist list widget
    p_LibraryWidget->GetPlaylistsListWidget()->AddPlaylist(currentPlaylist);
}
void MainWindow::SetEnabled()
{
    this->setEnabled(true);
}
//methods
void MainWindow::SetButtonTextColor(QPushButton *p_Button,const QColor & color)
{
    QPalette buttonPalette = p_Button->palette();
    buttonPalette.setColor(QPalette::ButtonText,color);
    p_Button->setPalette(buttonPalette);
}
