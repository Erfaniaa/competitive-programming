class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int index=0; index < nums.size(); index++) {
            if (nums[index] > 0 && nums[index] < nums.size() + 1) {
                int tmp = nums[nums[index]-1];
                nums[nums[index] - 1] = nums[index];
                nums[index] = tmp;
            }
        }
        for(int index=0; index < nums.size(); index++) {
            while (nums[index] > 0 && nums[index] < nums.size() + 1) {
                if (nums[nums[index] - 1] == nums[index]) break;
                int tmp = nums[nums[index]-1];
                nums[nums[index] - 1] = nums[index];
                nums[index] = tmp;
            }
        }
        for(int index=0; index < nums.size(); index++) {
            if (nums[index]!=index+1) return index+1;
        }
        return nums.size() + 1;
    }
};