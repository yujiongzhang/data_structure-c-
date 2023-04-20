/**
 * @file KMP.c
 * @author Zhang YJ (yj_zhang123@foxmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<stdio.h>
typedef char* String;


void get_next(String T,int *next)
{
    // i 后缀 j 前缀
    int j = 0;
    int i = 1;
    next[1] = 0;

    while (i<T[0])
    {
        if (0 == j || T[i] == T[j])
        {
            i++;
            j++;
            next[i] = j;
        }
        else
        {
            j = next[j];// j 回溯
        }
    //前缀固定的，后缀是相对的
    }
}

/**
 * @brief 返回子窜T在主串S第pos个字符之后的位置，若不存在则返回0
 * 
 * @param S 
 * @param T 
 * @param pos 
 * @return int 
 */
int Index_KMP(String S,String T, int pos)
{
    int i = pos;
    int j=1;
    int next[255];

    get_next(T,next);
    while ( i<=S[0] && j<=T[0])
    {
        if (0 == j ||S[i]==T[i])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }
    
    if (j>T[0])
    {
        return i - T[0];
    }
    else
    {
        return 0;
    }

}