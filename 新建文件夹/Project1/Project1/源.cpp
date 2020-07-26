#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> printNumbers(int n) {
        long long len = pow(10, n);
        vector<int> res(len-1, 0);
        for (int i = 0; i < len / 2; i++) {
            res[i] = i+1;
            res[len - i-2] = len - i-1;
        }
        res[len / 2] = len / 2;
        return res;
    }
};
int main() {
    Solution s;
    vector<int>res= s.printNumbers(1) ;
    return 0;
}