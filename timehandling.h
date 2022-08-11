#ifndef _FRAMEANIM_H
#define _FRAMEANIM_H
#include <time.h>


TimeHandler Fram1 =  {0, 0, 100};



typedef struct{
    clock_t actualTime;
    clock_t oldTime;
    int frameTime;
}TimeHandler; 



#endif
 