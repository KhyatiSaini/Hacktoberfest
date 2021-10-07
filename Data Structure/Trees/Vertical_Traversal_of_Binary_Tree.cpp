#include <bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}


Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    

    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        

    Node* root = newNode(stoi(ip[0]));
          
    queue<Node*> queue;
    queue.push(root);
        
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        Node* currNode = queue.front();
        queue.pop();
            
        string currVal = ip[i];
            
        if(currVal != "N") {
                
            currNode->left = newNode(stoi(currVal));
                
            queue.push(currNode->left);
        }
            

        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            

        if(currVal != "N") {
                

            currNode->right = newNode(stoi(currVal));
                

            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


void printInorder(Node* root)
{
    if(!root)
        return;
        
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

class Solution
{
    public:
    map<Node*,int> dist;
    
    void travel(Node* root,int n)
    {
        if(root==NULL)
        {
            return;
        }
        if(root)
        {
            dist[root]=n;
        }
        if(root->left)
        {
            travel(root->left,n-1);
        }
        if(root->right)
        {
            travel(root->right,n+1);
        }
        return;
    }
    
    
    vector<int> verticalOrder(Node *root)
    {
        if(root==NULL)
        {
            return {};
        }
        vector<int> v;
        travel(root,0);
        map<int,vector<int>> ans;
        queue<Node*> q;
        q.push(root);
        ans[0]={root->data};
        while(!q.empty())
        {
            Node* curr=q.front();
            q.pop();
            if(curr->left)
            {
                int k=dist[curr->left];
                ans[k].push_back(curr->left->data);
                q.push(curr->left);
            }
            if(curr->right)
            {
                int k=dist[curr->right];
                ans[k].push_back(curr->right->data);
                q.push(curr->right);
            }
        }
        for(auto i:ans)
        {
            for(auto j : i.second)
            {
                v.push_back(j);
            }
        }
        return v;

    }
};


int main() {
    int t;
    string  tc;
    getline(cin,tc);
    t=stoi(tc);
    while(t--)
    {
        string s;
        getline(cin,s);
        Solution obj;
    	Node* root = buildTree(s);
    	
    	vector <int> res = obj.verticalOrder(root);
    	for (int i : res) cout << i << " ";
        cout << endl;
    }
	return 0;
}

