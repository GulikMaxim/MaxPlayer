#ifndef PIXMAPBUTTON_H
#define PIXMAPBUTTON_H

/*! \class PixmapButton
    \brief pixmap button

    It has the ability to set the image
*/

#include <QWidget>
#include <QtGui>


class PixmapButton : public QPushButton
{
    Q_OBJECT
public:
    /*! \brief Constructor
      \param pixmap seted image
      \param size button size
      \param parent parent widget
    */
    explicit PixmapButton(QPixmap pixmap, QSize size, QWidget *parent = 0);

    /*! \brief sets fixed size
      \param size button size
    */
    void SetFixedSize(QSize size);
    
signals:
    
public slots:
    
};

#endif // PIXMAPBUTTON_H
