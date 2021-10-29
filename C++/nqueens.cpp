#include<bits/stdc++.h>
using namespace std;
int board[10][10];
class queens{


    // Utility Function

    void print(int N)
    {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                printf(" %d ", board[i][j]);
            printf("\n");
        }
        cout<<endl;
    }

    bool isSafe(int row, int col,int N)
    {
        int i, j;
    
        /* Check this row on left side */
        for (i = 0; i < col; i++)
            if (board[row][i])
                return false;
    
        /* Check upper diagonal on left side */
        for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
            if (board[i][j])
                return false;
    
        /* Check lower diagonal on left side */
        for (i = row, j = col; j >= 0 && i < N; i++, j--)
            if (board[i][j])
                return false;
    
        return true;
    }
    public :

    bool solve(int N, int col)
    {
        if (col >= N)
            return true;
    
        for (int i = 0; i < N; i++) {
            if (isSafe( i,col,N)) {
                board[i][col] = 1;
                cout<<"Placing queen "<<col+1<<"\n";
                print(N);
                if (solve(N,col + 1))
                    return true;
               
                cout<<"No Position for queen "<<col+2<<"\n";
                 board[i][col] = 0; // BACKTRACK
                cout<<"Bactracking from "<<col+1<<" Column\n";
            }
        }
  
    return false;
}
  
};
int main()
{
    queens q1;
    int n;
    cout<<"Enter the Number of Queens To be Placed\n";
    cin>>n;
    if(n<=3)
    {
        cout<<"No solution possible\n";
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            board[i][j]=0;
        }
    }
    q1.solve(n,0);
    return 0;
}
