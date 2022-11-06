#include <controls.h>
#include <graphics.h>

CONTROL controls[N_CONTROLS];

void create_controls(int x0, int y0, int n)
{
   controls[n].x0=x0;
   controls[n].y0=y0;
}

int select_control()
{
   int x, y;
   
   x = mousex();
   y = mousey();
   
   for (int i = 0; i < N_CONTROLS; i++)
   {
      if((x-controls[i].x0)*(x-controls[i].x0)+(y-controls[i].y0)*(y-controls[i].y0)<=37*37)
         return i;
      if((x-800)*274-(y-218)*(-302)<0)
         return FIELD;
   }
   return -1;
}

void create_back(const char *image_name)
{
   IMAGE *image=loadBMP(image_name);
   putimage(0,0,image,COPY_PUT);
   freeimage(image);
}