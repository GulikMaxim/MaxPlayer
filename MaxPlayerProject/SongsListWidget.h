#ifndef SONGSLISTWIDGET_H
#define SONGSLISTWIDGET_H

/*! \class  SongsListWidget
    \brief  Widget for view tarck list
*/

#include <QWidget>
#include <QtGui>
#include <trackbutton.h>
#include <phonon>

class SongsListWidget : public QScrollArea
{
    Q_OBJECT

    QList<TrackButton*> trackButtonsList;   /*!< list of tracks buttons*/
    QWidget *p_EmbeddableListSongWidget;     /*!< embeddable widget in scroll area, which is SongsListWidget. It will include list of songs */

    QList<int> selectedTracksIndexes;    /*!< list of seleted tracks indexes for working with group of tracks */
    int playTrackIndex; /*!< play tarck index*/

    bool multiSelectedMode;  /*!< state of multi selected mode */

public:
    /*! \brief Constructor
      \param songListUrl list of songs urls
      \param parent parent widget
    */
    explicit SongsListWidget(QList<QUrl> songListUrl, QWidget *parent = 0);
    /*! \brief Constructor
      \param parent parent widget
    */
    explicit SongsListWidget(QWidget *parent);
    TrackButton* GetSelectedTrack(); /*!< \return selected track*/
    TrackButton* GetNextPlayTrack(bool randomGanneration = false);  /*!< \return next track index*/
    TrackButton* GetPlayTrack();    /*!< \return play track*/
    int GetPlayTrackIndex();    /*!< \return play track index*/
    int GetTrackIndex(Phonon::MediaObject* p_PlayTrackObject);  /*!< \return track index*/
    int GetTracksQuantity();    /*!< \return quantity of tracks*/
    bool IsMultiSelectedMode(); /*!< \return multiselected state*/

    /*! \brief sets multi selected mode
        \param state multi selected state

        If state is true - multiselected mode is active
    */
    void SetMultiSelectedMode(bool state);

    /*! \brief sets fixed width
        \param width width of playlist widget
    */
    void SetFixedWidth(int width);

    /*! \brief opens tracks by urls
        \param songsUrls list of songs urls
    */
    void OpenTracks(QList<QUrl> songsUrls);
    void Clear();   /*!< clear playlists list*/
    bool isEmpty(); /*!< \return empty state*/
    QList<TrackButton*> GetTrackButtonsList();  /*!< \return track buttons list*/

    /*! \brief set play track index
        \param trackIndex setting track index
    */
    void SetPlayTrackIndex(int trackIndex);

private:
    void FillInTracksListWidget();
    
signals:
    void TrackButtonClickSignal();  /*!< calls when track button was clicked*/
    void songListChangedSignal();   /*!< calls when list of songs was changed*/
    
public slots:
    void TrackButtonClickSlot();    /*!< chenge cheking track state*/
    void RemoveSelectedTracksSlot();    /*!< remove selected track */
    void LeaveSelectedTracksSlot(); /*!< leave selected tracks*/
    
};

#endif // SONGSLISTWIDGET_H
