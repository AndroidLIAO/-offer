#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minArray(vector<int>& numbers) {
        int left = 0, right = numbers.size()-1;
        int mid = 0;
        while (left < right) {
            mid = (left + right) / 2;
            if (numbers[mid] == numbers[right]) {
                /*if (numbers[mid] == numbers[left]) {
                    left = mid;
                }
                else {
                    right = mid - 1;
                }*/
                right--;
            }
            else if (numbers[mid] > numbers[right]) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return numbers[left];
    }
};
int main() {
    Solution s;
    vector<int> numbers{ 2,0,1,2,2,2,2,2 };
    cout<<s.minArray(numbers)<<endl;
    return 0;
}