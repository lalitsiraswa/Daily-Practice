#include <bits/stdc++.h>
using namespace std;

// Bubble Sort Algorithm
// Time Complexity: O(N^2)
// Auxiliary Space: O(1)
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
// Time Complexity: O(N^2)
// Auxiliary Space: O(1)
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

// Selection Sort Algorithm
// Time Complexity : The time complexity of Selection Sort is O(N^2) as there are two nested loops:
// One loop to select an element of Array one by one = O(N)
// Another loop to compare that element with every other Array element = O(N)
// Therefore overall complexity = O(N) * O(N) = O(N*N) = O(N^2)
// Auxiliary Space: O(1) as the only extra memory used is for temporary variables while swapping two values in Array. The selection sort never makes more than O(N)
// swaps and can be useful when memory writing is costly.

void selectionSort(int array[], int n)
{
    int min_index;
    for (int i = 0; i < n; i++)
    {
        min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (array[j] < array[min_index])
                min_index = j;
        }
        // Swap the found minimum element
        // with the first element
        if (min_index != i)
            swap(array[min_index], array[i]);
    }
}
int main()
{
    cout << string(20, '-') << endl;
    int array[] = {6, 5, 4, 3, 2, 1};
    int n = sizeof(array) / sizeof(int);
    selectionSort(array, n);
    for (auto element : array)
        cout << element << " ";
    cout << endl
         << string(20, '-') << endl;
    return 0;
}