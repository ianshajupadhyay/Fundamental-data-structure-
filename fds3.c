#include<stdio.h>
int length(char *p);
void copy(char *p,char *s);
void compare(char *p,char *q);
void concat(char *p,char *q,char *s);
void palindrome(char *p,int);
int length(char *p)
{
    int l=0;
    while(*p!='\0')
    {
        p++;
        l++;
    }
    return(l);
}
void copy(char *p,char *s)
{
    int a=0;
    while(*p!='\0')
    {
        s[a++]=*p++;
    }
    s[a]='\0';
}
void compare(char *p,char *q)
{
    int a=0,l,flg=0,c=0;
    while(*(p+c)==*(q+c))
    {
        if(*(p+c)=='\0'||*(q+c)=='\0')
            break;
        c++;
    }
    if(*(p+c)=='\0'&&*(q+c)=='\0')
        printf("\nThe strings are equal");
    else
        printf("\nThe strings are not equal");
}
void concat(char *p,char *q,char *s)
{
    int a=0;
    while(*p!='\0')
    {
        s[a++]=*p++;
    }
    while(*q!='\0')
    {
        s[a++]=*q++;
    }
    s[a]='\0';
    printf("The concatenated string is :");
}
void palindrome(char *p,int l)
{
    int i,fld=0;
    for(i=0;i<=l/2;i++)
    {
        if(*(p+i)!=*(p+l-1-i))
         { fld=1;
         	break; }
    }
    if(fld==0) printf("\nString is Palindrome");
    else printf("\nNot palindrome");
}
int main()
{
    int l,a,ch;
    char *p,*q,*s,*z;
    char word1[20],word2[20],word3[40],word4[20];
    printf("\nEnter the 1st string :");
    scanf("%s",word1);
    p=word1;
    printf("Enter the 2nd string :");
    scanf("%s",word2);
    q=word2;
    s=word3;
    z=word4;
    do
    {
        int c,i,j;
        printf("\n1:length of string\n2:copy string\n3:compare two strings\n4:concatenation\n5:palindrome\n6:exit\n");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            i=length(p);
            printf("Length of 1st string is :%d\n",i);
            j=length(q);
            printf("Length of 2nd string is :%d\n",j);
            break;
        case 2:
            copy(p,s);
            puts("copied string is");
            puts(word3);
            copy(q,z);
            puts("copied string is");
            puts(word4);
            break;
        case 3:
            compare(p,q);
            break;
        case 4:
            concat(p,q,s);
            puts(word3);
            break;
        case 5:
            palindrome(p,i);
            palindrome(q,j);
            break;
        case 6:
            return 0;

        }
        printf("\nDo you want to continue\n");
 	scanf("%d",&ch);
    }while(ch==1);
}
