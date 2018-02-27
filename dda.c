#include<graphics.h>
#include<stdio.h>
#include<math.h>
#define round(x)((int)(x+0.5))
main()
{
float dx,dy,xinc,yinc;
int steps=0,x0,x1,y0,x,y,y1,gd,gm,i=0;
printf("enter the line endpoints\n");
scanf("%i%i%i%i",&x0,&y0,&x1,&y1);
detectgraph(&gd,&gm);
initgraph(&gd,&gm," ");
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
putpixel(x,y,15);
x=x+xinc;
y=y+yinc;
}
delay(5000);
}
