#include <stdio.h>
void enqueue();
void dequeue();
void display();
int A[50],front=-1,rear=-1,size,i;
int main()
{    int choice=0;
     printf("Enter the size of queue: ");
     scanf("%d",&size);   
     while(choice!=4){
     	printf("Enter Operation to perform on Queue: 1. Enqueue 2. Dequeue 3. Display 4. Exit \n");
     	scanf("%d",&choice);
     	switch(choice){
     		case 1: enqueue();
     			break;
		case 2: dequeue();
			break;
		case 3: display();
			break;
		case 4: printf("Exited from program");
		        break;
		}
      }
 }
 void enqueue(){
  if(rear==size-1){
   	printf("Overflow Error");
   }
   else if(front==-1&&rear==-1){ 
   	rear++;
   	front++;
   	printf("Enter element to be inserted:");
   	scanf("%d",&A[rear]);
   	}
   else{
   	rear++;
   	printf("Enter element to be inserted:");
   	scanf("%d",&A[rear]);
   	}
   }
  void dequeue(){
  if (front==-1&&rear==-1){
        printf("Underflow error");
  } else {
  printf("Deleted element is:%d\n",A[front]);
  	if(front==rear){
  	front=-1;
  	rear=-1;
        }else front++;
      }
   }
   void display(){
   if (front==-1&&rear==-1){
        printf("Queue Empty \n");
  }else{
   printf("The Queue is:");
   for(i=front;i<=rear;i++){
      printf("%d\t",A[i]);
      }
   printf("\n");
  }
  }
