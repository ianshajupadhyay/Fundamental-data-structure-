#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
 int data;
 struct node* next;
 struct node* prev;

} node;
void display(node *head)
{
 
 node *p=NULL;
 p=head;
 if(head==NULL)
	printf("EMPTY");
 else
 while(p!=NULL)
 {
	printf("%d ",p->data);
	p=p->next;
	
 }
}

int main()
{
 int n,x,c,pos;
 node *head =NULL;
 node * p = NULL;
 node * z = NULL;
 scanf("%d",&x);
	for(int i=0;i<x;i++)
	{
		node *temp =(node *)malloc (sizeof(node));
		scanf("%d",&temp->data);
		temp->next=NULL;
		temp->prev=NULL;
		if(i==0)
			head=temp;
		else
		{
			p=head;
			while(p->next!=NULL)
			  p=p->next;
			p->next=temp;
			temp->prev=p;
			temp->next=NULL;
			
		}
			
	}
 display(head);
 scanf("%d",&c);
	if(c==1)
	{
		node *temp =(node *)malloc (sizeof(node));
		scanf("%d",&temp->data);
		
		temp->next=head;
		head->prev=temp;
		temp->prev=NULL;
		head=temp;
		display(head);
	}
	if(c==2)
	{
		printf("\nEnter the position at which you want to neter the elemnet");
       		scanf("%d",&pos);
		p=head;
		z=head;
		node *temp =(node *)malloc (sizeof(node));
		scanf("%d",&temp->data);
		for(int i=1;i<=pos;i++)
		{
			if(i<=pos-1)	
			{
				p=p->next;
				z=z->next;
			}
			else
				z=z->next;		
		}
		p->next=temp;
		temp->prev=p;
		temp->next=z;
		z->prev=temp;	
		display(head);	
				
	}
	if(c==3)
	{
		int w,flag=0;
		printf("\nEnter the Elemnet to be searcged");
       		scanf("%d",&w);
		p=head;
		while(p->next!=NULL)
		{
			if(p->data==w)
			{
				flag++;
				break;	
			}
			else
			{
				p=p->next;
			}
		}
		if(flag==1)
			printf("Elemnt found");
		else 
			printf("not");
	}
	if(c==4)
	{
		printf("\nEnter the position at which you want to delete the elemnet");
       		 scanf("%d",&pos);
		node * z = NULL;
		node * w = NULL;
		z=head;
		p=head;
	
		for(int i=0;i<pos;i++)
		{
			if(i<pos-2)
			{
				p=p->next;
				z=z->next;	
			}
			else 
			{
				z=z->next;
			}
		}

		p->next=z;
		z->prev=p;
		display(head);
	}
	if(c==5)
	{
		p=head;
		while(p->next!=NULL)
		{
			p=p->next;
		}
		while(p->prev!=NULL)
		{
			printf("%d",p->data);
			p=p->prev;
		}
		printf("%d",p->data);
	}
}
