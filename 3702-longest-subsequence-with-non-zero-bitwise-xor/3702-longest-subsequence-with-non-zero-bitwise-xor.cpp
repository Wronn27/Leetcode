class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size(),prexor=0,flag=0;
        for(int i=0;i<n;i++)
            {
                prexor^=nums[i];
                if(nums[i]!=0) flag=1;
            }
        if(flag==1)
        return prexor==0 ? n-1 : n;
        else
        return 0;
    }
};
