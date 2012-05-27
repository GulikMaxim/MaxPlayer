#ifndef WINDOW_H
#define WINDOW_H

/*! \class Window
 \brief Window for displayed widgets
  */

#include <QFrame>
#include <QtGui>

class Window : public QFrame
{
    Q_OBJECT

private:
    QPoint *p_PreviousMouseCoordinates; /*!< save coordinates of mouse click for calculate position of moving window*/

    QPushButton *p_CloseWindowButton;   /*!< close window button*/
    QPushButton *p_MinimizeWindowButton;    /*!< minimize windiw button*/

public:
    /*! \brief Constructor
      \param parent parent widget
    */
    explicit Window(QWidget *parent = 0);

    void HideControlButtons();  /*!< hidden the controls buttons of window*/

    /*! \brief sets title of window
      \param title title text
    */
    void SetTitle(QString title);

    /*! \brief sets fixed size of window
      \param size size of window
    */
    void SetSize(QSize size);

private:
    void virtual mousePressEvent(QMouseEvent *p_MouseEvent);
    void virtual mouseMoveEvent(QMouseEvent *p_MouseEvent);
    void virtual mouseReleaseEvent(QMouseEvent *p_MouseEvent);

signals:
    void CloseWindowSignal();   /*!< calls when window was closed*/
    
public slots:
    
};

#endif // WINDOW_H
