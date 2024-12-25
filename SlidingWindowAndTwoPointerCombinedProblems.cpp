#include <bits/stdc++.h>
using namespace std;

// -------------------------------------------------------------- 1423. Maximum Points You Can Obtain from Cards ------------------------------------------------------
int maxScore(vector<int> &cardPoints, int k)
{
    int n = cardPoints.size();
    int windowSum = 0;
    for (int i = 0; i < k; i++)
    {
        windowSum += cardPoints[i];
    }
    // If the window size is equal to the number of elements:
    if (n == k)
    {
        return windowSum;
    }
    // left is pointing to the end of the left hand side window:
    int left = k - 1;
    // right is pointing to the starting of the right hand side window:
    int right = n - 1;
    int maximumScore = windowSum;
    while (left >= 0)
    {
        // Shrink the window from the left hand side:
        windowSum -= cardPoints[left];
        // Extend the window from the right hand side:
        windowSum += cardPoints[right];
        left -= 1;
        right -= 1;
        maximumScore = max(maximumScore, windowSum);
    }
    return maximumScore;
}
int main()
{
    cout << string(30, '-') << endl;
    vector<int> cardPoints = {6, 2, 3, 4, 7, 2, 1, 7, 1};
    cout << maxScore(cardPoints, 4);
    cout << endl
         << string(30, '-');
}