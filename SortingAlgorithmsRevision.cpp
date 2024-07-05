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
// Insertion Sort Algorithm
void insertionSort(int array[], int n)
{
    int key;
    for (int i = 1; i < n; i++)
    {
        key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}
int main()
{
    cout << string(20, '-') << endl;
    int array[] = {6, 5, 4, 3, 2, 1};
    int n = sizeof(array) / sizeof(int);
    insertionSort(array, n);
    for (auto element : array)
        cout << element << " ";
    cout << endl
         << string(20, '-') << endl;
    return 0;
}