#include<iostream>
using namespace std;
struct stack
{
    int size;
    int top;
    int elements[50];
};
void push(struct stack &s,int x)
{
    if(s.top==s.size-1)
        cout<<"stack is full";
    else
    {
        s.top=s.top+1;
        s.elements[s.top]=x;
    }
}
int pop(struct stack &s)
{
    int t;
    if(s.top==-1)
        cout<<"stack is empty";
	else
	{
		t=s.elements[s.top];
		s.top=s.top-1;
		return t;
	}
}
int peep(struct stack &s)
{
    int t;
    if(s.top==-1)
        cout<<"stack is empty";
    else
    {
        t=s.elements[s.top];
        return t;
    }
}
int find(int visit[],int V)
{
	int i;
	for(i=0;i<=V;i++)
	{
		if(visit[i]==-1)
			break;
	}
	return i;
}
int main()
{
   // int V=8,E=10;
   int V,E;
   cin>>V>>E;
    int G[V+1][V+1];
    for(int i=0;i<=V;i++)
    {
        for(int j=0;j<=V;j++)
            G[i][j]=0;
    }
    //int u[]={0,0,1,2,2,3,5,5,7,7};
    //int p[]={1,2,2,5,3,4,6,8,6,8};
    for(int i=0;i<E;i++)
    {
       // G[u[i]][p[i]]=1;
        //G[p[i]][u[i]]=1;
        int u,p;
        cin>>u>>p;
        G[u][p]=1;
       // G[p][u]=1;
    }
    int num[V],low[V],P[V];
    for(int i=0;i<=V;i++) //this loop is for initializing all values to -1
    {
        num[i]=-1;
        low[i]=-1;
        P[i]=-1;
    }
    struct stack S;
    S.top=-1;
    S.size=50;
    int visit[V];
    for(int i=0;i<=V;i++)
        visit[i]=-1;
    int v=0,n=0;
    int w;
    int cnt=0;
    while(1)
	{
		cout<<"curr is "<<v<<endl;
		if(visit[v]==-1)
		{
			visit[v]=0;
			num[v]=n;
			low[v]=n;  //initially low is num itself
			cout<<"num and low of "<<v<<" is "<<n<<endl;
			n++;
			push(S,v);
			cnt++;
		}
		for(w=0;w<=V;w++)
		{
			if(G[v][w]!=0)  //if v-w is an edge
			{
				G[w][v]=0;   //making v-->w
				if(visit[w]==-1)   //if w is unvisited
				{
					P[w]=v;   //making parent of w as v
					v=w;
					break;
				}
				else if(visit[w]==0)  //if w is visited
				{
					if(P[w]==v)  //if its a tree edge
					{
						low[v]=min(low[v],low[w]);
						cout<<"tree edge "<<v<<"-"<<w<<endl;
					}
					else  //if its a back edge
					{
						low[v]=min(num[v],num[w]);
						cout<<"back edge "<<v<<"-"<<w<<endl;
					}
				}
			}
		}
		if(w>V)  //if no edge is adjacent and unvisited
		{
			if(S.top==-1&&cnt==V+1)
				break;
			if(S.top==-1)
				v=find(visit,V);
			else
				v=pop(S);
		}
	}
	for(int i=0;i<=V;i++)
		cout<<i<<" "<<num[i]<<"-"<<low[i]<<"-"<<P[i]<<endl;
	cout<<"cut vertices"<<endl;
	for(v=0;v<=V;v++) //printing cut vertices
	{
		for(int w=0;w<=V;w++)
		{
			if(G[v][w]!=0)
			{
				if(num[v]<=low[w])
				{
					if(P[v]!=-1)
						cout<<v<<" ";
					else
					{
						int c=0;
						for(int i=0;i<=V;i++)
						{
							if(G[v][i]!=0)
								c++;
						}
						if(c>1)
							cout<<v<<" ";
					}
					break;
				}
			}
		}
	}
	cout<<endl<<"bridges"<<endl;
	for(v=0;v<=V;v++) //printing bridges
	{
		for(int w=0;w<=V;w++)
		{
			if(G[v][w]!=0)
			{
				if(num[v]<low[w])
				{
					cout<<v<<" "<<w<<endl;
				}
			}
		}
	}
}
//undirected
/*
8 10
0 1
0 2
1 2
2 5
2 3
3 4
5 6
5 8
7 6
7 8
*/
//directed
/*
4 5
1 0
0 3
3 4
0 2
2 1
*/
//directed
/*
12 17
0 1
1 3
3 4
4 1
3 2
3 7
3 8
5 8
4 5
2 9
9 6
6 2
6 12
8 7
7 10
10 8
8 11
*/
