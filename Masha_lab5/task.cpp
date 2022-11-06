#include <task.h>
#include <graphics.h>
#include <controls.h>
#include <string.h>

using namespace std;

point points[4];
int count_points=0;

void createpoint(int x0,int y0)
{
   if(count_points>3)
   {
      putpixel(points[count_points%4].x0,points[count_points%4].y0, COLOR(224,164,88));
      putpixel(points[count_points%4].x0+1,points[count_points%4].y0+1, COLOR(224,164,88));
      putpixel(points[count_points%4].x0-1,points[count_points%4].y0-1, COLOR(224,164,88));
      putpixel(points[count_points%4].x0+1,points[count_points%4].y0-1, COLOR(224,164,88));
      putpixel(points[count_points%4].x0-1,points[count_points%4].y0+1, COLOR(224,164,88));
   }
   points[count_points%4].x0=x0;
   points[count_points%4].y0=y0;
   putpixel(x0,y0, COLOR(45,48,71));
   putpixel(x0+1,y0+1, COLOR(45,48,71));
   putpixel(x0-1,y0-1, COLOR(45,48,71));
   putpixel(x0+1,y0-1, COLOR(45,48,71));
   putpixel(x0-1,y0+1, COLOR(45,48,71));
   count_points++;
   delay(150);
}

void save()
{
   IMAGE *picture = createimage(WIDTH+1, HEIGHT+1);
   getimage(0,0,WIDTH,HEIGHT, picture);
   saveBMP("result.bmp",picture);
}

void chaikin()
{
   setcolor(COLOR(192,74,188));
   int dx, dy, j;
   int npoints=4;
   int nlines=3;
   point *A,*B;
   A = new point[npoints];
   for(int i=0;i<4;i++) A[i]=points[i];
   for(int i=0;i<6;i++)
   {
      B=new point[nlines*2];
      j = 0;
      for(int k=0;k<nlines;k++)
      {
         dx=A[k+1].x0-A[k].x0;
         dy=A[k+1].y0-A[k].y0;
         B[j].x0=A[k].x0+0.25*dx;
         B[j].y0=A[k].y0+0.25*dy;
         j++;
         B[j].x0=A[k].x0+0.75*dx;
         B[j].y0=A[k].y0+0.75*dy;
         j++;
      }
      delete[] A;
      A = B;
      npoints=2*nlines;
      nlines=npoints-1;
   }
   A[0]=points[0];
   A[nlines-1]=points[3];
   for(int i=0; i<nlines-1;i++)
   {
      line(A[i].x0,A[i].y0,A[i+1].x0,A[i+1].y0);
   }
   delete[] A;
}

void bez()
{
   int x,y;
   double t;
   for(t=0.0;t<=1.0;t+=0.0001)
   {
      x=(1-t)*(1-t)*(1-t)*points[0].x0+3*(1-t)*(1-t)*t*points[1].x0+3*(1-t)*t*t*points[2].x0+t*t*t*points[3].x0;
      y=(1-t)*(1-t)*(1-t)*points[0].y0+3*(1-t)*(1-t)*t*points[1].y0+3*(1-t)*t*t*points[2].y0+t*t*t*points[3].y0;
      putpixel(x,y,COLOR(45,48,71));
   }
}

void coordinats(int x, int y)
{
   string text;
   text = "X:" + to_string(x) + " Y:" + to_string(y);
   setbkcolor(COLOR(65,157,120));
   setcolor(COLOR(224,164,88));
   setfillstyle(SOLID_FILL, COLOR(65,157,120));
   bar(700,780,800,800);
   outtextxy(700,780, text.c_str());
}