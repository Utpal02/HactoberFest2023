class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int t) {
        int n = nums.size();
        if(!n)
        return {-1,-1};
        int i = lower_bound(nums.begin(),nums.end(),t)-nums.begin();
        int j = upper_bound(nums.begin(),nums.end(),t)-nums.begin();
        if(i==n or nums[i]!=t)
        return {-1,-1};
        return {i,j-1};
    }
};
