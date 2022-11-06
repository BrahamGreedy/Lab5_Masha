#define _USE_MATH_DEFINES
#include <math.h>
#include "graphics.h"
#include "task.h"

typedef struct Point {
   int x,y;
} Point;

Point ar[4];

using namespace std;
void get_dots() {
   int x,y,r=5;
   for (int i=0; i<4; i++) {
      while (1) {
         x=mousex();
         y=mousey();
         if (mousebuttons()&& x<600) {
            Sleep(10);
            if (!mousebuttons()) {
               ar[i].x=x;
               ar[i].y=y;
               fillellipse(x,y,r,r);
               break;
            }
         }
      }
   }
}

void bezier_curve() {
   double t;
   double a[6];
   double n[4];
   int x,y;
   setcolor(RED);
   moveto(ar[0].x,ar[0].y);
   for (t=0; t<1; t+=0.05) {
      a[0]=(1-t)*ar[0].x+t*ar[1].x;
      a[1]=(1-t)*ar[0].y+t*ar[1].y;
      a[2]=(1-t)*ar[1].x+t*ar[2].x;
      a[3]=(1-t)*ar[1].y+t*ar[2].y;
      a[4]=(1-t)*ar[2].x+t*ar[3].x;
      a[5]=(1-t)*ar[2].y+t*ar[3].y;

      n[0]=(1-t)*a[0]+t*a[2];
      n[1]=(1-t)*a[1]+t*a[3];
      n[2]=(1-t)*a[2]+t*a[4];
      n[3]=(1-t)*a[3]+t*a[3];

      x=(1-t)*n[0]+t*n[2];
      y=(1-t)*n[1]+t*n[3];

      lineto(x,y);
   }
   lineto(ar[3].x,ar[3].y);
}

void algorithm_chaikina() {
   setcolor(BLUE);
   int n_lines=3,n_points=4,generathion=4;
   int *x_coord,*nx_coord;
   int *y_coord,*ny_coord;
   x_coord=new int[n_points];
   y_coord=new int[n_points];

   x_coord[0]=ar[0].x;
   x_coord[1]=ar[1].x;
   x_coord[2]=ar[2].x;
   x_coord[3]=ar[3].x;

   y_coord[0]=ar[0].y;
   y_coord[1]=ar[1].y;
   y_coord[2]=ar[2].y;
   y_coord[3]=ar[3].y;

   for (int i=0; i<generathion; i++) {
      nx_coord=new int[2*n_lines];
      ny_coord=new int[2*n_lines];

      for (int j=0,k=0; k<n_lines; j++,k++) {
         nx_coord[j]=x_coord[k]*0.75+x_coord[k+1]*0.25;
         ny_coord[j]=y_coord[k]*0.75+y_coord[k+1]*0.25;
         ++j;
         nx_coord[j]=x_coord[k]*0.25+x_coord[k+1]*0.75;
         ny_coord[j]=y_coord[k]*0.25+y_coord[k+1]*0.75;
      }

      delete []x_coord;
      delete []y_coord;
      x_coord=nx_coord;
      y_coord=ny_coord;
      n_points=n_lines*2;
      n_lines=n_points-1;
   }

   line(ar[0].x,ar[0].y,x_coord[0],y_coord[0]);
   for (int i=0; i<n_lines; i++) {
      line(x_coord[i],y_coord[i],x_coord[i+1],y_coord[i+1]);
   }
   line(x_coord[n_lines],y_coord[n_lines],ar[3].x,ar[3].y);
   delete []x_coord;
   delete []y_coord;
}
void save()
{
   int width, height;
   IMAGE *output;

   width  = getmaxx() + 1;
   height = getmaxy() + 1;
   output = createimage(width, height);

   getimage(0, 0, width - 1, height - 1, output);
   saveBMP("output.bmp", output);
   freeimage(output);
}