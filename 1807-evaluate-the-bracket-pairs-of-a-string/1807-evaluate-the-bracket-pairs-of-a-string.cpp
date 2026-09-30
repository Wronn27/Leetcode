class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        
        int n=s.size();
        
        unordered_map<string,string> mp;
        for(int i=0;i<knowledge.size();i++){
            mp[knowledge[i][0]]=knowledge[i][1];
        }

        string result="";
        int ind=0;
        
        while(ind<n){
            if(s[ind]=='('){
                string temp="";
                ind++;
                while(s[ind]!=')')
                    temp+=s[ind++];
                ind++;
                if(mp.contains(temp))
                    result+=mp[temp];
                else
                    result+='?';
            }
            else
                result+=s[ind++];
        }
        return result;
    }
};