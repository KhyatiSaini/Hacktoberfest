//problem statement (link) : https://leetcode.com/problems/count-binary-substrings/

class Solution {
public:
    int countBinarySubstrings(string s) {
        int n=s.size();
        int dp[s.size()][s.size()];
        
        memset(dp,0,sizeof(dp));
        
        int sum=0;
        for(int i=0;i<n-1;i++){
            if(s[i]!=s[i+1]){
                dp[i][i+1]=1;
                sum+=1;
            }
        }
        for(int k=3;k<n;k++){
            for(int i=0;i<n-k;i++){
                int j=i+k;
                if(s[i]!=s[j] && s[i]==s[i+1] && s[j]==s[j-1] && dp[i+1][j-1]==1){
                    dp[i][j]=1;
                    sum+=1;
                }
            }            
        }
        
        return sum;
    }
};
