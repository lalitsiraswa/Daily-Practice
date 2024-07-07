#include <bits/stdc++.h>
using namespace std;

// ------------------------------------------------------------------- 88. Merge Sorted Array ------------------------------------------------------------------
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int index = (m + n) - 1;
    int mPtr = --m, nPtr = --n;
    while (nPtr >= 0)
    {
        if (mPtr < 0)
        {
            nums1[index] = nums2[nPtr--];
        }
        else if (nums2[nPtr] > nums1[mPtr])
        {
            nums1[index] = nums2[nPtr--];
        }
        else
        {
            nums1[index] = nums1[mPtr--];
        }
        index--;
    }
}
void merge_2(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int p1 = m - 1, p2 = n - 1;
    int p = (m + n) - 1;
    while (p1 > -1 && p2 > -1)
    {
        if (nums1[p1] > nums2[p2])
            nums1[p--] = nums1[p1--];
        else
            nums1[p--] = nums2[p2--];
    }
    while (p2 > -1)
    {
        nums1[p--] = nums2[p2--];
    }
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     vector<int> nums1 = {2, 0};
//     vector<int> nums2 = {1};
//     int m = 1, n = 1;
//     merge(nums1, m, nums2, n);
//     for (auto item : nums1)
//         cout << item << " ";
//     cout << endl;
//     cout << string(35, '-');
//     return 0;
// }
// -------------------------------------------------------------- 27. Remove Element -----------------------------------------------------------------------
int removeElement(vector<int> &nums, int val)
{
    int n = nums.size();
    if (n == 0)
        return 0;
    int left = 0, right = n - 1;
    while (left < right)
    {
        if (nums[left] != val)
            left++;
        else if (nums[right] == val)
            right--;
        if (nums[left] == val && nums[right] != val)
        {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }
    return (nums[left] != val) ? left + 1 : left;
}
// -------------------
int removeElement_2(vector<int> &nums, int val)
{
    int index = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != val)
        {
            nums[index] = nums[i];
            index++;
        }
    }
    return index;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
//     cout << removeElement_2(nums, 2) << endl;
//     cout << string(35, '-');
//     return 0;
// }
// ------------------------------------------------------------ 153. Find Minimum in Rotated Sorted Array -------------------------------------------------------------
// Key Observation: If an array is rotated and sorted, we already know that for every index, one of the 2 halves of the array will always be sorted.
int findMin(vector<int> &nums)
{
    int left = 0;
    int right = nums.size() - 1;
    int minValue = INT_MAX;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        // if left part is sorted:
        if (nums[left] <= nums[mid])
        {
            // keep the minimum:
            minValue = min(minValue, nums[left]);
            // Eliminate left half:
            left = mid + 1;
        }
        // if right part is sorted:
        else
        {
            // keep the minimum:
            minValue = min(minValue, nums[mid]);
            // Eliminate right half:
            right = mid - 1;
        }
    }
    return minValue;
}
// --------------------
int findMin_2(vector<int> &nums)
{
    int left = 0;
    int right = nums.size() - 1;
    int minValue = INT_MAX;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        // search space is already sorted
        // then arr[low] will always be
        // the minimum in that search space:
        if (nums[left] <= nums[right])
        {
            minValue = min(minValue, nums[left]);
            break;
        }
        // if left part is sorted:
        if (nums[left] <= nums[mid])
        {
            // keep the minimum:
            minValue = min(minValue, nums[left]);
            // Eliminate left half:
            left = mid + 1;
        }
        // if right part is sorted:
        else
        {
            // keep the minimum:
            minValue = min(minValue, nums[mid]);
            // Eliminate right half:
            right = mid - 1;
        }
    }
    return minValue;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     vector<int> nums = {11, 13, 15, 17};
//     cout << findMin(nums) << endl;
//     cout << string(35, '-');
//     return 0;
// }
// --------------------------------------------------------------- 33. Search in Rotated Sorted Array ----------------------------------------------------------
// Key Observation: If an array is rotated and sorted, we already know that for every index, one of the 2 halves of the array will always be sorted.
int search(vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        if (nums[left] <= nums[mid])
        {
            if (nums[left] <= target && target <= nums[mid])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        else if (nums[mid] <= nums[right])
        {
            if (nums[mid] <= target && target <= nums[right])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
    }
    return -1;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     vector<int> nums = {1};
//     cout << search(nums, 3) << endl;
//     cout << endl
//          << string(35, '-');
//     return 0;
// }
// ------------------------------------------------------------- 26. Remove Duplicates from Sorted Array -----------------------------------------------------
int removeDuplicates(vector<int> &nums)
{
    int index = 0, i;
    for (i = 1; i < nums.size(); i++)
    {
        if (nums[i] != nums[i - 1])
        {
            nums[index++] = nums[i - 1];
        }
    }
    if (index > 0 && nums[index - 1] != nums[i - 1])
    {
        nums[index++] = nums[i - 1];
    }
    return (index == 0) ? 1 : index;
}
// ----------------
int removeDuplicates_2(vector<int> &nums)
{
    int index = 0, i;
    for (i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] != nums[i + 1])
        {
            nums[index++] = nums[i];
        }
    }
    if (index > 0 && nums[index - 1] != nums[i])
    {
        nums[index++] = nums[i];
    }
    return (index == 0) ? 1 : index;
}
// ---------------------
int removeDuplicates_3(vector<int> &nums)
{
    int index = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (index < 1 || nums[i] != nums[index - 1])
        {
            nums[index++] = nums[i];
        }
    }
    return index;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
