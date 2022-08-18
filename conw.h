#ifndef _CONW_H
#define _CONW_H


//used to store game settings
typedef struct{
    int xMaxSize;           
    int yMaxSize;           
    int animSpeed;
    int fillChance;
    int generation;
    int useExternatrigger;  //if 1 use external serial device as triggers
}GameHandler;

void FillField(int FillChance);
void PrintIntField();
void PrintCharField();
int GenNewField();

#endif