#ifndef CONTROLS_H
#define CONTROLS_H
#define HEIGHT 800
#define WIDTH 800

enum CONTROLS {STOP, CHAIKIN, BEZ, SAVE, EXIT, FIELD, N_CONTROLS};

struct CONTROL 
{
   int x0;
   int y0;
};

void create_controls(int, int, int);
void create_back(const char*);
int select_control();

#endif