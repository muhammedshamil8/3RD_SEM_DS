#include<stdio.h>
#include<conio.h>
void main()
{
struct
{
int r,c,v;
}s[10];
int rows,cols,n=0,i,j,x;
clrscr();
printf("Enter the dimension : ");
scanf("%d%d",&rows,&cols);
printf("\nEnter %d elements into the sparse matrix :\n",rows*cols);
for(i=0;i<rows;i++)
for(j=0;j<cols;j++)
{
scanf("%d",&x);
if(x!=0)
{
s[n].r=i;
s[n].c=j;
s[n].v=x;
n++;
}
}
printf("\nDetails of non-zero elements in the sparse matrix:");
printf("\nRow\tColumn\tValue\n");
for(i=0;i<n;i++)
printf("\n%d\t%d\t%d",s[i].r,s[i].c,s[i].v);
getch();
}