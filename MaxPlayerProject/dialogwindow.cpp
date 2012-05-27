#include "dialogwindow.h"

DialogWindow::DialogWindow(QWidget *parent) :
    TitleWidget(parent)
{
    //dialog window setup
    this->SetTitleFont(QFont("Bauhaus 93",10,QFont::Normal));
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setFixedSize(QSize(300,100));
    this->setFrameStyle(QFrame::Sunken | QFrame::Box);
    this->setLineWidth(1);

    QPalette dialogWindowPalette(Qt::cyan,Qt::black);               // set font's and backgrod colors
    dialogWindowPalette.setBrush(this->backgroundRole(),QBrush(QPixmap("MainWindowBackground.jpg")));
    this->setAutoFillBackground(true);
    this->setPalette(dialogWindowPalette);

    //control button setup
    QPalette buttonsPalette;
    buttonsPalette.setColor(QPalette::ButtonText, Qt::black);
    buttonsPalette.setColor(QPalette::Button,Qt::cyan);

    p_ConfirmButton = new QPushButton(this);
    p_ConfirmButton->setFont(QFont("Bauhaus 93",9,QFont::Normal));
    p_ConfirmButton->setPalette(buttonsPalette);
    p_ConfirmButton->setText("OK");
    p_ConfirmButton->setStyle(new QPlastiqueStyle);
    p_ConfirmButton->setFixedSize(45,20);
    p_ConfirmButton->move(this->width()/2 - p_ConfirmButton->width()-10,this->height()- p_ConfirmButton->height()-10);
    connect(p_ConfirmButton,SIGNAL(clicked()),SIGNAL(ConfirmButtonClickSignal()));

    p_CancelButton = new QPushButton(this);
    p_CancelButton->setFont(QFont("Bauhaus 93",9,QFont::Normal));
    p_CancelButton->setPalette(buttonsPalette);
    p_CancelButton->setText("Cancle");
    p_CancelButton->setStyle(new QPlastiqueStyle);
    p_CancelButton->setFixedSize(45,20);
    p_CancelButton->move(this->width()/2+10, this->height()- p_CancelButton->height()-10);
    connect(p_CancelButton,SIGNAL(clicked()),SIGNAL(CancelButtonClickSignal()));
    connect(p_CancelButton,SIGNAL(clicked()),this, SLOT(close()));

    p_InformationLabel = new QLabel(this);
    p_InformationLabel->hide();
    p_InformationLabel->setFont(QFont("Bauhaus 93",9,QFont::Normal));
    p_InformationLabel->move(30,this->height()/2-10);

}

//methods
void DialogWindow::SetConfirmButtonText(QString text)
{
    p_ConfirmButton->setText(text);
}
void DialogWindow::SetCancelButtonText(QString text)
{
    p_CancelButton->setText(text);
}
void DialogWindow::SetControlButtonsSize(QSize size)
{
    p_ConfirmButton->setFixedSize(size);
    p_CancelButton->setFixedSize(size);
    p_ConfirmButton->move(this->width()/2 - p_ConfirmButton->width()-10,this->height()- p_ConfirmButton->height()-10);
    p_CancelButton->move(this->width()/2+10, this->height()- p_CancelButton->height()-10);
}
void DialogWindow::SetFixedSize(QSize size)
{
    this->setFixedSize(size);
    p_ConfirmButton->move(this->width()/2 - p_ConfirmButton->width()-10,this->height()- p_ConfirmButton->height()-10);
    p_CancelButton->move(this->width()/2+10, this->height()- p_CancelButton->height()-10);
    p_InformationLabel->move(10,this->height()/2);
}
void DialogWindow::ShowInformationLabel(bool state)
{
    if(state)
    {
        p_InformationLabel->show();
    }
    else
    {
        p_InformationLabel->hide();
    }
}
void DialogWindow::SetInformationLabelText(QString text)
{
    p_InformationLabel->setText(text);
}
void DialogWindow::ShowConfirmButton(bool state)
{
    if(state)
    {
        p_CancelButton->move(this->width()/2+10, this->height()- p_CancelButton->height()-10);
        p_ConfirmButton->show();
    }
    else
    {
        p_ConfirmButton->hide();
        p_CancelButton->move(this->width()/2 - (p_CancelButton->width()/2), this->height()- p_CancelButton->height()-10);
    }
}
void DialogWindow::CancelWindow()
{
    p_CancelButton->click();
}
