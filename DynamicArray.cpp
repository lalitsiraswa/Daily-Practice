#include <bits/stdc++.h>
using namespace std;

class Dynamicarray
{
    int *data;
    int nextIndex;
    int capacity; // total size of the d1ay
public:
    Dynamicarray()
    {
        data = new int[5];
        nextIndex = 0;
        capacity = 5;
    }
    Dynamicarray(int capacity)
    {
        data = new int[capacity];
        nextIndex = 0;
        this->capacity = capacity;
    }
    Dynamicarray(Dynamicarray const &obj) // Copy Constructor
    {
        this->nextIndex = obj.nextIndex;
        this->capacity = obj.capacity;
        // this->data = obj.data ; // shallow copy

        // deep copy
        this->data = new int[obj.capacity];
        for (int i = 0; i < obj.nextIndex; i++)
            this->data[i] = obj.data[i];
    }
    Dynamicarray operator=(Dynamicarray const &obj)
    {
        this->nextIndex = obj.nextIndex;
        this->capacity = obj.capacity;
        // this->data = obj.data ; // shallow copy

        // deep copy
        this->data = new int[obj.capacity];
        for (int i = 0; i < obj.nextIndex; i++)
            this->data[i] = obj.data[i];
    }
    void add(int element)
    {
        if (nextIndex == capacity)
        {
            capacity *= 2;
            int *newData = new int[capacity];
            for (int i = 0; i < nextIndex; i++)
            {
                newData[i] = data[i];
            }
            delete[] data;
            // newData[nextIndex++] = element;
            data = newData;
        }
        data[nextIndex++] = element;
    }
    void add(int element, int index)
    {
        if (index < nextIndex)
            data[index] = element;
        else if (index == nextIndex)
            add(element);
        else
            return;
    }
    void print() const
    {
        for (int i = 0; i < nextIndex; i++)
            cout << data[i] << "  ";
        cout << endl;
    }
    int get(int index) const
    {
        if (index >= 0 && index < nextIndex)
            return data[index];
        else
            return -1;
    }
    int getCapacity() const
    {
        return capacity;
    }
};
int main()
{
    Dynamicarray d1;
    d1.add(10);
    d1.add(20);
    d1.add(30);
    d1.add(40);
    d1.add(50);
    d1.add(60);
    // d1.print();
    cout << "Capacity : " << d1.getCapacity() << endl;
    Dynamicarray d2(d1);
    d2.add(100, 0);
    d1.print();
    d2.print();
    //-------------------------
    // Dynamicarray d2;
    // d2 = d1;
    // d2.add(100, 0);
    // d1.print();
    // d2.print();
    return 0;
}