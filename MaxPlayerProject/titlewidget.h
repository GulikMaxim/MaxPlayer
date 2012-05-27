#ifndef TITLEWIDGET_H
#define TITLEWIDGET_H

/*! \class  TitleWidget
    \brief  Widget with title
*/

#include <QWidget>
#include <QtGui>

class TitleWidget : public QFrame
{
    Q_OBJECT

private:
    QLabel *p_TitleLabel; /*!< title label */
    QLabel *p_Underline;

public:
    /*! \brief Constructor
      \param parent parent widget
    */
    explicit TitleWidget(QWidget *parent = 0);
    /*! \brief Constructor
      \param title title of window
      \param parent parent widget
    */
    TitleWidget(QString title,QWidget *parent=0);

    /*! \brief sets title text
      \param titleText text of title
    */
    void SetTitleText(QString titleText);

    /*! \brief sets title font
      \param font font of title
    */
    void SetTitleFont(QFont font);

    /*! \brief moves title
      \param coordinates coordinates of title
    */
    void TitleMove(QPoint coordinates);

    /*! \brief sets frame width
      \param width frame with
    */
    void SetFrameWidth(int width);

    /*! \brief sets show title state
      \param showStatus show title state

      if state is true - title showes
    */
    void ShowTitle(bool showStatus);

private:
    void SetUnderline();
    
signals:
    
public slots:
    
};

#endif // TITLEWIDGET_H
