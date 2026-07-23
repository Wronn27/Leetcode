class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size(),sum=0,max_sum=INT_MIN;
        if(n==0) return 0;
        if(n==1) return nums[0];
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            max_sum=max(max_sum,sum);
            if(sum<0)
            sum=0;
        }
        return max_sum;
    }
};