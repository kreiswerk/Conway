#include <stdio.h>
#include <time.h>
#include "conw.h"
#include "timehandling.h"

//Variablen
int workTrig = 1;

//typdefs
typedef struct{
    int max;
    int min;
    int std;
    //hier muss vielleicht noch ein pointer für eine variable eingesetzt werden
}UserInputHandler;

TimeHandler Fram1 = {0, 0, 200000};

//Funktionsdeklarationen
int getUserInput(int input, int std, int max ,int min);


//Main
int main(int argc, char **argv)
{
    while(1)
    {
        FillField(50);

        if(FrameTimer(&Fram1))
        {
            PrintIntField();
            printf("\n");
            workTrig = 0;
        }
        else if(!workTrig)
        {
            workTrig = GenNewField();
        }   
    }
    
    
    
    
}


//Funktionen
int getUserInput(int input, int std, int max ,int min)
{
    printf("enter user input: ");
    scanf("%i", &input);
    if((input < max) & (input > min))
    {
        return input;
    }
    else
    {
        return std;
    }
}

