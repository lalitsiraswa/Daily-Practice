#include <bits/stdc++.h>
using namespace std;

// -------------------------------------------------------------- Decimal to Binary || Binary to Decimal --------------------------------------------------------------------
string convert2Binary(int num)
{
    string binary;
    while (num != 1)
    {
        int remainder = num % 2;
        binary.push_back(remainder + '0');
        int quotient = num / 2;
        num = quotient;
    }
    binary.push_back(1 + '0');
    reverse(binary.begin(), binary.end());
    return binary;
}
int binary2Decimal(string binary)
{
    int num = 0;
    reverse(binary.begin(), binary.end());
    for (int i = 0; i < binary.size(); i++)
    {
        int digit = binary.at(i) - '0';
        digit *= pow(2, i);
        num += digit;
    }
    return num;
}
int main()
{
    cout << string(30, '-') << endl;
    // cout << convert2Binary(23) << endl;
    cout << binary2Decimal("10111") << endl;
    cout << endl
         << string(30, '-');
}