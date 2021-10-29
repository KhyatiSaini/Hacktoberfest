class Solution {
public:
    int numUniqueEmails(vector<string>& emails) 
    {
        unordered_set<string> st;
        for(auto email: emails)
        {
            string word="";
            bool marked=false;
            bool arrived=false; 
            for(int i=0; i<email.length(); i++)
            {
                if(email[i]=='@')
                    arrived=true;
                if(arrived)
                    word += email[i];
                
                else if(!marked and email[i]!='.' and email[i]!='+')
                    word += email[i];
                
                else if(email[i]=='+')
                {
                    marked = true;
                }
            }
            st.insert(word);
        }
        return st.size();
    }
};