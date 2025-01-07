#include<stdio.h>
#include<alloc.h>
#include<conio.h>
typedef struct listnode* listpointer;
struct listnode
{
int data;
listpointer next;
};
listpointer fnode=NULL,p;
void create();
void list();
void search(int);
void main()
{
int choice;
int n,pos;
do
{
clrscr();
printf("\n\tLINKED LIST OPERATIONS\n");
printf("\n\t\t1. CREATE");
printf("\n\t\t2. LIST");
printf("\n\t\t3. SEARCH");
printf("\n\t\t4. EXIT");
printf("\n\n\tEnter your choice(1-4) : ");
scanf("%d",&choice);
switch(choice)
{
case 1:create();
break;
case 2:list();
break;
case 3:printf("\nEnter an element : ");
scanf("%d",&n);
search(n);
break;
default:continue;
}
getch();
}while(choice!=4);
}

void create()
{
int i,n;
if(fnode!=NULL)
{
printf("\nList already created...");
return;
}
printf("\nEnter the number of elements : ");
scanf("%d",&n);
if(n<1) return;
printf("\nEnter %d elements into list :\n",n);
fnode=(listpointer)malloc(sizeof(*fnode));
scanf("%d",&fnode->data);
fnode->next=NULL;
p=fnode;
for(i=0;i<n-1;i++)
{
p->next=(listpointer)malloc(sizeof(*p));
p=p->next;
scanf("%d",&p->data);
}
p->next=NULL;
printf("\nList created and %d elements inserted into the
list",listSize);
}
void list()
{
if(fnode==NULL)
{
printf("\nList is empty...");
return;
}
printf("\nElements in the list :\n\n");
for(p=fnode;p!=NULL;p=p->next)
printf(" %d",p->data);
}
void search(int x)
{
int i;
if(fnode==NULL)
{
printf("\nList is empty...");
return;
}
for(i=1,p=fnode;p!=NULL && p->data!=x;i++,p=p->next)
;
if(p==NULL)
printf("\nElement not found...");
else printf("\nElement is found at location %d",i);
}