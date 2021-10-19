#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};


struct node *ptr,*start,*newptr,*save,*rear;
typedef struct node node;

node* createNewNode(int data){
    ptr=(node*) malloc(sizeof(node));
    ptr->data=data;
    ptr->next=NULL;
    return ptr;
}

void insertBeg(node *np){
    if(start==NULL){
        start=np;
        rear=np;
    }
    else{
        np->next=start;
        start=np;
    }
}

void insertPos(node *np,int pos){
    int flag=1;
    save=start;
    while(flag<pos){
        save=save->next;
        flag++;
    }

    np->next=save->next;
    save->next=np;
}

void insertEnd(node *np){
    if(rear==NULL){
        start=np;
        rear=np;
    }
    else{
        rear->next=np;
        rear=np;
    }
}

void displayNode(){
    save=start;
    while(save!=rear){
        printf("%d-->",save->data);
        save=save->next;
    }
    printf("%d",rear->data);
    printf("\n");
}

void delBeg(){
    if(start!=NULL) {
        printf("\nBefore Deletion the linked list is \n");
        displayNode();
        save = start;
        start = start->next;
        free(save);
        printf("\nNode deleted from beginning");
        printf("\nAfter Deletion the linked list is \n");
        displayNode();
    }
    else{
        printf("\nUNDERFLOW!!\n");
        exit(0);
    }
}

void delPosition(int pos){
    int flag=1;node *temp;
    save=start;
    while(flag<pos){
        save=save->next;
        flag++;
    }
    temp=save->next;
    save->next=temp->next;
    free(temp);
    printf("\nNode deleted from position %d",pos);
    printf("\nAfter Deletion the linked list is \n");
    displayNode();
}

void delEnd(){
    node *temp;
    if(rear!=NULL){
        printf("\nBefore Deletion the linked list is \n");
        displayNode();
        save=rear;
        temp=start;
        while(temp->next!=rear){
            temp=temp->next;
        }
        rear=temp;
        free(save);
        printf("\nAfter Deletion the linked list is \n");
        displayNode();
    }
    else{
        printf("\nUNDERFLOW!!\n");
        exit(0);
    }
}

int main() {
    start=rear=NULL;
    int choice;char ch='y';

    printf("Program for performing operations on a Singly Linked List\n");

    int data,pos;


    while(ch=='y'||ch=='Y') {
        printf("1.Insertion\n");
        printf("2.Deletion\n");
        printf("3.Display\n");
        printf("4.Exit\n");

        printf("\n Enter Your Choice(1-3) ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("1.Insert at the beginning\n");
                printf("2.Insert at a specific position\n");
                printf("3.Insert at the end\n");
                printf("\n Enter Your Choice(1-3) ");


                scanf("%d", &choice);
                switch (choice){
                    case 1:
                        printf("\n Enter data ");
                        scanf("%d",&data);
                        newptr=createNewNode(data);
                        if(newptr==NULL){
                            printf("\nOVERFLOW!");
                            exit(0);
                        }
                        else{
                            insertBeg(newptr);
                        }

                        break;

                    case 2:
                        printf("\n Enter data ");
                        scanf("%d",&data);
                        newptr=createNewNode(data);
                        if(newptr==NULL) {
                            printf("\nOVERFLOW!");
                            exit(0);
                        }

                        printf("\n Enter position ");
                        scanf("%d",&pos);

                        insertPos(newptr,pos);
                        break;

                    case 3:
                        printf("\n Enter data ");
                        scanf("%d",&data);
                        newptr=createNewNode(data);
                        if(newptr==NULL) {
                            printf("\nOVERFLOW!");
                            exit(0);
                        }

                        else{
                            insertEnd(newptr);
                        }


                        break;

                    default:
                        printf("\nWRONG CHOICE!!");
                }

                break;


            case 2:
                printf("1.Delete from beginning\n");
                printf("2.Delete from a specific position\n");
                printf("3.Delete from the end\n");
                printf("\n Enter Your Choice(1-3) ");

                scanf("%d", &choice);
                switch (choice) {
                    case 1:
                        delBeg();
                        break;
                    case 2:
                        printf("\nBefore Deletion the linked list is \n");
                        displayNode();
                        printf("\n Enter position for deletion ");
                        scanf("%d",&pos);
                        delPosition(pos);
                        break;

                    case 3:
                        delEnd();
                        break;

                    default:
                        printf("\nWRONG CHOICE!!");
                }
                break;

            case 3:
                displayNode();
                break;

            case 4:
                exit(1);

            default:
                printf("\nWRONG CHOICE!!");
        }


    }
    return 0;
}
