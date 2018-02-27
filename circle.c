/**************************************************************
Author:Minnu Cyriac
Title:Circle
Class no:43
Date:14/02/2018
**************************************************************/
#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<math.h>
int gd=DETECT,gm;
void drawcircle(int x0,int y0,int x,int y)
{
putpixel(x0+x,y0+y,WHITE);
putpixel(x0-x,y0+y,WHITE);
putpixel(x0+x,y0-y,WHITE);
putpixel(x0-x,y0-y,WHITE);
putpixel(x0+y,y0+x,WHITE);
putpixel(x0-y,y0+x,WHITE);
putpixel(x0+y,y0-x,WHITE);
putpixel(x0-y,y0-x,WHITE);
}
/*int po(int n,int p)
{

int i,s=1;
for(i=1;i<=p;i++)
s=s*n;
return s;
}
*/
void midp(int x0, int y0,int radius)
{
int x=0,y=radius,p=1-radius;
initgraph(&gd,&gm,"");
while(x<y)
{
drawcircle(x0,y0,x,y);
x++;
if(p<0)
p=p+2*x+1;
else
{
y--;
p=p+2*(x-y)+1;
}

drawcircle(x0,y0,x,y);
}
delay(5000);
closegraph();
}
void bres(int xc,int yc,int r)
{
int x,y;
float p;
initgraph(&gd,&gm,"");
x=0;
y=r;
p=3-2*r;
drawcircle(xc,yc,x,y);
while(x<y)
{
if(p<0)
{
x++;
p=p+4*x+6;
}
else
{
x++;
y--;
p=p+4*x-4*y+10;
}
drawcircle(xc,yc,x,y);
}
delay(5000);
closegraph();
}
void dda(float xc,float yc,float r)
{
float xc1,xc2,yc1,yc2,eps,sx,sy;
float val,i=0;
initgraph(&gd,&gm,"");
xc1=r;
yc1=0;
sx=xc1;
sy=yc1;

do
{
val=pow(2,i);
i++;
}
while(val<r);
eps=1/(pow(2,i-1));
do
{
xc2=xc1+yc1*eps;
yc2=yc1-eps*xc2;
putpixel(xc+xc2,yc-yc2,3);

xc1=xc2;
yc1=yc2;
}
while((yc1-sy)<eps||(sx-xc1)>eps);
//drawcircle(xc,yc,xc2,yc2);
delay(5000);
closegraph();

}
int main()
{
int choice,x,y,r;
do
{
printf("menu\n1.dda\n2.bresenham\n3.midpoint\n4.exit\n enter your choice");
scanf("%i",&choice);
switch(choice)
{
case 1:printf("enter x0,y0,radius");
scanf("%i%i%i",&x,&y,&r);
dda(x,y,r);
break;
case 2:printf("enter x0,y0,radius");
scanf("%i%i%i",&x,&y,&r);
bres(x,y,r);
break;
case 3:printf("enter x0,y0,radius");
scanf("%i%i%i",&x,&y,&r);
midp(x,y,r);
break;
case 4:exit(0);
}
}
while(choice!=4);
return 0;
}

