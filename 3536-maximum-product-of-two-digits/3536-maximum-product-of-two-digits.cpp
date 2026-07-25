class Solution {
public:
    int maxProduct(int n) {
        string s=to_string(n);
        int si=s.size();
        sort(s.begin(),s.end());
        return (s[si-1]-'0')*(s[si-2]-'0');
    }   
};