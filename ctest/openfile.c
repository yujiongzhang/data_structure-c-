#include<stdio.h>
#include <windows.h> //win头文件

int main()
{
    //open file
    FILE *fp = fopen("imuavpgps.bin","rb");
    if (fp == NULL)
    {
        printf("open file error.\n");
        return 0;
    }
    
    //process data

    // char ch = fgetc(fp);
    // printf("%c\n",ch);
    // ch = fgetc(fp);
    // printf("%c\n",ch);


    // //EOF 结束标志
    // char ch;
    // while ( EOF != (ch = fgetc(fp)))
    // {
    //     printf("%c\n",ch);
    //     Sleep(100);
    // }
    
    //读取一行 fgets
    char str[200];
    fgets(str,200,fp);
    printf("%d\n",str);
    fgets(str,200,fp);
    printf("%s\n",str);
    fgets(str,200,fp);
    printf("%s\n",str);

    // char str[200];
    // char *fptr;
    // while (fptr = fgets(str,200,fp))
    // {
    //     printf("%s\n",fptr);
    //     printf("%s\n",str);
    //     Sleep(100);
    // }
    



    //close file
    fclose(fp);
    return 0;
}