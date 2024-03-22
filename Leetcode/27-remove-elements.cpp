class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = 0;
        vector<int>::iterator itr = nums.begin();
        int last_val_index = nums.size();
        for(int i = nums.size()-1; i > -1; --i)
        {
            if (nums[i]==val)
            {

                    nums[i] = nums[last_val_index-1];
                    nums[last_val_index-1] = val;
                    --last_val_index;
            }
            else
            {
                len+=1;
            }
        }
        return len;
}
};