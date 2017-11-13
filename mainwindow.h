#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QLabel>
#include <QPicture>
#include <algorithm>
#include <QImage>
#include <QColor>
#include <QtMath>
#include <QFileDialog>
#include <QPixmap>
#include <QDebug>
#include <QMouseEvent>
#include <QInputDialog>
#include "mydetectioncount.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void changeWindow(QImage image);
    void sendCoord(int kx, int ky);
    int xS,yS,xS1,yS1,xS2,yS2,xS3,yS3,MAXN1;
    qreal xArr,yArr;
    int counter = 0;
    MyDetectionCount count1;

private:
    QLabel *label;
    void mousePressEvent(QMouseEvent *event) override;
public slots:
    void handleFrame1(QImage image);
};

#endif // MAINWINDOW_H
