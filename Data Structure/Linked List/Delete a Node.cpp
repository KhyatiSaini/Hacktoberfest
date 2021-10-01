#include <iostream>

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

using namespace std;

Node *deleteNode(Node *head, int pos)
{
    //Write your code here
    Node* temp= head;
    if(head==NULL){
        return NULL;
    }
    
    if(pos==0){
        
        head= head->next;
        delete temp;
        return head;
        }
    int num=1;
    while(temp!=NULL){
        
        if(num==pos && temp->next!=NULL ){
            Node* a= temp->next;
            Node* b= temp->next->next;
            temp -> next = b;
            delete a;
           
        }
        
        num++;
       temp= temp->next;
    }
    
    return head;
    
}

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		int pos;
		cin >> pos;
		head = deleteNode(head, pos);
		print(head);
	}

	return 0;
}