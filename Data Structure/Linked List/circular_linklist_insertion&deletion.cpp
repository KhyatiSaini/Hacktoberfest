#include<iostream>
 using namespace std;

 struct Node
 {
 	int data;
 	Node *next;
 }*tail;
 
class Circular_LinkedList
 {
 	public:
 		void Insert_at_Front(int n);
 		void Insert_at_End(int n);
 		void Delete_at_Front();
 		void Display();
 	};
 
 int main()
 {
 	int choice;
	 Circular_LinkedList object;
 	tail=NULL;
  while(1)
  {	
  	cout<<"\n\t Press 1 for Insert at Front\n";
  	cout<<"\t Press 2 for Insert at End\n";
  	cout<<"\t Press 3 for Delete at Front\n";
  	cout<<"\t Press 4 for Display Nodes\n";
  	cout<<"\t Press 5 to Exit\n";
  	cout<<" Enter you Choice: \n";
  	cin>>choice;
  	 switch(choice)
  	 {
  	 	case 1:
  	 		object.Insert_at_Front(3);//Passing values
  	 		object.Insert_at_Front(2);
  	 		object.Insert_at_Front(1);
  	 		break;
  	 	case 2:
  	 		object.Insert_at_End(4);
  	 		object.Insert_at_End(5);
  	 		break;
  	 	case 3:
  	 		object.Delete_at_Front();
  	 		break;
  	 	case 4:
  	 		object.Display();
  	 		break;
  	 	case 5:
  	 		exit(0);
  	 	default:
  	 		cout<<"Wrong Choice\n";
	   }
  }
  return 0;
 }
 
 void Circular_LinkedList::Insert_at_Front(int n)
 {
 	Node *temp;
 	temp=new Node;
 	temp->data=n;
 	temp->next=NULL;
  if(tail==NULL)
  {
  	tail=temp;
  	tail->next=tail;
  }
  else
   {
   	temp->next=tail->next;
   	tail->next=temp;
   }
 }
 
 void Circular_LinkedList::Insert_at_End(int n)
  {
  	Node *temp;
 	temp=new Node;
 	temp->data=n;
 	temp->next=NULL;
  if(tail==NULL)
  {
  	temp->next=temp;
  	tail=temp;
  }
  else
   {
   	temp->next=tail->next;
   	tail->next=temp;
   	tail=temp;
   }
  }
  
 void Circular_LinkedList::Display()
  {
  	Node *front;
  	front=tail->next;
  	 if(tail==NULL)
  	  {
  	  	cout<<"Empty List: \n";
  	  }
  	cout<<"\tNodes are:\t";
  	while(front!=tail)
  	{
  		cout<<front->data<<" --> ";
  		front=front->next;
	  }
	  if(front==tail)
	  {
	  	cout<<front->data;
	  }
	  delete front;
	  cout<<endl;
  }
  
  void Circular_LinkedList::Delete_at_Front()
  {
  	Node *temp=new Node;
  	temp=tail->next;
  	if(tail==NULL)
  	 {
	   cout<<"Empty List\n";
	   return;
	 }
  	if(temp==tail)
  	{
  		delete temp;

	  }
	  else
	  {
	  	tail->next=temp->next;
	  	delete temp;
	  }
  }
