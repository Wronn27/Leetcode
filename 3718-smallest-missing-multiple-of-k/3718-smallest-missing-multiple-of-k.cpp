class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n=nums.size();
        set<int> st;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }

        int num=k;
        while(st.contains(num)){
            num+=k;
        }
        return num;
    }
};