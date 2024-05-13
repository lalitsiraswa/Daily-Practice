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

int main()
{
    cout << string(35, '-') << endl;
    cout << rand();
    cout << endl
         << string(35, '-');
    return 0;
}