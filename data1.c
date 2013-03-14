/*一些排列和查找函数
 * 2012 12 08
 */
#include<stdio.h>	//排序后折半查找
#include<stdlib.h>
#define MAX 100
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))
#define COMPARE(x,y) ((x)<(y)?-1:((x)==(y))?0:1)
void perm(int  *list,int i,int n);	//递归的全排列函数
void sort(int list[],int n);	//选择排序函数
void sort_2(int list[],int n);	//插入排序函数
void sort_3(int list[],int n);	//冒泡排序函数
int binsearch(int list[],int searchnum,int left,int right);	//折半查找函数
int main(void)
{
	int i,n,left,right,x;
	int list[MAX];
	printf("Enter the number of numbers to generate: ");
	scanf("%d",&n);
	if(n<1 ||n>MAX)
	{
		printf("Improper vaule of n\n");
		exit(1);
	}
	for(i=0;i<n;i++)
	{
		list[i]=rand()%100;
		printf("list[%d]=%d\n",i,list[i]);
	}
	sort_3(list,n);
	printf("\nsorted array:\n");
	for(i=0;i<n;i++)
		printf("%d  ",list[i]);
	printf("Enter the number you want to search : ");
	scanf("%d",&x);
	left=0;
	right=n-1;
	if(binsearch(list,x,left,right)!=-1)
		printf("It's in the array\n");
	else 
		printf("Sorry can't find it\n");
	printf ("数组的全排列\n");
	perm(list,0,n);
	return 0;
}
void sort(int list[],int n)
{
	int i,j,min,temp;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
			if(list[j]<list[min])
				min=j;
		SWAP(list[i],list[min],temp);
	}
}
void sort_2(int list[],int n)
{
	int key,i,j,temp;
	for(j=1;j<n;j++)
	{
		key=j;
		if(j==1){		//排序前两个数
			if(list[j-1]>list[j])
				SWAP(list[j-1],list[j],temp);
			continue;
			}
		for(i=key-1;i>0;i--)		//找到key的插入点
		{
			if(list[key]>=list[key-1])
				break;
			if(list[key]<list[i] && list[key]>=list[i-1])
			{
				key=i;
				break;
			}
		}
		if(i==0)		//如果没找到，就插在最前面
			key=i;
		temp=list[j];		//进行重新排序
		for(i=j-1;i>=key;i--)
			list[i+1]=list[i];
		list[key]=temp;
	}
}
void sort_3(int list[],int n)
{
	int i,j,temp;
	for(i=n-1;i>0;i--)
		for(j=0;j<i;j++)
			if(list[j]>list[j+1])
					SWAP(list[j],list[j+1],temp);
}
int binsearch(int list[],int searchnum,int left,int right)
{
	int middle;
	while(left<=right)
	{
		middle=(left+right)/2;
		switch(COMPARE(list[middle],searchnum))		//比较查找数和中值的大小关系
		{
			case -1: left=middle+1;
				break;
			case 0: return middle;
			case 1: right=middle-1;
		}
	}
	return -1;
}
void perm(int *list,int i,int n)
{
	int j,temp;
	if(i==n)
	{
		for(j=0;j<n;j++)
			printf("%d ",list[j]);
		printf("      ");
	}
	else 
	{
		for(j=i;j<n;j++)		//这是一个循环，遍历每种情况
		{
			SWAP(list[i],list[j],temp);
			perm(list,i+1,n);
			SWAP(list[i],list[j],temp);
		}
	}
}
