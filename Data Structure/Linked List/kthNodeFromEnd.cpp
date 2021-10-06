//Question 1: Write an algorithm to find kth node from the end of a linked list.
//        1->2->3->4->5->6->7->nullptr
#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	struct Node* next;
	Node(int x){
		data = x;
		next=NULL;
	}
};
int getKthNode(Node* head,int k){
	Node* main = head;
	Node* ref = head;
	
	int count=0;
	while(count<k){
		if(ref==NULL){
			cout<<"Total nodes are less than k."<<"\n";
			break;
		}
		count++;
		ref=ref->next;
	}
	
	if(ref==NULL){
		head=head->next;
		if(head!=NULL){
			return main->data;
		}
	}
	else{
		while(ref!=NULL){
			main=main->next;
			ref=ref->next;
		}
		return main->data;
	}
}
int main()
{
	struct Node* tail=NULL;
	struct Node* head=NULL;

	int n;
	cout<<"code to find kth node from the end of a linked list."<<"\n";
	cout<<"enter the no. of nodes(n): ";
	cin>>n;
	
	cout<<"enter the first data: ";
	int f;
	cin>>f;
	head=new Node(f);
	tail=head;
	
	for(int i=1;i<n;i++){
		int x;
		cin>>x;
		tail->next=new Node(x);
		tail=tail->next;
	}
	
	cout<<"enter the k value: ";
	int k;
	cin>>k;
	
	int ans = getKthNode(head,k);
	cout<<ans<<" is the node."; 
}
