# include<stdio.h>
# include<stdlib.h>
struct node
    {
        int data;
        struct node*link;
    };
struct node *current,*start= NULL;
void createnode()
{
    struct node*newnode=(struct node *) malloc(sizeof(struct node));
    printf("enter the value\n");
    scanf("%d",&newnode->data);
    newnode->link=NULL;
    if(start==NULL)
    {
        start=newnode;
        current=newnode;
    }
    else
    {
        current->link=newnode;
        current=newnode;
    }
    printf("node successfully created\n");
}
void display()
{
    if(start==NULL)
    {
        printf("list is empty\n");
    }
    else
    {
        printf("the linked list is\n");
        struct node*temp=start;
        while(temp!=NULL)
        {
            printf("%d--->\n",temp->data);
            temp=temp->link;
        }
        printf("NULL");

    }
}
void insertionnodefront()
{
   struct node*ptr=(struct node*) malloc(sizeof(struct node));
   printf("enter the value\n");
   scanf("%d",&ptr->data);
   ptr->link=start;
   start=ptr;
   printf("node inserted at front successfully\n");

}
void insertionnodeend()
{
   struct node*ptr1=(struct node*) malloc(sizeof(struct node));
   printf("enter the value\n");
   scanf("%d",&ptr1->data);
   ptr1->link=NULL;
   struct node*temp=start;
   while(temp->link!=NULL)
   {
       temp=temp->link;
   }
   temp->link=ptr1;
   printf("node inserted at end successfully\n");

}
void insertionnodeany()
{
   struct node*ptr2=(struct node*) malloc(sizeof(struct node));
   int pos,i=1;
   printf("enter the value\n");
   scanf("%d",&ptr2->data);
   struct node*temp=start;
   printf("enter the position to be inserted\n");
   scanf("%d",&pos);
   pos--;
   while(i<pos)
   {
       temp=temp->link;
       i++;
   }
   ptr2->link=temp->link;
   temp->link=ptr2;
   printf("node inserted at any position successfully done\n");
}
void deletionnodefront()
{
    if (start==NULL)
    {
        printf("link list empty\n");
    }
    else if (start->link==NULL)
    {
        struct node*temp=start;
        start=NULL;
        free(temp);
    }
    else
    {
        struct node*temp=start;
        start=temp->link;
        free(temp);
    }
    printf("node successfully deleted from front\n");
}
void deletionnodeend()
{
    if (start==NULL)
    {
        printf("link list empty\n");
    }
    else if (start->link==NULL)
    {
        struct node*temp=start;
        start=NULL;
        free(temp);
    }
    else
    {
         struct node*temp1=start;
         struct node*temp2=start;
         while(temp1->link!=NULL)
         {
             temp2=temp1;
             temp1=temp1->link;
         }
         temp2->link=NULL;
         free(temp1);
    }
    printf("node successfully deleted from end\n");
}
void deletionnodeany()
{
    if (start==NULL)
    {
        printf("link list empty\n");
    }
    else if (start->link==NULL)
    {
        struct node*temp=start;
        start=NULL;
        free(temp);
    }
    else
    {
        int pos1,i=1;
        struct node*temp1=start;
        struct node*temp2=start;
        printf("enter the node position to delete\n");
        scanf("%d",&pos1);
        pos1--;
        while(i<pos1)
        {
            temp1=temp1->link;
            i++;
        }
        temp2=temp1->link;
        temp1->link=temp2->link;
        free(temp2);
    }
    printf("node successfully deleted from specified position\n");

}
void main()
{
    int choice,ch=0;
    while(ch==0)
    {
        printf("\nlinked list menu:\n");
        printf("1.create node\n");
        printf("2.display list\n");
        printf("3.insertion node at front\n");
        printf("4.insertion node at end\n");
        printf("5.insertion node at any position\n");
        printf("6.deleting node from front\n");
        printf("7.deleting node from end\n");
        printf("8.deleting node from any position\n");
        printf("9.exit\n");
        printf("enter ur choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            createnode();
            break;
        case 2:
            display();
            break;
        case 3:
            insertionnodefront();
            break;
        case 4:
            insertionnodeend();
            break;
        case 5:
            insertionnodeany();
            break;
        case 6:
            deletionnodefront();
            break;
        case 7:
            deletionnodeend();
            break;
        case 8:
            deletionnodeany();
            break;
        case 9:
            printf("exiting prog..");
            ch=1;
        default:
            printf("invalid choice...\n");
        }
    }
}
