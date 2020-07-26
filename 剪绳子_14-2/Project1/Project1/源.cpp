#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int cuttingRope(int n) {
        if (n == 2)return 1;
        if (n == 3)return 2;
        long result = 1;
        while (n > 4) {
            result = result * 3 % 1000000007;
            n -= 3;
        }
        result = result * n % 1000000007;
        return result;
    }
};
int main() {
    Solution s;
    cout << s.cuttingRope(1000) << endl;
    return 0;
}