#include "aboutwidget.h"

AboutWidget::AboutWidget(QWidget *parent) :
    TitleWidget(parent)
{
    //widget setup
    this->setFixedSize(432,522);
    this->ShowTitle(false);

    QPalette *p_ExplorerPalette = new QPalette();
    p_ExplorerPalette->setBrush(this->backgroundRole(),QBrush(QPixmap("shifftingWidgetBackgraund.jpg")));
    p_ExplorerPalette->setColor(QPalette::Text,Qt::cyan);
    this->setAutoFillBackground(true);
    this->setPalette(*p_ExplorerPalette);

    //information label setup
    p_AboutLabel =new QLabel(this);
    p_AboutLabel->setFixedSize(433,550);
    p_AboutLabel->setFrameStyle(QFrame::Box | QFrame::Raised);
    p_AboutLabel->move(-1,-25);
    p_AboutLabel->setAlignment(Qt::AlignCenter);

    //set information
    p_AboutLabel->setFont(QFont("Bauhaus 93",12,QFont::Normal));
    p_AboutLabel->setText("Max Player\n current version: 1.02 \n made by: Gulik Maxim\n support email: gmaxsmile@gmail.com");
    QPalette *p_AboutLabelPalette = new QPalette();
    p_AboutLabelPalette->setColor(QPalette::WindowText,Qt::cyan);
    p_AboutLabel->setPalette(*p_AboutLabelPalette);
}
