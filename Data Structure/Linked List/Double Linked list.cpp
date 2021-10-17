#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

class node{

public:
    int data;
    node* prev;
    node* next;

        node(int val){
            data=val;
            prev=NULL;
            next=NULL;
        }

};

node* head=NULL;
node* last;
void insertAtTail(int val){

    node* n=new node(val);
    node* temp=head;

    if(head==NULL){

        head=n; 
        last=n;
        return;
    }
    while (temp->next!=NULL)
    {
     temp=temp->next;
    }

    n->prev=temp;
    temp->next=n;
    last=n;   

}

void deletion(int key)
{
node* temp=head;
node* todelete;

while (temp!=NULL)
{
    if(temp->data==key){

        todelete=temp;
        
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;

        delete todelete;
        return;
    }
    temp=temp->next;
}
}

void displayRev(){

node* temp=last;

while (last!=NULL)
{
cout<<last->data<<" ";
    last=last->prev;

}


}

void display( ){
    node* temp=head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
    temp=temp->next;
    }
}


int main(){
ios_base::sync_with_stdio(false);
int size,x;
cout<<"Size : ";
cin>>size;
cout<<"Enter Elements : "<<endl;

for (int i = 0; i < size; i++)
{
    cin>>x;
    insertAtTail(x);

}

cout<<"Your Double Linked list : "<<endl;
display();
cout<<"\n Reverse : "<<endl;
displayRev();
cout<<"\nEnter Key to delete : ";
cin>>x;
deletion(x);
display(); 

return 0;
}
