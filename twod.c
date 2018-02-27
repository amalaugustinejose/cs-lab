/**************************************************************
Author:Minnu Cyriac
Title:Two dimensional transformation
Class no:43
Date:14/02/2018
**************************************************************/
#include<stdio.h>

#include<graphics.h>
#include<math.h>
                                                                                                                                                                                 
int points[10][2];
int vertices=0;
void dda(int x1,int y1,int x2,int y2)
{
int k;
float steps,dx,dy,x,y,a,b;

dx=x2-x1;
dy=y2-y1;
if(abs(dx)>abs(dy))
steps=abs(dx);
else
steps=abs(dy);
if(steps!=0)
{                                                              
a=dx/steps;
b=dy/steps;
}
x=x1;
y=y1;
putpixel(x,y,3);
for(k=1;k<steps;k++)
{
x+=a;
y+=b;
putpixel((int)x,(int)y,3);
}
delay(1000);
}
void displaypoly()
{
int i;
for(i=0;i<vertices-1;i++)
{
dda(points[i][0],points[i][1],points[i+1][0],points[i+1][1]);
}
dda(points[vertices-1][0],points[vertices-1][1],points[0][0],points[0][1]);

}
void scale()
{
int i;
int sx,sy;
printf("enter scaling factor\n");
scanf("%d%d",&sx,&sy);
for(i=0;i<vertices;i++)
{
points[i][0]*=sx;
points[i][1]*=sy;
}
displaypoly();
}
void reflect()
{
int i,c,rx,ry;
do
{
printf("1.abt x axis\n2.abt y axis\n");
scanf("%i",&c);
if(c==1)
{
printf("enter y value\n");
scanf("%i",&ry);
for(i=0;i<vertices;i++)
{
int t=ry-points[i][1];
points[i][1]+=2*t;
}
} 
else if(c==2)
{
printf("enter x value\n");
scanf("%i",&rx);
for(i=0;i<vertices;i++)
{
int t=rx-points[i][0];
points[i][0]+=2*t;
}
} 
displaypoly();
}
while(c<3);
}

void rotate()
{
int i,t1,t2,xa,ya,r;
float c;
printf("enter fixed point\n");
scanf("%d%d",&xa,&ya);
printf("enter angle\n");
scanf("%i",&r);
c=r*(3.14/180);
delay(1000);
for(i=0;i<vertices;i++)
{
t1=(xa+((points[i][0]-xa)*cos(c)-(points[i][1]-ya)*sin(c)));

t2=(ya+((points[i][0]-xa)*sin(c)+(points[i][1]-ya)*cos(c)));
points[i][0]=t1;
points[i][1]=t2;
delay(1000);
}
displaypoly();
}


void shear()
{
int i,ch,shx,shy;
do
{
printf("1.with x axis\n2.with y axis\n");
scanf("%i",&ch);
if(ch==1)
{
printf("enter shear factor shx\n");
scanf("%i",&shx);
for(i=0;i<vertices;i++)
{
points[i][0]=points[i][0]+points[i][1]*shx;
//points[i][0]*=shx;
}
displaypoly();
} 
else if(ch==2)
{
printf("entershear factor shy\n");
scanf("%i",&shy);
for(i=0;i<vertices;i++)
{
points[i][1]=points[i][1]+points[i][0]*shy;
//points[i][1]*=shy;
}
displaypoly();
} 

}
while(ch<3);
}
void translate()
{
int tx,ty,i;
printf("enter translation factor\n");
scanf("%i%i",&tx,&ty);
for(i=0;i<vertices;i++)
{
points[i][0]+=tx;
points[i][1]+=ty;
}
displaypoly();
}
main()
{
int gd=DETECT,gm=VGAMAX,i,choice;

printf("\nenter the no.of sides of polygon");
scanf("%d",&vertices);
printf("\nenter the vertices\n");
for(i=0;i<vertices;i++)
{

scanf("%i%i",&points[i][0],&points[i][1]);
}
initgraph(&gd,&gm,NULL);
displaypoly();
printf("menu\n1.translation\n2.rotate\n3.scaling\n4.reflection\n5.shear\n6.exit\n");
//restorecrtmode();
do
{
printf("enter choice\n");
scanf("%i",&choice);
if(choice==6)
break;
else if(choice==1)
translate();
else if(choice==2)
rotate();
else if(choice==3)
scale();
else if(choice==4)
reflect();
else if(choice==5)
shear();
}while(choice<6);
delay(5000);
closegraph();
getch();
}
