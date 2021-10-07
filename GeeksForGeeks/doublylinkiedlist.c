#include<stdlib.h>
#include<stdio.h>
struct node{
    int data;
    struct node* prev;
    struct node* next;
};
struct node* head;
struct node* getnewNode(int x)
{
    struct node* newNode= (struct node*)malloc(sizeof(struct node));
    newNode->data=x;
    newNode->prev=NULL;
    newNode->next=NULL;
    return newNode;
}
void insertHead(int x)
{
    struct node* temp=getnewNode(x);
    if(head==NULL)
    {
        head=temp;
        return;
    }
    head->prev=temp;
    temp->next=head;
    head=temp;
}
void insertTail(int x)
{
    struct node* ptr=getnewNode(x);
    struct node* temp;
    if(head==NULL)
    {
        head=ptr;
        return;
    }
    temp = head;
    while(temp->next!=NULL)
          {
              temp = temp->next;
          }
    temp->next = ptr;
    ptr ->prev=temp;
    ptr->next = NULL;
}
void printforward()
{
    struct node* temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void printreverse()
{
    struct node* temp=head;
    if(temp==NULL)
        return;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
     while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->prev;
    }
    printf("\n");
}
int main()
{
  head=NULL;
  insertHead(2);
  insertHead(4);
  insertHead(1);
  insertTail(5);
  insertTail(7);
  printforward();//1 4 2 5 7
  printreverse();//7 5 2 4 1
}


