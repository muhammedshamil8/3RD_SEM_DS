#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct graphnode* graphpointer;
struct graphnode
{
int data;
graphpointer next;
};
int n=0,*added;
graphpointer *alist;
void create();
void display();
void bfs(int);
void dfs(int);
void create()
{
int i,j,m,v;
graphpointer temp;
if(n==0)
{

}
else
{

}
printf("\nEnter the number of vertices : ");
scanf("%d",&n);
alist=(graphpointer*)malloc((n+1)*sizeof(*alist));
added=(int*)malloc((n+1)*sizeof(int));

printf("\nGraph already created!!!");
return;
for(i=1;i<=n;i++)
{
: ",i);

printf("\nEnter the number of adjacent vertices for Vertex %d
scanf("%d",&m);
if(m==0)
{
alist[i]=NULL;
continue;
}
printf("\nEnter the adjacent vertices :\n");
scanf("%d",&v);
alist[i]=(graphpointer)malloc(sizeof(**alist));
alist[i]->data=v;
temp=alist[i];
for(j=1;j<m;j++)
{
scanf("%d",&v);
temp->next=(graphpointer)malloc(sizeof(**alist));
temp=temp->next;
temp->data=v;
}

temp->next=NULL;
}
}
void display()
{
int i;
graphpointer temp;
if(n==0)
{
printf("\nGraph is not created!!!");
return;
}
printf("\nAdjacency list:\n");
for(i=1;i<=n;i++)
{
printf("\nVertex %d : ",i);
for(temp=alist[i];temp!=NULL;temp=temp->next)
printf("\t%d",temp->data);
}
}
void bfs(int v)
{
int q[100],front=0,rear=0,u;
graphpointer temp;
if(n==0)
{
printf("\nGraph is not created!!!");
return;
}
if(v<1 || v>n)
{
printf("\nInvalid vertex!!!");
return;
}
for(u=1;u<=n;u++) added[u]=0;
printf("\nBreadth first search traversal from vertex %d :\n\n",v);
q[rear++]=v;
added[v]=1;
while(front!=rear)
{
u=q[front++];
printf("%d\t",u);
for(temp=alist[u];temp!=NULL;temp=temp->next)
if(!added[temp->data])
{
q[rear++]=temp->data;
added[temp->data]=1;
}
}
}
void dfs(int v)
{
int st[100],top=0,u;
graphpointer temp;
if(n==0)
{
printf("\nGraph is not created!!!");
return;
}

if(v<1 || v>n)
{
printf("\nInvalid vertex!!!");
return;
}
for(u=1;u<=n;u++) added[u]=0;
printf("\nDepth first search traversal from vertex %d :\n\n",v);
st[top++]=v;
added[v]=1;
while(top!=0)
{
u=st[--top];
printf("%d\t",u);
for(temp=alist[u];temp!=NULL;temp=temp->next)
if(!added[temp->data])
{
st[top++]=temp->data;
added[temp->data]=1;
}
}
}
void main()
{
int ch,v;
do
{
clrscr();
printf("\nGraph operations\n");
printf("\n\t1. Create");
printf("\n\t2. Display");
printf("\n\t3. Breadth first search");
printf("\n\t4. Depth first search");
printf("\n\t5. Exit");
printf("\n\nEnter your choice -> ");
scanf("%d",&ch);
switch(ch)
{
case 1:
create();
break;
case 2:
display();
break;
case 3:
printf("\nEnter a vertex : ");
scanf("%d",&v);
bfs(v);
break;
case 4:
printf("\nEnter a vertex : ");
scanf("%d",&v);
dfs(v);
break;
default:continue;
}
getch();
}while(ch!=5);}