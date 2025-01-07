#include<stdio.h>
#include<conio.h>
void sort(int*,int);
void main()
{
int a[10],n,i;
clrscr();
printf("Enter the size : ");
scanf("%d",&n);
printf("\nEnter %d elements into the array :\n",n);
for(i=1;i<=n;i++)
scanf("%d",&a[i]);
printf("\nArray before sorting :");
for(i=1;i<=n;i++)
printf(" %d",a[i]);
sort(a,n);
printf("\n\nArray after sorting :");
for(i=1;i<=n;i++)
printf(" %d",a[i]);
getch();
}
void sort(int a[],int n)
{
int i,j,k,temp;
for(i=n/2;i>=1;i--)
{
j=i;
k=2*j;
if(k+1<=n && a[k+1]>a[k]) k++;
while(a[j]<a[k])
{
temp=a[j];
a[j]=a[k];
a[k]=temp;
if(2*k>n) break;
j=k;
k*=2;
if(k+1<=n && a[k+1]>a[k]) k++;
}
}
i=n;
while(1)
{
temp=a[1];
a[1]=a[i];
a[i--]=temp;
if(i<2) break;
j=1;
k=2;
if(i>2 && a[3]>a[2]) k++;
while(a[j]<a[k])
{
temp=a[j];

a[j]=a[k];
a[k]=temp;
if(2*k>i) break;
j=k;
k*=2;
if(k+1<=i && a[k+1]>a[k]) k++;
}
}
}