#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int multiply(int x,vector<int> &v,int &res_size)
    {
        int carry=0;
        for(int i=0;i<res_size;i++)
        {
            int prod=v[i]*x+carry;
            
            v[i]=prod%10;
            
            carry=prod/10;
        }
        
        while(carry)
        {
            v.push_back(carry%10);
            carry=carry/10;
            res_size++;
        }
        return res_size;
    }

    vector<int> factorial(int N){
        vector<int> v;
        v.push_back(1);
        int res_size=1;
        
        for(int i=2;i<=N;i++)
        {
            res_size=multiply(i,v,res_size);
        }
        
        
        reverse(v.begin(),v.end());
        return v;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}
