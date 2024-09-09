#include<stdio.h>
void enqueue();
void dequeue();
void display();
int front=-1,rear=-1,m,item;
int a[100];
void main()
{
  int n;
  printf("enter size of queue:");
  scanf("%d",&m);
  printf("enter 1 for enqueue \t");
  printf("enter 2 for dequeue \t");
  printf("enter 3 for display \t");
  printf("enter 4 to stop\n");
  while(n!=4)
  {
    printf("choice:\n");
    scanf("%d",&n);
    {
     switch(n)
     {
      case 1:enqueue();
              break;
      case 2:dequeue();
              break;
       case 3:display();
              break;
        case 4:printf("exited from the code");
                break;
      }
    }
  }
 } 
 void enqueue()
 {
   if(front==(rear+1)%m)
   {
     printf("overflow\n");
   }
   else if((front==-1) &&(rear==-1))
   {
     front++;
     rear++;
      printf("enter value:");
      scanf("%d",&a[rear]);
    }
    else
    {
      rear=(rear+1)%m;
      printf("enter value:");
      scanf("%d",&a[rear]);
     }
   }
   void dequeue()
   {
     if((front==-1) &&(rear==-1))
     {
       printf("underflow\n");
      }
      else if(front==rear)
      {
        item==a[front];
        front=-1;
        rear=-1;
        printf("deleted value is %d\n",item);
      }
      else
      {
        item=a[front];
        front=(front+1)%m;
        printf("deleted value is %d\n",item);
       }
    }
   void display()
   {
      if(front==-1 && rear==-1)
     {
       printf("queue is empty\n");
     }
     else
     {
     for(int i=front;i<rear;i++)
     {
      printf("%d\n",a[i]);
     }
    }
   }


