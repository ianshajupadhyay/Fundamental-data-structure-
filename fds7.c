#include<stdio.h>
int  d;
int partition(int a[],int l,int  r)		{
	int pivot,i,j,k,temp;
	pivot=a[l];
	i=l;
	j=r+1;
	do	{
		do	{
			i++;
		}while((a[i]<pivot)&&(i<=r));
		do	{
			j--;
		}while(pivot<a[j]);
		if(i<j)	{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
			
		}
		for(k=0;k<r+1;k++)	{
			printf("%d ",a[k]);
			
			//
		}
		
		printf("  pivot: %d\n",a[l]);
	}while(i<j);
	a[l]=a[j];
	a[j]=pivot;
	for(k=0;k<r+1;k++)	{
			printf("%d ",a[k]);
			
			//
		}
		
		printf("  pivot: %d\n",a[l]);
	return(j);
}
void quick_sort(int a[],int l,int r)	{
	int j,k;
	if(l<r)		{
		j=partition(a,l,r);
		
		quick_sort(a,l,j-1);
		quick_sort(a,j+1,r);
	}
}
int main()	{
	int x,i;
	printf("Enter the no of elements : ");
	scanf("%d",&x);
	d=x;
	int a[x];
	printf("Enter the elements : ");
	for(i=0;i<x;i++)	{
		scanf("%d",&a[i]);
		
	}
	quick_sort(a,0,x-1);
	printf("\nSorted list is : ");
	for(i=0;i<x;i++)	{
		printf("%d ",a[i]);
	}
	printf("\n");
}
			
