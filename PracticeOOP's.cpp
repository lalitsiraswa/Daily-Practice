#include <bits/stdc++.h>
using namespace std;

class Number
{
private:
    int first;
    int second;

public:
    Number() {}
    Number(int first, int second) : first(first), second(second) {}
    Number operator+(Number n)
    {
        Number temp(first + n.first, second + n.second);
        return temp;
    }
    string operator==(Number n)
    {
        if (first == n.first && second == n.second)
            return "Equal!";
        else
            return "Not Equal!";
    }
    void operator++()
    {
        first = first + 1;
        second = second + 1;
    }
    void display()
    {
        cout << "first : " << first << "  second : " << second << endl;
    }
};

int main()
{
    Number n1(4, 7);
    ++n1;
    // Number n2(4, 7);
    // Number n3;
    // n3 = n1 + n2;
    n1.display();
    // cout << (n1 == n2);
}
