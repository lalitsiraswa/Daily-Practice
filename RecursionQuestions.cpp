#include <bits/stdc++.h>
using namespace std;

// ----------------------------------------------------------------- Pring Hello World N Times --------------------------------------------------------------------------
void printHelloWorld(int count)
{
    if (count == 0)
        return;
    cout << "Hello World" << endl;
    printHelloWorld(count - 1);
}
// int main()
// {
//     cout << string(30, '-') << endl;
//     printHelloWorld(5);
//     cout << endl
//          << string(30, '-') << endl;
//     return 0;
// }
// ---------------------------------------------------- Print 1 to N By Backtracking or Without using + sign  -----------------------------------------------------------
void print1ToNUsingBacktracking(int n)
{
    if (n == 0)
        return;
    print1ToNUsingBacktracking(n - 1);
    cout << n << endl;
}
int main()
{
    cout << string(30, '-') << endl;
    print1ToNUsingBacktracking(5);
    cout << endl
         << string(30, '-') << endl;
    return 0;
}