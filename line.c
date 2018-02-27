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
p=2*dy-dx;
while(x<x1||y<y1)
{
putpixel(x,y,5);
if(p>=0)
{
p=p+2*dy-2*dx;
y++;
}
else
{
p=p+2*dy;y=y;
}
if(x<x1)
x++;
delay(1000);
}
}
}
