#include<stdio.h>
#include"test.h"

int id;//定义只允许一次

int main()
{
    id=1;
    printf("%d",id);//id=1
    changId();
    printf("%d",id);//id=2
}