#include "trackbutton.h"

TrackButton::TrackButton(QWidget *parent) :  QPushButton(parent)
{
    //widget setup
    this->setFixedSize(350,48);
    this->setFlat(true);
    this->setStyle(new QPlastiqueStyle());
    isPlayStatus = false;

    //labels setup
    p_ArtistNameLabel = new  QLabel(this);
    p_ArtistNameLabel->setFont(QFont("Constantia",9,QFont::Light));
    p_ArtistNameLabel->move(5,10);

    p_TrackNameLabel = new QLabel(this);
    p_TrackNameLabel->setFont(QFont("Constantia",11,QFont::Light));
    p_TrackNameLabel->move(5,25);

    //play icon setup
    p_ActiveStatusLineLabel = new QLabel(this);
    QPixmap *playLinePix = new QPixmap("isPlayLine.png");
    p_ActiveStatusLineLabel->setPixmap(*playLinePix);
    p_ActiveStatusLineLabel->move(2,3);

    //playstatus icons setup
    p_PlayStatusTriangleLabel = new QLabel(this);
    QPixmap *playTrianglePix = new QPixmap("isPlayTriangle.png");
    p_PlayStatusTriangleLabel->setPixmap(*playTrianglePix);
    p_PlayStatusTriangleLabel->move(300,18);

    this->SetPlayStatus(false);
    this->SetActiveStatus(false);

    p_Track = NULL;
}

//Methods
void TrackButton::SetActiveStatus(bool isActive)
{
    isActiveStatus = isActive;
    if(isActiveStatus == true)
    {
        p_ActiveStatusLineLabel->show();
        p_ArtistNameLabel->move(10,10);
        p_TrackNameLabel->move(10,25);
    }
    else
    {
        p_ActiveStatusLineLabel->hide();
        p_ArtistNameLabel->move(5,10);
        p_TrackNameLabel->move(5,25);
    }
}
void TrackButton::SetPlayStatus(bool isPlay)
{
    isPlayStatus = isPlay;
    if(isPlayStatus == true)
    {
        p_PlayStatusTriangleLabel->show();
    }
    else
    {
        p_PlayStatusTriangleLabel->hide();
    }
}
void TrackButton::OpenTrack(QUrl trackUrl)
{
    p_Track = new Track(trackUrl);

    p_ArtistNameLabel->setText(p_Track->GetArtist());
    p_TrackNameLabel->setText(p_Track->GetTitle());
}
Track* TrackButton::GetTrack()
{
    return p_Track;
}
bool TrackButton::IsActive()
{
    return isActiveStatus;
}
bool TrackButton::IsPlay()
{
    return isPlayStatus;
}
