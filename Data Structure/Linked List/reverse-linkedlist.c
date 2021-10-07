#include <stdio.h>
#include<stdlib.h>

typedef struct node node;
struct node
{
  int data;
  node* next;
};
node* head;
void insert(int number)
{
  node* temp=NULL;
  temp=(node*)malloc(sizeof(node));
  temp->data=number;
  temp->next=NULL;
  if(head==NULL)
  {
    head=temp;
  }
  else
  {
    node* add;
    add=head;
    while(add->next!=0)
    {
      add=add->next;
    }
    add->next=temp;
  }
}
void print()
{
  node* temp=head;
  while(temp!=NULL)
  {
    printf("%d ",temp->data);
    temp=temp->next;
  }
}
void reverse()
{
    node* current,*next,*prev;
    prev=NULL;
    current=head;
    while(current->next!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    current->next=prev;
    head=current;
}
int main(void) {
  int number_of_data;
  printf("Enter the number of data to be inserted:");
  scanf("%d",&number_of_data);
  int i,number;
  for(i=0;i<number_of_data;i++)
  {
    printf("\nEnter the number to be stored in the linked list:");
    scanf("%d",&number);
    insert(number);
    print();

  }
    printf("\nThe list after reversing will be seen as follows:\n");
    reverse();
    print();

}
