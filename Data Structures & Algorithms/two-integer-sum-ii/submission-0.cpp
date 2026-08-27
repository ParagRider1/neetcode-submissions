class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int st=0;
        int end=nums.size()-1;
        //given sorted nums
        vector<int> ans(2);
        while(st<end){
             int sum=nums[st]+nums[end];
             if(sum==target){
                ans[0]=st+1;
                ans[1]=end+1;
                break;
             }else if(sum<target){
                st++;
             }else{
                end--;
             }
        }
        return ans;
    }
};
