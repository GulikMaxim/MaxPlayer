#ifndef ABOUTWIDGET_H
#define ABOUTWIDGET_H


/*! \class AboutWidget
 \brief Widget contains the information about player

  Includes information about developer,
  support email and current version of player
*/

#include <QtGui>
#include <titlewidget.h>

class AboutWidget : public TitleWidget
{
    Q_OBJECT

    QLabel* p_AboutLabel; /*!< information label*/
public:
    explicit AboutWidget(QWidget *parent = 0);
    
signals:
    
public slots:
    
};

#endif // ABOUTWIDGET_H
