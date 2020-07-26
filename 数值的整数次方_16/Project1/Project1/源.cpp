#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        //����x�ĸ�����ʱ���Ƚ�xȡ����
        long long N = n;
        if (n < 0) {
            x = 1 / x;
            N = -N;
        }
        return pow(x, N);
    }
    double pow(int x, long long n) {
        //�ݹ�Ļ�׼����
        if (n == 0)return 1;
        if (n == 1)return x;
        double mid = pow(x, n / 2);
        //���n������������Ҫ���һ��x
        if (n & 1)return mid * mid * x;
        return mid * mid;
    }
};