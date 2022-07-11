#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int divide(int a, int b)
    {
        int ans = 0;
        //特判
        if (a == INT_MIN && b == -1)
        {
            return INT_MAX;
        }
        // a b全置为负数 避免溢出int
        bool flag = ((a > 0) ^ (b > 0)) ? 0 : 1;
        if (a > 0)
        {
            a = -a;
        }
        if (b > 0)
        {
            b = -b;
        }
        while (a <= b)
        {
            // 判断 d >= INT_MIN 的原因：保证 d + d 不会溢出
            // 可以这样判断的原因是：INT_MIN >> 1是最小值 -2^31 的一半，
            // 而 a 的值不可能比 -2^31 还要小，所以 d 不可能比 INT_MIN >> 1 小
            int k = 1, d = b;
            while (d + d >= a && d >= INT_MIN >> 1)
            {
                d += d;
                // 代码优化：如果 k 已经大于最大值的一半的话，那么直接返回最小值
                // 因为这个时候 k += k 的话肯定会大于等于 2147483648 ，这个超过了题目给的范围
                if (k > INT_MAX / 2)
                {
                    return INT_MIN;
                }
                k += k;
            }
            ans += k;
            a -= d;
        }
        return flag ? ans : -ans;
    }
};

int main()
{   
     return 0;
}