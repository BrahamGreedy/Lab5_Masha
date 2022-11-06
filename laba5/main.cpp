#include <stdio.h>
#include "graphics.h"
#include "control.h"
#include "task.h"
using namespace std;

int main()
{
   initwindow(800, 650);
   setbkcolor(WHITE);
   clearviewport();
   
   create_control(GET_DOTS, 600, 25, "get_dots.bmp");
   create_control(BEZIER, 600,150, "bezier.bmp");
   create_control(CHAIKIN, 600,275, "chaikin.bmp");
   create_control(SAVE, 600, 400, "save.bmp");
   create_control(EXIT,   600, 525, "exit.bmp");
   bool sw=false;
   setcolor(YELLOW);
   while (true)
   {
      while (mousebuttons() != 1);
      switch (select_control())
      {
      case NONE:
         break;
      case GET_DOTS:
         setfillstyle(SOLID_FILL,WHITE);
         bar(0,0,600,800);
         setfillstyle(SOLID_FILL,LIGHTBLUE);
         get_dots();
         sw=true;
         break;
      case BEZIER:
         if (sw) {
            bezier_curve();
         }
         break;
      case CHAIKIN:
         if (sw) {
            algorithm_chaikina();
         }
         break;
      case SAVE:
         save();
         break;
      case EXIT:
         closegraph();
         return 0;
      }
   }
}