#include "mainwindow.h"
#include "cameraframegrabber.h"
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
void MainWindow::handleFrame1(QImage image)
{
    qDebug() << "loh";
    //qDebug() << image.pixelColor(100,100);
    //image.mirrored();
    QTransform myTransf,myTransf1;
    myTransf.rotate(180);
    image = image.transformed(myTransf);
    image = image.mirrored(true,false);
    this->changeWindow(image);
}
