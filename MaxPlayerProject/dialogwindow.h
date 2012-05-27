#ifndef DIALOGWINDOW_H
#define DIALOGWINDOW_H

/*! \class DialogWindow
  \brief widget for confirm operation perfomance

  Includes the field with information about operation, the confirm and cancel buttons.
  */

#include <QtGui>
#include <titlewidget.h>

class DialogWindow : public TitleWidget
{
    Q_OBJECT

    QPushButton *p_ConfirmButton;   /*!< button at confirm operation*/
    QPushButton *p_CancelButton;    /*!< button at cancel operations*/

    QLabel *p_InformationLabel; /*!< this label includes all information about performance operation*/

public:
    /*! \brief Constructo
        \param parent parent widget
        */
    explicit DialogWindow(QWidget *parent = 0);

    /*! \brief establishes text on confirming button
        \param text the establishment text*/
    void SetConfirmButtonText(QString text);

    /*! \brief establishes text on canceling button
        \param text the establishment text*/
    void SetCancelButtonText(QString text);    

    /*! \brief establishes fixed size of a control button
        \param size establishment size*/
    void SetControlButtonsSize(QSize size);

    /*! \brief establishes fixed size of a dialog window
        \param size establishment size*/
    void SetFixedSize(QSize size);

    /*! \brief establishment show state
        \param state show state

        if state = true dialog window have show state, else hide state
    */
    void ShowInformationLabel(bool state);

    /*! \brief  establishes information text
        \param text establishes text
    */
    void SetInformationLabelText(QString text);

    /*! \brief establishment show state of confirm button
        \param state show state

        if state = true confirm button have show state, else hide state
    */
    void ShowConfirmButton(bool state);

    /*! \brief  cancel dialog window
    */
    void CancelWindow();
    
signals:
    void CancelButtonClickSignal(); /*!< \brief  calls when cancle button clicked*/
    void ConfirmButtonClickSignal(); /*!< \brief  calls when confirm button clicked*/
    
public slots:
};

#endif // DIALOGWINDOW_H
