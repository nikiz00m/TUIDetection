#ifndef FRAMEGRABBER_H
#define FRAMEGRABBER_H

#include <QAbstractVideoSurface>
#include <QList>
#include <QImage>
class frameGrabber : public QAbstractVideoSurface
{
public:
    frameGrabber();

    bool present(const QVideoFrame &frame);
};

#endif // FRAMEGRABBER_H
