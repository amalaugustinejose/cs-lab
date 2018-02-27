/*******************************************************
TITLE: Curves
AUTHOR: JOSMIN PETER
CLASS NO:36
DATE:07/02/2018
*******************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<math.h>
void bezier(int x[4],int y[4])
{
int i;
double t;
for(t=0.0;t<1.0;t+=0.0005)
{
double xt=pow(1-t,3)*x[0]+3*t*pow(1-t,2)*x[1]+3*pow(t,2)*(1-t)*x[2]+pow(t,3)*x[3];
double yt=pow(1-t,3)*y[0]+3*t*pow(1-t,2)*y[1]+3*pow(t,2)*(1-t)*y[2]+pow(t,3)*y[3];
putpixel(xt,yt,WHITE);
}
/*for(i=0;i<4;i++)
{
putpixel(x[i],y[i],GREEN);
}*/
return;
}
void main()
{
int gd=DETECT,gm;
int x1[4]={255,265,275,255},y1[4]={240,230,260,250};
int x2[4]={255,240,310,300},y2[4]={250,200,200,250};
int x3[4]={300,300,350,350},y3[4]={250,200,200,250};
int x4[4]={350,340,410,395},y4[4]={250,200,200,250};
int x5[4]={180,180,230,230},y5[4]={220,280,290,220};
initgraph(&gd,&gm,"");
bezier(x5,y5);
bezier(x1,y1);
bezier(x2,y2);
bezier(x3,y3);
bezier(x4,y4);
getch();
}
