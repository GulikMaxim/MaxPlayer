#ifndef ENTERLINEDIALOGWINDOW_H
#define ENTERLINEDIALOGWINDOW_H

/*! \class EnterLineDialogWindow
    \brief widget for input information

    Includes line of editing for input information and label with name of informaiton
*/

#include <QtGui>
#include <dialogwindow.h>

class EnterLineDialogWindow : public DialogWindow
{
    Q_OBJECT

    QLabel *p_EditLineNameLabel;    /*!< name of input information*/
    QLineEdit *p_EditLine;  /*!< line of editing for input informtion*/
public:

    /*! \brief Constructor
        \param parent parent widget
    */
    explicit EnterLineDialogWindow(QWidget *parent = 0);
    
    /*! \brief establishment show state of edit line
        \param state show state

        if state = true edit line have show state, else hide state
    */
    void ShowEditLine(bool state);

signals:    
    void DialogWindowShowSignal(bool);  /*!< \brief  calls when dialog window setting show state*/
    void ConfirmButtonClickSignal(QString); /*!< \brief  calls when confirm button clicked*/
    
public slots:
    void CancelButtonClickedSlot(); /*!< \brief  cancels input line dialog window*/
    void ConfirmButtonClickedSlot();    /*!< \brief  saves input line*/
    
};

#endif // ENTERLINEDIALOGWINDOW_H