//     cout << removeDuplicates_2(nums) << endl;
//     cout << endl
//          << string(35, '-');
//     return 0;
// }
// ----------------------------------------------------- 169. Majority Element -------------------------------------------------------------
int majorityElement(vector<int> &nums)
{
    unordered_map<int, int> frequencyMap;
    for (auto item : nums)
    {
        frequencyMap[item] += 1;
    }
    int maxFreq = INT_MIN;
    int majorElement;
    for (auto item : frequencyMap)
    {
        if (item.second > maxFreq)
        {
            maxFreq = item.second;
            majorElement = item.first;
        }
    }
    return majorElement;
}
// ------------------------------------
//--- Using Boyer-Moore Majority Voting Algorithm ----
int majorityElement_2(vector<int> &nums)
{
    int n = nums.size();
    int majority_element = nums[0];
    int counter = 1;
    for (int i = 1; i < n; i++)
    {
        if (nums[i] == majority_element)
            counter++;
        else
        {
            counter--;
            if (counter == 0)
            {
                majority_element = nums[i];
                counter = 1;
            }
        }
    }
    return majority_element;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
//     cout << majorityElement(nums) << endl;
//     cout << endl
//          << string(35, '-');
//     return 0;
// }
// --------------------------------------------------- 14. Longest Common Prefix ----------------------------------------------------------
string longestCommonPrefix(vector<string> &strs)
{
    string longestCommonPrefix;
    for (int i = 0; i < strs[0].size(); i++)
    {
        for (int j = 1; j < strs.size(); j++)
        {
            if (strs[j].size() - 1 >= i)
            {
                if (strs[j][i] != strs[0][i])
                    return longestCommonPrefix;
            }
            else
                return longestCommonPrefix;
        }
        longestCommonPrefix.push_back(strs[0][i]);
    }
    return longestCommonPrefix;
}
// ----------------
string longestCommonPrefix_2(vector<string> &strs)
{
    string longestCommonPrefix = "";
    sort(strs.begin(), strs.end());
    string firstString = strs[0];
    string lastString = strs[strs.size() - 1];
    for (int i = 0; i < firstString.size(); i++)
    {
        if (firstString[i] != lastString[i])
            return longestCommonPrefix;
        longestCommonPrefix.push_back(firstString[i]);
    }
    return longestCommonPrefix;
}
// ----------------
string longestCommonPrefix_3(vector<string> &strs)
{
    string longestCommonPrefix = "";
    for (int i = 0; i < strs[0].size(); i++)
    {
        char ch = strs[0][i];
        for (int j = 1; j < strs.size(); j++)
        {
            if (ch != strs[j][i])
                return longestCommonPrefix;
        }
        longestCommonPrefix.push_back(ch);
    }
    return longestCommonPrefix;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     vector<string> strs = {"flower", "flow", "flowerable"};
//     cout << longestCommonPrefix_3(strs) << endl;
//     cout << endl
//          << string(35, '-');
//     return 0;
// }
// ----------------------------------------------------------- 80. Remove Duplicates from Sorted Array II --------------------------------------------------------
int removeDuplicates2(vector<int> &nums)
{
    int index = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (index < 2 || nums[i] != nums[index - 2])
        {
            nums[index++] = nums[i];
        }
    }
    return index;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     vector<int> nums = {1, 1, 1, 2, 2, 3};
//     cout << removeDuplicates2(nums) << endl;
//     cout << endl
//          << string(35, '-');
//     return 0;
// }
// ------------------------------------------------------------------------ 189. Rotate Array ------------------------------------------------------------------
void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> rotatedVect(n);
    for (int i = 0; i < n; i++)
    {
        rotatedVect[(i + k) % n] = nums[i];
    }
    nums = rotatedVect;
}
// ------- TLE -------
void rotate_2(vector<int> &nums, int k)
{
    int n = nums.size();
    for (int i = 0; i < k; i++)
    {
        int temp = nums[n - 1];
        for (int j = n - 2; j >= 0; j--)
        {
            nums[(j + 1) % n] = nums[j];
        }
        nums[0] = temp;
    }
}
// ---------- USING "reverse()" -----------
void rotate_3(vector<int> &nums, int k)
{
    int n = nums.size();
    k = k % n;
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}
// ------------ Reverse Manually ------------
void rotate_4(vector<int> &nums, int k)
{
    int n = nums.size();
    k = k % n;
    int left = 0, right = n - 1;
    while (left < right)
    {
        int temp = nums[left];
        nums[left++] = nums[right];
        nums[right--] = temp;
    }
    left = 0, right = k - 1;
    while (left < right)
    {
        int temp = nums[left];
        nums[left++] = nums[right];
        nums[right--] = temp;
    }
    left = k, right = n - 1;
    while (left < right)
    {
        int temp = nums[left];
        nums[left++] = nums[right];
        nums[right--] = temp;
    }
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
//     rotate_2(nums, 3);
//     for (auto num : nums)
//         cout << num << " ";
//     cout << endl
//          << string(35, '-');
//     return 0;
// }
// -------------------------------------------------------------- 121. Best Time to Buy and Sell Stock ------------------------------------------------------------
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<int> buy(n);
    vector<int> sell(n);
    buy[0] = prices[0];
    for (int i = 1; i < n; i++)
    {
        buy[i] = min(buy[i - 1], prices[i]);
    }
    sell[n - 1] = prices[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        sell[i] = max(sell[i + 1], prices[i]);
    }
    int maxProfit = sell[0] - buy[0];
    for (int i = 1; i < n; i++)
    {
        maxProfit = max(maxProfit, sell[i] - buy[i]);
    }
    return maxProfit;
}
// -------- USING TWO POINTER -----------
int maxProfit_2(vector<int> &prices)
{
    int n = prices.size();
    int buyPtr = 0, sellPtr = 0, maxProfit = INT_MIN;
    while (sellPtr < n)
    {
        int currentProfit = prices[sellPtr] - prices[buyPtr];
        if (currentProfit < 0)
        {
            buyPtr = sellPtr;
        }
        else if (currentProfit > maxProfit)
        {
            maxProfit = currentProfit;
            sellPtr++;
        }
        else
        {
            sellPtr++;
        }
    }
    return maxProfit;
}
// -------- Kadane's Algorithm -----------
int maxProfit_3(vector<int> &prices)
{
    int maxCurr = 0, maxSoFar = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        int currProfit = prices[i] - prices[i - 1];
        maxCurr += currProfit;
        maxCurr = max(0, maxCurr);
        maxSoFar = max(maxCurr, maxSoFar);
    }
    return maxSoFar;
}
// -------------- DP ----------------
int maxProfit_4(vector<int> &prices)
{
    int maxProfit = 0;
    int minPrice = prices[0];
    for (int i = 1; i < prices.size(); i++)
    {
        int currProfit = prices[i] - minPrice;
        maxProfit = max(maxProfit, currProfit);
        minPrice = min(minPrice, prices[i]);
    }
    return maxProfit;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     vector<int> prices = {7, 1, 5, 3, 6, 4};
//     cout << maxProfit_3(prices) << endl;
//     cout << endl
//          << string(35, '-');
//     return 0;
// }
// ----------------------------------------------------------------- 58. Length of Last Word --------------------------------------------------------------
int lengthOfLastWord(string s)
{
    int n = s.size();
    int right = n - 1;
    bool isWordStart = false;
    int lastWordIndex = right;
    while (right >= 0)
    {
        if (s[right] != ' ' && !isWordStart)
        {
            isWordStart = true;
            lastWordIndex = right;
        }
        if (isWordStart && s[right] == ' ')
            break;
        right--;
    }
    return lastWordIndex - right;
}
// --------------------
int lengthOfLastWord2(string s)
{
    int right = s.size() - 1;
    while (right >= 0 && s[right] == ' ')
    {
        right--;
    }
    int wordLength = 0;
    while (right >= 0 && s[right] != ' ')
    {
        wordLength++;
        right--;
    }
    return wordLength;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     string s = "Hello World";
//     cout << lengthOfLastWord(s) << endl;
//     cout << endl
//          << string(35, '-');
//     return 0;
// }
// ---------------------------------------------------------- 122. Best Time to Buy and Sell Stock II -------------------------------------------
long getResult(vector<int> &prices, int index, int buy, int n, vector<vector<long>> &dp)
{
    // Base case: When we reach the end of the array, there are no more decisions to make.
    if (index == n)
    {
        return 0;
    }
    // If the result for this state has already been calculated, return it
    if (dp[index][buy] != -1)
    {
        return dp[index][buy];
    }
    long profit = 0;
    // We can buy the stock
    if (buy == 0)
    {
        long notBuyStock = 0 + getResult(prices, index + 1, 0, n, dp);
        long buyStock = -prices[index] + getResult(prices, index + 1, 1, n, dp);
        profit = max(notBuyStock, buyStock);
    }
    // We can sell the stock
    if (buy == 1)
    {
        long notSellStock = 0 + getResult(prices, index + 1, 1, n, dp);
        long sellStock = prices[index] + getResult(prices, index + 1, 0, n, dp);
        profit = max(notSellStock, sellStock);
    }
    // Store the calculated profit in the DP table and return it
    return dp[index][buy] = profit;
}
int maxProfitMomoization(vector<int> &prices)
{
    int n = prices.size();
    // Create a DP table to memoize results
    vector<vector<long>> dp(n, vector<long>(2, -1));
    if (n == 0)
    {
        return 0;
    }
    long maxProfit = getResult(prices, 0, 0, n, dp);
    return maxProfit;
}
// --------------------
int maxProfitTabulation(vector<int> &prices)
{
    int n = prices.size();
    // Create a DP table to memoize results
    vector<vector<long>> dp(n + 1, vector<long>(2, -1));
    // Base condition: When we have no stocks left, the profit is 0.
    dp[n][0] = dp[n][1] = 0;
    long profit;
    // Loop through the array in reverse order
    for (int index = n - 1; index >= 0; index--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            // We can buy the stock
            if (buy == 0)
            {
                long notBuyStock = 0 + dp[index + 1][0];
                long buyStock = -prices[index] + dp[index + 1][1];
                profit = max(notBuyStock, buyStock);
            }
            // We can sell the stock
            if (buy == 1)
            {
                long notSellStock = 0 + dp[index + 1][1];
                long sellStock = prices[index] + dp[index + 1][0];
                profit = max(notSellStock, sellStock);
            }
            // Store the calculated profit in the DP table and return it
            dp[index][buy] = profit;
        }
    }
    // The maximum profit is stored in dp[0][0] after all calculations
    return dp[0][0];
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     vector<int> prices = {7, 1, 5, 3, 6, 4};
//     cout << maxProfitMomoization(prices) << endl;
//     cout << endl
//          << string(35, '-');
//     return 0;
// }
// ----------------------------------------------------------------------- 55. Jump Game -------------------------------------------------------------------------
// ------- Memoization ---------
bool canJumpHelper(vector<int> &nums, int n, int index, vector<int> &dp)
{
    if (index >= n - 1)
    {
        return true;
    }
    if (nums[index] == 0)
    {
        return 0;
    }
    if (dp[index] != -1)
    {
        return dp[index];
    }
    for (int i = 1; i <= nums[index]; i++)
    {
        bool answer = canJumpHelper(nums, n, index + i, dp);
        if (answer == true)
            return true;
    }
    return dp[index] = false;
}
bool canJump(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, -1);
    if (n == 0)
        return 1;
    return canJumpHelper(nums, n, 0, dp);
}
// ---------------------
bool canJumpOtherWay(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
    {
        return true;
    }
    vector<int> isVisited(n, 0);
    for (int index = 0; index < n; index++)
    {
        if (nums[index] == 0 && isVisited[index + 1] == 0)
        {
            return false;
        }
        for (int i = 0; i <= nums[index] && (index + i) < n; i++)
        {
            isVisited[index + i] = 1;
        }
        if (isVisited[n - 1] == 1)
            break;
    }
    return true;
}
// ------- Valley peak approach --------
bool canJumpValleyPeakApproach(vector<int> &nums)
{
    int n = nums.size();
    int reachable = 0;
    for (int index = 0; index < n; index++)
    {
        if (reachable < index)
            return false;
        reachable = max(reachable, nums[index] + index);
    }
    return true;
}
// ---------------------
bool canJump3(vector<int> &nums)
{
    int targetIndex = nums.size() - 1;
    for (int index = nums.size() - 2; index >= 0; index--)
    {
        if (targetIndex <= nums[index] + index)
        {
            targetIndex = index;
        }
    }
    if (targetIndex == 0)
    {
        return true;
    }
    return false;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     vector<int> nums = {3, 0, 8, 2, 0, 0, 1};
//     cout << canJumpOtherWay(nums) << endl;
//     cout << endl
//          << string(35, '-');
//     return 0;
// }
// --------------------------------------------------------------------- 45. Jump Game II -----------------------------------------------------------------------------
// ------- Valley peak approach --------
int minJumpValleyPeakApproach(vector<int> &nums)
{
    int jumps = 0;
    int currEnd = 0;
    int currFarthest = 0;
    for (int index = 0; index < nums.size() - 1; index++)
    {
        currFarthest = max(currFarthest, nums[index] + index);
        if (index == currEnd)
        {
            jumps++;
            currEnd = currFarthest;
        }
    }
    return jumps;
}
// -------------- TLE ---------------
int minRequiredJump(vector<int> &nums, int index)
{
    if (index >= nums.size() - 1)
    {
        return 0;
    }
    if (nums[index] == 0)
    {
        return INT_MAX;
    }
    int minJumps = INT_MAX;
    for (int i = index + 1; i <= index + nums[index] && i < nums.size(); i++)
    {
        int jumps = minRequiredJump(nums, i);
        if (jumps != INT_MAX && jumps + 1 < minJumps)
        {
            minJumps = jumps + 1;
        }
    }
    return minJumps;
}
int jump(vector<int> &nums)
{
    return minRequiredJump(nums, 0);
}
// ----------------- Memoization -------------------
int minRequiredJumpMemo(vector<int> &nums, int index, vector<int> &dp)
{
    if (index >= nums.size() - 1)
    {
        return 0;
    }
    if (nums[index] == 0)
    {
        return INT_MAX;
    }
    if (dp[index] != -1)
    {
        return dp[index];
    }
    int minJumps = INT_MAX;
    for (int i = index + 1; i <= index + nums[index] && i < nums.size(); i++)
    {
        int jumps = minRequiredJumpMemo(nums, i, dp);
        if (jumps != INT_MAX && jumps + 1 < minJumps)
        {
            minJumps = jumps + 1;
        }
    }
    return dp[index] = minJumps;
}
int jumpMemoization(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, -1);
    return minRequiredJumpMemo(nums, 0, dp);
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     vector<int> nums = {2, 3, 1, 1, 4};
//     cout << jump(nums) << endl;
//     cout << endl
//          << string(35, '-');
//     return 0;
// }
// --------------------------------------------------------------------- 274. H-Index -------------------------------------------------------------------------
int hIndex1(vector<int> &citations)
{
    int n = citations.size();
    int hInd = 0;
    for (int i = 1; i <= n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (citations[j] >= i)
            {
                count++;
            }
        }
        if (count >= i) // (i > hInd) The i will always be greater here so no need to check
        {
            hInd = i;
        }
    }
    return hInd;
}
// ------- Using sort() and binary search ------
int hIndex01(vector<int> &citations)
{
    sort(citations.begin(), citations.end());
    int n = citations.size();
    int left = 0, right = n - 1, mid = 0;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (citations[mid] == (n - mid))
            return citations[mid];
        else if (citations[mid] > (n - mid))
            right = mid - 1;
        else
            left = left + 1;
    }
    return (n - left);
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     vector<int> nums = {3, 0, 6, 1, 5};
//     cout << hIndex(nums) << endl;
//     cout << endl
//          << string(35, '-');
//     return 0;
// }
// ----------------------------------------------------------------------- 275. H-Index II --------------------------------------------------------------------------
int hIndex2(vector<int> &citations)
{
    int n = citations.size();
    int left = 0, right = n - 1, mid = 0;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (citations[mid] == (n - mid))
            return citations[mid];
        else if (citations[mid] > (n - mid))
            right = mid - 1;
        else
            left = mid + 1;
    }
    return n - left;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     vector<int> nums = {0, 1, 3, 5, 6};
//     cout << hIndex(nums) << endl;
//     cout << endl
//          << string(35, '-');
//     return 0;
// }
// ------------------------------------------------------------- 238. Product of Array Except Self -------------------------------------------------------------
vector<int> productExceptSelf(vector<int> &nums)
{
    int n = nums.size();
    vector<int> prefixProduct(n);
    vector<int> suffixProduct(n);
    prefixProduct[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        prefixProduct[i] = nums[i] * prefixProduct[i - 1];
    }
    suffixProduct[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        suffixProduct[i] = nums[i] * suffixProduct[i + 1];
    }
    vector<int> result(n);
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            result[i] = suffixProduct[i + 1];
        }
        else if (i == n - 1)
        {
            result[i] = prefixProduct[n - 2];
        }
        else
        {
            result[i] = prefixProduct[i - 1] * suffixProduct[i + 1];
        }
    }
    return result;
}
// -----------------------------------
vector<int> productExceptSelf2(vector<int> &nums)
{
    int n = nums.size();
    vector<int> suffixProduct(n);
    suffixProduct[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        suffixProduct[i] = nums[i] * suffixProduct[i + 1];
    }
    vector<int> result(n);
    result[0] = suffixProduct[1];
    int prefixProduct = nums[0];
    for (int i = 1; i < n; i++)
    {
        if (i == n - 1)
        {
            result[i] = prefixProduct;
        }
        else
        {
            result[i] = prefixProduct * suffixProduct[i + 1];
        }
        prefixProduct *= nums[i];
    }
    return result;
}
// ------------------------------
vector<int> productExceptSelf3(vector<int> &nums)
{
    int n = nums.size();
    vector<int> leftToRight(n);
    int product = 1;
    for (int i = 0; i < n; i++)
        leftToRight[i] = (product *= nums[i]);
    product = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (i == n - 1)
        {
            leftToRight[i] = leftToRight[n - 2];
            product *= nums[i];
        }
        else if (i == 0)
            leftToRight[i] = product;
        else
        {
            leftToRight[i] = leftToRight[i - 1] * product;
            product *= nums[i];
        }
    }
    return leftToRight;
}
// ------------------------------
vector<int> productExceptSelf4(vector<int> &nums)
{
    int n = nums.size();
    vector<int> suffixProduct(n);
    suffixProduct[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        suffixProduct[i] = nums[i] * suffixProduct[i + 1];
    }
    int product = 1;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            suffixProduct[i] = suffixProduct[i + 1];
            product *= nums[i];
        }
        else if (i == n - 1)
        {
            suffixProduct[i] = product;
        }
        else
        {
            suffixProduct[i] = product * suffixProduct[i + 1];
            product *= nums[i];
        }
    }
    return suffixProduct;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     vector<int> nums = {1, 2, 3, 4};
