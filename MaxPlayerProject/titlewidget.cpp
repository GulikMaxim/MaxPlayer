#include "titlewidget.h"

TitleWidget::TitleWidget(QWidget *parent) : QFrame(parent)
{
    //widet setup
    this->setFrameStyle(QFrame::Sunken| QFrame::Box);
    this->setLineWidth(0);

    p_Underline = new QLabel(this);
    p_Underline->setFrameStyle(QFrame::Sunken | QFrame::HLine);
    p_Underline->setFixedHeight(1);

    p_TitleLabel = new QLabel(this);

    TitleMove(QPoint(5,3));
    SetTitleFont(QFont("Constantia",9,QFont::Light));

}

TitleWidget::TitleWidget(QString title,QWidget *parent) : QFrame(parent)
{
    //widet setup
    this->setFrameStyle(QFrame::Sunken | QFrame::Box);
    this->setLineWidth(0);

    p_Underline = new QLabel(this);
    p_Underline->setFrameStyle(QFrame::Sunken| QFrame::HLine);

    p_TitleLabel = new QLabel(title,this);

    TitleMove(QPoint(5,3));
    SetTitleFont(QFont("Constantia",9,QFont::Light));
}

//methods
void TitleWidget::SetTitleText(QString titleText)
{
    p_TitleLabel->setText(titleText);
}
void TitleWidget::TitleMove(QPoint coordinates)
{
    p_TitleLabel->move(coordinates.x(),coordinates.y());
    SetUnderline();
}
void TitleWidget::SetTitleFont(QFont font)
{
    p_TitleLabel->setFont(font);
    SetUnderline();
}
void TitleWidget::SetFrameWidth(int width)
{
    this->setLineWidth(width);
}
void TitleWidget::SetUnderline()
{
    QPoint underlineCoordinates(100,100);
    underlineCoordinates.setX(p_TitleLabel->x());
    underlineCoordinates.setY(p_TitleLabel->y()+p_TitleLabel->font().pointSize()+4);
    p_Underline->setFixedWidth(p_TitleLabel->width());
    p_Underline->move(underlineCoordinates);
}
void TitleWidget::ShowTitle(bool showStatus)
{
    if(showStatus)
    {
        p_TitleLabel->show();
        p_Underline->show();
    }
    else
    {
        p_TitleLabel->hide();
        p_Underline->hide();
    }
}
