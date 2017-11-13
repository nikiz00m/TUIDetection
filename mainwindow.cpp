#include "mainwindow.h"
#include "cameraframegrabber.h"
#include "mydetectioncount.h"
#include <QLabel>
#include <QDebug>
#include <QTransform>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , label(new QLabel)
{
    setWindowTitle("Detect");
    auto camera = new QCamera();
    auto frameGr = new CameraFrameGrabber();
    camera->setViewfinder(frameGr);
    connect(frameGr, SIGNAL(frameAvailable(QImage)), this, SLOT(handleFrame1(QImage)));
    camera->start();
}

MainWindow::~MainWindow()
{

}
void MainWindow::changeWindow(QImage image)
{
    this->resize(1000 , 800 );
    QPixmap pixm = QPixmap::fromImage(image).scaled(1000, 800 );
    label->setPixmap(pixm);
    setCentralWidget(label);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    //qDebug() << event->pos() << counter;
    if (counter == 0)
    {
        this->xS = event->pos().x();
        this->yS = event->pos().y();
        counter = counter + 1;
    }
    else
    {
        if (counter == 1)
        {
            this->xS1 = event->pos().x();
            this->yS1 = event->pos().y();
            counter = counter + 1;
        }
        else
        {
            if (counter == 2)
            {
                 this->xS2 = event->pos().x();
                 this->yS2 = event->pos().y();
                 counter = counter + 1;
            }
            else
            {
                if (counter == 3)
                {
                    this->xS3 = event->pos().x();
                    this->yS3 = event->pos().y();
                    counter = counter + 1;
                }
                else
                {
                    if (counter == 4)
                    {
                        this->xArr = event->pos().x();
                        this->yArr = event->pos().y();
                        counter = counter + 1;
                        MAXN1 = QInputDialog::getInt(this,"Показания","Максимальное показание амперметра",0,0,100,1);
                    }
                }
            }
        }
    }
}
void MainWindow::sendCoord(int kx, int ky)
{
    count1.xL = kx * std::min(xS,xS1);
    count1.xR = kx * std::max(xS,xS1);
    count1.yup = ky * std::max(yS,yS1);
    count1.yd = ky * std::min(yS,yS1);
    count1.middleX = count1.xL + count1.xR;
    count1.middleX = count1.middleX / 2;
    count1.middleY = count1.yd + count1.yup;
    count1.middleY = count1.middleY / 2;
    count1.edgeRx = kx * std::max(xS2,xS3);
    count1.edgeRy = ky * std::max(yS2,yS3);
    count1.XA = xArr * kx;
    count1.YA = yArr * ky;
    count1.maxNumber = MAXN1;
}
void MainWindow::handleFrame1(QImage image)
{
    QTransform myTransf;
    myTransf.rotate(180);
    image = image.transformed(myTransf);
    image = image.mirrored(true,false);
    int q1,q2;
    this->changeWindow(image);
    if (counter > 4 )
    {
        q1 = image.width() / 1000;
        q2 = image.height() / 800;
        sendCoord(q1,q2);
        qDebug() << count1.ans(image);
    }
}
