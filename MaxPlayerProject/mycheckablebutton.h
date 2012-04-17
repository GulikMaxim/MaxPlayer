#ifndef MYCHECKABLEBUTTON_H
#define MYCHECKABLEBUTTON_H

#include <QPushButton>

class MyCheckableButton : public QPushButton
{
    Q_OBJECT

public:
    explicit MyCheckableButton(QWidget *parent = 0);
    MyCheckableButton(QPixmap turnOnPixmap, QPixmap TurnOfPixmap, QWidget *parent = 0);

private:
    QIcon *p_TurnOnIcon;
    QIcon *p_TurnOffIcon;

    bool checked;

public:
    bool isChecked();
    void SetTurnOnIcon(QPixmap pixmap);
    void SetTurnOffIcon(QPixmap pixmap);
    void SetSize(QSize size);
    void SetCheckedState(bool status);
    
signals:
    
public slots:
    void MyCheckableButtonClickSlot();
    
};

#endif // MYCHECKABLEBUTTON_H