//     vector<int> product = productExceptSelf4(nums);
//     for (auto item : product)
//         cout << item << " ";
//     cout << endl
//          << string(35, '-');
//     return 0;
// }
// --------------------------------------------------------------------- 380. Insert Delete GetRandom O(1) ----------------------------------------------------------
class RandomizedSet
{
    // Average Time O(1) & Auxiliary Space O(N)
public:
    vector<int> nums;             // array vector
    unordered_map<int, int> umap; // // Unordered Map does searching, insertion & deletion of element in average O(1) time
    /** Initialize your data structure here. */
    RandomizedSet()
    {
        // No need to initialise nums & umap as they are initialised automatically
        // to 0 as and when their container size increases.
    }
    /** Inserts a value to the array vector. Returns true if the array did not already contain the specified element. */
    bool insert(int val)
    {
        if (umap.find(val) != umap.end())
        {
            // If val is not already present in the map, find() function
            // returns an iterator(m.end()) pointing to the successive memory location
            // from the last element of the map. Otherwise, find() returns an iterator
            // pointing to val which was already present in the map.
            return false;
        }
        else
        {
            nums.push_back(val);         // insert val at the end of the array
            umap[val] = nums.size() - 1; // unordered_map[key]=value stores the array element and
                                         // its index as key=array element & value=array element index
            return true;
        }
    }
    /** Removes a value from the array vector. Returns true if the array contained the specified element. */
    bool remove(int val)
    {
        if (umap.find(val) == umap.end()) // val not present in the array vector
            return false;
        else
        {
            // val present in the array vector
            // For example: a=[8,4,3,2], m={[8,0],[4,1],[3,2],[2,3]}, val=4, lastValue=2
            // After a[m[val]]=a.back(); a=[8,2,3,2], m={[8,0],[4,1],[3,2],[2,3]}
            // After a.pop_back(); a=[8,2,3], m={[8,0],[4,1],[3,2],[2,3]}
            // After m[last]=m[val]; a=[8,2,3], m={[8,0],[4,1],[3,2],[2,1]}
            // After m.erase(val); a=[8,2,3], m={[8,0],[3,2],[2,1]}
            int lastValue = nums.back(); // back() fetches last element of the array vector
            nums[umap[val]] = lastValue; // m[val] locates the index of val in the array vector.
                                         // Then we copy array last element value to the val location in the array

            nums.pop_back();             // Delete the last element of the array
            umap[lastValue] = umap[val]; // In hashmap, assign index of val in array to the index of the last element
            umap.erase(val);             // Delete the val entry from map
            return true;
        }
    }
    /** Get a random element from the array vector */
    int getRandom()
    {
        // rand() function gives random value in the range of 0 to RAND_MAX(whose value is 32767). x%y gives
        // remainder when x is divided by y and this remainder is in the range of 0 to y-1.
        // rand()%a.size() gives random value in the range of (0 to a.size()-1).
        // a[rand()%a.size()] will give random value of array in the range of a[0] to a[a.size()-1].
        return nums[rand() % nums.size()];
    }
};

// int main()
// {
//     cout << string(35, '-') << endl;
//     cout << rand();
//     cout << endl
//          << string(35, '-');
//     return 0;
// }
// --------------------------------------------------------------------- 134. Gas Station -------------------------------------------------------------------------
int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int n = gas.size();
    int current = 0;
    int total_fuel = 0;
    int total_cost = 0;
    int startGasStatition = 0;
    for (int i = 0; i < n; i++)
    {
        total_fuel += gas[i];
        total_cost += cost[i];
    }
    if (total_fuel < total_cost)
    {
        return -1;
    }
    for (int i = 0; i < n; i++)
    {
        current += gas[i] - cost[i];
        if (current < 0)
        {
            startGasStatition = i + 1;
            current = 0;
        }
    }
    return startGasStatition;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     vector<int> gas = {1, 2, 3, 4, 5};
//     vector<int> cost = {3, 4, 5, 1, 2};
//     cout << canCompleteCircuit(gas, cost) << endl;
//     cout << endl
//          << string(35, '-');
//     return 0;
// }
// --------------------------------------------------------------------- 42. Trapping Rain Water -------------------------------------------------------------------------
int trap(vector<int> &height)
{
    vector<vector<int>> tracker;
    int max_left = height[0], max_right = height[height.size() - 1];
    for (int index = 0; index < height.size(); index++)
    {
        if (index > 0)
            max_left = max(height.at(index), max_left);
        tracker.push_back({max_left, height.at(index), 0});
    }
    for (int index = height.size() - 1; index >= 0; index--)
    {
        if (index < height.size() - 1)
            max_right = max(height.at(index), max_right);
        tracker.at(index)[2] = max_right;
    }
    int maxWaterTrap = 0;
    for (int index = 0; index < tracker.size(); index++)
    {
        int maxWaterFilled = min(tracker.at(index)[0], tracker.at(index)[2]);
        int waterTrapForSingleBar = maxWaterFilled - tracker.at(index)[1];
        maxWaterTrap += (waterTrapForSingleBar <= 0) ? 0 : waterTrapForSingleBar;
    }
    return maxWaterTrap;
}
// ------------------------
int trap2(vector<int> &height)
{
    int n = height.size();
    int waterTrapped = 0;
    int prefix[n], suffix[n];
    prefix[0] = height[0];
    for (int index = 1; index < n; index++)
    {
        prefix[index] = max(prefix[index - 1], height[index]);
    }
    suffix[n - 1] = height[n - 1];
    for (int index = n - 2; index >= 0; index--)
    {
        suffix[index] = max(suffix[index + 1], height[index]);
    }
    for (int index = 0; index < n; index++)
    {
        waterTrapped += min(prefix[index], suffix[index]) - height[index];
    }
    return waterTrapped;
}
// ---------------
int trap3(vector<int> &height)
{
    int n = height.size();
    int waterTrapped = 0;
    int leftPointer = 0, rightPointer = n - 1;
    int leftMax = 0, rightMax = 0;
    while (leftPointer <= rightPointer)
    {
        if (height[leftPointer] <= height[rightPointer])
        {
            if (leftMax <= height[leftPointer])
                leftMax = height[leftPointer];
            else
                waterTrapped += leftMax - height[leftPointer];
            leftPointer++;
        }
        else
        {
            if (rightMax <= height[rightPointer])
                rightMax = height[rightPointer];
            else
                waterTrapped += rightMax - height[rightPointer];
            rightPointer--;
        }
    }
    return waterTrapped;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
//     cout << trap(height) << endl;
//     cout << endl
//          << string(35, '-');
//     return 0;
// }
// ------------------------------------------------------------------------- 13. Roman to Integer ----------------------------------------------------------------------------
int romanToInt(string s)
{
    int n = s.size();
    map<char, int> mp;
    mp.insert(make_pair('I', 1));
    mp.insert(make_pair('V', 5));
    mp.insert(pair<char, int>('X', 10));
    mp.insert(pair<char, int>('L', 50));
    mp.insert({'C', 100});
    mp.insert({'D', 500});
    mp.insert({'M', 1000});
    int integerValue = 0;
    int i = 0;
    while (i < n)
    {
        if (mp[s[i]] < mp[s[i + 1]] && i < n - 1)
        {
            integerValue += mp[s[i + 1]] - mp[s[i]];
            i += 2;
        }
        else
        {
            integerValue += mp[s[i]];
            i += 1;
        }
    }
    return integerValue;
}
// -----------------
int romanToInt2(string s)
{
    int roman2Int[26] = {0};
    roman2Int['I' - 65] = 1;
    roman2Int['V' - 65] = 5;
    roman2Int['X' - 65] = 10;
    roman2Int['L' - 65] = 50;
    roman2Int['C' - 65] = 100;
    roman2Int['D' - 65] = 500;
    roman2Int['M' - 65] = 1000;
    int result = 0;
    for (int i = 0; i < s.size(); i++)
    {
        // Roman numerals are usually written largest to smallest from left to right.
        if ((i + 1) < s.size() && roman2Int[s[i] - 65] < roman2Int[s[i + 1] - 65])
        {
            result += roman2Int[s[i + 1] - 65] - roman2Int[s[i] - 65];
            i++;
        }
        else
            result += roman2Int[s[i] - 65];
    }
    return result;
}
// ----------------
int romanToInt3(string s)
{
    int roman2Int[26] = {0};
    roman2Int['I' - 65] = 1;
    roman2Int['V' - 65] = 5;
    roman2Int['X' - 65] = 10;
    roman2Int['L' - 65] = 50;
    roman2Int['C' - 65] = 100;
    roman2Int['D' - 65] = 500;
    roman2Int['M' - 65] = 1000;
    int result = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'I' && (i + 1) < s.size() && ((s[i + 1] == 'V') || (s[i + 1] == 'X')))
        {
            result += roman2Int[s[i + 1] - 65] - roman2Int[s[i] - 65];
            i++;
        }
        else if (s[i] == 'X' && (i + 1) < s.size() && ((s[i + 1] == 'L') || (s[i + 1] == 'C')))
        {
            result += roman2Int[s[i + 1] - 65] - roman2Int[s[i] - 65];
            i++;
        }
        else if (s[i] == 'C' && (i + 1) < s.size() && ((s[i + 1] == 'D') || (s[i + 1] == 'M')))
        {
            result += roman2Int[s[i + 1] - 65] - roman2Int[s[i] - 65];
            i++;
        }
        else
            result += roman2Int[s[i] - 65];
    }
    return result;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     string s = "III";
//     cout << romanToInt(s) << endl;
//     cout << endl
//          << string(35, '-');
//     return 0;
// }
// ------------------------------------------------------------------------- 135. Candy ---------------------------------------------------------------------------
int candy(vector<int> &ratings)
{
    int n = ratings.size();
    if (n == 1)
        return 1;
    int candies[n];
    for (int i = 0; i < n; i++)
        candies[i] = 1;
    for (int i = 1; i < n; i++)
    {
        if (ratings[i] > ratings[i - 1] && candies[i] <= candies[i - 1])
            candies[i] = candies[i - 1] + 1;
    }
    for (int i = n - 2; i >= 0; i--)
    {
        if (ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1])
            candies[i] = candies[i + 1] + 1;
    }
    int totalCandies = 0;
    for (int i = 0; i < n; i++)
        totalCandies += candies[i];
    return totalCandies;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     // vector<int> ratings = {1, 0, 2};
//     // vector<int> ratings = {1, 2, 2};
//     vector<int> ratings = {1, 2, 87, 87, 87, 2, 1};
//     cout << candy(ratings) << endl;
//     cout << endl
//          << string(35, '-');
//     return 0;
// }
// ----------------------------------------------------------------------- 151. Reverse Words in a String ------------------------------------------------------------
string reverseWords(string s)
{
    int n = s.size();
    string word;
    string reverseWordsString;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != ' ')
        {
            word += s[i];
        }
        if ((s[i] == ' ' && !word.empty()) || (i == n - 1 && !word.empty()))
        {
            if (reverseWordsString.empty())
                reverseWordsString = word;
            else
                reverseWordsString = word + ' ' + reverseWordsString;
            word.clear();
        }
    }
    // -----------------------------------------------------
    // if (!word.empty())
    // {
    //     if (reverseWordsString.empty())
    //         reverseWordsString = word;
    //     else
    //         reverseWordsString = word + ' ' + reverseWordsString;
    // }
    // -----------------------------------------------------
    return reverseWordsString;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     // string s = "the sky is blue";
