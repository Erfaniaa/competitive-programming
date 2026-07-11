class Solution {
public:
    /*
        Solution explanation:
        Short explanation: checkout turtle and rabbit algorithm on cycle detection
        Complete explanation: TBD
    */
    int findDuplicate(vector<int>& nums) {
        int slow=nums[0],fast=nums[0];

        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) {
                // do while is that you?
                break;
            }
        }
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};