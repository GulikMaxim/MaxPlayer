#ifndef WINDOW_H
#define WINDOW_H

#include <QFrame>
#include <QtGui>

class Window : public QFrame
{
    Q_OBJECT

    QPoint *p_PreviousMouseCoordinates;     // save coordinates of mouse click for calculate position of moving window

public:
    explicit Window(QWidget *parent = 0);

private:
    void virtual mousePressEvent(QMouseEvent *p_MouseEvent);
    void virtual mouseMoveEvent(QMouseEvent *p_MouseEvent);
    void virtual mouseReleaseEvent(QMouseEvent *p_MouseEvent);
    
signals:
    
public slots:
    
};

#endif // WINDOW_H
