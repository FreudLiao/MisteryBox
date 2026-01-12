class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size(); //先取得vector長度大小
      //從第零個開始算
        for(int i = 0; i < n; i++ ){
            for(int j = i + 1; j < n; j++ ){
                if(nums[i] + nums[j] == target){
                    return {i,j};
                }
            }
        }
        return {};//回傳vector裡面型態的值
    }
};
