#include<stdio.h>
int z[20][3],k=1;
int display(int a,int b,int x[a][b],int count)	{
	int i,j,y[20][3];
	printf("\n%d\t%d\t%d\n",a,b,count);
	z[0][0]=a;
	z[0][1]=b;
	z[0][2]=count;
	for(i=0;i<a;i++)	
	{
		for(j=0;j<b;j++)	
		{
			if(x[i][j]!=0)
			{
				printf("%d\t%d\t%d\n",i,j,x[i][j]);
				z[k][0]=i;
				z[k][1]=j;
				z[k][2]=x[i][j];
				k++;
			}
		}
	}
}
int add(int z1[20][3],int z2[20][3])	{
	if(z1[0][0]==z2[0][0] && z1[0][1]==z2[0][1])	{
		int m[20][3],s1=z1[0][2],s2=z2[0][2],i,j,r;
		m[0][0]=z1[0][0];
		m[0][1]=z1[0][1];
		i=j=r=1;
		while(i<=s1 && j<=s2)	{
			while(i<=s1 && j<=s2)	{
				if(z1[i][0]<z2[j][0])	{
					m[r][0]=z1[i][0];
					m[r][1]=z1[i][1];
					m[r][2]=z1[i][2];
					i++;
					r++;
					break;
				}
				if(z2[j][0]<z1[i][0])	{
					m[r][0]=z2[j][0];
					m[r][1]=z2[j][1];
					m[r][2]=z2[j][2];
					j++;
					r++;
					break;
				}
				if(z1[i][1]<z2[j][1])	{
					m[r][0]=z1[i][0];
					m[r][1]=z1[i][1];
					m[r][2]=z1[i][2];
					i++;
					r++;
					break;
				}
				if(z2[j][1]<z1[i][1])	{
					m[r][0]=z2[j][0];
					m[r][1]=z2[j][1];
					m[r][2]=z2[j][2];
					j++;
					r++;
					break;
				}
				m[r][0]=z2[j][0];
				m[r][1]=z2[j][1];
				m[r][2]=z1[i][2]+z2[j][2];
				i++;
				j++;
				r++;
			}	
		}
		while(i<=s1)	{
			m[r][0]=z1[i][0];
			m[r][1]=z1[i][1];
			m[r][2]=z1[i][2];
			i++;
			r++;
		}
		while(j<=s2)	{
			m[r][0]=z2[j][0];
			m[r][1]=z2[j][1];
			m[r][2]=z2[j][2];
			j++;
			r++;
		}
		m[0][2]=r-1;
		printf("\n\nAddition of sparse matrix is\n");
		for(i=0;i<r;i++)	{
			printf("%d\t%d\t%d\n",m[i][0],m[i][1],m[i][2]);
		}
	}
	else 
		printf("Addition is not possible\n");
}
int simple_trans(int x[20][3])	{
	int y[20][3],t=x[0][2],i,j,k=1;
	y[0][0]=x[0][1];
	y[0][1]=x[0][0];
	y[0][2]=x[0][2];
	for(i=0;i<x[0][1];i++)	{
		for(j=1;j<=t;j++)	{
			if(i==x[j][1])	{
				y[k][0]=i;
				y[k][1]=x[j][0];
				y[k][2]=x[j][2];
				k++;
			}
		}
	}
	printf("%d\t%d\t%d\n",y[0][0],y[0][1],y[0][2]);
	for(i=1;i<k;i++)	{
		printf("%d\t%d\t%d\n",y[i][0],y[i][1],y[i][2]);
	}
}	
void fast_transpose(int x[20][3])	{
	int i,m,n,t,temp,s[20],T[20],y[20][3];
	y[0][1]=m=x[0][0];
	y[0][0]=n=x[0][1];
	y[0][2]=t=x[0][2];
	for(i=0;i<n;i++)	{
		s[i]=0;
	}
	for(i=1;i<=t;i++)	{
		s[x[i][1]]=s[x[i][1]]+1;
	}
	T[0]=1;
	for(i=1;i<n;i++)	{
		T[i]=T[i-1]+s[i-1];
	}
	for(i=1;i<=t;i++)	{
		temp=x[i][1];
		int j=T[temp];
		T[temp]++;
		y[j][0]=x[i][1];
		y[j][1]=x[i][0];
		y[j][2]=x[i][2];
	}
	printf("%d\t%d\t%d\n",y[0][0],y[0][1],y[0][2]);
	for(i=1;i<=t;i++)	{
		printf("%d\t%d\t%d\n",y[i][0],y[i][1],y[i][2]);
	}
}
int main()	{
	int a,b,c,d,i,j,count1=0,count2=0,z1[20][3],z2[20][3],k1,k2;
	printf("Enter the size of the 1st matrix : ");
	scanf("%d%d",&a,&b);
	int x[a][b];
	printf("Enter the elements of the 1st matrix :\n");
	for(i=0;i<a;i++)	{
		for(j=0;j<b;j++)	{
			scanf("%d",&x[i][j]);
			if(x[i][j]==0)	{
				count1++;
			}
		}
	}
	if(count1>((a*b)/2))	{
		printf("\n1st Matrix is sparse");
		printf("\nSparse representation of first matrix is : ");
		count1=(a*b)-count1;
		display(a,b,x,count1);
		printf("\n");
		k1=k;
		for(i=0;i<k1;i++)	{
			z1[i][0]=z[i][0];
			z1[i][1]=z[i][1];
			z1[i][2]=z[i][2];
		}
	}
	else
		printf("\n1st Matrix is not sparse");
	k=1;
	printf("\nEnter the size of the 2nd matrix : ");
	scanf("%d%d",&c,&d);
	int y[c][d];
	printf("Enter the elements of the 2nd matrix :\n");
	for(i=0;i<c;i++)	{
		for(j=0;j<d;j++)	{
			scanf("%d",&y[i][j]);
			if(y[i][j]==0)	{
				count2++;
			}
		}
	}
	if(count2>((c*d)/2))	{
		printf("\n2nd Matrix is sparse");
		printf("\nSparse representation of second matrix is : ");
		count2=(c*d)-count2;
		display(c,d,y,count2);
		printf("\n");
		k2=k;
		for(i=0;i<k2;i++)	{
			z2[i][0]=z[i][0]; 
			z2[i][1]=z[i][1];
			z2[i][2]=z[i][2];
		}
	}
	else
		printf("\n2nd Matrix is not sparse");
	int opt;	
	do	{
		printf("Menu\n");
		printf("1:Addition\n2:Simple Transpose\n3:Fast Transpose\n4:Exit\n");
		scanf("%d",&opt);
		switch(opt)	{
			case 1:	add(z1,z2);
					break;
			case 2:	printf("Simple Transpose of first matrix\n");
					simple_trans(z1);
					printf("Simple Transpose of second matrix\n");
					simple_trans(z2);
					break;
			case 3:	printf("Fast Transpose of first matrix\n");
					fast_transpose(z1);
					printf("Fast Transpose of second matrix\n");
					fast_transpose(z2);
					break;
		}
	}while(opt!=4);
}		
