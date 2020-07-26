#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int fib(int n) {
        int cur = 1, pre = 0;
        long result = 0;
        int temp = pow(10, 9) + 7;
        int i = 2;
        while (i++ <= n) {
            result = (cur + pre)%temp;//每次都先求余，这样避免越界问题
            pre = cur;
            cur = result;
        }
        return cur;
    }
};
int main() {
    Solution s;
    cout<<s.fib(100)<<endl;
    return 0;
}