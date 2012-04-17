#include "trackbutton.h"

TrackButton::TrackButton(QWidget *parent) :  QPushButton(parent)
{
    //widget setup
    this->setFixedSize(350,48);
    this->setFlat(true);
    this->setStyle(new QPlastiqueStyle());
    isPlayStatus = false;

    //labels setup
    p_ArtistNameLabel = new  QLabel("dfsdfsdfs",this);
    p_ArtistNameLabel->setFont(QFont("Constantia",9,QFont::Light));
    p_ArtistNameLabel->move(5,10);

    p_TrackNameLabel = new QLabel("adfadfadf",this);
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
}

//Methods
void TrackButton::SetActiveStatus(bool isActive)
{
    isActiveStatus = isActive;
    //QPalette trackButtonPalette = this->palette();
    if(isActiveStatus == true)
    {
        //trackButtonPalette.setColor(QPalette::ButtonText,Qt::cyan);
        p_ActiveStatusLineLabel->show();
        p_ArtistNameLabel->move(10,10);
        p_TrackNameLabel->move(10,25);
    }
    else
    {
        //trackButtonPalette.setColor(QPalette::ButtonText,Qt::white);
        p_ActiveStatusLineLabel->hide();
        p_ArtistNameLabel->move(5,10);
        p_TrackNameLabel->move(5,25);
    }
    //this->setPalette(trackButtonPalette);
}
void TrackButton::SetPlayStatus(bool isPlay)
{
    isPlayStatus = isPlay;
    //QPalette trackButtonPalette = this->palette();
    if(isPlayStatus == true)
    {
        //trackButtonPalette.setColor(QPalette::ButtonText,Qt::cyan);
        //p_ActiveStatusLineLabel->show();
        p_PlayStatusTriangleLabel->show();
        //p_ArtistNameLabel->move(20,10);
        //p_TrackNameLabel->move(20,25);
    }
    else
    {
        //trackButtonPalette.setColor(QPalette::ButtonText,Qt::white);
        //p_ActiveStatusLineLabel->hide();
        p_PlayStatusTriangleLabel->hide();
        //p_ArtistNameLabel->move(5,10);
        //p_TrackNameLabel->move(5,25);
    }
    //this->setPalette(trackButtonPalette);
}
void TrackButton::OpenTrack(QUrl trackUrl)
{
    p_AudioObject = new Phonon::MediaObject();
    p_AudioObject->setCurrentSource(Phonon::MediaSource(trackUrl.toString()));

    p_ArtistNameLabel->setText(/*p_AudioObject->metaData().value("ARTIST")*/QString("Not detected"));
    p_TrackNameLabel->setText(/*p_AudioObject->metaData().value("TITLE")*/QString("Not detected"));
}
Phonon::MediaObject* TrackButton::GetTrackObject()
{
    return p_AudioObject;
}
bool TrackButton::IsActive()
{
    return isActiveStatus;
}
bool TrackButton::IsPlay()
{
    return isPlayStatus;
}
