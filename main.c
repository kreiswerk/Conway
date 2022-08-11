#include <stdio.h>
#include <time.h>
#include "conw.h"
#include "frameanim.h"

//Variablen
int userinput = 70;
int generations = 50;
int a;


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
    Fram1.frametime = 100000;
    printf("Fillchance: ");
    //scanf("%i", &userinput);
    printf("\nNumber of Generations: ");
    //scanf("%i", &generations);
    FillField(userinput);

    // while(a < generations)
    // { 
    while(1)
    {
        Fram1.actualTime = clock();

        if(Fram1.actualTime - Fram1.oldTime >= Fram1.frametime)
        {
            Fram1.oldTime = Fram1.actualTime;
            PrintIntField();
        }

        
        GenNewField();
        printf("\n");    
    }

        // a++;   
    // }

    int a; 
    a = getUserInput(a, 20, 40, 30);
    printf("\nINput = %i", a);
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