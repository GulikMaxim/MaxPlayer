#include "enterlinedialogwindow.h"

EnterLineDialogWindow::EnterLineDialogWindow(QWidget *parent) :
    DialogWindow(parent)
{
    //dialog window setup
    this->setFixedSize(300,100);

    QPalette editLinePalette;
    editLinePalette.setColor(QPalette::Base,Qt::black);

    p_EditLineNameLabel = new QLabel("Enter name: ",this);
    p_EditLineNameLabel->setFont(QFont("Bauhaus 93",9,QFont::Normal));
    p_EditLineNameLabel->move(15,40);

    p_EditLine = new QLineEdit(this);
    p_EditLine->setPalette(editLinePalette);
    p_EditLine->setFixedWidth(200);
    p_EditLine->setFont(QFont("Constantia",9,QFont::Light));
    p_EditLine->setFrame(QFrame::Sunken | QFrame::Box);
    p_EditLine->move(85,37);

    connect(this,SIGNAL(CancelButtonClickSignal()),SLOT(CancelButtonClickedSlot()));
    connect(this,SIGNAL(ConfirmButtonClickSignal()),SLOT(ConfirmButtonClickedSlot()));
}

//methods
void EnterLineDialogWindow::ShowEditLine(bool state)
{
    if(state)
    {
        p_EditLineNameLabel->show();
        p_EditLine->show();
        p_EditLine->clear();
    }
    else
    {
        p_EditLineNameLabel->hide();
        p_EditLine->hide();
    }
}

//slots
void EnterLineDialogWindow::CancelButtonClickedSlot()
{
    this->ShowConfirmButton(true);
    this->ShowInformationLabel(false);
    this->ShowEditLine(true);
    emit DialogWindowShowSignal(false);
}
void EnterLineDialogWindow::ConfirmButtonClickedSlot()
{
    QString editLineText = p_EditLine->text();
    if(editLineText.size())
    {
        emit ConfirmButtonClickSignal(editLineText);
    }
    else
    {
        this->ShowEditLine(false);
        this->ShowConfirmButton(false);
        this->ShowInformationLabel(true);
    }
}
