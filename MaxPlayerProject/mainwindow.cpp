#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : Window(parent)
{
    //main window setup
    p_MainPalette = new QPalette(Qt::cyan,Qt::black);               // set font's and backgrod colors
    this->setPalette(*p_MainPalette);
    this->setFont(QFont("Bauhaus 93",10,QFont::Normal));
    this->setFixedSize(526,480);
    this->setStyle(new QPlastiqueStyle());

    //control buttons setup
    p_PlaylistButton = new QPushButton("Playlist",this);
    p_PlaylistButton->setCheckable(true);
    p_PlaylistButton->setFlat(true);
    p_PlaylistButton->setFixedSize(80,60);
    p_PlaylistButton->move(3,30);
    p_PlaylistButton->setStyle(new QPlastiqueStyle());
    connect(p_PlaylistButton,SIGNAL(clicked()),SLOT(PlaylistButtonClickedSlot()));

    p_LibraryButton = new QPushButton("Library",this);
    p_LibraryButton->setCheckable(true);
    p_LibraryButton->setFlat(true);
    p_LibraryButton->setFixedSize(80,60);
    p_LibraryButton->move(3,90);
    p_LibraryButton->setStyle(new QPlastiqueStyle());
    connect(p_LibraryButton,SIGNAL(clicked()),SLOT(LibraryButtonClickedSlot()));

    p_ExplorerButton = new QPushButton("Explorer",this);
    p_ExplorerButton->setCheckable(true);
    p_ExplorerButton->setFlat(true);
    p_ExplorerButton->setFixedSize(80,60);
    p_ExplorerButton->move(3,150);
    p_ExplorerButton->setStyle(new QPlastiqueStyle());
    connect(p_ExplorerButton,SIGNAL(clicked()),SLOT(ExplorerButtonClickedSlot()));

    p_SettingButton = new QPushButton("Settings",this);
    p_SettingButton->setCheckable(true);
    p_SettingButton->setFlat(true);
    p_SettingButton->setFixedSize(80,60);
    p_SettingButton->move(3,210);
    p_SettingButton->setStyle(new QPlastiqueStyle());
    connect(p_SettingButton,SIGNAL(clicked()),SLOT(SettingButtonClickedSlot()));

    //Player widget setup
    p_AudioPlayerWidget = new AudioPlayerWidget();
    p_AudioPlayerWidget->setParent(this);
    p_AudioPlayerWidget->move(83,380);

    //Shifting widgets setup
    QQueue<QUrl> songs;
    songs << QUrl("D:\\Sound\\06. George Michael - Jesus To A Child.mp3");
    songs << QUrl("D:\\vintazh_i_dj_smash_-_moskva_(zaycev.net).mp3");
    songs << QUrl("D:\\February_session_2012.mp3");
    songs << QUrl("D:\\the_beatles_-_yesterday.mp3");
    songs << QUrl("D:\\Sound\\01. Black - Wonderful Life.mp3");
    songs << QUrl("D:\\Sound\\02. Celine Dion - My Heart Will Go On.mp3");
    songs << QUrl("D:\\Sound\\03. No Doubt - Don't Speak.mp3");
    songs << QUrl("D:\\Sound\\04. Chris Isaak - Wicked Game.mp3");


    p_PlaylistWidget = new PlaylistWidget(songs);
    p_LibraryWidget = new LibraryWidget();
    p_ExplorerWidget = new ExplorerWidget();
    p_SettingWidget = new SettingWidget();

    //Shifting widgets stack setup
    p_ShiftingFieldWidgets = new QStackedWidget(this);
    p_ShiftingFieldWidgets->setFixedSize(437,352);
    p_ShiftingFieldWidgets->setFrameStyle(QFrame::Box | QFrame::Sunken);
    p_ShiftingFieldWidgets->move(83,30);
    p_ShiftingFieldWidgets->addWidget(p_PlaylistWidget);
    p_ShiftingFieldWidgets->addWidget(p_LibraryWidget);
    p_ShiftingFieldWidgets->addWidget(p_ExplorerWidget);
    p_ShiftingFieldWidgets->addWidget(p_SettingWidget);

    emit(p_PlaylistButton->click());  // work begin with playlist state
    p_AudioPlayerWidget->ConnectPlaylist(p_PlaylistWidget);    // connect playlist with player widget
}

