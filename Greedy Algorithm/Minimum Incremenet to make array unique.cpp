https://leetcode.com/problems/minimum-increment-to-make-array-unique/?envType=daily-question&envId=2024-06-14

class Solution {
public:
    void speedUp(){
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int minIncrementForUnique(vector<int>& nums) {
        speedUp();
        sort(nums.begin(), nums.end());

        int count = 0;
        for(int i = 1;i < nums.size(); i++){
            if(nums[i-1] >= nums[i]){
                int a = nums[i-1] - nums[i];
                count += a + 1;
                nums[i] += a + 1;
            }
        }
        return count;
    }
};
