#include <stdio.h>
int nu=0,p=0,d[20],t[20];
int in(int x[],int y[],int s1,int s2);
int un(int z[],int s3);
int diff(int x[],int y[],int s1,int s2);
int symmdiff(int x[],int y[],int s1,int s2);
int in(int x[],int y[],int s1,int s2)
{
    int i,j,count=0,num=0;
    for(i=0;i<s1;i++)
    {
        count=0;
        for(j=i+1;j<s1;j++)
            {
                if(x[i]==x[j])
                count=1;
            }
        if(count==0)
            {
                x[num]=x[i];
                num++;
            }
    }
    for(i=0;i<num;i++)
        {
            for(j=0;j<s2;j++)
                {
                    if (x[i]==y[j])
                        {
                            t[p]=x[i];
                            printf("%d ",t[p]);
                            p++;
                            break;
                        }
                }
        }
}
int un(int z[],int s3)
{
    int j,i,count=0;
    for(i=0;i<s3;i++)
        {
            count=0;
            for(j=i+1;j<s3;j++)
                {
                    if(z[i]==z[j])
                    count=1;
                }
            if(count==0)
                {
                    d[nu]=z[i];
                    printf("%d ",d[nu]);
                    nu++;
                }
        }
}
int sort(int d[],int nu)
{
    int i,step,temp;
    for(step=0;step<nu-1;step++)
        {
            for(i=0;i<nu-step-1;i++)
            if(d[i]>d[i+1])
                {
                    temp=d[i];
                    d[i]=d[i+1];
                    d[i+1]=temp;
                }
        }
    for(i=0;i<nu;i++)
    printf("%d ",d[i]);
}
int symmdiff(int x[],int y[],int s1,int s2)
{
    int i,j,count;
    for(i=0;i<s1;i++)
        {	count=0;
            for(j=0;j<s2;j++)
                {
                    if(x[i]==y[j])
                    	{
                    		count=1;
                    	}
                }
                    if(count==0)
                    	{
                    		printf(" %d",x[i]);
                    	}
                
         }
}
int diff(int x[],int y[],int s1,int s2)
{
    int i,j,count,flag;
    for(i=0;i<s1;i++)
        {	count=0,flag=0;
            for(j=0;j<s2;j++)
                {
                    if(x[i]==y[j])
                    	{
                    		count=1;
                    	}
                }
             if(count==0)
             printf("%d ",x[i]);
         }
}
int main()
{
    int i,j,x[20],y[20],z[20],s1,s2,s3,choice;
    char ca,m;
    printf("Enter the size of 1st array:");
    scanf("%d",&s1);
    printf("Enter the elements of 1st array:\n");
    for(i=0;i<s1;i++)
        {
            scanf(" %d",&x[i]);
        }
    printf("\nEnter the size of 2nd array:");
    scanf("%d",&s2);
    printf("Enter the elements of 2nd array:\n");
    for(i=0;i<s2;i++)
        {
            scanf(" %d",&y[i]);
        }
    printf("\nThe first array is:");
    for(i=0;i<s1;i++)
        {
            printf(" %d",x[i]);
        }
    printf("\nThe second array is:");
    for(i=0;i<s2;i++)
        {
            printf(" %d",y[i]);
        }
    printf("\n");
    if(s1>=s2)
    {
        int j=0;
        for(i=0;i<s1;i++)
        {
            z[i]=x[i];
            if(j<s2)
                {
                    z[i+s1]=y[j];
                    j++;
                }
        }
        s3=(s1+s2);
    }
    else
    {
        int j=0;
        for(i=0;i<s2;i++)
        {
            z[i]=y[i];
            if(j<s1)
                {
                    z[i+s2]=x[j];
                    j++;
                }
        }
        s3=(s1+s2);
    }
    do
        {
            printf("\n Menu \n1:Intersection \n2:Union \n3:Symmetric Difference \n4:Difference");
            printf("\n Enter your choice:");
            scanf("%d",&choice);
            if(choice==1)
                {	
                	printf("Intersection:\n");
                    in(x,y,s1,s2);
                }
            else if(choice==2)
                {	
                	printf("Union:\n");
                    un(z,s3);
                }
            else if(choice==3)
                {   
                	printf("Symmetric Difference:\n");
                    symmdiff(d,t,nu,p);
                }
            else if(choice==4)
                {
                	printf("Difference:\n");
                    diff(x,y,s1,s2);
                }
            printf("\n Do you want to enter again:");
            scanf("%c",&m);
            scanf("%c",&ca);
            }while(ca=='y'||ca=='Y');
    printf("Thank You\n");
}
