#include <stdio.h>
#include <math.h>
#define PI 3.14159265359
 
int main()
{
    int T;
    for (scanf("%d", &T); T > 0; T--)
    {
        double d, r, vt, t, vh;
        double result;
        scanf("%lf %lf %lf %lf %lf", &d, &r, &vt, &t, &vh);
     
        if (vt == 0)
            result = r*r*PI / 4;
        else if (vh == 0)
            result = 0;
        else
        {
            double ft = d / vh;
            double r3 = (ft - t) * vt;
            double a = r, b = r3;
            double t1 = 2 * acos((d*d + b*b - a*a) / (2 * b * d));
            double t2 = 2 * acos((d*d + a*a - b*b) / (2 * a * d));
            double S = (b*b*(t1 - sin(t1)) + a*a*(t2 - sin(t2))) / 2;
            S /= 2;
            double SR0 = r*r*PI / 4;
            result = SR0 - S;
        }
        printf("%.10lf\n", result);
    }
 
    return 0;
}