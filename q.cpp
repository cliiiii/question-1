#include <stdio.h>
int r[100][100],m[100];
int main()
{
    int a,c,num=0,i,j,k;
	float x[100];
	scanf("%d",&a);
	for(i=0;i<a;i++)  //循环输入参与运算的数于一维数组中
	{
		scanf("%d",&c);
        x[i]=c;
		m[i]=1;     /*因为题目要求只要有一对数x与y，x+y=z即可计数一次，如果有另一对数的和也等于z则不参与计数，所以为了防止重复计算，设置一个新的一维数组m[i]，设置每个数对应位置的数是1，相当于开关打开。*/
	}
	for(k=0;k<a;k++)
	{
		for(j=k;j<a;j++)   
		{
			if(x[k]==x[j])
				r[k][j]=0;   //利用二维数组存入两个数的和
			else
		    	r[k][j]=x[k]+x[j];
		}
	}
    for(i=0;i<a;i++)
	{
		for(j=0;j<a;j++)
		{
			for(k=0;k<a;k++)
			{
				if((r[i][j]==x[k])&&(m[k]==1))
				{
					num++;
				    m[k]=0;    /*用循环遍历数组，如果和等于一维数组内任何一个数，且开关是打开的m[i]=1，则让计数器（一个变量）加一，把与开关设置为0，这样就会让这个数不再参与接下来的计算，防止重复计数。*/
				}
			}
		}
	}
    printf("%d\n",num);
	return 0;
}