class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int less=0,count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<target)
            less++;
            else if(nums[i]==target)
            count++;
        }
        vector<int> ans;
        for(int i=0;i<count;i++){
            ans.push_back(less+i);
        }

        return ans;
    }
};