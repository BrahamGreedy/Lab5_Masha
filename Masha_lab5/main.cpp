#include <iostream>
#include <controls.h>
#include <graphics.h>
#include <task.h>

using namespace std;

int main()
{
   bool flag=false;
   initwindow(WIDTH, HEIGHT, "lines");
   create_back("bg.jpg");
   create_controls(482,725, STOP);
   create_controls(543,554, CHAIKIN);
   create_controls(723,488, BEZ);
   create_controls(633,740, SAVE);
   create_controls(738,639, EXIT);
   while(1)
   {
      while(mousebuttons()!=1)
      {
         coordinats(mousex(),mousey());
      }
      switch(select_control())
      {
         case FIELD:
            if(flag) break;
            createpoint(mousex(),mousey());
            break;
         case STOP:
            flag?flag=false:flag=true;
            delay(150);
            break;
         case CHAIKIN:
            if(!flag) break;
            chaikin();
            break;
         case BEZ:
            if(!flag) break;
            bez();
            break;
         case SAVE:
            save();
            break;
         case EXIT:
            return 0;
      }
   }
}