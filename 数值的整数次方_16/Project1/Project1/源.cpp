#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        //当求x的负次幂时，先将x取倒数
        long long N = n;
        if (n < 0) {
            x = 1 / x;
            N = -N;
        }
        return pow(x, N);
    }
    double pow(int x, long long n) {
        //递归的基准条件
        if (n == 0)return 1;
        if (n == 1)return x;
        double mid = pow(x, n / 2);
        //如果n是奇数，则需要多乘一个x
        if (n & 1)return mid * mid * x;
        return mid * mid;
    }
};