#include <stdio.h>
#include <time.h>
#include "conw.h"
#include "timehandling.h"

//VARIABLES
int workTrig = 0;

//STRUCTS
typedef struct{
    int max;
    int min;
    int std;
    //maybe add pointer here
}UserInputHandler;

GameHandler Game1 = {0, 0, 0, 0, 0, 0};
TimeHandler Fram1 = {0, 0, 100000};

//FUNCTION DECLARATIONS
int getUserInput(int input, int std, int max ,int min);


//Main
int main(int argc, char **argv)
{
    FillField(40);
    while(1)
    {
        if(FrameTimer(&Fram1))
        {
            PrintCharField();
            //PrintIntField();
            printf("\n");
            workTrig = 0;
        }
        else if(!workTrig)
        {
            workTrig = GenNewField();
        }   
    }
    
    
    
    
}


//FUNCTIONS
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

