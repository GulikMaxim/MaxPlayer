#ifndef TRACKBUTTON_H
#define TRACKBUTTON_H

/*! \class  TrackButton
    \brief  Widget for working with one track

    View all infirmation about track. Can be active
*/

#include <QtGui>
#include <track.h>

class TrackButton : public QPushButton
{
    Q_OBJECT

    Track *p_Track; /*!< track objeck*/

    bool isPlayStatus;  /*!< play state of tracke */
    bool isActiveStatus;    /*!< active state of track */

    QLabel *p_ArtistNameLabel;  /*!< artist name label*/
    QLabel *p_TrackNameLabel;   /*!< track name label*/

    QLabel *p_ActiveStatusLineLabel; /*!< line for view activ state*/
    QLabel *p_PlayStatusTriangleLabel;  /*!< triangle for view play state*/

    QUrl *p_TrackUrl;   /*!< url of track*/
public:
    /*! \brief Constructor
      \param parent parent widget
    */
    explicit TrackButton(QWidget *parent = 0);

    bool PlayStatus(); /*!< \return return play status*/

    /*! \brief sets activ status
      \param isActive active status
    */
    void SetActiveStatus(bool isActive);

    /*! \brief sets play status
      \param isPlay play status
    */
    void SetPlayStatus(bool isPlay);

    /*! \brief open track by url
      \param trackUrl url of track
    */
    void OpenTrack(QUrl trackUrl);
    Track* GetTrack(); /*!< \return pointer on track object*/
    bool IsActive();    /*!< \return active status*/
    bool IsPlay();  /*!< \return play status */
    QUrl GetTrackUrl(); /*!< \return track url */

private:

signals:

public slots:

};

#endif // TRACKBUTTON_H
