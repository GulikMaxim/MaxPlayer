#include "explorerwidget.h"

ExplorerWidget::ExplorerWidget(QWidget *parent) :
    TitleWidget(parent)
{
    //widget setap
    this->setFixedSize(432,522);
    this->SetTitleText("Menu");
    this->SetTitleFont(QFont("Bauhaus 93",9,QFont::Normal));
    this->TitleMove(QPoint(372,2));

    QPalette *p_ExplorerPalette = new QPalette();
    p_ExplorerPalette->setBrush(this->backgroundRole(),QBrush(QPixmap("shifftingWidgetBackgraund.jpg")));
    this->setAutoFillBackground(true);
    this->setPalette(*p_ExplorerPalette);
    this->ShowTitle(false);

    //explorer menu setup
    p_ExplorerMenuButton = new MyCheckableButton(QPixmap("MenuTurnOn.png"),QPixmap("Menu.png"),this);
    p_ExplorerMenuButton->move(416,20);
    p_ExplorerMenuButton->SetSize(QSize(16,16));
    connect(p_ExplorerMenuButton,SIGNAL(clicked()),SLOT(ExplorerMenuButtonClickSlot()));

    p_AddSongsInPlaylistButton= new PixmapButton(QPixmap("OpenTracks.png"),QSize(36,36),this);
    p_AddSongsInPlaylistButton->move(382,50);
    p_AddSongsInPlaylistButton->hide();
    connect(p_AddSongsInPlaylistButton,SIGNAL(clicked()),SLOT(AddSongsInPlaylistButtonClickSlot()));

    //explorer setup
    QStringList formats;
    formats<<"*.aa"<<"*.aac"<<"*.amr"<<"*.ape"<<"*.asf"<<"*.cda"<<"*.flac"<<"*.mp3"<<"*.mt9"<<"*.ogg"<<"*.voc"<<"*.wav"<<"*.wma";

    //model setup
    p_DirModel = new QDirModel();
    p_DirModel->setFilter(QDir::AllDirs | QDir::Files | QDir::NoDotAndDotDot);
    p_DirModel->setNameFilters(formats);

    //view setup
    p_TreeView = new QTreeView(this);
    p_TreeView->move(0,-1);
    p_TreeView->setModel(p_DirModel);
    p_TreeView->setFixedSize(416,524);
    p_TreeView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    p_TreeView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    p_TreeView->setFrameStyle(QFrame::Box | QFrame::Raised);
    p_TreeView->setHeaderHidden(true);
    p_TreeView->setColumnHidden(3,true);
    p_TreeView->setColumnHidden(2,true);
    p_TreeView->setColumnWidth(0,350);
    p_TreeView->setColumnWidth(1,66);
    p_TreeView->setSortingEnabled(true);
    p_TreeView->setSelectionMode(QAbstractItemView::MultiSelection);

    //connect(p_TreeView,SIGNAL(clicked(QModelIndex)),SLOT(ElementClickedSlot(QModelIndex)));
}

//methods
void ExplorerWidget::ClearSelection()
{
    selectedSongs.clear();
}
void ExplorerWidget::OpenMenu(bool openStatus)
{
    QTime t;
    if(openStatus)
    {
        for(int width=416;width>=370;width--)    //delay for smooth opening
        {
            t.start();
            for(;t.elapsed()<2;){}
            p_TreeView->setFixedWidth(width);
            QApplication::processEvents();
        }
    }
    else
    {
        for(int width=370;width<=416;width++)    //delay for smooth opening
        {
            t.start();
            for(;t.elapsed()<2;){}
            p_TreeView->setFixedWidth(width);
            QApplication::processEvents();
        }
    }
}
QList<QUrl> ExplorerWidget::GetSelectedSongs()
{
    return selectedSongs;
}
//slots
void ExplorerWidget::ExplorerMenuButtonClickSlot()
{
    if(p_ExplorerMenuButton->isChecked())
    {
        this->ShowTitle(true);
        this->OpenMenu(true);
        p_AddSongsInPlaylistButton->show();
    }
    else
    {
        p_AddSongsInPlaylistButton->hide();
        this->OpenMenu(false);
        this->ShowTitle(false);
    }
}
/*void ExplorerWidget::ElementClickedSlot(QModelIndex index)
{
    QFileInfo activeElement = p_DirModel->fileInfo(index);

    if(activeElement.isFile())  //if active element is file
    {
        QUrl songPath(activeElement.absoluteFilePath());
        if(!selectedSongs.removeOne(songPath))   //if it file has not been added to the selected songs list
        {
            selectedSongs<<songPath;
        }
    }
}*/
void ExplorerWidget::AddSongsInPlaylistButtonClickSlot()
{
    QItemSelectionModel *p_SelectionModel= p_TreeView->selectionModel();
    QModelIndexList selectedIndexesList = p_SelectionModel->selectedRows();

    for(int index = 0;index < selectedIndexesList.size(); index++)  // devided on 4, because need indexes of first column from four
    {
        QFileInfo activeElement = p_DirModel->fileInfo(selectedIndexesList[index]);
        if(activeElement.isFile())
        {
            QUrl songPath(activeElement.absoluteFilePath());
            if(!selectedSongs.removeOne(songPath))
            {
                selectedSongs<<songPath;
            }
        }
    }
    p_SelectionModel->clearSelection();

    emit AddSongsInPlaylistSignal();
}
