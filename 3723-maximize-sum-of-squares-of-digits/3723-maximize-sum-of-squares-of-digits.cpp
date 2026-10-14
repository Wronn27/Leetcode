class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum>9*num || sum<=0) return "";
        string ans="";
        int rem=sum;

        for(int i=0;i<num;i++)
            {
                int digit=min(9,rem);
                if(digit<0) return "";

                ans+=digit+'0';
                rem-=digit;
            }
        return ans;
    }
};