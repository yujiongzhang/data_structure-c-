/**
 * @file hannuo.c
 * @author Zhang YJ (yj_zhang123@foxmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include<stdio.h>
/**
 * @brief 将 n个盘子从x借助y移动到z
 * 
 * @param n 
 * @param x 
 * @param y 
 * @param z 
 */
void move(int n, char x,char y,char z)
{
    if (1 == n)
    {
        printf("%c-->%c\n",x,z);
    }
    else{
        move(n-1,x,z,y);
        printf("%c-->%c\n",x,z);
        move(n-1,y,x,z);
    }
}

int main()
{
    int n;
    printf("input the number of hanno:");
    scanf("%d",&n);
    printf("the moving step list: \n");
    move(n,'X','Y','Z');
    return 0;

}