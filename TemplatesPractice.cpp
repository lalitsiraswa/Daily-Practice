#include <bits/stdc++.h>
using namespace std;

// Function Template
// template <typename T>
// T myMax(T x, T y)
// {
//     return (x > y) ? x : y;
// }
// int main()
// {
//     cout << string(35, '-') << endl;
//     cout << myMax<int>(4, 5) << endl;
//     cout << myMax<double>(4.6, 5.7) << endl;
//     cout << myMax<char>('Z', 'A') << endl;
//     cout << endl
//          << string(35, '-');
// }
// ------------
// Class Template
template <typename T>
class Array
{
private:
    T *ptr;
    int size;

public:
    Array(T arr[], int s);
    void print();
};
template <typename T>
Array<T>::Array(T arr[], int s)
{
    ptr = new T[s];
    size = s;
    for (int i = 0; i < size; i++)
        ptr[i] = arr[i];
}
template <typename T>
void Array<T>::print()
{
    for (int i = 0; i < size; i++)
        cout << " " << *(ptr + i);
    cout << endl;
}
int main()
{
    cout << string(35, '-') << endl;
    int arr[5] = {2, 4, 6, 8, 10};
    Array<int> a(arr, 5);
    a.print();
    cout << endl
         << string(35, '-');
}