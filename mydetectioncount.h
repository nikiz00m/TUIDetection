#ifndef MYDETECTIONCOUNT_H
#define MYDETECTIONCOUNT_H

#include <QtMath>
#include <algorithm>
#include <QImage>
#include <QColor>

class MyDetectionCount
{
public:
    MyDetectionCount();
    void findEdgeAngle();
    int xL = 0,xR = 0;
    int yd = 0,yup = 0;
    int edgeRx = 0,edgeRy = 0;
    int maxNumber;
    int middleY,middleX;
    qreal deg = 0,XA,YA;
    qreal blackCount(QColor first);
    bool isBlack(int x, int y,QImage image);
    bool isBlack1(qreal ans);
    qreal angle(QImage image);
    qreal ans(QImage image);

};

#endif // MYDETECTIONCOUNT_H
