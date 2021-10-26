//Intersection Point in Y Shapped Linked Lists 
//GFG ACCEPTED
//Linked List


#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}



int main()
{
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}


//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{
    int ans = -1;
    Node *t1, *t2;
    
    t1 = head1;
    t2 = head2;
    
    int count1 = 0, count2 = 0;
    
    //finding number of nodes in first ll
    while(t1 != NULL)
    {
        count1++;
        t1=t1->next;
    }
    
    //finding number of nodes in second ll
    while(t2 != NULL)
    {
        count2++;
        t2=t2->next;
    }
    
    
    t1 = head1;
    t2 = head2;
    int c = 1;

    /*reaching a point in bigger ll ahead of which there are equal number of nodes in both the ll
    ex:
    1 2 3 5
    4 5 
    common: 3 4 6
     so in bigger one we will traverse till 3 so that

 1 2 3 5 ->3 4 6
     4 5 ->3 4 6
     equal here onwards
    */
    if(count1 > count2)
    {
        while(c <= abs(count1 - count2))
        {
            t1 = t1->next;
            c++;
        }
    }
    else
    {
        while(c <= abs(count1 - count2))
        {
            t2 = t2->next;
            c++;
        }
    }
    while(t1 != NULL && t2 != NULL && t1 != t2)
    {
        t1 = t1->next;
        t2 = t2->next;
    }
    
    if(t1 != NULL)
        ans = t1->data;
    return ans;
}

