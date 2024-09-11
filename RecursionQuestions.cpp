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
int main()
{
    cout << string(30, '-') << endl;
    printHelloWorld(5);
    cout << endl
         << string(30, '-') << endl;
    return 0;
}