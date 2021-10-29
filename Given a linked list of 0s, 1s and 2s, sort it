class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
    
    
    int count0=0;
    int count1=0;
    int count2=0;
    
  for(Node *curr = head;curr!=NULL;curr=curr->next){
      if(curr->data == 0)count0++;
      if(curr->data == 1)count1++;
      if(curr->data == 2)count2++;
  }   
      Node *curr = head;
      while(count0--){
          curr->data = 0;
          curr=curr->next;
      }
        while(count1--){
          curr->data = 1;
          curr=curr->next;
      }
        while(count2--){
          curr->data = 2;
          curr=curr->next;
      }
  
    return head;
    
    
    }
};
