#include "pixmapbutton.h"

PixmapButton::PixmapButton(QPixmap pixmap, QSize size , QWidget *parent) :
    QPushButton(parent)
{
    this->setFlat(true);
    this->setFixedSize(size);
    this->setIconSize(QSize(size.width()-4,size.height()-4));
    this->setIcon(pixmap);
}

//methods
void PixmapButton::SetFixedSize(QSize size)
{
    this->setFixedSize(size);
    this->setIconSize(QSize(size.width()-4,size.height()-4));
}
