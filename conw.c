#include <stdio.h>
#include <stdlib.h>
/* Allgemein wird bei arrays angenommmen das arr[x][y]      */
/* sowie das bei for schleifen immer die ganze zeile        */
/*  gelesen und dann in die nächste spalte gesprungen wird  */


//DEFINES
#define X_Size 50
#define Y_Size 50


//STRUCTS
typedef struct{
    int arr[X_Size][Y_Size];
    int oldarr[X_Size][Y_Size];
}field;

field Field1;

//VARIABLES



//FUNCTIONS
void FillField(int FillChance)
{
    for(int y = 0; y < Y_Size; y++)
    {
        for(int x = 0; x < X_Size; x++)
        {
            int i = rand();
            if(i < (21474836*FillChance))
            {
                Field1.arr[x][y] = 1;
            }
            else
            {
                Field1.arr[x][y] = 0;
            }
                       
        }
    }
        
    
}

void PrintIntField()
{
   for(int y = 0; y < Y_Size; y++)
    {
        for(int x = 0; x < X_Size; x++)
        {
            printf("%2i", Field1.arr[x][y]);            
        }
        printf("\n");
    } 
}

int ApplyRules(int x, int y)
{
    int liveCells = 0;

    if((x == 0) | (x == X_Size-1) | (y == 0) | (y== Y_Size-1))
    {
        //überprüft ob es sich um eine ecke handelt
        if(((x==0)&(y==0)) | ((x==0)&(y==Y_Size-1)) | ((x==X_Size-1)&(y==0)) | ((x==X_Size-1)&(y==Y_Size-1)))
        {
            //hier müssen ecken checken implementiert werden
        }
        else
        {
            //Alle Felder an der linken Border
            if(x == 0)
            {
                if(Field1.oldarr[X_Size-1][y-1] == 1)
                {
                    liveCells++;   
                }

                if(Field1.oldarr[x][y-1] == 1)
                {
                    liveCells++;   
                }

                if(Field1.oldarr[x+1][y-1] == 1)
                {
                    liveCells++;   
                }

                if(Field1.oldarr[X_Size-1][y] == 1)
                {
                    liveCells++;   
                }

                if(Field1.oldarr[x+1][y] == 1)
                {
                    liveCells++;   
                }

                if(Field1.oldarr[X_Size-1][y+1] == 1)
                {
                    liveCells++;   
                }

                if(Field1.oldarr[x][y+1] == 1)
                {
                    liveCells++;   
                }

                if(Field1.oldarr[x+1][y+1] == 1)
                {
                    liveCells++;   
                }
            }

            //Alle Felder an der rechten Border
            if(x == X_Size-1)
            {
                if(Field1.oldarr[x-1][y-1] == 1)
                {
                    liveCells++;   
                }

                if(Field1.oldarr[x][y-1] == 1)
                {
                    liveCells++;   
                }

                if(Field1.oldarr[0][y-1] == 1)
                {
                    liveCells++;   
                }

                if(Field1.oldarr[x-1][y] == 1)
                {
                    liveCells++;   
                }

                if(Field1.oldarr[0][y] == 1)
                {
                    liveCells++;   
                }

                if(Field1.oldarr[x-1][y+1] == 1)
                {
                    liveCells++;   
                }

                if(Field1.oldarr[x][y+1] == 1)
                {
                    liveCells++;   
                }

                if(Field1.oldarr[0][y+1] == 1)
                {
                    liveCells++;   
                }
            }

            //ALle Felder an der unteren Border
            if(y == 0)
            {
                if(Field1.oldarr[x-1][Y_Size-1] == 1)
                {
                    liveCells++;   
                }

                if(Field1.oldarr[x][Y_Size-1] == 1)
                {
                    liveCells++;   
                }

                if(Field1.oldarr[x+1][Y_Size-1] == 1)
                {
                    liveCells++;   
                }

                if(Field1.oldarr[x-1][y] == 1)
                {
                    liveCells++;   
                }

                if(Field1.oldarr[x+1][y] == 1)
                {
                    liveCells++;   
                }

                if(Field1.oldarr[x-1][y+1] == 1)
                {
                    liveCells++;   
                }

                if(Field1.oldarr[x][y+1] == 1)
                {
                    liveCells++;   
                }

                if(Field1.oldarr[x+1][y+1] == 1)
                {
                    liveCells++;   
                }
            }

            //Alle Felder an der oberen Border
            if(y == Y_Size-1)
            {
                if(Field1.oldarr[x-1][y-1] == 1)
                {
                    liveCells++;   
                }

                if(Field1.oldarr[x][y-1] == 1)
                {
                    liveCells++;   
                }

                if(Field1.oldarr[x+1][y-1] == 1)
                {
                    liveCells++;   
                }

                if(Field1.oldarr[x-1][y] == 1)
                {
                    liveCells++;   
                }

                if(Field1.oldarr[x+1][y] == 1)
                {
                    liveCells++;   
                }

                if(Field1.oldarr[x-1][0] == 1)
                {
                    liveCells++;   
                }

                if(Field1.oldarr[x][0] == 1)
                {
                    liveCells++;   
                }

                if(Field1.oldarr[x+1][0] == 1)
                {
                    liveCells++;   
                }
            }    
        }
        
    }
    else
    {
        if(Field1.oldarr[x-1][y-1] == 1)
        {
            liveCells++;   
        }

        if(Field1.oldarr[x][y-1] == 1)
        {
            liveCells++;   
        }

        if(Field1.oldarr[x+1][y-1] == 1)
        {
            liveCells++;   
        }

        if(Field1.oldarr[x-1][y] == 1)
        {
            liveCells++;   
        }

        if(Field1.oldarr[x+1][y] == 1)
        {
            liveCells++;   
        }

        if(Field1.oldarr[x-1][y+1] == 1)
        {
            liveCells++;   
        }

        if(Field1.oldarr[x][y+1] == 1)
        {
            liveCells++;   
        }

        if(Field1.oldarr[x+1][y+1] == 1)
        {
            liveCells++;   
        }
    }

    if(Field1.oldarr[x][y] == 1)
    {
        if((liveCells == 2) | (liveCells == 3))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        if(liveCells == 3)
        {
            return 1;
        }
        else 
        {
            return 0;
        }
    }
}


void GenNewField()
{
    //Copy array to oldarray
    for(int y = 0; y < Y_Size; y++)
    {
        for(int x = 0; x < X_Size; x++)
        {
            Field1.oldarr[x][y] = Field1.arr[x][y];
        }
    }

    //Apply rules to oldarray to generate new array
    for(int y = 0; y < Y_Size; y++)
    {
        for(int x = 0; x < X_Size; x++)
        {
            Field1.arr[x][y] = ApplyRules(x, y);
        }
    }
}

