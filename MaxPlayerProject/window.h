#ifndef WINDOW_H
#define WINDOW_H

#include <QFrame>
#include <QtGui>

class Window : public QFrame
{
    Q_OBJECT

private:
    QPoint *p_PreviousMouseCoordinates;     // save coordinates of mouse click for calculate position of moving window

    QPushButton *p_CloseWindowButton;
    QPushButton *p_MinimizeWindowButton;

public:
    explicit Window(QWidget *parent = 0);

    void HideControlButtons();
    void SetTitle(QString title);

private:
    void virtual mousePressEvent(QMouseEvent *p_MouseEvent);
    void virtual mouseMoveEvent(QMouseEvent *p_MouseEvent);
    void virtual mouseReleaseEvent(QMouseEvent *p_MouseEvent);

public:
    void SetSize(QSize size);
    
signals:
    void CloseWindowSignal();
    
public slots:
    
};

#endif // WINDOW_H
