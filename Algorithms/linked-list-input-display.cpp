#include <stdio.h>
#include <stdlib.h>
struct node                                       //creating a structure
{
    int data;
    struct node *next;
};
struct node *temp, *newNode, *head;                //creating variables of struct node data type 

//function for creating nodes
void createNode(struct node *head, int size)
{
    printf("enter the elements of the node\n");
    scanf("%d", &head->data);                     //inputting the data inside head
    head->next = NULL;                            //assigning NULL inside next of head
    temp = head;                                  
    for (int i = 1; i < size; i++)                //loop for creating nodes 
    {
        newNode = (struct node *)malloc(sizeof(struct node *));     //dynamic memory allocation using malloc
        scanf("%d", &newNode->data);
        newNode->next = NULL;                                       //assigning NULL to the next of newnode
        temp->next = newNode;
        temp = temp->next;
    }
}
void displayNode(struct node *head, int size)                        //function for displaying the nodes created
{
    temp = head;                          
    for (int i = 0; i < size; i++)                                   //loop for displaying the data of different nodes
    {
        printf("%d -> ", temp->data);                                //printing the data of the respective nodes 
        temp = temp->next;
    }
    printf("NULL\n");                                                 //printing NULL for the last node
}

int main()                                                             //main function
{
    int option;
    int size;
    int continuation = 1;
    head = (struct node *)malloc(sizeof(struct node *));              //dynamic memory allocation of head
    while (continuation != 0)
    {
        printf("choose from the below menu \n1. creation of node\n2. display of node \n");
        scanf("%d", &option);                                         //inputting the option
        switch (option)
        {
        case 1:
            printf("enter the size of the node\n");                   
            scanf("%d", &size);
            createNode(head, size);                                    //function calling
            break;
        case 2:
            displayNode(head, size);                                    //function calling
            break;
        }
        printf("press 0 to exit and 1 to continue\n");                  
        scanf("%d", &continuation);                                      //inputting whether user wants to continue or not
    }
    return 0;
}


