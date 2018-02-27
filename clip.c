#include<stdio.h>
#include<graphics.h>
#include<math.h>

#include<stdlib.h>


int p1[20]={0},p2[20]={0},n1,n2,clr=4,ch,u=0;
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

void dda(float x0,float y0, float x1, float y1)
{
float dx=x1-x0;
float dy=y1-y0;
float steps;
int k;

float xi,yi,x=x0,y=y0;
if(x1==x0 && y1==y0)
{
//putpixel(x,y,clr);
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
if(isinside(x,y)==1)
  putpixel(x,y,clr);
}
}

void accept(int n,int poly[20])
{
int i;
printf("\n Enter the Vertex Co-ordinates:\n");
for(i=0;i<n;i++)
{
  scanf("%d%d",&poly[i*2],&poly[i*2+1]);
}
poly[i*2]=poly[0];
poly[i*2+1]=poly[1];
}

void main()
{
int gdriver , gmode,ch;

detectgraph(&gdriver,&gmode);
initgraph(&gdriver, &gmode, "" );

float i,x1,y1,x2,y2;

printf("\n Enter the no of Vertices of Clipping Window: ");
scanf("%d",&n1);
accept(n1,p1);

do{
clrscr();
printf("\n Enter the no of Vertices of Polygon: ");
scanf("%d",&n2);
accept(n2,p2);


printf("\n Before Clipping:\n");
setcolor(BLUE);
drawpoly(n1+1,p1);
drawpoly(n2+1,p2);
delay(5000);
 
drawpoly(n1+1,p1);
printf("\n After Clipping:\n");
for(i=0;i<n2;i++)
// printf("%d,%d.... %d.%d\n",p2[i*2],p2[(i*2)+1],p2[(i*2)+2],p2[(i*2)+3]);
for(i=0;i<n2;i++)
{
   x1=(float)p2[(i*2)];
   y1=(float)p2[(i*2)+1];
   x2=(float)p2[(i*2)+2];
   y2=(float)p2[(i*2)+3];
 // printf("\n %f,%f.... %f,%f\n",x1,y1,x2,y2);
   dda(x1,y1,x2,y2);
}
/*x1=(float)p2[0];
y1=(float)p2[1];
printf("\n %f,%f.... %f,%f\n",x1,y1,x2,y2);
dda(x2,y2,x1,y1);*/
printf("\n %d\n",u);
putpixel(p2[0],p2[1],7);
putpixel(p2[2],p2[3],7);

delay(1000);
setcolor(7);

drawpoly(n1+1,p1);
delay(3000);

  printf("\npress 1 to Continue:");
  scanf("%i",&ch);
 }while(ch==1);
}
