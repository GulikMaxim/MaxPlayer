#include "mycheckablebutton.h"

MyCheckableButton::MyCheckableButton(QWidget*parent) :
    QPushButton(parent)
{
    //button setup
    this->setFlat(true);

    //icons setap
    p_TurnOnIcon = new QIcon();
    SetTurnOnIcon(QPixmap("lightgray.jpg"));
    p_TurnOffIcon = new QIcon();
    SetTurnOffIcon(QPixmap("darkgray.jpg"));

    connect(this,SIGNAL(clicked()),SLOT(MyCheckableButtonClickSlot()));

    SetCheckedState(false);
}

MyCheckableButton::MyCheckableButton(QPixmap turnOnPixmap, QPixmap TurnOfPixmap, QWidget *parent) :
    QPushButton(parent)
{
    //button setup
    this->setFlat(true);

    //icons setap
    p_TurnOnIcon = new QIcon();
    SetTurnOnIcon(turnOnPixmap);
    p_TurnOffIcon = new QIcon();
    SetTurnOffIcon(TurnOfPixmap);

    connect(this,SIGNAL(clicked()),SLOT(MyCheckableButtonClickSlot()));

    SetCheckedState(false);
}

//methods
bool MyCheckableButton::isChecked()
{
    return checked;
}
void MyCheckableButton::SetTurnOnIcon(QPixmap pixmap)
{
    p_TurnOnIcon->addPixmap(pixmap);
    //this->setIcon(*p_TurnOnIcon);
}
void MyCheckableButton::SetTurnOffIcon(QPixmap pixmap)
{
    p_TurnOffIcon->addPixmap(pixmap);
    //this->setIcon(*p_TurnOffIcon);
}
void MyCheckableButton::SetSize(QSize size)
{
    this->setFixedSize(size);
    this->setIconSize(QSize(size.height()-4,size.width()-4));
}
void MyCheckableButton::SetCheckedState(bool state)
{
    checked = state;
    if(checked)
    {
        this->setIcon(*p_TurnOnIcon);
    }
    else
    {
        this->setIcon(*p_TurnOffIcon);
    }
}
//slots
void MyCheckableButton::MyCheckableButtonClickSlot()
{
    if(this->isChecked())
    {
        checked = false;
        this->setIcon(*p_TurnOffIcon);
    }
    else
    {
        checked = true;
        this->setIcon(*p_TurnOnIcon);
    }
}
