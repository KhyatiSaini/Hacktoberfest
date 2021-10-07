#include<bits/stdc++.h>
using namespace std;

class node {
public:
int data;
node* next;
node (int val) {
    data = val;
    next = NULL;
}
};

void insertatTail(node* &head, int val) {
    node* n = new node(val);
    if (head == NULL) {
        head = n;
        return;
    }
    node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = n;
}

void display(node* head) {
    node* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void makecycle(node* &head, int pos) {
    node* temp = head;
    node* startNode;

    int count = 1;
    while (temp->next != NULL) {
        if (count == pos) {
            startNode = temp;
        }
        temp = temp->next;
        count++;
    }

    temp->next = startNode;
}

bool detectCycle(node* &head) {
    node* slow = head;
    node* fast = head;
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }
    return false;
}

void removeCycle(node* &head) {
    node* slow = head;
    node* fast = head;

    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow!=fast);
    fast = head;

    while (slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = NULL;
    
}

int main() {
    node* head = NULL;
    insertatTail(head,1);
    insertatTail(head,2);
    insertatTail(head,3);
    insertatTail(head,4);
    insertatTail(head,5);
    insertatTail(head,6);
    makecycle(head,3);
    cout<<detectCycle(head)<<endl;
    removeCycle(head);
    cout<<detectCycle(head)<<endl;
    display(head);
}
