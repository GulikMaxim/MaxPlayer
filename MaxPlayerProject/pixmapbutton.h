#ifndef PIXMAPBUTTON_H
#define PIXMAPBUTTON_H

#include <QWidget>
#include <QtGui>


class PixmapButton : public QPushButton
{
    Q_OBJECT
public:
    explicit PixmapButton(QPixmap Pixmap, QSize size, QWidget *parent = 0);

    void SetFixedSize(QSize size);
    
signals:
    
public slots:
    
};

#endif // PIXMAPBUTTON_H
