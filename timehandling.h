#ifndef _TIMEHANDLING_H
#define _TIMEHANDLING_H
#include <time.h>


//Defines
#define Framerate(r) ((1/r)*100000)

typedef struct{
    clock_t actualTime;
    clock_t oldTime;
    int frameTime;
}TimeHandler; 





int FrameTimer(TimeHandler *a);


#endif
 