#include<stdio.h>
#include<graphics.h>
#include<math.h>
//#include<conio.h>
#include<stdlib.h>

int n,clr=1;
float x[100],y[100];

void dda(float x0,float y0, float x1, float y1)
{
float dx=x1-x0;
float dy=y1-y0;
float steps;
int k;

float xi,yi,x=x0,y=y0;
if(x1==x0 && y1==y0)
{
putpixel(x,y,clr);
return;
}
if(abs(dx)>abs(dy))
  steps=abs(dx);
else
 steps=abs(dy);

xi=dx/steps;
yi=dy/steps;
     // printf("\n[%f,%f]",x,y);
putpixel(x,y,clr);

for(k=0;k<steps;k++)
{
x+=xi;
y+=yi;
putpixel(x,y,clr);
}
}

void draw()
{
 int i;
 for(i=0;i<n;i++)
 {
 // printf("\n %f , %f",x[i],y[i]);
  if(i==n-1)
   dda(x[i],y[i],x[0],y[0]);
  else
   dda(x[i],y[i],x[i+1],y[i+1]);
 }
 clr++;
 if(clr==2)
  clr=4;
 if(clr==5)
  clr=1;
}

void translation(int tx, int ty)
{

int i;
printf("Translating %i, %i\n",tx,ty);
draw();
for(i=0;i<n;i++)
 {
  x[i]+=tx;
  y[i]+=ty;
 }
 draw();
}

void rotation(double r)
{
 float t1,t2,i,xr,yr;
 printf("\n Enter Pivot points: ");
 scanf("%f%f",&xr,&yr);
 printf("\nIn radians: %f",r);
 clrscr();
 draw();
 for(i=0;i<n;i++)
 {
  t1=xr+((x[i]-xr)*cos(r)-(y[i]-yr)*sin(r));
  t2=yr+((x[i]-xr)*sin(r)+(y[i]-yr)*cos(r));
  x[i]=t1; y[i]=t2;
  printf("%f %f\n",t1,t2);
 }
 draw();

}

void reflection(int c,int r)
{
 int i,t;
 int midx=getmaxx()/2;
 int midy=getmaxy()/2;
 line(5,midy,getmaxx()-5,midy);
 line(midx+3,5,midx+3,getmaxy()-5);

 draw();
 if(c==1)
 {
  for(i=0;i<n;i++)
  {
  // t=abs(r-y[i]);
  // y[i]+=t;
  y[i]=midy-y[i];
  y[i]=-y[i];
  y[i]=midy-y[i];

  }
 }
 else
 {
   for(i=0;i<n;i++)
  {
  // t=abs(r-x[i]);
  // x[i]+=t;
  x[i]=x[i]-midx;
  x[i]=-x[i];
  x[i]=x[i]+midx;
  }
 }
 draw();
}

void scaling(int sx,int sy)
{
 int i;
 draw();
 for(i=0;i<n;i++)
 {
  x[i]*=sx;
  y[i]*=sy;
 }
 draw();
}

void shear(int c, int s)
{
 int i;
 draw();
 if(c==1)
  for(i=0;i<n;i++)
    x[i]+=s*(y[i]-y[0]);

  else
   for(i=0;i<n;i++)
    y[i]+=s*(x[i]-x[0]);

  draw();

}

int main()
{
 int gdriver , gmode,ch;

detectgraph(&gdriver,&gmode);
initgraph(&gdriver, &gmode, "" );

int i,tx,ty,sx,sy,c1,c2,rx,ry,shx,shy,d;
double r;
printf("\n Enter no. of vertices of polygon: ");
scanf("%i",&n);
printf("\n Enter co ordinates:\n");
for(i=0;i<n;i++)
 scanf("%f%f",&x[i],&y[i]);

clrscr();
draw();

do
{
printf("\n1.Translation\n2.Rotation\n3.Reflection\n4.Scaling\n5.Shearing\n0. EXIT\n Enter ur Choice: ");
scanf("%i",&ch);
switch(ch)
{
 case 1: printf("\n Enter translational Distance: ");
	 scanf("%i%i",&tx,&ty);
	 clrscr();
	 translation(tx,ty);
	 break;
 case 2: printf("\n Enter ANGLE OF ROTATION: ");
	 scanf("%i",&d);
	 r=d*(3.14/180);

	 clrscr();
	 rotation(r);
	 break;
 case 3: printf("\n Reflection wrt\n 1. x- axis\n 2. y- axis\n Enter choice: ");
	 scanf("%i",&c1);
	 if(c1==1)
	 { printf("\n Enter y-value: ");
	   scanf("%i",&ry);
	   clrscr();
	   reflection(c1,ry);
	 }
	 else
	 { printf("\n Enter x-value: ");
	   scanf("%i",&rx);
	   clrscr();
	   reflection(c1,rx);
	 }
	 break;
 case 4: printf("\nEnter Scaling Factor: ");
	 scanf("%i%i",&sx,&sy);
	 clrscr();
	 scaling(sx,sy);
	 break;
 case 5: printf("\n Shearing wrt\n 1. x- axis\n 2. y- axis\n Enter choice: ");
	 scanf("%i",&c2);
	 if(c2==1)
	 { printf("\n Enter Shear Factor: ");
	   scanf("%i",&shx);
	   clrscr();
	   shear(c2,shx);
	 }
	 else
	 { printf("\n Enter Shear Factor: ");
	   scanf("%i",&shy);
	   clrscr();
	   shear(c2,shy);
	 }
	 break;
 case 0: exit(0);
	 break;

}
 getch();
}while(ch!=0);
return 0;
}
