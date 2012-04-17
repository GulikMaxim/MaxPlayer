#include "window.h"

Window::Window(QWidget *parent) :
    QFrame(parent)
{
    //window setup
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setFrameStyle(QFrame::Plain | QFrame::Box);

    //Logo setup
    QLabel *p_LogoLabel = new QLabel(this);
    p_LogoLabel->setFont(QFont("Freestyle script",15,QFont::Normal));  //Chiller
    //p_LogoLabel->setFixedSize(150,20);
    p_LogoLabel->setText("                          MaxPLayer. Only music...");
    p_LogoLabel->move(0,3);

    //Control and window buttons setup
    QPushButton *p_CloseWindowButton = new QPushButton(this);
    p_CloseWindowButton->setFlat(true);
    p_CloseWindowButton->setFixedSize(20,20);
    p_CloseWindowButton->setIconSize(QSize(16,16));
    p_CloseWindowButton->setIcon(QIcon(QPixmap(".\\close.png")));
    p_CloseWindowButton->move(480,3);
    connect(p_CloseWindowButton,SIGNAL(clicked()),SLOT(close()));

    QPushButton *p_MinimizeWindowButton = new QPushButton(this);
    p_MinimizeWindowButton->setFlat(true);
    p_MinimizeWindowButton->setFixedSize(20,20);
    p_MinimizeWindowButton->setIconSize(QSize(16,16));
    p_MinimizeWindowButton->setIcon(QIcon(QPixmap(".\\minimize.png")));
    p_MinimizeWindowButton->move(500,3);
    connect(p_MinimizeWindowButton,SIGNAL(clicked()),SLOT(showMinimized()));

    /*QGridLayout *p_ControlButtonsLayout = new QGridLayout();
    p_ControlButtonsLayout->addWidget(p_LogoLabel,0,4,1,1);
    p_ControlButtonsLayout->addWidget(p_CloseWindowButton,0,5,1,1);
    p_ControlButtonsLayout->addWidget(p_MinimizeWindowButton,0,6,1,1);
    this->setLayout(p_ControlButtonsLayout);*/
}

//events
void Window::mousePressEvent(QMouseEvent *p_MouseEvent)
{
    p_PreviousMouseCoordinates = new QPoint(p_MouseEvent->x(),p_MouseEvent->y());
    this->setCursor(QCursor(Qt::SizeAllCursor));
}
void Window::mouseMoveEvent(QMouseEvent *p_MouseEvent)
{
    int coordDifX,coordDifY;   // difference of previous and current mouse coordinates
    coordDifX = p_MouseEvent->x() - p_PreviousMouseCoordinates->x();
    coordDifY = p_MouseEvent->y() - p_PreviousMouseCoordinates->y();
    this->move(this->x()+coordDifX,this->y()+coordDifY);
}
void Window::mouseReleaseEvent(QMouseEvent *p_MouseEvent)
{
    this->setCursor(QCursor(Qt::ArrowCursor));
}

