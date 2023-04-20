#include <stdio.h>
#include <time.h>

#define X 8
#define Y 8

int chess[X][Y];

int nextxy(int *x, int *y,int count)
{
    switch (count)
    {
    case 0:
        if (*x + 2<= X-1 && *y-1>=0 && chess[*x+2][*y-1]==0)
        {
            *x +=2;
            *y -=1;
            return 1;
        }
        break;
    
    case 1:
        if (*x+2<=X-1 && *y+1<=Y-1 && chess[*x+2][*y+1] == 0)
        {
            *x +=2;
            *y +=1;
            return 1;
        }
        break;

    case 2:
        if (*x-1>=0 && *y+2<=Y-1 && chess[*x+1][*y-2] == 0)
        {
            *x +=1;
            *y -=2;
            return 1;
        }
        break;

    case 3:
        if (*x+1<=X-1 && *y+2<=Y-1 && chess[*x+1][*y+2] == 0)
        {
            *x +=1;
            *y +=2;
            return 1;
        }
        break;

    case 4:
        if (*x-2>=0 && *y-1>=0 && chess[*x-2][*y-1] == 0)
        {
            *x -= 2;
            *y -= 1;
            return 1;
        }
        break;
    case 5:
        if (*x-2>=0 && *y+1<=Y-1 && chess[*x-2][*y+1] == 0)
        {
            *x -=2;
            *y +=1;
            return 1;
        }
        break;
    case 6:
        if (*x-1>=0 && *y-2>=0 && chess[*x-1][*y-2] == 0)
        {
            *x -=1;
            *y -=2;
            return 1;
        }
        break;
    case 7:
        if (*x-1>=0 && *y+2<=Y-1 && chess[*x-1][*y+2] == 0)
        {
            *x -=1;
            *y +=2;
            return 1;
        }
        break;
    default:
        break;
    }
    return 0;

}

int TravelChessBoard(int x,int y,int tag)
{

}