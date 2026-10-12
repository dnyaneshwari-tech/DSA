class Solution {
public:
    int search(vector<int>& nums, int tar) {
        
        int str = 0 , end = nums.size()-1;
        while(str <= end){
            int mid = str + (end - str)/2;
            if( nums[mid] == tar ){
                return mid;
            }
            if(nums[str] <= nums[mid]){
                if(nums[str] <= tar && tar<= nums[mid]){
                    end = mid-1;
                }
                else{
                    str = mid+1;
                }
            }
            else{
                if(nums[mid] <= tar && tar <= nums[end]){
                    str = mid+1;
                }
                else{
                    end = mid-1;
                }
            }
        }
        return -1;
    }
};
