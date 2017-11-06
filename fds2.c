#include <stdio.h>
int i,j;
void add(int a[][20],int b[][20],int m,int n,int p,int q);
void mul(int a[][20],int b[][20],int m,int n,int p,int q);
void trans(int a[][20],int m,int n);
void saddle(int a[][20],int m,int n);
void add(int a[][20],int b[][20],int m,int n,int p,int q)
{
  int c[20][20];
    if((m==p)&&(n==q))
    {
          for(i=0;i<m;i++)
       {
           for(j=0;j<n;j++)
           {
               c[i][j]=(a[i][j]+b[i][j]);
           }
       }
      for(i=0;i<m;i++)
       {
           for(j=0;j<n;j++)
            {
                printf(" %d",c[i][j]);
            }
            printf("\n");
       }
    }
    else
        printf("Addition is not possible");
}
void mul(int a[][20],int b[][20],int m,int n,int p,int q)
{   int c[20][20];
    if(n==p)
    {
        int k;
        for(i=0;i<m;i++)
        {

            for(j=0;j<q;j++)
            {    c[i][j]=0;
                for(k=0;k<n;k++)
                    c[i][j]=(c[i][j]+(a[i][k]*b[k][j]));
            }
        }
        for(i=0;i<m;i++)
        {
            printf("\n");

                for(j=0;j<q;j++)
                {
                    printf(" %d",c[i][j]);
                }
        }
    }
    else
        printf("Multiplication is not possible");
}
void trans(int a[][20],int m,int n)
{
   1 for(i=0;i<n;i++)
        {
            printf("\n");

                for(j=0;j<m;j++)
                {
                    printf(" %d",a[j][i]);
                }
        }
}
void saddle(int a[][20],int m,int n)
{	for(i=0;i<m;i++)
		{
			int t,k,count=0,min=99999,max=0;
			for(j=0;j<n;j++)
				{
					if (a[i][j]<min)
						{	
							min=a[i][j];
							t=j;
						}
				}
			for(k=0;k<m;k++)
				{
					if(a[k][t]>max)
					{
						max=a[k][t];
					}
					if((k<(m-1))&&(max!=a[k+1][t]))
					count=1;
				}
			if((min==max)&&(count==1))
				{
					printf("%d",max);
				}
			if(count==0||(min!=max))
			{
				printf("There is no saddle point");
			}
		}
}
int main()
{
    int m,n,p,q,a[20][20],b[20][20];
    int choice;
    char ch,ca;
    printf("Enter the rows and columns of the first matrix\n");
    scanf("%d %d",&m,&n);
    for(i=0;i<m;i++)
       {
           for(j=0;j<n;j++)
            {
                printf("Enter the %d%d element of the first matrix:",(i+1),(j+1));
                scanf("%d",&a[i][j]);
            }
       }
    printf("The first matrix is:\n\n");
    for(i=0;i<m;i++)
       {
           for(j=0;j<n;j++)
            {
                printf(" %d",a[i][j]);
            }
            printf("\n");
       }
    printf("Enter the rows and columns of the second matrix\n");
    scanf("%d %d",&p,&q);
    for(i=0;i<p;i++)
        {
            for(j=0;j<q;j++)
            {
                printf("Enter the %d%d element of the second matrix:",(i+1),(j+1));
                scanf("%d",&b[i][j]);
            }
        }
    printf("The second matrix is:\n\n");
    for(i=0;i<p;i++)
       {
           for(j=0;j<q;j++)
            {
                printf(" %d",b[i][j]);
            }
            printf("\n");
       }
    do
        {
            printf("\n Menu \n1:Addition \n2:Multiplication \n3:Transpose \n4:Saddle Point");
            printf("\n Enter your choice:");
            scanf("%d",&choice);
            if(choice==1)
                {
                   add(a,b,m,n,p,q);
                }
            else if(choice==2)
                {
                    mul(a,b,m,n,p,q);
                }
            else if(choice==3)
                {
                    trans(a,m,n);
                }
            else if(choice==4)
                {
					saddle(a,m,n);
                }
            printf("\n Do you want to enter again:");
            scanf("%c",&ch);
            scanf("%c",&ca);
            }while(ca=='y'||ca=='Y');
    printf("Thank You\n");
}
