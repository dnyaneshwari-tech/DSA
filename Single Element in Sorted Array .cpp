class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0];
        if (nums[0] != nums[1]) return nums[0];
        if (nums[n - 1] != nums[n - 2]) return nums[n - 1];

        int str = 1, end = n - 2;

        while (str <= end) {
            int mid = str + (end - str) / 2;

            if (nums[mid] != nums[mid - 1] &&
                nums[mid] != nums[mid + 1]) {
                return nums[mid];
            }

            if (mid % 2 == 0) {
                if (nums[mid] == nums[mid - 1]) {
                    end = mid - 1;
                } else {
                    str = mid + 1;
                }
            } else {
                if (nums[mid] == nums[mid - 1]) {
                    str = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }

        return -1;
    }
};
