#include<iostream>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>
using namespace std;
int main(void)
{
int d=DETECT,m;
int x[]={200,300,400,500};
int y[]={300,400,200,350};
initgraph (&gd, &gm,"");
 for (double u= 0.0; u<1.0; u=u+0.0005)

   {

           double xt = pow (1-u,3) * x[0] + 3 * u * pow (1-u,2) * x[1] +

                          3 * pow (u, 2) * (1-u) * x[2] + pow (u, 3) * x[3];



           double yt = pow (1-u,3) * y[0] + 3 * u * pow (1-u, 2) * y[1] +

                          3 * pow (u, 2) * (1-u) * y[2] + pow (u,3) * y[3];

           putpixel (xt, yt, YELLOW);
   }
  getch();
closegraph();
}

