#include <stdio.h>
#include <time.h>
#include "conw.h"
#include "timehandling.h"

//Variablen

//typdefs
typedef struct{
    int max;
    int min;
    int std;
    //hier muss vielleicht noch ein pointer für eine variable eingesetzt werden
}UserInputHandler;


//Funktionsdeklarationen
int getUserInput(int input, int std, int max ,int min);


//Main
int main(int argc, char **argv)
{
    FillField(50);

    for(int a=0; a < 100; a++)
    {
        PrintIntField();
        GenNewField();
        printf("\n");
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

//was ist eigentlich die mission hier --> zeit implementieren,, frames !!!