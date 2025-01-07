#include<stdio.h>
#include<conio.h>
typedef struct {int coef,exp;} polynomial;
void read(polynomial*,int);
void print(polynomial*,int);
void main()
{
polynomial p1[10],p2[10],p3[20];
int m,n,i,j,k;
clrscr();
printf("Number of terms in first polynomial : ");
scanf("%d",&m);
printf("\nEnter %d terms for first polynomial:\n",m);
read(p1,m);
printf("\nNumber of terms in second polynomial : ");
scanf("%d",&n);
printf("\nEnter %d terms for second polynomial:\n",n);
read(p2,n);
i=j=k=0;
while(i<m && j<n)
{
if(p1[i].exp>p2[j].exp)
p3[k++]=p1[i++];
else if(p1[i].exp<p2[j].exp)
p3[k++]=p2[j++];
else if(p1[i].coef+p2[j].coef!=0)
{
p3[k]=p1[i++];
p3[k++].coef+=p2[j++].coef;
}
else i++,j++;
}
while(i<m) p3[k++]=p1[i++];
while(j<n) p3[k++]=p2[j++];
printf("\nFirst polynomial : ");
print(p1,m);
printf("\nSecond polynomial : ");
print(p2,n);
printf("\nPolynomial sum : ");
print(p3,k);
getch();
}
void read(polynomial p[],int n)
{
int i;
for(i=0;i<n;i++)
{
printf("\nCoefficient : ");
scanf("%d",&p[i].coef);
printf("Exponent : ");
scanf("%d",&p[i].exp);
}
}

void print(polynomial p[],int n)
{
int i;
if(p[0].exp==0) printf("%d",p[0].coef);
else if(p[0].exp==1) printf("%dx",p[0].coef);
else printf("%dx^%d",p[0].coef,p[0].exp);
for(i=1;i<n;i++)
{
if(p[i].coef>0) printf("+");
if(p[i].exp==0) printf("%d",p[i].coef);
else if(p[i].exp==1) printf("%dx",p[i].coef);
else printf("%dx^%d",p[i].coef,p[i].exp);
}
}