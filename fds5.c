#include<stdio.h>
#include<string.h>
void selection(char str[100]);
void selection(char str[100])
{
	int i,pos,j,temp,len=strlen(str);
	char small;
	for(i=0;i<len-1;i++)
	{
		small=str[i];
		for(j=i+1;j<len;j++)
		{
			if(small>str[j])
			{
				small=str[j];
				pos=j;
			}
		}
		temp=str[pos];
		str[pos]=str[i];
		str[i]=temp;
	}
	printf("\nNew String : %s",str);
	printf("\n");
}
void bubble(char str[100]);
void bubble(char str[100])
{
	int i,pos,j,temp,len=strlen(str);
	char big;
	for(i=0;i<len-1;i++)
	{
		big=str[i];
		for(j=i+1;j<len;j++)
		{
			if(big<str[j])
			{
				big=str[j];
				pos=j;
				temp=str[pos];
				str[pos]=str[i];
				str[i]=temp;
			}
		}
	}
	printf("New String : %s",str);
	printf("\n");
}
void insertion(char str[100]);
void insertion(char str1[100])
{
	int a,i,j,pos,len=strlen(str1);
	char temp,big,small;
	char *str2;
	strcpy(str1,str2);
	for(i=1;i<len;i++)
	{
		temp=str1[i];
		for(j=i-1;j>=0;j--)
		{
			if(temp<str1[j])
			{
                  		str1[j+1]=str1[j];
				pos=j;
			}
			else
				break;
		}
		str1[j+1]=temp;
	}
	a=strcmp(str2,str1);
	if(a==0)	{
		printf("String is already sorted");
	}
	else	{
		printf("New String : %s",str1);
		printf("\n");
	}
}
void binary();
void binary()
{
	int n,i,a[n];
	printf("Enter the size : ");
	scanf("%d",&n);
	printf("Enter the elements : \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int h=0,l=n,mid,d,flag=0,pos;
      	printf("\nEnter the element to be searched : ");
      	scanf("%d",&d);
      	for(i=0;i<n;i++)
      	{
        	mid=(h+l)/2;
        	if(a[mid]==d)
        	{
              		flag=1;
              		break;
        	}
        	if(a[mid]>d)
        	{
            		l=mid-1;
        	}
        	else if(a[mid]<d)
        	{
              		h=mid+1;
        	}
	}
      	if(flag==1)
      		printf("\nElement found");
      	else
      		printf("\nElement not found");
}
int main()
{
	char str[100],ch1,ch2;
	int ch,l,k;
	do
	{
		printf("MENU\n1.Insertion(ascending)\n2.Bubble(descending)\n3.Binary search\n4.Exit");
		printf("\nEnter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
            		case 1:	printf("Enter a string : ");
                   		scanf("%s",str);
                   		insertion(str);
                   		break;
            		case 2:	printf("Enter a string : ");
                   		scanf("%s",str);
                   		bubble(str);
            	       		break;
            		case 3:	binary();
		   		break;
	    		case 4:	return 0;
            	}
		printf("\nDo you want to continue : ");
      		scanf("%c",&ch2);
      		scanf("%c",&ch1);
	}while(ch1=='y'||ch1=='Y');
}
