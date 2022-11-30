#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v(20, 0);
    cout << v.size() << endl;
    for(int i = 0; i < v.size(); i++)
        cout << v.at(i) << " ";
    // vector<int> v;
    // for (int i = 0; i < 100; i++)
    // {
    //     v.push_back(i + 1);
    //     // cout << "Size of the vector : " << v.size() << endl;
    //     cout << "Capacity of the vector : " << v.capacity() << endl;
    // }
    // for(int i = 0; i < v.size(); i++)
    //     cout << v.at(i) << endl;
}

//------------------------------------------------------------
// int main()
// {
//     vector<int> *vp = new vector<int>();
//     vector<int> v;
//     v.push_back(10);
//     v.push_back(20);
//     v.push_back(30);
//     v[1] = 100;
//     v[4] = 1002; // this will not work
//     v[5] = 1234; // this will not work
//     v.push_back(23);
//     v.push_back(234);
//     for (auto item : v)
//         cout << item << "  ";
//     cout << endl
//          << endl;
//     // cout << v[0] << endl;
//     // cout << v[1] << endl;
//     // cout << v[2] << endl;
//     // cout << v[3] << endl;
//     // cout << v[4] << endl;
//     // cout << v[5] << endl; // Access garbage value
//     // cout << v[6] << endl; // Access garbage value
//     //---------------------
//     cout << v.at(0) << endl;
//     cout << v.at(1) << endl;
//     cout << v.at(2) << endl;
//     cout << v.at(3) << endl;
//     cout << v.at(4) << endl;
//     cout << v.at(5) << endl; // Access garbage value
//     cout << v.at(6) << endl; // Access garbage value
// }