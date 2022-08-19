#include <stdio.h>
#include <stdlib.h>

/*  
generally arrays are read or edited in a way that
rows(x) are read first and on the end of the row 
we advance to a new column(y) 
*/


//DEFINES
#define USECHARFIELD

#define X_Size 60
#define Y_Size 60


//STRUCTS
typedef struct{
    int arr[X_Size][Y_Size];
    int oldarr[X_Size][Y_Size];
}field;

field Field1;

//VARIABLES
char CharField[X_Size][Y_Size];


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


void PrintCharField()
{
    for(int y = 0; y < Y_Size; y++)
    {
        for(int x = 0; x < X_Size; x++)
        {
            printf("%2c", CharField[x][y]);            
        }
        printf("\n");
    }
}


int ApplyRules(int x, int y)
{
    int liveCells = 0;

    if((x == 0) | (x == X_Size-1) | (y == 0) | (y== Y_Size-1))
    {
        //checks if current field is a corner
        if(((x==0)&(y==0)) | ((x==0)&(y==Y_Size-1)) | ((x==X_Size-1)&(y==0)) | ((x==X_Size-1)&(y==Y_Size-1)))
        {
            //check corners here 
        }
        else
        {
            //all fields on the left border
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

            //all fields on the right border
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

            //all fields on the bottom border
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

            //all fields on the top border
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


int GenNewField()
{
    //copy array to oldarray
    for(int y = 0; y < Y_Size; y++)
    {
        for(int x = 0; x < X_Size; x++)
        {
            Field1.oldarr[x][y] = Field1.arr[x][y];
        }
    }

    //apply rules to oldarray to generate new array
    for(int y = 0; y < Y_Size; y++)
    {
        for(int x = 0; x < X_Size; x++)
        {
            Field1.arr[x][y] = ApplyRules(x, y);
        }
    }
    
    #ifdef USECHARFIELD
    for(int y = 0; y < Y_Size; y++)
    {
        for(int x = 0; x < X_Size; x++)
        {
            if(Field1.arr[x][y] == 1)
            {
                CharField[x][y] = '+';
            }
            else if(Field1.arr[x][y] == 0)
            {
                CharField[x][y] = ' ';
            }    

        }
    }
    #endif

    return 1;
}

