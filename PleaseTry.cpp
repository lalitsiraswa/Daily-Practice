#include <bits/stdc++.h>
#include <typeinfo>
using namespace std;

int main()
{
    vector<int> vect{1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
    unordered_map<int, int> umap;
    for (int i = 0; i < vect.size(); i++)
    {
        umap.insert({vect[i], i});
    }
    unordered_map<int, int>::iterator last2nd;
    last2nd = umap.end();
    cout << --last2nd->first << "  :  " << --last2nd->second << endl;
    // for(auto itr = umap.begin(); itr != umap.end();)
    // {
    //     cout << itr->first << " : " << itr->second << endl;
    //     itr++;
    // }
    // auto itr = umap.begin();
    // while (itr != umap.end())
    // {
    //     cout << itr->first << " : " << itr->second << endl;
    //     itr++;
    // }
}

//--------------------------------------------------------------------------------------------------
// int main()
// {
//     vector<int> vect{1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
//     unordered_map<int, int> umap;
//     for (int i = 0; i < vect.size(); i++)
//     {
//         umap.insert(pair(vect[i], i));
//     }
//     for (auto item : umap)
//     {
//         cout << item.first << " : " << item.second << endl;
//     }
// }

//------------------------------------------------------------------------------------------------
// class Demo
// {
// public:
//     Demo()
//     {
//         cout << "Default!";
//     }
//     Demo(int x)
//     {
//         cout << "Hello Parent!" << endl;
//     }
// };
// class Dep : Demo
// {
// public:
//     Dep()
//     {
//         cout << "Hello Child!" << endl;
//     }
// };

// int main()
// {
//     Dep obj;
// }

//------------------------------------------------------------------
// static int n = 1;
// void insert(int *arr)
// {
//     int element;
//     cout << "Enter an element : ";
//     cin >> element;
//     *(arr + n) = element;
//     // cout << *(arr+n) << endl;
//     ++n;
// }

// int main()
// {
//     int first = 5;
//     int *arr = &first;
//     insert(arr);
//     for(int i = 0; i < n; i++)
//         cout << *arr << "  ";
// }