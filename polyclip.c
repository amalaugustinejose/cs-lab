/**************************************************************
Author:Minnu Cyriac
Title:Polygon Clipping
Class no:43
Date:16/02/2018
**************************************************************/
#include<stdio.h>
#include<stdio.h>
#include<graphics.h>
#include<math.h>
int p1[20],p2[20],n1=0,n2=0,u=0;
void dda(int,int,int,int);
int isinside(float,float);
void accept(int n, int poly[20])
{
int i;
for(i=0;i<n;i++)
{
scanf("%d%d",&poly[i*2],&poly[i*2+1]);
}
poly[i*2]=poly[0];
poly[i*2+1]=poly[1];
}
void main()
{
int gd=DETECT,gm;
int i,x1,y1,x2,y2;

printf("enter the no.of vertices of clipping window\n");
scanf("%d",&n1);
printf("enter vertices\n");
//accept(n1,p1);
for(i=0;i<n1;i++)
{
scanf("%d%d",&p1[i*2],&p1[(i*2)+1]);
}
p1[i*2]=p1[0];
p1[i*2+1]=p1[1];
printf("enter the no.of vertices of polygon");
scanf("%d",&n2);
printf("enter the vertices\n");
//accept(n2,p2);
for(i=0;i<n2;i++)
{
scanf("%d%d",&p2[i*2],&p2[i*2+1]);
}
p2[i*2]=p2[0];
p2[i*2+1]=p2[1];
initgraph(&gd,&gm," \\bgi ");
drawpoly(n1+1,p1);
drawpoly(n2+1,p2);
delay(2000);
closegraph();
initgraph(&gd,&gm,"");
drawpoly(n1+1,p1);
setcolor(BLUE);
for(i=0;i<n2;i++)
{
x1=p2[i*2];
y1=p2[i*2+1];
x2=p2[i*2+2];
y2=p2[i*2+3];
dda(x1,y1,x2,y2);
}
delay(200);
getch();
closegraph();
}
void dda(int x1,int y1,int x2,int y2)
{
int dx,dy,k;
float x,y,steps,xinc,yinc;
dx=x2-x1;
dy=y2-y1;
if(abs(dx)>abs(dy))
steps=abs(dx);
else
steps=abs(dy);
xinc=dx/steps;
yinc=dy/steps;
x=x1;
y=y1;
for(k=0;k<steps;k++)
{
x+=xinc;
y+=yinc;
if(isinside(x,y)==1)
{
putpixel(x,y,RED);
}
}
}
/*int isinside(float x,float y)
{
int outside=0,i;
float xf1,yf1,xf2,yf2;
for(i=0;i<n1;i++)
{
xf1=(float)p1[i*2];
yf1=(float)p1[(i*2)+1];
xf2=(float)p1[(i*2)+2];
yf2=(float)p1[(i*2)+3];
if(((y<=yf1)&&(y>=yf2))||((y>=yf1)&&(y<=yf2)))
{
if((yf2-yf1)!=0)
{
if((xf1+(((y-yf1)/(yf2-yf1))+(xf2-xf1)))<=x)
{
outside=!outside;
}}}}
return outside;
}*/
int isinside(float x, float y)
{
 int out=0,j;
 float xf1,yf1,xf2,yf2;
 for(j=0;j<n1+1;j++)
 { xf1=(float)p1[(j*2)];
   yf1=(float)p1[(j*2)+1];
   xf2=(float)p1[(j*2)+2];
   yf2=(float)p1[(j*2)+3];
  if(y<p1[1] && y<p1[3])
   u++;
  else if( (y<=yf1 && y>=yf2) || (y>=yf1 && y<=yf2) )
  { if((yf2-yf1)!=0)
   if(xf1+((y-yf1)/(yf2-yf1)+(xf2-xf1)) <= x)
     out=!out;
  }
 }
 return out;
}
