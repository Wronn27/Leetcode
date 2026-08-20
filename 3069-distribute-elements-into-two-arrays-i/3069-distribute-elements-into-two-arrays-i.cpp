class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr1,arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        int a1=0,a2=0;

        for(int i=2;i<n;i++){
            if(arr1[a1]>arr2[a2]){
                arr1.push_back(nums[i]);
                a1++;
            }
            else
            {
                arr2.push_back(nums[i]);
                a2++;
            }
        }
        arr1.insert(arr1.end(), arr2.begin(), arr2.end());
        return arr1;
    }
};