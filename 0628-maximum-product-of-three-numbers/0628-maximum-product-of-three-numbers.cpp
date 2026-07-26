class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        if(n==3) return accumulate(nums.begin(),nums.end(),1, multiplies<int>());
        sort(nums.begin(),nums.end());
        return max({nums[n-1]*nums[0]*nums[1],
                    nums[n-1]*nums[n-2]*nums[0],
                    nums[n-1]*nums[n-2]*nums[n-3],
                    nums[0]*nums[1]*nums[2]
        });
    }
};