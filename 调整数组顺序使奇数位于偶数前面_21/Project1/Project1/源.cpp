#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    /**
        ��������ż��ǰ�棺
            ����˫ָ�룬��1������ָ����ָ������ʱ���������ƶ���
                        ��2������ָ��ָ��ż��ʱ����ָ�������ƶ���
                        ��3�����򽻻�������ָ��
    
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