#include <bits/stdc++.h>
using namespace std;

// Bubble Sort Algorithm
void bubbleSort(int *array, int n)
{
    bool swapped;
    for (int i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(array[j], array[j + 1]);
                swapped = true;
            }
        }
        // If no two elements were swapped
        // by inner loop, then break
        if (swapped == false)
            break;
    }
}
int main()
{
    cout << string(20, '-') << endl;
    int array[] = {6, 5, 4, 3, 2, 1};
    int n = sizeof(array) / sizeof(int);
    bubbleSort(array, n);
    for (auto element : array)
        cout << element << " ";
    cout << endl
         << string(20, '-') << endl;
    return 0;
}