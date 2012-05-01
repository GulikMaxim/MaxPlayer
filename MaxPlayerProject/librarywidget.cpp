#include "librarywidget.h"

LibraryWidget::LibraryWidget(QWidget *parent) :
    TitleWidget(parent)
{
    //title setup
    this->setFixedSize(432,522);
    this->SetTitleText("Menu");
    this->SetTitleFont(QFont("Bauhaus 93",9,QFont::Normal));
    this->TitleMove(QPoint(372,2));
    this->ShowTitle(false);

    //background setup
    QPalette *p_LibraryPalette = new QPalette(Qt::cyan,Qt::black);               // set font's and backgrod colors
    p_LibraryPalette->setBrush(this->backgroundRole(),QBrush(QPixmap("EmptyBackgraund.jpg")));
    this->setAutoFillBackground(true);
    this->setPalette(*p_LibraryPalette);


    //lybrary setup

    p_PlaylistsList = new PlaylistsListWidget(this);
    p_PlaylistsList->move(0,-1);
    connect(p_PlaylistsList,SIGNAL(PlaylistChangedSignal()),SLOT(PlaylistsListChangedSlot()));
    p_PlaylistsList->ReadPlaylistsFrom(".\\playlists\\");

    //library menu setup
    p_LibraryMenuButton = new MyCheckableButton(QPixmap("MenuTurnOn.png"),QPixmap("Menu.png"),this);
    p_LibraryMenuButton->move(416,20);
    p_LibraryMenuButton->SetSize(QSize(16,16));
    connect(p_LibraryMenuButton,SIGNAL(clicked()),SLOT(LibraryMenuButtonClickSlot()));

    p_DeletePlaylistsButton= new PixmapButton(QPixmap("DeletePlaylists.png"),QSize(36,36),this);
    p_DeletePlaylistsButton->move(382,82);
    p_DeletePlaylistsButton->hide();
    connect(p_DeletePlaylistsButton,SIGNAL(clicked()),p_PlaylistsList,SLOT(RemoveSelectedPlaylistsSlot()));

    p_MultiSellectionCheckBox = new QCheckBox("MultiList",this);
    p_MultiSellectionCheckBox->setFont(QFont("Bauhaus 93",8,QFont::Normal));
    p_MultiSellectionCheckBox->move(371,40);
    p_MultiSellectionCheckBox->setStyle(new QPlastiqueStyle());
    QPalette *p_CorrectionCheckBoxPalette = new QPalette();
    p_CorrectionCheckBoxPalette->setBrush(QPalette::Base,QBrush(Qt::darkCyan));
    p_MultiSellectionCheckBox->setPalette(*p_CorrectionCheckBoxPalette);
    p_MultiSellectionCheckBox->hide();
    connect(p_MultiSellectionCheckBox,SIGNAL(clicked()),SLOT(MultiSellectionCheckBoxChangeSlot()));

//    p_SavePlaylistButton = new PixmapButton(QPixmap("SavePlaylist.png"),QSize(36,36),this);
//    p_SavePlaylistButton->move(382,138);
//    p_SavePlaylistButton->hide();

//    p_LeaveTracksButton= new PixmapButton(QPixmap("LeaveSongs.png"),QSize(36,36),this);
//    p_LeaveTracksButton->move(382,196);
//    p_LeaveTracksButton->hide();
//    connect(p_LeaveTracksButton,SIGNAL(clicked()),p_SongList,SLOT(LeaveSelectedTracksSlot()));

    this->OpenMenu(false);
}

//methods
PlaylistsListWidget* LibraryWidget::GetPlaylistsList()
{
    return p_PlaylistsList;
}
void LibraryWidget::OpenMenu(bool openStatus)
{
    QTime t;
    if(openStatus)
    {
        for(int width=416;width>=370;width--)    //delay for smooth opening
        {
            t.start();
            for(;t.elapsed()<2;){}
            p_PlaylistsList->SetFixedWidth(width);
            QApplication::processEvents();
        }
    }
    else
    {
        for(int width=370;width<=416;width++)    //delay for smooth opening
        {
            t.start();
            for(;t.elapsed()<2;){}
            p_PlaylistsList->SetFixedWidth(width);
            QApplication::processEvents();
        }
    }
}
void LibraryWidget::OpenPlaylists(QList<QUrl> songsUrls)
{
    //p_SongList->OpenTracks(songsUrls);
}
void LibraryWidget::Clear()
{
    p_PlaylistsList->Clear();
}
//slots
void LibraryWidget::LibraryMenuButtonClickSlot()
{
    if(p_LibraryMenuButton->isChecked())
    {
        this->ShowTitle(true);
        this->OpenMenu(true);
        p_MultiSellectionCheckBox->show();
//        p_SavePlaylistButton->show();
        p_DeletePlaylistsButton->show();
//        p_LeaveTracksButton->show();
    }
    else
    {
//        p_SavePlaylistButton->hide();
        p_DeletePlaylistsButton->hide();
//        p_LeaveTracksButton->hide();
        p_MultiSellectionCheckBox->hide();
        this->OpenMenu(false);
        this->ShowTitle(false);
    }
}
void LibraryWidget::MultiSellectionCheckBoxChangeSlot()
{
    if(p_MultiSellectionCheckBox->checkState() == Qt::Checked)
    {
        p_PlaylistsList->SetMultiSelectedMode(true);
    }
    else
    {
        p_PlaylistsList->SetMultiSelectedMode(false);
    }
}
void LibraryWidget::PlaylistsListChangedSlot()
{
    if(p_PlaylistsList->isEmpty())
    {
        QPalette *p_PlaylistPalette = new QPalette(Qt::cyan,Qt::black);               // set font's and backgrod colors
        p_PlaylistPalette->setBrush(this->backgroundRole(),QBrush(QPixmap("EmptyBackgraund.jpg")));
        this->setAutoFillBackground(true);
        this->setPalette(*p_PlaylistPalette);
    }
    else
    {
        QPalette *p_PlaylistPalette = new QPalette(Qt::cyan,Qt::black);               // set font's and backgrod colors
        p_PlaylistPalette->setBrush(this->backgroundRole(),QBrush(QPixmap("shifftingWidgetBackgraund.jpg")));
        this->setAutoFillBackground(true);
        this->setPalette(*p_PlaylistPalette);
    }
}
