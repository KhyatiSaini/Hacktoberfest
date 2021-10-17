#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

class node{
public:
int data;
node* next;
node(int val){
        data=val;
        next=NULL;
}
}*head;

void sort(){
node* temp=head;

    while(temp->next!=NULL){
    node *index=head;

        while (index->next!=NULL)
        {
                if(index->data > index->next->data){
                    
                    swap(index->data,index->next->data);//5 4 3 2 1 0

                }
                index=index->next;

        }
    temp=temp->next;

    }

}

void display(){

    node* temp=head;

    while(temp!=NULL){
cout<<temp->data<<" ";
temp=temp->next;

    }
}

int main(){
ios_base::sync_with_stdio(false);
head=new node(5);
head->next=new node(4);
head->next->next=new node(3);
head->next->next->next=new node(2);
head->next->next->next->next=new node(1);
head->next->next->next->next->next=new node(0);

sort();
display();

return 0;
}
