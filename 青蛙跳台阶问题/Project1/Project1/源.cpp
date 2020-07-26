#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numWays(int n) {
        if (n < 2)return 1;
        int pre = 0, cur = 1;
        int i = 1;
        while (i++ <= n) {
            int temp = (pre + cur)% 1000000007;
            pre = cur;
            cur = temp;
        }
        return cur;
    }
};
int main() {
    Solution s;
    cout << s.numWays(2) << endl;
    return 0;
}