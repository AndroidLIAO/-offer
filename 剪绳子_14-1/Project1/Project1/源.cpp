#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:

    int cuttingRope(int n) {
 /*当我们考虑一个数的拆分情况时，只需要考虑一个数被两个数相加的情况就可了，不要再往下拆分，否则就只能列举所有拆分的可能情况，那样就成了暴力了
1、设dp[i]表示将整数i拆分后得到的最大乘积
2、dp[i]有可能从两个方面得到：
    （1）拆分成两个数相乘
    （2）dp[i-j]*j
    */
        if (n == 2)return 1;
        vector<int> dp(n + 1, 1);
        int res = 1;
        for (int i = 3; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                res = (i - j) * j;
                dp[i] = max(dp[i], max(res, dp[i - j] * j));
            }
        }
        return dp[n];
    }
};