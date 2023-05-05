#include "test.h"
extern int id; //申明变量 id 是在外部定义的，申明可以在很多个文件中进行

void changId()
{
id=2;
}