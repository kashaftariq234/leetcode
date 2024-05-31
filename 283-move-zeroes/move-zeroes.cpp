class Solution {
public:
    void moveZeroes(vector<int>& nums) {
         int i=0;
        int j=0;
        if(nums.size()<=1){
            return ;
        }
        while(j<nums.size()&&i<nums.size()){
            while(i<nums.size()&&nums[i]!=0){
                i++;
            }
            j=i;
            while(j<nums.size()&&nums[j]==0){
                j++;
            }
            if(j==nums.size()||i==nums.size()){
                return;
            }
            int temp = nums[i];
            nums[i] = nums[j]; 
            nums[j] = temp;
        }
    }
};