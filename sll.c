#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
 int data;
 struct node* next;
} node;

node *create(int n);

void display(node * head);
node *swapNodes(struct node *head, int x, int y)
{
   if(x==y)
   	return 0;
   struct node *prevX =NULL,*currX = head;
   while (currX && currX->data != x)
   {
       prevX = currX;
       currX = currX->next;
   } 
   struct node *prevY = NULL , *currY =head;
   while (currY && currY->data != x)
   {
       prevY = currY;
       currY = currY->next;
   } 
   if(prevX != NULL)
   {
	prevX->next = currY;
   }  
   else 
       head= currY;  
   if (prevY != NULL)
       prevY->next = currX;
   else 
       head = currX;
   struct node *temp;
   temp = currY->next;
   currY->next = currX->next;
   currX->next  = temp;
   return head;
   
}
node * printmiddle(struct node *head)
{
   struct node *slow = head;
   struct node *fast = head;
   while(fast !=NULL && fast->next != NULL)
	{
		fast= fast->next->next;
		slow = slow->next;
	}
   printf("middle elemnt is %d",slow->data);
}
node * insertatbeg( node * head , int x)
{
 node * temp;
 temp = (node *)malloc(sizeof(node));
 temp->data = x;
 temp->next = head;
 head=temp;
 
 return head;
}
int main()
{ 
 int n,x,c,pos;
 node *head =NULL;
 node * p = NULL;
 node * z = NULL;
 node * v = NULL;
 scanf("%d",&n);
 head = create(n);
 display(head);
 printf("\nEnter which function do you want \n1-insert beg\n2-insert in between \n3-insert at end \n4-display\n5-delete element from certain position\n6-count\n7-search\n8-swap nodes without swaping data\n9-print middle of linked list\n10-find element from end\n11-search element from beginning ");
 scanf("%d",&c); 
 
if(c==1){
 		head=insertatbeg( head , x);
 		display(head) ;
        }
if(c==2)
	{
		scanf("%d",&x);
		printf("\nenter the position ayt which you want to enter element\n");
		scanf("%d",&pos);
		node * temp;
		temp = (node *)malloc(sizeof(node));
		p = (node *)malloc(sizeof(node));
		z = (node *)malloc(sizeof(node));
                p=head;
                z=head;
		for(int i=1;i<pos;i++)
		 {
 	                if(i<pos-1)
			{	
				p=p->next;
                        	z=z->next;
			}
			else
				p=p->next;
 		}
                printf("%d\n",p->data);	
		temp->data = x;
 		temp->next = p;
		z->next=temp;
 		p=temp;
	        display(head);
 
	}
if(c==3)
     	{
		scanf("%d",&x);		
		node * temp;
		temp = (node *)malloc(sizeof(node));
		p = (node *)malloc(sizeof(node));
		
                p=head;
                for(int i=1;i<n;i++)
		 {
 	                p=p->next;
 		}
		temp->data=x;
		p->next=temp;
		temp->next = NULL;
  		p=temp;		
		display(head);	
		
	}
if(c==4)    		
	{
		display(head);	
	}
if(c==5)
	{

		
		printf("\nenter the position ayt which you want to enter element\n");
		scanf("%d",&pos);
		
		p = (node *)malloc(sizeof(node));
		z = (node *)malloc(sizeof(node));
		v = (node *)malloc(sizeof(node));
                p=head;
                z=head;
		v=head;	
		for(int i=1;i<pos;i++)
		 {
 
	                if(i<pos-1)
			{	
				p=p->next;
                        	z=z->next;
				v=v->next;			
			}
			else
			{
				v=v->next;
				p=p->next;
 			}
		}
		p=p->next;
		z->next = p;
		free(v);
		display(head);
	}
if(c==6)
	{
		int count=0;
		p = (node *)malloc(sizeof(node));
		p=head;
		while(p!=NULL)
		{
			count++;
			p=p->next;
		}
		printf("Total no of nodes are : %d",count);		
	}
	
if(c==7)
	{
		int search,c=0;
		scanf("%d",&search);
		p = (node *)malloc(sizeof(node));
		p=head;		
		while(p!=NULL)
		{
			if(p->data==search)
			{
				c=1;
				break;
			}
			p=p->next;
		}
		if(c==1)
			printf("Element found");
		else
			printf("not found");
	}
if(c==8)
	{
  	
		int x=3,y=4;
		head=swapNodes(head,x,y);
		display(head);
		
	}	
if(c==9)
	{
		printmiddle(head);
	}
	
if(c==10)
	{
	
		  int q,len = 0, i;
scanf("%d",&q);
    struct node *temp = head;

   
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }

   
    

    temp = head;


    for (i = 1; i < len-q+1; i++)
       temp = temp->next;

    printf ("%d", temp->data);	
	}
if(c==11)
	{
    struct node* prev   = NULL;
    struct node* current = head;
    struct node* next;
    while (current != NULL)
    {
        next  = current->next;  
        current->next = prev;   
        prev = current;
        current = next;
    }
    head = prev;
	}
    display(head);

}


node * create(int n)
{
 node * head =NULL;
 node * temp =NULL;
 node * p = NULL;
 head = (node *)malloc(sizeof(node));
 for(int i=0;i<n;i++)
 {
  
  temp = (node *)malloc(sizeof(node));
  p = (node *)malloc(sizeof(node));
  printf("entervalue of %d : ",i+1);
  scanf("%d",&temp->data);
  temp->next=NULL;
  if(i==0)
    head=temp;
   else
   {
    p=head;
    while(p->next!=NULL)
        p=p->next;
    p->next=temp;
   }
  

 }

 return head;
}
void display(node *head)
 {
  node *p=NULL;
  if(head==NULL)
    printf("Empty");
  else
     {
       p=head;
       while(p!=NULL)
       {
         printf("%d->",p->data);
         p=p->next;
       }
     }
  printf("\n");
 }

