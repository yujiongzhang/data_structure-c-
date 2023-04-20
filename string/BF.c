#include<stdio.h>
int main()
{
	int a[100],b[100],i,j,m,n;
	scanf("%d %d",&n,&m);
	//输入数组a
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	//输入数组b
	for(i=1;i<=m;i++)
		scanf("%d",&b[i]);
	
	i=j=1;
	while(i<=n&&j<=m)    //两个数组均未到最后的元素 
	{
		if(a[i]==b[j])
		{
			//继续比较后续的元素 
			++i;
			++j;
		}
		else
		{
			//下标后退，继续开始匹配 
			i=i-j+2; 
			j=1;
		}
	}
	if(j>m)   //若寻找成功，此时j=m+1, 
		printf("%d\n",i-m-1);   //为了满足题目下标从0开始，所以i-m还要减1 
	else
		printf("No Answer\n");
	return 0;
} 

