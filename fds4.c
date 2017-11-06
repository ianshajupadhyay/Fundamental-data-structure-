#include<stdio.h>
struct student
{
	int roll_no;
};
struct details
{
	char name[30];
	float marks;
	struct student a;
};
int main()
{  
	struct details s[30];
	int n,i,x,y,t,r,f,count=0;
	printf("Enter the number of student whose data you want to input:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("Enter the data for %d student\n",i);
		printf("Roll no.:");
		scanf("%d",&s[i].a.roll_no);
		printf("Name:");
		scanf("%s",s[i].name);
		printf("1st year CGPA:");
		scanf("%f",&s[i].marks);
		printf("\n");	
	}
	do
	{  
		printf("MENU\n");
	  	printf("1.Display all data\n2.Add data\n3.Search data\n4.Modify data\n5.Delete data\n6.Exit\n");
		scanf("%d",&x);
		switch(x)
		{
			case 1:{
					printf("Rollno\tName\t1st year CGPA\n");
					for(i=1;i<=n;i++)
               				{
	            				printf("%d\t",s[i].a.roll_no);
				    		printf("%s\t",s[i].name);
	            				printf("%f\n",s[i].marks);
             				}
             				break;
               			} 
         		case 2:{	n=n+1;
	       		  		printf("Roll no.:");
					scanf("%d",&s[i].a.roll_no);
					printf("Name:");
					scanf("%s",s[i].name);
					printf("1st year CGPA:");
					scanf("%f",&s[i].marks);
			        	printf("Updated data is\n");
			      		printf("Rollno\tName\t1st year CGPA\n");
			      		for(i=1;i<=n;i++)
					{
						printf("%d\t",s[i].a.roll_no);
				    		printf("%s\t",s[i].name);
	            				printf("%f\n",s[i].marks);
					}
					break;
				}    
	   		case 3:{
	   				printf("Enter the roll no you want to search:\n");
	   				scanf("%d",&t);
	          			for(i=1;i<=n;i++)
	          			{
	          				if(s[i].a.roll_no==t)
	          				{
	          					printf("Record is found\n");
	          					printf("Rollno\tName\t1st year CGPA\n");
	          					printf("%d\t",s[i].a.roll_no);
				    			printf("%s\t",s[i].name);
	            					printf("%f\n",s[i].marks);
	          					count=count+1;
			  			}
			  		}
			  		if(count==0)
			  		printf("Record not found\n");
			  		break;
		 		}
	
	     		case 4:{
	     			 	printf("Enter the student record s.no you want to modify:");
	     	    			scanf("%d",&r);
	     				printf("Enter the new data of student record\n");
	     				printf("Roll no.:");
					scanf("%d",&s[r].a.roll_no);
					printf("Name:");
					scanf("%s",s[r].name);
					printf("1st year CGPA:");
					scanf("%f",&s[r].marks);
			    		printf("Rollno\tName\t1st year CGPA\n");
			    		for(i=1;i<=n;i++)
				     	{
						printf("%d\t",s[i].a.roll_no);
				        	printf("%s\t",s[i].name);
	            	    			printf("%f\n",s[i].marks);
				     	}
	            			break;
				}
			case 5:{ 
		 			printf("Enter the s.no of student record you want to delete:");
		     			scanf("%d",&f);
		     			for(i = 0; i < 30; i++)
		     				s[f].a.roll_no=0;
		     				s[f].name[i]='\0';
		     				s[f].marks=0;
		     			printf("Rollno\tName\t1st year CGPA\n");
		     			for(i=1;i<=n;i++)
				     	{
						printf("%d\t",s[i].a.roll_no);
				        	printf("%s\t",s[i].name);
	            	    			printf("%f\n",s[i].marks);
				     	}	
		        		break;
			   	}	   
			case 6:{
					x=6;
					break;
				}
		}	
	}while(x!=6);
}
