#ifndef TITLEWIDGET_H
#define TITLEWIDGET_H

#include <QWidget>
#include <QtGui>

class TitleWidget : public QFrame
{
    Q_OBJECT

private:
    QLabel *p_TitleLabel;
    QLabel *p_Underline;

public:
    explicit TitleWidget(QWidget *parent = 0);
    TitleWidget(QString title,QWidget *parent=0);

    void SetTitleText(QString titleText);
    void SetTitleFont(QFont font);    
    void TitleMove(QPoint coordinates);
    void SetFrameWidth(int width);
    void ShowTitle(bool showStatus);

private:
    void SetUnderline();
    
signals:
    
public slots:
    
};

#endif // TITLEWIDGET_H