//slots
void MainWindow::PlaylistButtonClickedSlot()
{
    if(p_LibraryButton->isChecked())    // cheking state of other buttons and change colors of them
    {
        p_LibraryButton->setChecked(false);
        SetButtonTextColor(p_LibraryButton,Qt::white);
    }
    else
    {
        if(p_ExplorerButton->isChecked())
        {
            p_ExplorerButton->setChecked(false);
            SetButtonTextColor(p_ExplorerButton,Qt::white);
        }
        else
        {
            if(p_SettingButton->isChecked())
            {
                p_SettingButton->setChecked(false);
                SetButtonTextColor(p_SettingButton,Qt::white);
            }
        }
    }

    if(p_PlaylistButton->isChecked())
    {
        this->SetButtonTextColor(p_PlaylistButton,Qt::black);
        p_ShiftingFieldWidgets->setCurrentWidget(p_PlaylistWidget);
    }
    else
    {
        p_PlaylistButton->setChecked(true);
    }
}
void MainWindow::LibraryButtonClickedSlot()
{
    if(p_PlaylistButton->isChecked())    // cheking state of other buttons and change colors of them
    {
        p_PlaylistButton->setChecked(false);
        SetButtonTextColor(p_PlaylistButton,Qt::white);
    }
    else
    {
        if(p_ExplorerButton->isChecked())
        {
            p_ExplorerButton->setChecked(false);
            SetButtonTextColor(p_ExplorerButton,Qt::white);
        }
        else
        {
            if(p_SettingButton->isChecked())
            {
                p_SettingButton->setChecked(false);
                SetButtonTextColor(p_SettingButton,Qt::white);
            }
        }
    }

    if(p_LibraryButton->isChecked())
    {
        SetButtonTextColor(p_LibraryButton,Qt::black);
        p_ShiftingFieldWidgets->setCurrentWidget(p_LibraryWidget);
    }
    else
    {
        p_LibraryButton->setChecked(true);
    }
}
void MainWindow::ExplorerButtonClickedSlot()
{
    if(p_PlaylistButton->isChecked())    // cheking state of other buttons and change colors of them
    {
        p_PlaylistButton->setChecked(false);
        SetButtonTextColor(p_PlaylistButton,Qt::white);
    }
    else
    {
        if(p_LibraryButton->isChecked())
        {
            p_LibraryButton->setChecked(false);
            SetButtonTextColor(p_LibraryButton,Qt::white);
        }
        else
        {
            if(p_SettingButton->isChecked())
            {
                p_SettingButton->setChecked(false);
                SetButtonTextColor(p_SettingButton,Qt::white);
            }
        }
    }

    if(p_ExplorerButton->isChecked())
    {
        SetButtonTextColor(p_ExplorerButton,Qt::black);
        p_ShiftingFieldWidgets->setCurrentWidget(p_ExplorerWidget);
    }
    else
    {
        p_ExplorerButton->setChecked(true);
    }
}
void MainWindow::SettingButtonClickedSlot()
{
    if(p_PlaylistButton->isChecked())    // cheking state of other buttons and change colors of them
    {
        p_PlaylistButton->setChecked(false);
        SetButtonTextColor(p_PlaylistButton,Qt::white);
    }
    else
    {
        if(p_LibraryButton->isChecked())
        {
            p_LibraryButton->setChecked(false);
            SetButtonTextColor(p_LibraryButton,Qt::white);
        }
        else
        {
            if(p_ExplorerButton->isChecked())
            {
                p_ExplorerButton->setChecked(false);
                SetButtonTextColor(p_ExplorerButton,Qt::white);
            }
        }
    }

    if(p_SettingButton->isChecked())
    {
        SetButtonTextColor(p_SettingButton,Qt::black);
        p_ShiftingFieldWidgets->setCurrentWidget(p_SettingWidget);
    }
    else
    {
        p_SettingButton->setChecked(true);
    }
}

//methods
void MainWindow::SetButtonTextColor(QPushButton *p_Button,const QColor & color)
{
    QPalette buttonPalette = p_Button->palette();
    buttonPalette.setColor(QPalette::ButtonText,color);
    p_Button->setPalette(buttonPalette);
}
