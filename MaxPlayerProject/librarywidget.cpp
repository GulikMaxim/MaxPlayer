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

    p_SavePlaylistButton = new PixmapButton(QPixmap("SavePlaylist.png"),QSize(36,36),this);
    p_SavePlaylistButton->move(382,138);
    p_SavePlaylistButton->hide();
    connect(p_SavePlaylistButton,SIGNAL(clicked()),SLOT(SavePlaylistButtonClickedSlot()));

    this->OpenMenu(true);
    p_LibraryMenuButton->click();

    //dialog menu window setup
    p_EnterNameDialogWindow = new EnterLineDialogWindow();
    p_EnterNameDialogWindow->SetTitleText(QString("Save playlist"));
    p_EnterNameDialogWindow->SetConfirmButtonText("Save");
    p_EnterNameDialogWindow->SetInformationLabelText("Name didn't enter!");
    connect(p_EnterNameDialogWindow,SIGNAL(DialogWindowShowSignal(bool)),SIGNAL(DialogWindowShowSignal(bool)));
    connect(p_EnterNameDialogWindow,SIGNAL(ConfirmButtonClickSignal(QString)),SLOT(CheckingPlaylistNameSlot(QString)));
}

//methods
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
PlaylistsListWidget* LibraryWidget::GetPlaylistsListWidget()
{
    return p_PlaylistsList;
}
//slots
void LibraryWidget::LibraryMenuButtonClickSlot()
{
    if(p_LibraryMenuButton->isChecked())
    {
        this->ShowTitle(true);
        this->OpenMenu(true);
        p_MultiSellectionCheckBox->show();
        p_SavePlaylistButton->show();
        p_DeletePlaylistsButton->show();
    }
    else
    {
        p_SavePlaylistButton->hide();
        p_DeletePlaylistsButton->hide();
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
void LibraryWidget::SavePlaylistButtonClickedSlot()
{
    emit DialogWindowShowSignal(true);
    p_EnterNameDialogWindow->show();

}

void LibraryWidget::CheckingPlaylistNameSlot(QString playlistName)
{
    if(this->GetPlaylistsListWidget()->GetPlaylistIndex(playlistName) > -1)
    {
        p_EnterNameDialogWindow->SetInformationLabelText("Playlist with this name is already saved!");
        p_EnterNameDialogWindow->ShowInformationLabel(true);
        p_EnterNameDialogWindow->ShowConfirmButton(false);
        p_EnterNameDialogWindow->ShowEditLine(false);
    }
    else
    {
        p_EnterNameDialogWindow->SetInformationLabelText("Name didn't enter!");
        p_EnterNameDialogWindow->ShowEditLine(true);
        p_EnterNameDialogWindow->ShowConfirmButton(true);
        p_EnterNameDialogWindow->ShowInformationLabel(false);
        p_EnterNameDialogWindow->CancelWindow();
        emit SavePlaylistButtonClickedSignal(playlistName);
    }
}
