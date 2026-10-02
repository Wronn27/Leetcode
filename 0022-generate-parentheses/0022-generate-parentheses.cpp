class Solution {
public:
    void solve(int num_open,int num_close,string temp,vector<string> &ans)
    {
        if(num_open==0 && num_close==0)
        {
            ans.push_back(temp);
            return;
        }

        if(num_open>0)
        {
            temp=temp+'(';
            solve(num_open-1,num_close,temp,ans);
            temp.pop_back();
        }
        

        if(num_close>num_open)
        {
            temp=temp+')';
            solve(num_open,num_close-1,temp,ans);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        if(n==1) return {"()"};
        string temp="";
        vector<string> ans;
        solve(n,n,temp,ans);
        return ans;
    }
};