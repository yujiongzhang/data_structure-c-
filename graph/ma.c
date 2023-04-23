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
        if (*x+1<=X-1 && *y-2>=0 && chess[*x+1][*y-2] == 0)
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

void printchess()
{
    int i,j;
    for ( i = 0; i < X; i++)
    {
        for (j = 0; j < Y; j++)
        {
            printf("%d\t",chess[i][j]);
        }
        printf("\n"); 
    }
     printf("\n");
}

//深度优先遍历棋盘
int TravelChessBoard(int x,int y,int tag)
{
    int x1 = x, y1 = y, flag = 0, count = 0;
    chess[x][y] = tag;

    if ( X*Y == tag)
    {
        // 打印棋盘
        printchess();
        return 1;
    }

    // 找到马的下一个可走的坐标（x1,y1）, 如果找到flag = 1；否则为 0
    flag = nextxy(&x1,&y1,count);
    while ( 0 == flag && count<7)
    {
        count++;
        flag = nextxy(&x1,&y1,count);
    }
    

    while (flag)
    {
        if (TravelChessBoard(x1,y1,tag+1))
        {
            return 1;
        }
        
        // 继续找到马的下一步可走的坐标（x1,y1）, 如果找到flag = 1；否则为 0
        x1 = x;
        y1 = y;
        count++;
        flag = nextxy(&x1,&y1,count);
        while (0 == flag && count < 7)
        {
            count++;
            flag = nextxy(&x1,&y1,count);
        }
        

    }
    
    if ( 0 == flag)
    {
        chess[x][y] = 0;
    }
    

    return 0;

}



int main()
{
    int i,j;
    clock_t start,finish;

    start = clock();

    for ( i = 0; i < X; i++)
    {
        for (j = 0; j < Y; j++)
        {
            chess[i][j] = 0;
        }
    }
    

    if ( !TravelChessBoard(2,0,1))
    {
        printf("sorry! error!\n");
    }

    finish = clock();

    printf("\ntime is %f second\n\n",(double)(finish - start));



    return 0;
}