#include<stdio.h>

int count = 0;

int notDanger(int row, int j, int (*chess)[8])
{
    int i,k;
    int flag1 = 0;
    int flag2 = 0,flag3=0,flag4=0,flag5=0;

    //判断列方向
    for ( i = 0; i < 8; i++)
    {
        if (*(*(chess+i)+j)!=0)
        {
            flag1 = 1;
            break;
        }
        
    }
    //判断左上方
    for ( i = row,k=j; i >=0 && k>=0; i--,k--)
    {
        if (*(*(chess+i)+k)!=0)
        {
            flag2 = 1;
            break;
        }
    }
    //判断右下方
    for ( i = row,k=j; i < 8  && k<8; i++,k++)
    {
        if (*(*(chess+i)+k)!=0)
        {
            flag3 = 1;
            break;
        }
    }

    //判断右上方
    for ( i = row,k=j; i>=0 && k<8; i--,k++)
    {
        if (*(*(chess+i)+k)!=0)
        {
            flag4 = 1;
            break;
        }
    }

    //判断左下方
    for ( i = row,k=j; i < 8  && k>=0; i++,k--)
    {
        if (*(*(chess+i)+k)!=0)
        {
            flag5 = 1;
            break;
        }
    }

    if (flag1 || flag2 || flag3 || flag4 || flag5)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

/**
 * @brief 
 * 
 * @param row 起始行
 * @param n   列数
 * @param chess 指向棋盘每一行的指针
 */
void EightQueen( int row, int n, int (*chess)[8])
{
    int chess2[8][8],i,j;
    for ( i = 0; i < 8; i++)
    {
        for ( j = 0; j < 8; j++)
        {
            chess2[i][j] = chess[i][j];
        }
    }

    if (8 == row)
    {
        printf(" times of success: %d \n",count);
        for ( i = 0; i < 8; i++)
        {
            for ( j = 0; j < 8; j++)
            {
                printf("%d ",*(*(chess2+i)+j));
            }
            printf("\n");
        }
        printf("\n\n");
        count++;
    }
    else
    {
        //判断位置是否有危险，如果没有，继续往下。
        for ( j = 0; j < n; j++)
        {
            if (notDanger(row,j,chess))
            {
                for ( i = 0; i < 8; i++)
                {
                    *(*(chess2+row)+i) = 0;
                }
                *(*(chess2+row)+j) = 1;
                EightQueen(row+1, n, chess2);
            }
        }
    }

}

int main()
{
    int chess[8][8],i,j;
    for ( i = 0; i < 8; i++)
    {
        for ( j = 0; j < 8; j++)
        {
            chess[i][j] = 0;
        }
    }
    EightQueen(0,8,chess);
    printf(" there are %d methods \n",count);
    return 0;
}