#include "playlistwidget.h"

PlaylistWidget::PlaylistWidget(QWidget *parent) :
    TitleWidget(parent)
{
    //title setup
    this->setFixedSize(432,522);
    this->SetTitleText("Menu");
    this->SetTitleFont(QFont("Bauhaus 93",9,QFont::Normal));
    this->TitleMove(QPoint(372,2));
    this->ShowTitle(false);

    //background setup
    QPalette *p_PlaylistPalette = new QPalette(Qt::cyan,Qt::black);               // set font's and backgrod colors
    p_PlaylistPalette->setBrush(this->backgroundRole(),QBrush(QPixmap("EmptyBackgraund.jpg")));
    this->setAutoFillBackground(true);
    this->setPalette(*p_PlaylistPalette);

    p_SongList = new SongsListWidget(this);
    p_SongList->move(0,-1);
    connect(p_SongList,SIGNAL(songListChangedSignal()),SLOT(SongListChangedSlot()));

    ///playlist menu setup
    p_PlayListMenuButton = new MyCheckableButton(QPixmap("MenuTurnOn.png"),QPixmap("Menu.png"),this);
    p_PlayListMenuButton->move(416,20);
    p_PlayListMenuButton->SetSize(QSize(16,16));
    connect(p_PlayListMenuButton,SIGNAL(clicked()),SLOT(PlaylistMenuButtonClickSlot()));

    p_DeleteTracksButton= new PixmapButton(QPixmap("DeleteTracks.png"),QSize(36,36),this);
    p_DeleteTracksButton->move(382,82);
    p_DeleteTracksButton->hide();
    connect(p_DeleteTracksButton,SIGNAL(clicked()),p_SongList,SLOT(RemoveSelectedTracksSlot()));

    p_MultiSellectionCheckBox = new QCheckBox("MultiList",this);
    p_MultiSellectionCheckBox->setFont(QFont("Bauhaus 93",8,QFont::Normal));
    p_MultiSellectionCheckBox->move(371,40);
    p_MultiSellectionCheckBox->setStyle(new QPlastiqueStyle());
    QPalette *p_CorrectionCheckBoxPalette = new QPalette();
    p_CorrectionCheckBoxPalette->setBrush(QPalette::Base,QBrush(Qt::darkCyan));
    p_MultiSellectionCheckBox->setPalette(*p_CorrectionCheckBoxPalette);
    p_MultiSellectionCheckBox->hide();
    connect(p_MultiSellectionCheckBox,SIGNAL(clicked()),SLOT(MultiSellectionCheckBoxChangeSlot()));

    p_LeaveTracksButton= new PixmapButton(QPixmap("LeaveSongs.png"),QSize(36,36),this);
    p_LeaveTracksButton->move(382,138);
    p_LeaveTracksButton->hide();
    connect(p_LeaveTracksButton,SIGNAL(clicked()),p_SongList,SLOT(LeaveSelectedTracksSlot()));

    this->OpenMenu(false);
    p_PlayListMenuButton->click();
}

//methods
SongsListWidget* PlaylistWidget::GetSongsList()
{
    return p_SongList;
}
void PlaylistWidget::OpenMenu(bool openStatus)
{
    QTime t;
    if(openStatus)
    {
        for(int width=416;width>=370;width--)    //delay for smooth opening
        {
            t.start();
            for(;t.elapsed()<2;){}
            p_SongList->SetFixedWidth(width);
            QApplication::processEvents();
        }
    }
    else
    {
        for(int width=370;width<=416;width++)    //delay for smooth opening
        {
            t.start();
            for(;t.elapsed()<2;){}
            p_SongList->SetFixedWidth(width);
            QApplication::processEvents();
        }
    }
}
void PlaylistWidget::Clear()
{
    p_SongList->Clear();
}
//slots
void PlaylistWidget::PlaylistMenuButtonClickSlot()
{
    if(p_PlayListMenuButton->isChecked())
    {
        this->ShowTitle(true);
        this->OpenMenu(true);
        p_MultiSellectionCheckBox->show();
        p_DeleteTracksButton->show();
        p_LeaveTracksButton->show();
    }
    else
    {
        p_DeleteTracksButton->hide();
        p_LeaveTracksButton->hide();
        p_MultiSellectionCheckBox->hide();
        this->OpenMenu(false);
        this->ShowTitle(false);
    }
}
void PlaylistWidget::MultiSellectionCheckBoxChangeSlot()
{
    if(p_MultiSellectionCheckBox->checkState() == Qt::Checked)
    {
        p_SongList->SetMultiSelectedMode(true);
    }
    else
    {
        p_SongList->SetMultiSelectedMode(false);
    }
}
void PlaylistWidget::SongListChangedSlot()
{
    if(p_SongList->isEmpty())
    {
        QPalette *p_PlaylistPalette = new QPalette(Qt::cyan,Qt::black);               // set font's and backgrod colors
        p_PlaylistPalette->setBrush(this->backgroundRole(),QBrush(QPixmap("PlayListEmptyBackgraund.jpg")));
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
