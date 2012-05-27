#include "window.h"

Window::Window(QWidget *parent) :
    QFrame(parent)
{
    //window setup
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setFixedSize(526,620);

    //Control and window buttons setup
    p_CloseWindowButton = new QPushButton(this);
    p_CloseWindowButton->setFlat(true);
    p_CloseWindowButton->setFixedSize(20,20);
    p_CloseWindowButton->setIconSize(QSize(16,16));
    p_CloseWindowButton->setIcon(QIcon(QPixmap(".\\close.png")));
    p_CloseWindowButton->move(480,6);
    connect(p_CloseWindowButton,SIGNAL(clicked()),SLOT(close()));
    connect(p_CloseWindowButton,SIGNAL(clicked()),SIGNAL(CloseWindowSignal()));

    p_MinimizeWindowButton = new QPushButton(this);
    p_MinimizeWindowButton->setFlat(true);
    p_MinimizeWindowButton->setFixedSize(20,20);
    p_MinimizeWindowButton->setIconSize(QSize(16,16));
    p_MinimizeWindowButton->setIcon(QIcon(QPixmap(".\\minimize.png")));
    p_MinimizeWindowButton->move(500,6);
    connect(p_MinimizeWindowButton,SIGNAL(clicked()),SLOT(showMinimized()));
}

//methods
void Window::SetSize(QSize size)
{
    this->setFixedSize(size);
    p_CloseWindowButton->move(size.width()-50,6);
    p_MinimizeWindowButton->move(size.width()-30,6);
}
void Window::HideControlButtons()
{
    p_CloseWindowButton->hide();
    p_MinimizeWindowButton->hide();
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

