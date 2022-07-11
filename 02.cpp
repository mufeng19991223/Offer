#include <bits/stdc++.h>
                         
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int lena = a.length();
        int lenb = b.length();
        int carry = 0;
        int len = max(lena, lenb);
        string ans = "";
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        for(int i = 0; i < len; i++)
        {
            carry += i < a.size()? a[i] == '1': 0;
            carry += i < b.size()? b[i] == '1': 0;
            ans.push_back((carry % 2)? '1': '0');
            carry /= 2;
        } 
        if(carry)
        {
            ans.push_back('1');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
int main()
{
    Solution s;
    cout << s.addBinary("11", "10");    
    return 0;
}