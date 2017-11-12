#ifndef CAMERAFRAMEGRABBER_H
#define CAMERAFRAMEGRABBER_H

// Qt includes
#include <QAbstractVideoSurface>
#include <QList>
#include <QCamera>

class CameraFrameGrabber : public QAbstractVideoSurface
{
    Q_OBJECT
public:
    explicit CameraFrameGrabber(QObject *parent = 0);

    QList<QVideoFrame::PixelFormat> supportedPixelFormats(QAbstractVideoBuffer::HandleType handleType) const;

    bool present(const QVideoFrame &frame);
    int cnt=0;

signals:
    void frameAvailable(QImage frame);
};

#endif // CAMERAFRAMEGRABBER_H
