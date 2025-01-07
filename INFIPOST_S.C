#include<stdio.h>
#include<conio.h>
int rank(char);
void main()
{
char stack[50],infix[50],postfix[50],c;
int i,j,top=-1;
clrscr();
printf("\nEnter an expression in the infix form : ");
gets(infix);
for(i=0,j=0;infix[i]!='\0';i++)
{
c=infix[i];
if(c>='0' && c<='9' || c>='a' && c<='z' || c>='A' && c<='Z')
postfix[j++]=c;
else if(rank(c)!=0)
{
if(top==-1 || stack[top]=='(')
{
stack[++top]=c;
continue;
}
while(top!=-1 && rank(c)>=rank(stack[top]))
{
if(stack[top]=='(')
{
top--;
break;
}
postfix[j++]=stack[top--];
}
if(c!=')') stack[++top]=c;
}
}
while(top!=-1) postfix[j++]=stack[top--];
postfix[j]='\0';
printf("\nExpression in the postfix form is %s",postfix);
getch();
}
int rank(char op)
{
int r;
switch(op)
{
case '(':r=1;
break;
case '*':
case '/':r=2;
break;
case '+':
case '-':r=3;
break;
case ')':r=4;
break;
default: r=0;
}
return r;
}