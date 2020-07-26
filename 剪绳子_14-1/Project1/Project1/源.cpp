#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:

    int cuttingRope(int n) {
 /*�����ǿ���һ�����Ĳ�����ʱ��ֻ��Ҫ����һ��������������ӵ�����Ϳ��ˣ���Ҫ�����²�֣������ֻ���о����в�ֵĿ�������������ͳ��˱�����
1����dp[i]��ʾ������i��ֺ�õ������˻�
2��dp[i]�п��ܴ���������õ���
    ��1����ֳ����������
    ��2��dp[i-j]*j
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