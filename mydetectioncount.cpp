#include "mydetectioncount.h"

MyDetectionCount::MyDetectionCount()
{

}
qreal MyDetectionCount::blackCount(QColor first)
{
    qreal GBF;
    GBF=first.blue() + first.green();
    return GBF;
}

bool MyDetectionCount::isBlack(int x, int y , QImage image)
{
   if (blackCount(image.pixelColor(x,y)) < 90)
       return true;
        else
       return false;
}
bool MyDetectionCount::isBlack1(qreal ans)
{
   if (ans < 85)
       return true;
        else
       return false;
}
void MyDetectionCount::findEdgeAngle()
{
    qreal k;
    k = edgeRy - YA;
    k /= edgeRx - XA;
    deg =((0 - 1) * qAtan(k));
}
qreal MyDetectionCount::angle(QImage image)
{
    int lev1 =  edgeRy +  4*(yup - edgeRy) / 6;
    int f = 0;
    int ans = 0;
    int q;
    for (int i = 0; i <= edgeRx - middleX; i++)
    {
        if (isBlack(edgeRx - i,lev1,image))
        {
            while (isBlack(edgeRx - i - ans,lev1,image))
            {
                ans++;
            }
            f = 1;
            q = i;
            break;
        }
        if (isBlack(xL + xR - edgeRx + i,lev1,image))
        {
            while (isBlack(xL + xR - edgeRx + i + ans,lev1,image))
            {
                ans++;
            }
            f = 0;
            q = i;
            break;
        }
    }
        if (f == 1)
        {
            qreal k;
            k = YA - lev1;
            k /= XA - edgeRx + q + ans/2;
            qreal ans1;
            ans1 = M_PI + qAtan(k);
            return ((ans1 - deg)/(M_PI -  (2 * deg)));
        }
        else
        {

            qreal k;
            k = YA - lev1;
            k /= XA -(xL + xR - edgeRx + q + ans/2);
            qreal ans1;
            ans1 = qAtan(k);
            return ((ans1 - deg)/(M_PI -  (2 * deg)));
        }
}
qreal MyDetectionCount::ans(QImage image)
{
    findEdgeAngle();
    return angle(image)*maxNumber;
}
