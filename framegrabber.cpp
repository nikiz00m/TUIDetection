#include "framegrabber.h"

frameGrabber::frameGrabber()
{

}

QImage frameGrabber::present(const QVideoFrame &frame)
{
    if (frame.isValid()) {
            QVideoFrame cloneFrame(frame);
            cloneFrame.map(QAbstractVideoBuffer::ReadOnly);
            const QImage image(cloneFrame.bits(),
                               cloneFrame.width(),
                               cloneFrame.height(),
                               QVideoFrame::imageFormatFromPixelFormat(cloneFrame .pixelFormat()));
            emit frameAvailable(image);
            cloneFrame.unmap();
            return true;
        }
        return false;
}