//     // string s = "  hello world  ";
//     string s = "  hello world  ";
//     cout << reverseWords(s) << endl;
//     cout << endl
//          << string(35, '-');
//     return 0;
// }
// ----------------------------------------------------------------------- 6. Zigzag Conversion ------------------------------------------------------------
string convert(string s, int numRows)
{
    int n = s.size();
    vector<vector<char>> matrix(numRows, vector<char>(n, '@'));
    int i = 0, j = 0;
    int index = 0;
    while (index < n)
    {
        int flag = 0;
        for (i = 0; i < numRows; i++)
        {
            matrix[i][j] = s[index++];
            if (index >= n)
            {
                flag = 1;
                break;
            }
        }
        if (flag)
            break;
        for (i = numRows - 2; i > 0; i--)
        {
            matrix[i][++j] = s[index++];
            if (index >= n)
            {
                flag = 1;
                break;
            }
        }
        if (flag)
            break;
        ++j;
    }
    string result;
    for (i = 0; i < numRows; i++)
    {
        for (int k = 0; k <= j; k++)
        {
            if (matrix[i][k] != '@')
                result += matrix[i][k];
        }
    }
    return result;
}
// -------------------------------------
string convert2(string s, int numRows)
{
    if (numRows == 1)
        return s;
    int n = s.size();
    string result;
    for (int row = 0; row < numRows; row++)
    {
        int increment = 2 * (numRows - 1);
        for (int i = row; i < n; i += increment)
        {
            result += s[i];
            if (row > 0 && row < numRows - 1 && (i + increment - 2 * row) < n)
                result += s[i + increment - 2 * row];
        }
    }
    return result;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     string s = "PAYPALISHIRING";
//     cout << convert2(s, 4) << endl;
//     cout << endl
//          << string(35, '-');
//     return 0;
// }
// --------------------------------------------------------- 28. Find the Index of the First Occurrence in a String --------------------------------------------------
int strStr(string haystack, string needle)
{
    int m = haystack.size();
    int n = needle.size();
    int wordLastIndex = n - 1;
    int wordIndex = 0;
    int startingIndex = 0;
    bool isStartingSelected = false;
    if (n > m)
        return -1;
    int i = 0;
    while (i < m)
    {
        if (haystack[i] == needle[wordIndex])
        {
            if (!isStartingSelected)
            {
                isStartingSelected = true;
                startingIndex = i;
            }
            wordIndex++;
            i++;
        }
        else
        {
            i = startingIndex + 1;
            startingIndex = i;
            wordIndex = 0;
            isStartingSelected = false;
        }
        if (wordIndex == n)
            break;
    }
    return wordIndex == n ? startingIndex : -1;
}
// -----------------------
int strStr2(string haystack, string needle)
{
    int m = haystack.size();
    int n = needle.size();
    if (n > m)
        return -1;
    int wordIndex = 0;
    int i = 0;
    while (i < m)
    {
        if (haystack[i] == needle[wordIndex])
        {
            int startingIndex = i;
            int wordLastIndex = n - 1;
            while (true)
            {
                if ((startingIndex + n - 1 - wordIndex) < m)
                {
                    if (haystack[i] == needle[wordIndex] && haystack[startingIndex + n - 1 - wordIndex] == needle[wordLastIndex - wordIndex])
                    {
                        i++;
                        wordIndex++;
                    }
                    else
                    {
                        i = startingIndex + 1;
                        wordIndex = 0;
                        break;
                    }
                    if (wordIndex > (n / 2))
                        return startingIndex;
                }
                else
                {
                    return -1;
                }
            }
        }
        else
            i++;
    }
    return -1;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     string haystack = "babba";
//     string needle = "bbb";
//     cout << strStr2(haystack, needle) << endl;
//     cout << endl
//          << string(35, '-');
//     return 0;
// }
// ------------ KMP Algorithm -----------
class Solution
{
public:
    void calculateLongestPrefixSuffix(string &needle, int m, vector<int> &lps)
    {
        int left = 0, right = 1;
        while (right < m)
        {
            // If Right-th char matches with Left-th char
            if (needle[left] == needle[right])
            {
                lps[right] = left + 1;
                left++;
                right++;
            }
            else
            {
                if (left > 0)
                    left = lps[left - 1];
                else
                    right++;
            }
        }
    }
    int patternMatcher(string &haystack, int n, string &needle, int m, vector<int> &lps)
    {
        int haystack_pos = 0;
        int needle_pos = 0;
        while (needle_pos < m && haystack_pos < n)
        {
            // If current char in pattern & text both match
            if (haystack[haystack_pos] == needle[needle_pos])
            {
                haystack_pos++;
                needle_pos++;
            }
            // Check if the pattern has been found
            if (needle_pos == m)
                return haystack_pos - m; // return starting pos of pattern
            if (haystack[haystack_pos] != needle[needle_pos])
            {
                if (needle_pos > 0)
                    needle_pos = lps[needle_pos - 1];
                else
                    haystack_pos++;
            }
        }
        return -1;
    }
    int strStr(string haystack, string needle)
    {
        int n = haystack.size();
        int m = needle.size();
        if (m > n)
            return -1;
        vector<int> lps(m, 0); // longest prefix suffix
        calculateLongestPrefixSuffix(needle, m, lps);
        return patternMatcher(haystack, n, needle, m, lps);
    }
};
// ------------------------------------------
int strStr3(string haystack, string needle)
{
    int m = haystack.size();
    int n = needle.size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (haystack[i + j] != needle[j])
                break;
            if (j == n - 1)
                return i;
        }
    }
    return -1;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     Solution *sol = new Solution();
//     cout << sol->strStr("abxabcabcaby", "abcaby") << endl;
//     cout << endl
//          << string(35, '-');
//     return 0;
// }
// ------------------------------------------------------------------------ 125. Valid Palindrome -----------------------------------------------------------------
bool isPalindrome(string s)
{
    int n = s.size();
    string str;
    for (int i = 0; i < n; i++)
    {
        if ((s[i] >= 97 && s[i] <= 122) || (s[i] >= 48 && s[i] <= 57))
        {
            str += s[i];
        }
        if ((s[i] >= 65 && s[i] <= 90))
        {
            str += (s[i]) + 32;
        }
    }
    int left = 0, right = str.size() - 1;
    while (left < right)
    {
        if (str[left] != str[right])
            return false;
        left++;
        right--;
    }
    return true;
}
// -----------------------------------
bool isPalindrome2(string s)
{
    int n = s.size();
    int left = 0, right = n - 1;
    while (left <= right)
    {
        if (s[left] >= 65 && s[left] <= 90)
        {
            s[left] = s[left] + 32;
        }
        if (s[right] >= 65 && s[right] <= 90)
        {
            s[right] = s[right] + 32;
        }
        left++;
        right--;
    }
    left = 0, right = n - 1;
    while (left < right)
    {
        if (!((s[left] >= 97 && s[left] <= 122) || (s[left] >= 48 && s[left] <= 57)))
        {
            left++;
        }
        else if (!((s[right] >= 97 && s[right] <= 122) || (s[right] >= 48 && s[right] <= 57)))
        {
            right--;
        }
        else if (s[left] != s[right])
        {
            return false;
        }
        else
        {
            left++;
            right--;
        }
    }
    return true;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     // string s = "A man, a plan, a canal: Panama";
//     // string s = "race a car";
//     // string s = " ";
//     string s = "0P";
//     cout << isPalindrome2(s) << endl;
//     cout << endl
//          << string(35, '-');
//     return 0;
// }
// ----------------------------------------------------------------------- 392. Is Subsequence ----------------------------------------------------------------
bool isSubsequence(string s, string t)
{
    int m = s.size();
    int n = t.size();
    if (m > n)
        return false;
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (t[i] == s[j])
            j++;
        if (j == m)
            return true;
    }
    return j == m ? true : false;
}
// ---------------------
bool isSubsequence2(string s, string t)
{
    int m = s.size();
    int n = t.size();
    if (m > n)
        return false;
    int left = 0, right = n - 1;
    int i = 0, j = m - 1;
    while (left <= right && i <= j)
    {
        if (t[left] == s[i])
        {
            left++;
            i++;
        }
        else
        {
            left++;
        }
        if (left > right && i <= j)
            return false;
        if (t[right] == s[j])
        {
            j--;
            right--;
        }
        else
        {
            right--;
        }
    }
    return i > j ? true : false;
}
// ------------------------
bool isSubs(string &s, string &t, int m, int n)
{
    if (m == 0)
        return true;
    if (n == 0)
        return false;
    // If last characters of two strings are matching
    if (s[m - 1] == t[n - 1])
        return isSubs(s, t, m - 1, n - 1);
    // If last characters are not matching
    return isSubs(s, t, m, n - 1);
}
bool isSubsequence3(string s, string t)
{
    if (isSubs(s, t, s.size(), t.size()))
        return true;
    return false;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     cout << isSubsequence2("abbc", "ahbdc") << endl;
//     cout << endl
//          << string(35, '-');
//     return 0;
// }
// ----------------------------------------------------------- 167. Two Sum II - Input Array Is Sorted -----------------------------------------------------------
vector<int> twoSum(vector<int> &numbers, int target)
{
    int n = numbers.size();
    int left = 0, right = n - 1;
    while (left < right)
    {
        int sum = numbers[left] + numbers[right];
        if (sum == target)
            break;
        else if (sum > target)
            right--;
        else
            left++;
    }
    return {left + 1, right + 1};
}
// ----------------------
vector<int> twoSum2(vector<int> &numbers, int target)
{
    int n = numbers.size();
    unordered_map<int, int> umap;
    umap[numbers[0]] = 1;
    for (int i = 1; i < n; i++)
    {
        int difference = target - numbers[i];
        if (umap.find(difference) != umap.end())
            return {umap[difference], i + 1};
        else
            umap[numbers[i]] = i + 1;
    }
    return {};
}
// ------------------------
vector<int> twoSum3(vector<int> &numbers, int target)
{
    int left = 0, right = numbers.size() - 1;
    while (numbers[left] + numbers[right] != target)
    {
        if (numbers[left] + numbers[right] < target)
            left++;
        else
            right--;
    }

    return {left + 1, right + 1};
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     vector<int> numbers = {-1, 0};
//     vector<int> result = twoSum2(numbers, -1);
//     cout << result[0] << " " << result[1] << endl;
//     cout << string(35, '-');
//     return 0;
// }
// ------------------------------------------------------------- 11. Container With Most Water ------------------------------------------------------------------
// ------------- TLE -------------
int maxArea(vector<int> &height)
{
    int maxAmountWater = 0;
    for (int leftPointer = 0; leftPointer < height.size(); leftPointer)
    {
        for (int rightPointer = leftPointer + 1; rightPointer < height.size(); rightPointer++)
        {
            int maxWaterCanFillBetween = min(height[leftPointer], height[rightPointer]);
            int currMaxWater = (rightPointer - leftPointer) * maxWaterCanFillBetween;
            maxAmountWater = max(maxAmountWater, currMaxWater);
        }
    }
    return maxAmountWater;
}
// --------------------
int maxArea2(vector<int> &height)
{
    int n = height.size();
    int mostWaterLevel = 0;
    int left = 0, right = n - 1;
    while (left < right)
    {
        int maxWaterCanFillBetween = min(height[left], height[right]);
        int currMaxWater = (right - left) * maxWaterCanFillBetween;
        mostWaterLevel = max(mostWaterLevel, currMaxWater);
        if (height[left] < height[right])
            left++;
        else
            right--;
    }
    return mostWaterLevel;
}
// --------------------
int maxArea3(vector<int> &height)
{
    int n = height.size();
    int mostWaterLevel = 0;
    int left = 0, right = n - 1;
    while (left < right)
    {
        int maxWaterCanFillBetween = min(height[left], height[right]);
        int currMaxWater = (right - left) * maxWaterCanFillBetween;
        mostWaterLevel = max(mostWaterLevel, currMaxWater);
        while (height[left] <= maxWaterCanFillBetween && left < right)
            left++;
        while (height[right] <= maxWaterCanFillBetween && left < right)
            right--;
    }
    return mostWaterLevel;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     cout << string(35, '-');
//     return 0;
// }
// ------------------------------------------------------------------------ 15. 3Sum ----------------------------------------------------------------------
// --------- TUF Solution ---------
vector<vector<int>> threeSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end()); // Sorted Array
    if (nums.size() < 3)
    { // Base case 1
        return {};
    }
    if (nums[0] > 0)
    { // Base case 2
        return {};
    }
    vector<vector<int>> answer;
    for (int i = 0; i < nums.size(); ++i)
    { // Traversing the array to fix the number.
        if (nums[i] > 0)
        { // If number fixed is +ve, stop there because we can't make it zero by searching after it.
            break;
        }
        if (i > 0 && nums[i] == nums[i - 1])
        { // If number is getting repeated, ignore the lower loop and continue.
            continue;
        }
        int low = i + 1, high = nums.size() - 1; // Make two pointers high and low, and initialize sum as 0.
        int sum = 0;
        while (low < high)
        { // Search between two pointers, just similiar to binary search.
            sum = nums[i] + nums[low] + nums[high];
            if (sum > 0)
            { // If sum is +ve, means, we need more -ve numbers to make it 0, decreament high (high--).
                high--;
            }
            else if (sum < 0)
            { // If sum is -ve, means, we need more +ve numbers to make it 0, increament low (low++).
                low++;
            }
            else
            {
                answer.push_back({nums[i], nums[low], nums[high]});                   // we have found the required triplet, push it in answer vector
                int last_low_occurence = nums[low], last_high_occurence = nums[high]; // Now again, to avoid duplicate triplets, we have to navigate to last occurences of num[low] and num[high] respectively
                while (low < high && nums[low] == last_low_occurence)
                { // Update the low and high with last occurences of low and high.
                    low++;
                }
                while (low < high && nums[high] == last_high_occurence)
                {
                    high--;
                }
            }
        }
    }
    return answer; // Return the answer vector.
}
// ---------------------
vector<vector<int>> threeSum2(vector<int> &nums)
{
    sort(nums.begin(), nums.end()); // Sorted Array
    if (nums.size() < 3)
    { // Base Case 1
        return {};
    }
    if (nums[0] > 0)
    { // Base Case 2
        return {};
    }
    unordered_map<int, int> hashMap;
    for (int i = 0; i < nums.size(); ++i)
    { // Hashing of Indices
        hashMap[nums[i]] = i;
    }
    vector<vector<int>> answer;
    for (int i = 0; i < nums.size() - 2; ++i)
    { // Traversing the array to fix the number.
        if (nums[i] > 0)
        { // If number fixed is +ve, stop there because we can't make it zero by searching after it.
            break;
        }
        for (int j = i + 1; j < nums.size() - 1; ++j)
        {                                            // Fixing another number after first number
            int required = -1 * (nums[i] + nums[j]); // To make sum 0, we would require the -ve sum of both fixed numbers.
            if (hashMap.count(required) && hashMap.find(required)->second > j)
            { // If it exists in hashmap and its last occurrence index > 2nd fixed index, we found our triplet.
                answer.push_back({nums[i], nums[j], required});
            }
            j = hashMap.find(nums[j])->second; // Update j to last occurence of 2nd fixed number to avoid duplicate triplets.
        }
        i = hashMap.find(nums[i])->second; // Update i to last occurence of 1st fixed number to avoid duplicate triplets.
    }
    return answer; // Return answer vector.
}
// ------- TLE --------
vector<vector<int>> threeSum_TUF(vector<int> &nums)
{
    int n = nums.size();
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        set<int> hashset;
        for (int j = i + 1; j < n; j++)
        {
            // Calculate the 3rd element:
            int third = -(nums[i] + nums[j]);
            // Find the element in the set:
            if (hashset.find(third) != hashset.end())
            {
                vector<int> temp = {nums[i], nums[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(nums[j]);
        }
    }
    // store the set in the answer:
    vector<vector<int>> result(st.begin(), st.end());
    return result;
}
// ----------------
vector<vector<int>> threeSum_TUF_OtherWay(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {
        // remove duplicates:
        if (i != 0 && nums[i] == nums[i - 1])
            continue;
        // moving 2 pointers:
        int j = i + 1;
        int k = n - 1;
        while (j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum < 0)
                j++;
            else if (sum > 0)
                k--;
            else
            {
                result.push_back({nums[i], nums[j], nums[k]});
                j++;
                k--;
                // skip the duplicates:
                while (j < k && nums[j] == nums[j - 1])
                    j++;
                while (j < k && nums[k] == nums[k + 1])
                    k--;
            }
        }
    }
    return result;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     cout << string(35, '-');
//     return 0;
// }
// -------------------------------------------------------- ORACLE TEST - Count of substrings having all distinct characters -----------------------------------------------------
int countSubstrings(string str)
{
    int n = str.size();
    long long int result = 0;
    int counter[26] = {0};
    memset(counter, 0, sizeof(counter));
    int i = 0;
    int j = 0;
    while (j < n)
    {
        if (j < n && (counter[str[j] - 'a'] == 0))
        {
            counter[str[j] - 'a']++;
            result += (j - i + 1);
            j++;
        }
        else
        {
            counter[str[i] - 'a']--;
            i++;
        }
    }
    return result;
}
// ------------
int countSubstrings2(string str)
{
    int n = str.size();
    int count = 0;
    unordered_set<char> charSet;
    int left = 0;
    int right = 0;
    while (right < n)
    {
        // If the character at right is not in the set, add it and expand the window
        if (charSet.find(str[right]) == charSet.end())
        {
            charSet.insert(str[right]);
            count += (right - left + 1);
            right++;
        }
        // If the character at right is a duplicate, shrink the window from the left
        else
        {
            charSet.erase(str[left]);
            left++;
        }
    }
    return count;
}
// ------------
int countSubstrings3(string str)
{
    int n = str.size();
    if (n == 0)
        return 0;
    unordered_map<char, int> lastIndexMap;
    int left = 0;
    int count = 0;
    for (int right = 0; right < n; right++)
    {
        if (lastIndexMap.find(str[right]) != lastIndexMap.end() && lastIndexMap[str[right]] >= left)
        {
            left = lastIndexMap[str[right]] + 1;
        }
        lastIndexMap[str[right]] = right;
        count += (right - left + 1);
    }
    return count;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     // string str = "abac";
//     string str = "gffg";
//     cout << countSubstrings3(str) << endl;
//     cout << string(35, '-');
//     return 0;
// }
// ---------------------------------------------------------------- 209. Minimum Size Subarray Sum -------------------------------------------------------------
int minSubArrayLen(int target, vector<int> &nums)
{
    int n = nums.size();
    int sum = 0;
    int right = 0;
    while (right < n)
    {
        sum += nums[right++];
        if (sum >= target)
            break;
    }
    if (sum < target)
        return 0;
    int left = 0;
    while (left < n)
    {
        if ((sum - nums[left]) < target)
            break;
        sum -= nums[left++];
    }
    int minLength = right - left;
    while (right < n)
    {
        sum += nums[right++];
        while (left < n)
        {
            if ((sum - nums[left]) < target)
                break;
            sum -= nums[left++];
            minLength = min((right - left), minLength);
        }
    }
    return minLength;
}
// ------------
int minSubArrayLen2(int target, vector<int> &nums)
{
    int n = nums.size();
    int sum = 0;
    int left = 0;
    int minSubArrayLength = INT_MAX;
    for (int right = 0; right < n; right++)
    {
        sum += nums[right];
        while (left < n && (sum - nums[left]) >= target)
        {
            sum -= nums[left];
            left++;
        }
        // [1,2,3,4,5] -> target = 15
        if (sum >= target)
            minSubArrayLength = min((right - left) + 1, minSubArrayLength);
    }
    return minSubArrayLength == INT_MAX ? 0 : minSubArrayLength;
}
// ------------
int minSubArrayLen3(int target, vector<int> &nums)
{
    int n = nums.size();
    int left = 0;
    int sum = 0;
    int minLengthSubArray = INT_MAX;
    for (int right = 0; right < n; right++)
    {
        sum += nums[right];
        while (sum >= target)
        {
            minLengthSubArray = min((right - left) + 1, minLengthSubArray);
            sum -= nums[left];
            left++;
        }
    }
    return minLengthSubArray == INT_MAX ? 0 : minLengthSubArray;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     vector<int> nums = {5, 1, 3, 5, 10, 7, 4, 9, 2, 8};
//     cout << minSubArrayLen3(15, nums) << endl;
//     cout << string(35, '-');
//     return 0;
// }
// ---------------------------------------------------------- 3. Longest Substring Without Repeating Characters -----------------------------------------------------------
int lengthOfLongestSubstring(string s)
{
    int n = s.size();
    int maxLength = 0;
    unordered_map<char, int> charMap;
    int left = 0;
    int right = 0;
    for (right; right < n; right++)
    {
        if (charMap[s[right]] == 1)
        {
            maxLength = max((right - left), maxLength);
            while (s[left] != s[right])
            {
                charMap[s[left]] = 0;
                left++;
            }
            charMap[s[left]] = 0;
            left++;
        }
        charMap[s[right]] = 1;
    }
    maxLength = max((right - left), maxLength);
    return maxLength;
}
// -------------------------
int lengthOfLongestSubstring2(string s)
{
    int n = s.size();
    unordered_set<char> charSet;
    int maxLength = 0;
    int left = 0;
    int right = 0;
    for (right; right < n; right++)
    {
        if (charSet.find(s[right]) != charSet.end())
        {
            maxLength = max((right - left), maxLength);
            while (s[left] != s[right])
            {
                charSet.erase(s[left]);
                left++;
            }
            charSet.erase(s[left]);
            left++;
        }
        charSet.insert(s[right]);
    }
    maxLength = max((right - left), maxLength);
    return maxLength;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     string s = "abcabcbb";
//     cout << lengthOfLongestSubstring2(s) << endl;
//     cout << string(35, '-');
//     return 0;
// }
// ------------------------------------------------------------------ 76. Minimum Window Substring ---------------------------------------------------------------------
// ------------- WRONG -----------
// string minWindow(string s, string t)
// {
//     int m = s.size();
//     int n = t.size();
//     if (n > m)
//         return "";
//     unordered_map<char, int> tMap;
//     for (int i = 0; i < n; i++)
//         tMap[t[i]]++;
//     string minWindowString = "";
//     for (int i = 0; i < m; i++)
//     {
//         int j = i;
//         unordered_map<char, int> sMap;
//         string currWindowString = "";
//         while (j < m)
//         {
//             if (tMap.find(s[j]) != tMap.end())
//             {
//                 sMap[s[j]]++;
//             }
//             j++;
//             int k = 0;
//             for (k; k < n; k++)
//             {
//                 if (sMap[t[k]] < tMap[t[k]])
//                     break;
//             }
//             if (k == n)
//             {
//                 currWindowString = s.substr(i, (j - i) + 1);
//                 if (minWindowString == "")
//                     minWindowString = currWindowString;
//                 else
//                     minWindowString = (minWindowString.size() > currWindowString.size()) ? currWindowString : minWindowString;
//                 break;
//             }
//         }
//     }
//     return (minWindowString == "") ? "" : minWindowString;
// }
// ------------------

string minWindow(string s, string t)
{
    if (t == "")
        return "";
    unordered_map<char, int> reqCount;
    unordered_map<char, int> window;
    for (int i = 0; i < t.size(); i++)
        reqCount[t.at(i)]++;
    int required = reqCount.size();
    int current = 0;
    int resLen = INT_MAX;
    int left = 0;
    vector<int> res = {-1, -1};
    for (int right = 0; right < s.size(); right++)
    {
        char c = s.at(right);
        if (reqCount[c])
            window[c]++;
        if (reqCount[c] && reqCount[c] == window[c])
            current++;
        while (current == required)
        {
            if (right - left + 1 < resLen)
            {
                res = {left, right};
                resLen = right - left + 1;
            }
            char c = s.at(left);
            if (reqCount[c] > 0)
                window[c]--;
            if (reqCount[c] && window[c] < reqCount[c])
                current--;
            left++;
        }
    }
    int leftIndex = res.at(0);
    return resLen != INT_MAX ? s.substr(leftIndex, resLen) : "";
}

// int main()
// {
//     cout << string(35, '-') << endl;
//     // string s = "ADOBECODEBANC";
//     // string t = "ABC";
//     string s = "DDDAAABBCA";
//     string t = "ABC";
//     cout << minWindow(s, t) << endl;
//     cout << string(35, '-');
//     return 0;
// }
// --------------------------------------------------------------------- 36. Valid Sudoku --------------------------------------------------------------------------
bool isMatrixValid(vector<vector<char>> &board, int index)
{
    unordered_set<char> matrixValidate;
    for (int i = index; i < index + 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            char ch = board[i][j];
            if (ch == '.')
                continue;
            if (matrixValidate.find(ch) == matrixValidate.end())
                matrixValidate.insert(ch);
            else
                return false;
        }
    }
    matrixValidate.clear();
    for (int i = index; i < index + 3; i++)
    {
        for (int j = 3; j < 6; j++)
        {
            char ch = board[i][j];
            if (ch == '.')
                continue;
            if (matrixValidate.find(ch) == matrixValidate.end())
                matrixValidate.insert(ch);
            else
                return false;
        }
    }
    matrixValidate.clear();
    for (int i = index; i < index + 3; i++)
    {
        for (int j = 6; j < 9; j++)
        {
            char ch = board[i][j];
            if (ch == '.')
                continue;
            if (matrixValidate.find(ch) == matrixValidate.end())
                matrixValidate.insert(ch);
            else
                return false;
        }
    }
    return true;
}
bool isValidSudoku(vector<vector<char>> &board)
{
    for (int i = 0; i < 9; i++)
    {
        unordered_set<char> rowValidate;
        for (int j = 0; j < 9; j++)
        {
            char ch = board[i][j];
            if (ch == '.')
                continue;
            if (rowValidate.find(ch) == rowValidate.end())
                rowValidate.insert(ch);
            else
                return false;
        }
        unordered_set<char> columnValidate;
        for (int k = 0; k < 9; k++)
        {
            char ch = board[k][i];
            if (ch == '.')
                continue;
            if (columnValidate.find(ch) == columnValidate.end())
                columnValidate.insert(ch);
            else
                return false;
        }
    }
    if ((!isMatrixValid(board, 0)) || (!isMatrixValid(board, 3)) || (!isMatrixValid(board, 6)))
        return false;
    return true;
}
// -------------------------
bool isValidSudoku2(vector<vector<char>> &board)
{
    int n = 9;
    unordered_set<char> rowSet[n];
    unordered_set<char> colSet[n];
    unordered_set<char> squareSet[n];
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            char val = board[row][col];
            if (val == '.')
                continue;
            int sPos = (row / 3) * 3 + col / 3;
            if (rowSet[row].count(val) || colSet[col].count(val) || squareSet[sPos].count(val))
                return false;
            rowSet[row].insert(val);
            colSet[col].insert(val);
            squareSet[sPos].insert(val);
        }
    }
    return true;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     vector<vector<char>> board = {{'.', '.', '.', '.', '5', '.', '.', '1', '.'},
//                                   {'.', '4', '.', '3', '.', '.', '.', '.', '.'},
//                                   {'.', '.', '.', '.', '.', '3', '.', '.', '1'},
//                                   {'8', '.', '.', '.', '.', '.', '.', '2', '.'},
//                                   {'.', '.', '2', '.', '7', '.', '.', '.', '.'},
//                                   {'.', '1', '5', '.', '.', '.', '.', '.', '.'},
//                                   {'.', '.', '.', '.', '.', '2', '.', '.', '.'},
//                                   {'.', '2', '.', '9', '.', '.', '.', '.', '.'},
//                                   {'.', '.', '4', '.', '.', '.', '.', '.', '.'}};
//     cout << isValidSudoku2(board) << endl;
//     cout << string(35, '-');
//     return 0;
// }
// ----------------------------------------------------------------- 54. Spiral Matrix ----------------------------------------------------------------------------
vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int rowCount = matrix.size();
    int columnCount = matrix[0].size();
    int topRow = 0, bottomRow = rowCount - 1;
    int leftColumn = 0, rightColumn = columnCount - 1;
    vector<int> result;
    while (1)
    {
        for (int col = leftColumn; col <= rightColumn; col++)
        {
            result.push_back(matrix[topRow][col]);
        }
        topRow++;
        if (topRow > bottomRow)
            break;
        for (int row = topRow; row <= bottomRow; row++)
        {
            result.push_back(matrix[row][rightColumn]);
        }
        rightColumn--;
        if (leftColumn > rightColumn)
            break;
        for (int col = rightColumn; col >= leftColumn; col--)
        {
            result.push_back(matrix[bottomRow][col]);
        }
        bottomRow--;
        if (topRow > bottomRow)
            break;
        for (int row = bottomRow; row >= topRow; row--)
        {
            result.push_back(matrix[row][leftColumn]);
        }
        leftColumn++;
        if (leftColumn > rightColumn)
            break;
    }
    return result;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     // vector<vector<int>> matrix = {
//     //     {1, 2, 3, 4, 5},
//     //     {16, 17, 18, 19, 6},
//     //     {15, 24, 25, 20, 7},
//     //     {14, 23, 22, 21, 8},
//     //     {13, 12, 11, 10, 9}};
//     // vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
//     vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
//     vector<int> result = spiralOrder(matrix);
//     cout << string(35, '-');
//     return 0;
// }
// -------------------------------------------------------------- 48. Rotate Image -----------------------------------------------------------------------------

void rotate(vector<vector<int>> &matrix)
{
    int m = matrix.size(), n = matrix[0].size();
    // SWAP DIAGONAL RIGHT ELEMENTS WITH LEFT ELEMENTS
    for (int row = 0; row < m; row++)
    {
        for (int column = row; column < n; column++)
        {
            int temp = matrix[row][column];
            matrix[row][column] = matrix[column][row];
            matrix[column][row] = temp;
        }
    }
    // OR

    // SWAP DIAGONAL LEFT ELEMENTS WITH RIGHT ELEMENTS
    // for (int row = 0; row < m; row++)
    // {
    //     for (int column = 0; column < row; column++)
    //     {
    //         int temp = matrix[row][column];
    //         matrix[row][column] = matrix[column][row];
    //         matrix[column][row] = temp;
    //     }
    // }

    // SWAP VERICALLY MIDDLE LEFT ELEMENTS WITH RIGHT ELEMENTS
    for (int row = 0; row < m; row++)
    {
        for (int column = 0; column < n / 2; column++)
        {
            int temp = matrix[row][column];
            matrix[row][column] = matrix[row][(n - 1) - column];
            matrix[row][(n - 1) - column] = temp;
        }
    }
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     vector<vector<int>> matrix = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
//     rotate(matrix);
//     cout << string(35, '-');
//     return 0;
// }
// ---------------------------------------------------------------- 73. Set Matrix Zeroes ----------------------------------------------------------------------------
void setZeroes(vector<vector<int>> &matrix)
{
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> matrixCopy = matrix;
    for (int row = 0; row < m; row++)
    {
        for (int column = 0; column < n; column++)
        {
            if (matrix[row][column] == 0)
            {
                for (int rw = 0; rw < m; rw++)
                    matrixCopy[rw][column] = 0;
                for (int col = 0; col < n; col++)
                    matrixCopy[row][col] = 0;
            }
        }
    }
    matrix = matrixCopy;
}
// ------------------
void setZeroes2(vector<vector<int>> &matrix)
{
    int rowCount = matrix.size();
    int columnCount = matrix[0].size();
    vector<int> isRowZero;
    vector<int> isColumnZero;
    for (int row = 0; row < rowCount; row++)
    {
        for (int col = 0; col < columnCount; col++)
        {
            if (matrix[row][col] == 0)
            {
                isRowZero.push_back(row);
                isColumnZero.push_back(col);
            }
        }
    }
    for (int row : isRowZero)
    {
        for (int col = 0; col < columnCount; col++)
        {
            matrix[row][col] = 0;
        }
    }
    for (int col : isColumnZero)
    {
        for (int row = 0; row < rowCount; row++)
        {
            matrix[row][col] = 0;
        }
    }
}
// -------- BRUTE FORCE APPROACH (NOT EXCEPTED) ----------
void markRow(vector<vector<int>> &matrix, int row)
{
    int columnCount = matrix[0].size();
    for (int col = 0; col < columnCount; col++)
    {
        if (matrix[row][col] != 0)
            matrix[row][col] = -1;
    }
}
void markColumn(vector<vector<int>> &matrix, int column)
{
    int rowCount = matrix.size();
    for (int row = 0; row < rowCount; row++)
    {
        if (matrix[row][column] != 0)
            matrix[row][column] = -1;
    }
}
void setZeroes3(vector<vector<int>> &matrix)
{
    int rowCount = matrix.size();
    int columnCount = matrix[0].size();
    for (int row = 0; row < rowCount; row++)
    {
        for (int col = 0; col < columnCount; col++)
        {
            if (matrix[row][col] == 0)
            {
                markRow(matrix, row);
                markColumn(matrix, col);
            }
        }
    }
    for (int row = 0; row < rowCount; row++)
    {
        for (int col = 0; col < columnCount; col++)
        {
            if (matrix[row][col] == -1)
                matrix[row][col] = 0;
        }
    }
}
// -----------------------
void setZeroes4(vector<vector<int>> &matrix)
{
    int rowCount = matrix.size();
    int columnCount = matrix[0].size();
    // int row[rowCount] = {0}; --> matrix[..][0]
    // int col[columnCount] = {0}; --> matrix[0][..]
    int col0 = 1;
    // step: 1: Traverse the matrix amd
    // mark 1st row & col accordingly:
    for (int row = 0; row < rowCount; row++)
    {
        for (int column = 0; column < columnCount; column++)
        {
            if (matrix[row][column] == 0)
            {
                // mark i-th row
                matrix[row][0] = 0;
                // mark j-th column
                if (column != 0)
                    matrix[0][column] = 0;
                else
                    col0 = 0;
            }
        }
    }

    // Step 2: Mark with 0 from (1, 1) to (rowCount-1, columnCount-1):
    for (int row = 1; row < rowCount; row++)
    {
        for (int column = 1; column < columnCount; column++)
        {
            if (matrix[row][column] != 0)
            {
                // check for row & column
                if (matrix[row][0] == 0 || matrix[0][column] == 0)
                    matrix[row][column] = 0;
            }
        }
    }
    // Step 3: Finally mark the 1st column and then 1st row:
    if (matrix[0][0] == 0)
    {
        for (int column = 0; column < columnCount; column++)
        {
            matrix[0][column] = 0;
        }
    }
    if (col0 == 0)
    {
        for (int row = 0; row < rowCount; row++)
        {
            matrix[row][0] = 0;
        }
    }
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     vector<vector<int>> matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
//     setZeroes4(matrix);
//     cout << string(35, '-');
//     return 0;
// }
// ---------------------------------------------------------------- 289. Game of Life --------------------------------------------------------------------------
// --------- BRUTE FORCE APPROACH ----------
void gameOfLife(vector<vector<int>> &board)
{
    int rowCount = board.size();
    int columnCount = board[0].size();
    vector<vector<int>> boardCopy = board;
    for (int row = 0; row < rowCount; row++)
    {
        for (int column = 0; column < columnCount; column++)
        {
            int neighbourCount = 0;
            // Top
            if (row > 0)
            {
                neighbourCount += board[row - 1][column];
            }
            // Bottom
            if (row < rowCount - 1)
            {
                neighbourCount += board[row + 1][column];
            }
            // Left
            if (column > 0)
            {
                neighbourCount += board[row][column - 1];
            }
            // Right
            if (column < columnCount - 1)
            {
                neighbourCount += board[row][column + 1];
            }
            // Top-Left
            if (row > 0 && column > 0)
            {
                neighbourCount += board[row - 1][column - 1];
            }
            // Top-Right
            if (row > 0 && column < columnCount - 1)
            {
                neighbourCount += board[row - 1][column + 1];
            }
            // Bottom-Left
            if (row < rowCount - 1 && column > 0)
            {
                neighbourCount += board[row + 1][column - 1];
            }
            // Bottom-Right
            if (row < rowCount - 1 && column < columnCount - 1)
            {
                neighbourCount += board[row + 1][column + 1];
            }
            if (board[row][column] == 1)
            {
                // Any live cell with fewer than two live neighbors dies as if caused by under-population.
                if (neighbourCount < 2)
                    boardCopy[row][column] = 0;
                // Any live cell with two or three live neighbors lives on to the next generation.
                // Any live cell with more than three live neighbors dies, as if by over-population.
                if (neighbourCount > 3)
                    boardCopy[row][column] = 0;
            }
            // Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
            else if (neighbourCount == 3)
            {
                boardCopy[row][column] = 1;
            }
        }
    }
    board = boardCopy;
}
// ------------- Without Using Extra Space -----------
void gameOfLife2(vector<vector<int>> &board)
{
    int rowCount = board.size();
    int columnCount = board[0].size();
    for (int row = 0; row < rowCount; row++)
    {
        for (int column = 0; column < columnCount; column++)
        {
            int neighbourCount = 0;
            // Top
            if (row > 0 && abs(board[row - 1][column]) == 1)
            {
                neighbourCount++;
            }
            // Bottom
            if (row < rowCount - 1 && abs(board[row + 1][column]) == 1)
            {
                neighbourCount++;
            }
            // Left
            if (column > 0 && abs(board[row][column - 1]) == 1)
            {
                neighbourCount++;
            }
            // Right
            if (column < columnCount - 1 && abs(board[row][column + 1]) == 1)
            {
                neighbourCount++;
            }
            // Top-Left
            if (row > 0 && column > 0 && abs(board[row - 1][column - 1]) == 1)
            {
                neighbourCount++;
            }
            // Top-Right
            if (row > 0 && column < columnCount - 1 && abs(board[row - 1][column + 1]) == 1)
            {
                neighbourCount++;
            }
            // Bottom-Left
            if (row < rowCount - 1 && column > 0 && abs(board[row + 1][column - 1]) == 1)
            {
                neighbourCount++;
            }
            // Bottom-Right
            if (row < rowCount - 1 && column < columnCount - 1 && abs(board[row + 1][column + 1]) == 1)
            {
                neighbourCount++;
            }
            if (board[row][column] == 1)
            {
                // Any live cell with fewer than two live neighbors dies as if caused by under-population.
                if (neighbourCount < 2)
                    board[row][column] = -1;
                // Any live cell with two or three live neighbors lives on to the next generation.
                // Any live cell with more than three live neighbors dies, as if by over-population.
                if (neighbourCount > 3)
                    board[row][column] = -1;
            }
            // Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
            else if (neighbourCount == 3)
            {
                board[row][column] = 2;
            }
        }
    }
    for (int row = 0; row < rowCount; row++)
    {
        for (int column = 0; column < columnCount; column++)
        {
            if (board[row][column] >= 1)
                board[row][column] = 1;
            else
                board[row][column] = 0;
        }
    }
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     vector<vector<int>> board = {{0, 1, 0},
//                                  {0, 0, 1},
//                                  {1, 1, 1},
//                                  {0, 0, 0}};
//     // vector<vector<int>> board = {{1, 1}, {1, 0}};
//     gameOfLife2(board);
//     for (int row = 0; row < board.size(); row++)
//     {
//         for (int column = 0; column < board[0].size(); column++)
//         {
//             cout << board[row][column] << "  ";
//         }
//         cout << endl;
//     }
//     cout << string(35, '-');
//     return 0;
// }
// ------------------------------------------------------------------- 383. Ransom Note ------------------------------------------------------------------
bool canConstruct(string ransomNote, string magazine)
{
    unordered_map<char, int> ransomNoteCharFrequency;
    unordered_map<char, int> magazineCharFrequency;
    for (char ch : ransomNote)
        ransomNoteCharFrequency[ch]++;
    for (char ch : magazine)
        magazineCharFrequency[ch]++;
    for (char ch : ransomNote)
    {
        if (ransomNoteCharFrequency[ch] > magazineCharFrequency[ch])
            return false;
    }
    return true;
}
// ---------------
bool canConstruct2(string ransomNote, string magazine)
{
    int ransomNoteSize = ransomNote.size();
    unordered_map<char, int> magazineCharFrequency;
    sort(ransomNote.begin(), ransomNote.end());
    for (char ch : magazine)
        magazineCharFrequency[ch]++;
    int frequencyCounter = 1;
    for (int i = 1; i < ransomNoteSize; i++)
    {
        if (ransomNote[i] == ransomNote[i - 1])
            frequencyCounter++;
        else
        {
            if (frequencyCounter > magazineCharFrequency[ransomNote[i - 1]])
                return false;
            frequencyCounter = 1;
        }
    }
    if (frequencyCounter > magazineCharFrequency[ransomNote[ransomNoteSize - 1]])
        return false;
    return true;
}
// ---------------
bool canConstruct3(string ransomNote, string magazine)
{
    // Initialize an array of count with the size 26.
    int magazineCharCounter[26] = {0};
    // Traverse a loop through the entire String of magazine where char ch stores the char at the index of magazine.
    for (char ch : magazine)
        magazineCharCounter[ch - 97]++;
    // Run another for loop for ransomNote.
    for (char ch : ransomNote)
    {
        // If the charachter doesn't exists in magazineCharCounter ('magazine') for ransomNote, we return false.
        if (magazineCharCounter[ch - 97]-- <= 0)
            return false;
    }
    // If nothing goes wrong, return true.
    return true;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     string ransomNote = "abcabc";
//     string magazine = "abcdefabc";
//     cout << canConstruct3(ransomNote, magazine) << endl;
//     cout << string(35, '-');
//     return 0;
// }
// --------------------------------------------------------------- 205. Isomorphic Strings ---------------------------------------------------------------------
// --------- Brute Force Approach ---------
bool isIsomorphic(string s, string t)
{
    if (s.size() != t.size())
        return false;
    unordered_map<char, vector<int>> sTracker;
    unordered_map<char, vector<int>> tTracker;
    for (int i = 0; i < s.size(); i++)
    {
        sTracker[s[i]].push_back(i);
        tTracker[t[i]].push_back(i);
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (sTracker[s[i]] != tTracker[t[i]])
            return false;
    }
    return true;
}
// -------------------------------------------
// Check for the last Index
bool isIsomorphic2(string s, string t)
{
    if (s.size() != t.size())
        return false;
    unordered_map<char, int> sLastIndexTracker;
    unordered_map<char, int> tLastIndexTracker;
    for (int i = 0; i < s.size(); i++)
    {
        if (sLastIndexTracker[s[i]] != tLastIndexTracker[t[i]])
            return false;
        // s = "ab"
        // t = "aa"
        // Dry run to understand why +1.
        sLastIndexTracker[s[i]] = i + 1;
        tLastIndexTracker[t[i]] = i + 1;
    }
    return true;
}
// -----------------------------------
bool isIsomorphic3(string s, string t)
{
    if (s.size() != t.size())
        return false;
    unordered_map<char, int> sTracker;
    unordered_map<char, int> tTracker;
    for (int i = 0; i < s.size(); i++)
    {
        if (sTracker[s[i]] && sTracker[s[i]] != t[i])
            return false;
        if (tTracker[t[i]] && tTracker[t[i]] != s[i])
            return false;
        sTracker[s[i]] = t[i];
        tTracker[t[i]] = s[i];
    }
    return true;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     string s = "paper";
//     string t = "title";
//     cout << isIsomorphic2(s, t) << endl;
//     cout << string(35, '-');
//     return 0;
// }
// ---------------------------------------------------------------- 290. Word Pattern ---------------------------------------------------------------------------
bool wordPattern(string pattern, string s)
{
    vector<string> wordVector;
    string word = "";
    for (char ch : s)
    {
        if (ch != ' ')
            word += ch;
        else if (!word.empty())
        {
            wordVector.push_back(word);
            word.clear();
        }
    }
    if (!word.empty())
        wordVector.push_back(word);
    if (pattern.size() != wordVector.size())
        return false;
    unordered_map<char, string> patternTracker;
    unordered_map<string, char> wordTracker;
    for (int i = 0; i < pattern.size(); i++)
    {
        if (patternTracker.find(pattern[i]) != patternTracker.end() && patternTracker[pattern[i]] != wordVector[i])
            return false;
        if (wordTracker.find(wordVector[i]) != wordTracker.end() && wordTracker[wordVector[i]] != pattern[i])
            return false;
        patternTracker[pattern[i]] = wordVector[i];
        wordTracker[wordVector[i]] = pattern[i];
    }
    return true;
}
// -------------------
// Tracking last index
bool wordPattern2(string pattern, string s)
{
    vector<string> wordVector;
    string word = "";
    for (char ch : s)
    {
        if (ch != ' ')
            word += ch;
        else if (!word.empty())
        {
            wordVector.push_back(word);
            word.clear();
        }
    }
    if (!word.empty())
        wordVector.push_back(word);
    if (pattern.size() != wordVector.size())
        return false;
    unordered_map<char, int> patternTracker;
    unordered_map<string, int> wordTracker;
    for (int i = 0; i < pattern.size(); i++)
    {
        if (patternTracker[pattern[i]] != wordTracker[wordVector[i]])
            return false;
        patternTracker[pattern[i]] = i + 1;
        wordTracker[wordVector[i]] = i + 1;
    }
    return true;
}
// --------------------------
bool wordPattern3(string pattern, string s)
{
    unordered_map<char, string> patternTracker;
    unordered_map<string, char> wordTracker;
    int index = 0;
    int i = 0;
    for (int i = 0; i < pattern.size(); i++)
    {
        // pattern = "he" // pattern = "abc"
        // s = "unit"     // s = "dog cat ball call"
        // Dry Run This
        if (index == s.size())
            return false;
        while (index < s.size() && s[index] == ' ')
            index++;
        string word;
        while (index < s.size() && s[index] != ' ')
            word += s[index++];
        if (patternTracker.find(pattern[i]) != patternTracker.end() && patternTracker[pattern[i]] != word)
            return false;
        if (wordTracker.find(word) != wordTracker.end() && wordTracker[word] != pattern[i])
            return false;
        patternTracker[pattern[i]] = word;
        wordTracker[word] = pattern[i];
    }
    return index == s.size() ? true : false;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     string pattern = "he";
//     string s = "unit";
//     cout << wordPattern3(pattern, s) << endl;
//     cout << string(35, '-');
//     return 0;
// }
// --------------------------------------------------------------- 242. Valid Anagram ------------------------------------------------------------------------
bool isAnagram(string s, string t)
{
    if (s.size() != t.size())
        return false;
    unordered_map<char, int> sCharFrequency;
    unordered_map<char, int> tCharFrequency;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        sCharFrequency[s[i]]++;
        tCharFrequency[t[i]]++;
    }
    for (char ch : t)
    {
        if (tCharFrequency[ch] != sCharFrequency[ch])
            return false;
    }
    return true;
}
// -------------------
bool isAnagram2(string s, string t)
{
    if (s.size() != t.size())
        return false;
    unordered_map<char, int> sCharFrequency;
    for (char ch : s)
    {
        sCharFrequency[ch]++;
    }
    for (char ch : t)
    {
        if (sCharFrequency[ch]-- <= 0)
            return false;
    }
    return true;
}
// ------------------------
bool isAnagram3(string s, string t)
{
    if (s.size() != t.size())
        return false;
    int characterCounter[26] = {0};
    for (int i = 0; i < s.size(); i++)
    {
        characterCounter[s[i] - 97]++;
        characterCounter[t[i] - 97]--;
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (characterCounter[s[i] - 97] != 0)
            return false;
    }
    return true;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     string s = "anagram";
//     string t = "nagaram";
//     cout << isAnagram3(s, t) << endl;
//     cout << string(35, '-');
//     return 0;
// }
// ----------------------------------------------------------------- 70. Climbing Stairs -------------------------------------------------------------------------
int climbStairs(int n)
{
    if (n == 1 || n == 0)
        return 1;
    int oneStep = climbStairs(n - 1);
    int twoStep = 0;
    if (n >= 2)
        twoStep = climbStairs(n - 2);
    return oneStep + twoStep;
}
// ---------- Memoisation -----------
int climbStairsHelper(int n, vector<int> &dp)
{
    if (n == 0)
        return 1;
    if (dp[n] != -1)
        return dp[n];
    int oneStep = climbStairsHelper(n - 1, dp);
    int twoStep = 0;
    if (n >= 2)
        twoStep = climbStairsHelper(n - 2, dp);
    return dp[n] = oneStep + twoStep;
}
int climbStairs2(int n)
{
    vector<int> dp(n + 1, -1);
    climbStairsHelper(n, dp);
    return dp[n];
}

// ------------------------------------------------------------------ 49. Group Anagrams -----------------------------------------------------------------------
vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    int n = strs.size();
    unordered_map<string, vector<string>> umap;
    vector<vector<string>> anagramsGroup;
    // use auto& rather then auto to avoid unnecessary copy
    for (auto &str : strs)
    {
        string helper = str;
        sort(helper.begin(), helper.end());
        umap[helper].push_back(str);
    }
    for (auto &item : umap)
        anagramsGroup.push_back(item.second);
    return anagramsGroup;
}
// --------------------------
// Counting Sort
string strSort(string s)
{
    int counter[26] = {0};
    for (char ch : s)
        counter[ch - 97]++;
    string str;
    for (int i = 0; i < 26; i++)
    {
        str += string(counter[i], i + 97);
    }
    return str;
}
vector<vector<string>> groupAnagrams2(vector<string> &strs)
{
    int n = strs.size();
    unordered_map<string, vector<string>> umap;
    for (string &str : strs)
        umap[strSort(str)].push_back(str);
    vector<vector<string>> anagramsGroup;
    for (auto &item : umap)
        anagramsGroup.push_back(item.second);
    return anagramsGroup;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     // vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
//     // vector<vector<string>> result = groupAnagrams(strs);
//     string result = strSort("fedcba");
//     cout << result << endl;
//     cout << string(35, '-');
//     return 0;
// }
// ------------------------------------------------------------------- 1. Two Sum --------------------------------------------------------------------------
vector<int> twoSum_01(vector<int> &nums, int target)
{
    unordered_map<int, int> umap;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        int remaining = target - nums[i];
        if (umap[remaining])
        {
            return {umap[remaining] - 1, i};
        }
        umap[nums[i]] = i + 1;
    }
    return {0, 0};
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     vector<int> nums = {2, 7, 11, 15};
//     vector<int> result = twoSum_01(nums, 9);
//     cout << result[0] << ", " << result[1] << endl;
//     cout << string(35, '-');
//     return 0;
// }
// ----------------------------------------------------------------- 202. Happy Number ---------------------------------------------------------------------------
bool isHappy(int n)
{
    unordered_map<int, int> occured;
    int remainder = 0, sumOfProduct = 0;
    while (n)
    {
        sumOfProduct = 0;
        while (n)
        {
            remainder = n % 10;
            n = n / 10;
            sumOfProduct += (remainder * remainder);
        }
        if (sumOfProduct == 1)
            return 1;
        if (occured[sumOfProduct])
            return false;
        occured[sumOfProduct] = 1;
        n = sumOfProduct;
    }
    return false;
}
// ---------------------------
int sumOfSquaredDigits(int number)
{
    int totalSum = 0;
    while (number > 0)
    {
        int remainder = number % 10;
        number = floor(number / 10);
        totalSum += remainder * remainder;
    }
    return totalSum;
}
bool isHappy2(int n)
{
    int slowPointer = n;
    int fastPointer = sumOfSquaredDigits(n);
    while (fastPointer != 1 && slowPointer != fastPointer)
    {
        slowPointer = sumOfSquaredDigits(slowPointer);
        fastPointer = sumOfSquaredDigits(sumOfSquaredDigits(fastPointer));
    }
    if (fastPointer == 1)
        return true;
    return false;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     // int n = 19;
//     int n = 2;
//     // int n = 1;
//     cout << isHappy2(n) << endl;
//     cout << string(35, '-');
//     return 0;
// }
// ----------------------------------------------------------------- 219. Contains Duplicate II ---------------------------------------------------------------------------
bool containsNearbyDuplicate(vector<int> &nums, int k)
{
    unordered_map<int, int> umap;
    for (int i = 0; i < nums.size(); i++)
    {
        if (umap.find(nums[i]) != umap.end())
        {
            int distance = abs(umap[nums[i]] - i);
            if (distance <= k)
                return true;
        }
        umap[nums[i]] = i;
    }
    return false;
}
// -------------
bool containsNearbyDuplicate2(vector<int> &nums, int k)
{
    unordered_map<int, int> umap;
    for (int i = 0; i < nums.size(); i++)
    {
        if (umap[nums[i]])
        {
            int distance = abs((umap[nums[i]] - 1) - i);
            if (distance <= k)
                return true;
        }
        umap[nums[i]] = i + 1;
    }
    return false;
}
// ---------------
bool containsNearbyDuplicate3(vector<int> &nums, int k)
{
    unordered_map<int, int> umap;
    for (int i = 0; i < nums.size(); i++)
    {
        if (umap.count(nums[i]))
        {
            if (abs(umap[nums[i]] - 1) <= k)
                return true;
        }
        umap[nums[i]] = i;
    }
    return false;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     vector<int> nums = {1, 0, 1, 1};
//     int k = 1;
//     cout << containsNearbyDuplicate2(nums, k) << endl;
//     cout << string(35, '-');
//     return 0;
// }
// --------------------------------------------------------------- 128. Longest Consecutive Sequence ------------------------------------------------------------------
// -------- Brute Force Approach --------
int longestConsecutive(vector<int> &nums)
{
    int longestLength = INT_MIN;
    int currentLongestLength = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        int nextElement = nums[i] + 1;
        while (1)
        {
            bool elementFound = false;
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] == nextElement)
                {
                    currentLongestLength++;
                    nextElement++;
                    elementFound = true;
                    break;
                }
            }
            if (!elementFound)
            {
                longestLength = max(longestLength, currentLongestLength);
                currentLongestLength = 1;
                break;
            }
        }
    }
    return longestLength;
}
// ---------------------
int longestConsecutive2(vector<int> &nums)
{
    if (nums.size() == 0)
        return 0;
    sort(nums.begin(), nums.end());
    int longestLength = INT_MIN;
    int currentLongestLength = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] == nums[i - 1])
            continue;
        else if (nums[i] == (nums[i - 1] + 1))
            currentLongestLength++;
        else
        {
            longestLength = max(longestLength, currentLongestLength);
            currentLongestLength = 1;
        }
    }
    longestLength = max(longestLength, currentLongestLength);
    return longestLength;
}
// --------- TUF ------------
int longestConsecutiveTuf(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;
    int longest = 1;
    unordered_set<int> st;
    // put all the array elements into set:
    for (int i = 0; i < n; i++)
        st.insert(nums[i]);
    // Find the longest sequence:
    for (auto &item : st)
    {
        // if 'it' is a starting number:
        if (st.find(item - 1) == st.end())
        {
            // find consecutive numbers:
            int count = 1;
            int x = item;
            while (st.find(x + 1) != st.end())
            {
                x = x + 1;
                count++;
            }
            longest = max(longest, count);
        }
    }
    return longest;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     // vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
//     vector<int> nums = {102, 4, 100, 1, 101, 3, 2, 1, 1};
//     cout << longestConsecutiveTuf(nums) << endl;
//     cout << string(35, '-');
//     return 0;
// }
// -------------------------------------------------------------------- 228. Summary Ranges ------------------------------------------------------------------------
vector<string> summaryRanges(vector<int> &nums)
{
    int n = nums.size();
    vector<string> rangeSummary;
    if (n == 0)
        return rangeSummary;
    int startRange = nums[0];
    int endRange = nums[0];
    for (int i = 1; i < n; i++)
    {
        if (nums[i] == endRange + 1)
            endRange = nums[i];
        else
        {
            if (startRange == endRange)
                rangeSummary.push_back(to_string(startRange));
            else
                rangeSummary.push_back(to_string(startRange) + "->" + to_string(endRange));
            startRange = nums[i];
            endRange = nums[i];
        }
    }
    if (startRange == endRange)
        rangeSummary.push_back(to_string(startRange));
    else
        rangeSummary.push_back(to_string(startRange) + "->" + to_string(endRange));
    return rangeSummary;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     // vector<int> nums = {0, 2, 3, 4, 6, 8, 9};
//     vector<int> nums = {0, 1, 2, 4, 5, 7};
//     vector<string> rangeSummary = summaryRanges(nums);
//     for (auto range : rangeSummary)
//         cout << range << endl;
//     cout << string(35, '-');
//     return 0;
// }
// --------------------------------------------------------------------- 56. Merge Intervals ------------------------------------------------------------------------
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> result;
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
    vector<int> interval = {intervals[0][0], intervals[0][1]};
    for (int i = 1; i < n; i++)
    {
        if (intervals[i][0] <= interval[1])
        {
            if (intervals[i][1] >= interval[1])
                interval[1] = intervals[i][1];
        }
        else
        {
            result.push_back(interval);
            interval[0] = intervals[i][0];
            interval[1] = intervals[i][1];
        }
    }
    result.push_back(interval);
    return result;
}
// -------------
vector<vector<int>> merge2(vector<vector<int>> &intervals)
{
    vector<vector<int>> result;
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
    vector<int> interval = {intervals[0][0], intervals[0][1]};
    for (int i = 1; i < n; i++)
    {
        if (intervals[i][0] <= interval[1])
        {
            interval[0] = min(interval[0], intervals[i][0]);
            interval[1] = max(interval[1], intervals[i][1]);
        }
        else
        {
            result.push_back(interval);
            interval[0] = intervals[i][0];
            interval[1] = intervals[i][1];
        }
    }
    result.push_back(interval);
    return result;
}
// ------------------
vector<vector<int>> merge3(vector<vector<int>> &intervals)
{
    vector<vector<int>> answer;
    sort(intervals.begin(), intervals.end());
    vector<int> newInterval = intervals[0];
    int i = 1, n = intervals.size();
    while (i < n)
    {
        if (intervals[i][0] <= newInterval[1])
            newInterval[1] = max(intervals[i][1], newInterval[1]);
        else if (intervals[i][0] > newInterval[1])
        {
            answer.push_back(newInterval);
            newInterval = intervals[i];
        }
        i++;
    }
    answer.push_back(newInterval);
    return answer;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     // vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
//     // vector<vector<int>> intervals = {{1, 4}, {4, 5}};
//     // vector<vector<int>> intervals = {{1, 4}, {0, 4}};
//     // vector<vector<int>> intervals = {{1, 4}, {2, 3}};
//     vector<vector<int>> intervals = {{1, 4}, {0, 5}};
//     vector<vector<int>> result = merge(intervals);
//     for (vector<int> vect : result)
//     {
//         cout << vect[0] << ", " << vect[1] << endl;
//     }
//     cout << string(35, '-');
//     return 0;
// }
// ----------------------------------------------------------------- 57. Insert Interval -------------------------------------------------------------------------
vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    vector<vector<int>> result;
    int n = intervals.size();
    for (int i = 0; i < n; i++)
    {
        if (newInterval[0] > intervals[i][1])
        {
            result.push_back(intervals[i]);
        }
        else if (intervals[i][0] > newInterval[1])
        {
            result.push_back(newInterval);
            newInterval = intervals[i];
        }
        else if (newInterval[0] <= intervals[i][1])
        {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
        }
    }
    result.push_back(newInterval);
    return result;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     vector<vector<int>> intervals = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
//     vector<int> newInterval = {4, 8};
//     vector<vector<int>> result = insert(intervals, newInterval);
//     for (vector<int> vect : result)
//     {
//         cout << vect[0] << ", " << vect[1] << endl;
//     }
//     cout << string(35, '-');
//     return 0;
// }
// -------------------------------------------------------------------- 42. Trapping Rain Water Revision -----------------------------------------------------------------------
int trapRevise(vector<int> &height)
{
    int n = height.size();
    int left = 0;
    int right = n - 1;
    int totalWaterTrapped = 0;
    int leftMax = height[0];
    int rightMax = height[n - 1];
    while (left < right)
    {
        if (height[left] > leftMax)
        {
            leftMax = height[left];
        }
        if (height[right] > rightMax)
        {
            rightMax = height[right];
        }
        int totalWaterCanFillBetween = min(leftMax, rightMax);
        if (height[left] <= height[right])
        {
            if (totalWaterCanFillBetween > height[left])
                totalWaterTrapped += (totalWaterCanFillBetween - height[left]);
            left++;
        }
        else
        {
            if (totalWaterCanFillBetween > height[right])
                totalWaterTrapped += (totalWaterCanFillBetween - height[right]);
            right--;
        }
    }
    return totalWaterTrapped;
}
// ------------------------
int trapRevise2(vector<int> &height)
{
    int n = height.size();
    int waterTrapped = 0;
    int leftPointer = 0, rightPointer = n - 1;
    int leftMax = 0, rightMax = 0;
    while (leftPointer <= rightPointer)
    {
        if (height[leftPointer] <= height[rightPointer])
        {
            if (height[leftPointer] > leftMax)
                leftMax = height[leftPointer];
            else
                waterTrapped += leftMax - height[leftPointer];
            leftPointer++;
        }
        else
        {
            if (height[rightPointer] > rightMax)
                rightMax = height[rightPointer];
            else
                waterTrapped += rightMax - height[rightPointer];
            rightPointer--;
        }
    }
    return waterTrapped;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
//     cout << trapRevise2(height) << endl;
//     cout << string(35, '-');
//     return 0;
// }
// ------------------------------------------------------------------ 209. Minimum Size Subarray Sum --------------------------------------------------------------
int minSubArrayLenRevision(int target, vector<int> &nums)
{
    int n = nums.size();
    int subarraySum = 0, subarrayLength = 0;
    int minSubarrayLength = INT_MAX;
    int right = 0;
    while (right < n)
    {
        subarrayLength++;
        subarraySum += nums[right];
        if (subarraySum >= target)
            break;
        right++;
    }
    if (subarraySum < target)
        return 0;
    int left = 0;
    while (left < n && (subarraySum - nums[left]) >= target)
    {
        subarraySum -= nums[left];
        subarrayLength--;
        left++;
    }
    minSubarrayLength = min(minSubarrayLength, subarrayLength);
    right++;
    while (right < n)
    {
        subarraySum += nums[right];
        subarrayLength++;
        while (left < n && (subarraySum - nums[left]) >= target)
        {
            subarraySum -= nums[left];
            subarrayLength--;
            left++;
        }
        minSubarrayLength = min(minSubarrayLength, subarrayLength);
        right++;
    }
    return minSubarrayLength;
}
// ------------------
int minSubArrayLenRevision2(int target, vector<int> &nums)
{
    int n = nums.size();
    int left = 0;
    int sum = 0;
    int minLengthSubArray = INT_MAX;
    for (int right = 0; right < n; right++)
    {
        sum += nums[right];
        while (sum >= target)
        {
            minLengthSubArray = min((right - left) + 1, minLengthSubArray);
            sum -= nums[left];
            left++;
        }
    }
    return minLengthSubArray == INT_MAX ? 0 : minLengthSubArray;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     vector<int> nums = {5, 1, 3, 5, 10, 7, 4, 9, 2, 8};
//     int target = 15;
//     cout << minSubArrayLenRevision2(target, nums) << endl;
//     cout << string(35, '-');
//     return 0;
// }
// ------------------------------------------------------------------- 53. Maximum Subarray Revision ------------------------------------------------------------------------
// Kadane's Algorithms
int maxSubArrayRevision(vector<int> &nums)
{
    int max_so_far = INT_MIN;
    int max_ending_here = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        max_ending_here += nums[i];
        if (max_ending_here > max_so_far)
            max_so_far = max_ending_here;
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}
int maxSubArrayRevision2(vector<int> &nums)
{
    int n = nums.size();
    int curr = 0;
    int prev = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        curr += nums[i];
        if (nums[i] > curr)
            curr = nums[i];
        if (curr > prev)
            prev = curr;
    }
    return prev;
}
// int main()
// {
//     cout << string(35, '-') << endl;
//     vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
//     cout << maxSubArrayRevision(nums) << endl;
//     cout << string(35, '-');
//     return 0;
// }
// ------------------------------------------------------------------- 4. Median of Two Sorted Arrays -------------------------------------------------------------------
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();
    int m = nums2.size();
    int mergeSize = m + n;
    vector<int> merged(mergeSize);
    int nums1Pointer = n - 1;
    int nums2Pointer = m - 1;
    int mergedPointer = mergeSize - 1;
    while (nums1Pointer >= 0 && nums2Pointer >= 0)
    {
        if (nums1[nums1Pointer] >= nums2[nums2Pointer])
        {
            merged[mergedPointer] = nums1[nums1Pointer];
            nums1Pointer--;
        }
        else
        {
            merged[mergedPointer] = nums2[nums2Pointer];
            nums2Pointer--;
        }
        mergedPointer--;
    }
    while (nums1Pointer >= 0)
    {
        merged[mergedPointer] = nums1[nums1Pointer];
        nums1Pointer--;
        mergedPointer--;
    }
    while (nums2Pointer >= 0)
    {
        merged[mergedPointer] = nums2[nums2Pointer];
        nums2Pointer--;
        mergedPointer--;
    }
    int mid = mergeSize / 2;
    if (mergeSize % 2 == 0)
        return (double(merged[mid - 1]) + double(merged[mid])) / 2;
    return double(merged[mid]);
}
int main()
{
    cout << string(35, '-') << endl;
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2, 4};
    cout << findMedianSortedArrays(nums1, nums2) << endl;
    cout << string(35, '-');
    return 0;
}