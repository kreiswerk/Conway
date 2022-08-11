#include <time.h>
#include "timehandling.h"

int FrameTimer(TimeHandler *a)
{
    a->actualTime = clock();
    if(a->actualTime - a->oldTime >= a->frameTime)
    {
        return 1;
    }
    else 
        return 0;

} 


