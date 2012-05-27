#ifndef MYCHECKABLEBUTTON_H
#define MYCHECKABLEBUTTON_H

/*! \class MyCheckableButton
    \brief checkable button

    It has the ability to set the image on the on or off modes
*/

#include <QPushButton>

class MyCheckableButton : public QPushButton
{
    Q_OBJECT

public:
    /*! \brief Constructor
      \param parent parent widget
    */
    explicit MyCheckableButton(QWidget *parent = 0);

    /*! \brief Constructor
      \param turnOnPixmap on mode image
      \param TurnOfPixmap off mode image
      \param parent parent widget
    */
    MyCheckableButton(QPixmap turnOnPixmap, QPixmap TurnOfPixmap, QWidget *parent = 0);

private:
    QIcon *p_TurnOnIcon;    /*!< on mode icon*/
    QIcon *p_TurnOffIcon;   /*!< of mode icon*/

    bool checked;   /*!< checked state*/

public:

    bool isChecked();   /*!< \return current state */

    /*! \brief sets on mode image
      \param pixmap  image
    */
    void SetTurnOnIcon(QPixmap pixmap);

    /*! \brief sets off mode image
      \param pixmap image
    */
    void SetTurnOffIcon(QPixmap pixmap);

    /*! \brief sets fixed size of button
      \param size size
    */
    void SetSize(QSize size);

    /*! \brief establishment chcked state of buuton
        \param state checked state

        if state = true button is checked, else isn't checked
    */
    void SetCheckedState(bool status);
    
signals:
    
public slots:
    void MyCheckableButtonClickSlot(); /*!< changes cheked state state*/
    
};

#endif // MYCHECKABLEBUTTON_H
