#include<stdio.h>
#include<string.h>
#include<ctype.h>
void push(char);
char pop();
int precedence(char);
int top=-1,j=0,i;
char a[20],p[20],s[20];
void main()
{    
    printf("Enter the expression=");
    scanf("%s",a);
    printf("The entered expression in infix form =%s\n",a);
    int n=strlen(a);
    for(i=0;i<n;i++)
    {
        if(isalnum(a[i]))
        {
          p[j]=a[i];
          j++;
        }
        else if(a[i]=='(')
        {
          push(a[i]);
        }
        else if(a[i]==')')
        {
           while(s[top]!='(')
           {
             p[j]=pop();
             j++;
           }
           pop();
        }
        else
        {
          while((top!=-1) &&(precedence(a[i])<=precedence(s[top])))
          {
             p[j]=pop();
             j++;
          }
          push(a[i]);
        }
    }
    while(top!=-1)
    {
       p[j]=pop();
       j++;
    }
    p[j]='\0';
    printf("The entered expression in postfix form=%s\n",p);
 }
 void push(char item)
 {
      top++;
      s[top]=item;
 }
 char pop()
 {
  char item;
  item=s[top];
  top--;
  return item;
 }
 int precedence(char x)
 {
     switch(x)
     {
         case '^':return 3;
         case '*':
         case '/':return 2;
         case '+':
         case '-':return 1;
         default :return 0;
     }
       
  }
