#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include <phonon>
#include <window.h>
#include <audioplayerwidget.h>
#include <playlistwidget.h>
#include <explorerwidget.h>
#include <settingwidget.h>
#include <librarywidget.h>

class MainWindow : public Window
{
    Q_OBJECT

    QStackedWidget *p_ShiftingFieldWidgets; /*stack of widgets that shows at shifting field*/

    /*widgets that user can select when clicked on the one
    of buttons on the left side of player main window*/
    PlaylistWidget *p_PlaylistWidget;
    ExplorerWidget *p_ExplorerWidget;
    SettingWidget *p_SettingWidget;
    LibraryWidget *p_LibraryWidget;

    //player widget
    AudioPlayerWidget *p_AudioPlayerWidget;

    //palette of program
    QPalette *p_MainPalette;

    //left side control buttom
    QPushButton *p_PlaylistButton;
    QPushButton *p_LibraryButton;
    QPushButton *p_ExplorerButton;
    QPushButton *p_SettingButton;

public:
    explicit MainWindow(QWidget *parent = 0);
    void SetButtonTextColor(QPushButton* p_Button, const QColor & color);
    
signals:
    
public slots:
    void PlaylistButtonClickedSlot();
    void LibraryButtonClickedSlot();
    void ExplorerButtonClickedSlot();
    void SettingButtonClickedSlot();
};

#endif // MAINWINDOW_H
