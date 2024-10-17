#include<stdio.h>
void main(){
   int limit,i,pos;
   printf("enter the total number of nodes\n");
   scanf("%d",&limit);
   int a[limit];
   printf("enter the nodes data\n");
   for(i=1;i<=limit;i++){
     scanf("%d",&a[i]);
   }
   printf("enter the position you want to check\n");
   scanf("%d",&pos);
   if((pos/2)!=0){
     printf("parent of %d is:%d\n",a[pos],a[pos/2]);
   }
   else{
     printf("no parent\n");
   }
   if(2*pos>limit){
      printf("no left child\n");
   }
   else{
     printf("Left child of %d is :%d\n",a[pos],a[2*pos]);
   }
   if((2*pos)+1>limit){
     printf("no right child\n");
     }
   else{
   printf("Right child of %d is:%d\n",a[pos],a[(2*pos)+1]);
   }
   }

   
   
   
   
