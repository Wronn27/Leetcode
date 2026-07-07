class Solution {
public:
    long long sumAndMultiply(int n) {
        string str=to_string(n);
        reverse(str.begin(),str.end());
        long long num=stoll(str);

        long long sum=0,rev=0;
        while(num>0)
        {
            cout<<num<<endl;
            int rem=num%10;
            if(rem>0)
            {
                rev=rev*10+rem;
                sum+=rem;
            }
            num/=10;
        }
        long long res=sum*rev;
        return res;
    }
};