class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        if(n==1) return s;
        int freq[26];
        memset(freq,0,sizeof(freq));

        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }
        
        string left="";
        char mid=0;
        for(int i=0;i<26;i++){
            left+=string(freq[i]/2,char(i+'a'));
            if(freq[i]%2)
            mid=char('a'+i);
        }
        string right=left;
        reverse(right.begin(),right.end());

        return mid ? left+mid+right : left+right;
    }
};