#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    /**
        奇数放在偶数前面：
            运用双指针，（1）当左指针是指向奇数时，则往右移动；
                        （2）当右指针指向偶数时，右指针往左移动；
                        （3）否则交换这两个指针
    
    **/
    vector<int> exchange(vector<int>& nums) {
        if (nums.empty())return nums;
        int left = 0, right = nums.size() - 1;
        while (left<right) {
           while ((nums[left] & 0x1) == 1&&left<right)left++;
            while ((nums[right] & 0x1) == 0&&left<right)right--;
            if(left<right)swap(nums[left], nums[right]);
        }
        return nums;
    }
};