/**************************************************************
Author:Minnu Cyriac
Title:LINE
Class no:43
Date:14/02/2018
**************************************************************/
#include<stdio.h>
#include<graphics.h>
#include<math.h>
#define round(x)((int)(x+0.5))
int main()
{
int x0,x1,y0,y1,dx,dy,tdy,x,y,tdx,p,gd,gm,c,k,steps,i;
float xinc,yinc;
printf("enter the line endpoints\n");
scanf("%i%i%i%i",&x0,&y0,&x1,&y1);

printf("1.dda\n2.bresenham\nenter your choice\n");
scanf("%i",&c);

detectgraph(&gd,&gm);
initgraph(&gd,&gm,"");
if(c==1)
{
dx=x1-x0;
dy=y1-y0;
if(abs(dx)>abs(dy))
steps=abs(dx);
else
steps=abs(dy);
xinc=dx/(float)steps;
yinc=dy/(float)steps;
x=x0;
y=y0;
for(i=0;i<=steps;i++)
{
putpixel(round(x),round(y),15);
x=x+xinc;
y=y+yinc;
}
delay(5000);
}
else if(c==2)
{

putpixel(x0,y0,15);
x=x0;
y=y0;
dx=x1-x0;
dy=y1-y0;
tdx=2*dx;
tdy=2*dy;
//d=tdy-tdx;
p=tdy-dx;
//if(dx==0)
//dx=dy;
for(k=0;k<=dx;k++)
{
if(p<0)
{
putpixel(x+1,y,15);
x=x+1;
p=p+tdy;
}
else
{
putpixel(x+1,y+1,15);

x=x+1;
y=y+1;
p=p+tdy-tdx;
}
}
delay(5000);
}
else
printf("invalid choice\n");
}


