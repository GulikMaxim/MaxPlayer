#include "playlistbutton.h"

PlaylistButton::PlaylistButton(QWidget *parent) :
    QPushButton(parent)
{
    //widget setup
    this->setFixedSize(200,115);
   // this->setFlat(true);
    QPalette playlistButtonPalette;
    playlistButtonPalette.setColor(QPalette::Button,Qt::black);
    playlistButtonPalette.setColor(QPalette::ButtonText,Qt::white);
    playlistButtonPalette.setColor(QPalette::Base,Qt::cyan);
    this->setPalette(playlistButtonPalette);
    this->setStyle(new QPlastiqueStyle());
    this->setFont(QFont("Bauhaus 93",9,QFont::Light));   //Bauhaus 93

    //bckgoround label setup
    p_BackgroundLabel = new QLabel(this);
    p_BackgroundLabel->setFixedSize(205,117);
    p_BackgroundLabel->move(-2,0);
    p_BackgroundLabel->setFrameStyle(QFrame::Box | QFrame::Raised);
    p_BackgroundLabel->setLineWidth(1);

    //labels setup
    p_TitleNameLabel = new QLabel("Name",p_BackgroundLabel);
    p_TitleNameLabel->move(5,6);
    p_UnderlineNameLabel = new QLabel(this);
    p_UnderlineNameLabel->setFrameStyle(QFrame::Sunken| QFrame::HLine);
    p_UnderlineNameLabel->move(5,18);
    p_UnderlineNameLabel->setFixedWidth(40);
    p_UnderlineNameLabel->setFixedHeight(1);

    p_TitleQuntityLabel = new QLabel("Quantity of tracks",p_BackgroundLabel);
    p_TitleQuntityLabel->move(5,41);
    p_UnderlineQuntityLabel = new QLabel(this);
    p_UnderlineQuntityLabel->setFrameStyle(QFrame::Sunken| QFrame::HLine);
    p_UnderlineQuntityLabel->move(5,53);
    p_UnderlineQuntityLabel->setFixedWidth(100);
    p_UnderlineQuntityLabel->setFixedHeight(1);

    p_TitleCreationDateLabel = new QLabel("Creation date",p_BackgroundLabel);
    p_TitleCreationDateLabel->move(5,76);
    p_UnderlineCreationDateLabel = new QLabel(p_BackgroundLabel);
    p_UnderlineCreationDateLabel->setFrameStyle(QFrame::Sunken| QFrame::HLine);
    p_UnderlineCreationDateLabel->move(5,88);
    p_UnderlineCreationDateLabel->setFixedWidth(80);
    p_UnderlineCreationDateLabel->setFixedHeight(1);

    p_NameLabel = new  QLabel(this);
    p_NameLabel->setFont(QFont("Constantia",11,QFont::Light));
    p_NameLabel->move(20,21);

    p_QuantityTracksLabel = new QLabel(this);
    p_QuantityTracksLabel->setFont(QFont("Constantia",11,QFont::Light));
    p_QuantityTracksLabel->move(20,56);

    p_CreationDateLabel = new QLabel(this);
    p_CreationDateLabel->setFont(QFont("Constantia",11,QFont::Light));
    p_CreationDateLabel->move(20,91);

    //play icon setup
    p_ActiveStatusLineLabel = new QLabel(p_BackgroundLabel);
    QPixmap *playLinePix = new QPixmap("PlaylistActive.png");
    p_ActiveStatusLineLabel->setPixmap(*playLinePix);
    p_ActiveStatusLineLabel->move(5,4);

    this->SetActiveStatus(false);

    p_Playlist = NULL;
}

//methods
void PlaylistButton::SetActiveStatus(bool status)
{
    isActiveStatus = status;
    if(isActiveStatus == true)
    {
        p_ActiveStatusLineLabel->show();

        p_TitleNameLabel->move(15,6);
        p_UnderlineNameLabel->move(15,18);
        p_TitleQuntityLabel->move(15,41);
        p_UnderlineQuntityLabel->move(15,53);
        p_TitleCreationDateLabel->move(15,76);
        p_UnderlineCreationDateLabel->move(15,88);
        p_NameLabel->move(30,21);
        p_QuantityTracksLabel->move(30,56);
        p_CreationDateLabel->move(30,91);
    }
    else
    {
        p_ActiveStatusLineLabel->hide();

        p_TitleNameLabel->move(5,6);
        p_UnderlineNameLabel->move(5,18);
        p_TitleQuntityLabel->move(5,41);
        p_UnderlineQuntityLabel->move(5,53);
        p_TitleCreationDateLabel->move(5,76);
        p_UnderlineCreationDateLabel->move(5,88);
        p_NameLabel->move(20,21);
        p_QuantityTracksLabel->move(20,56);
        p_CreationDateLabel->move(20,91);
    }
}
void PlaylistButton::OpenPlayList(QUrl playlistUrl)
{
    //open playlist
}
Playlist* PlaylistButton::GetPlaylist()
{
    return p_Playlist;
}
bool PlaylistButton::IsActive()
{
    if(isActiveStatus)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void PlaylistButton::SetPlaylist(Playlist *p_Playlist)
{
   PlaylistButton::p_Playlist = p_Playlist;
   p_NameLabel->setText(p_Playlist->GetName());
   p_QuantityTracksLabel->setText(QString::number(p_Playlist->GetQuantitySongsUrls()));
   p_CreationDateLabel->setText(p_Playlist->GetCreationDate().toString());
}

//slots
