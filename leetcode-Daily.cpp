#include <bits/stdc++.h>
using namespace std;
//--------------------------------------------------------------- 16. 3Sum Closest -------------------------------------------------------------------------------
int threeSumClosest(vector<int> &nums, int target)
{
}
int main()
{
    return 1;
}
//--------------------------------------------------------------- 179. Largest Number -------------------------------------------------------------------------------
// bool compare(string a, string b)
// {
//     return a + b > b + a;
// }
// string largestNumber(vector<int> &nums)
// {
//     vector<string> container;
//     for (int i : nums)
//         container.push_back(to_string(i));
//     sort(container.begin(), container.end(), compare);
//     // sort(container.begin(), container.end(), [](string a, string b)
//     //      { return a + b > b + a; });
//     string result;
//     for (int i = 0; i < container.size(); i++)
//         result += container[i];
//     return result[0] == '0' ? "0" : result;
// }
//-------------------------------------------------------------------
// string largestNumber(vector<int> &nums)
// {
//     int n = nums.size();
//     string result;
//     vector<string> container;
//     for (auto &item : nums)
//         container.push_back(to_string(item));
//     for (int i = 0; i < (n - 1); i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             string a = container[i];
//             string b = container[j];
//             if (a + b < b + a)
//                 swap(container[i], container[j]);
//         }
//     }
//     for (auto &item : container)
//         result.append(item);
//     return result[0] == '0' ? "0" : result;
// }
// int main()
// {
//     vector<int> nums = {3, 30, 34, 5, 9};
//     cout << largestNumber(nums) << endl;
//     return 1;
// }

//--------------------------------------------------------------- 560. Subarray Sum Equals K -------------------------------------------------------------------------------
//---------------------- Wrong Answeer -----------------------
// int subarraySum(vector<int> &nums, int k)
// {
//     int n = nums.size();
//     int totalWindowSum = 0, numOfSubArray = 0;
//     int left = 0, right = 0;
//     for (right; right < n; right++)
//     {
//         totalWindowSum += nums[right];
//         if (totalWindowSum >= k || right == n - 1)
//             break;
//     }
//     right++;
//     while (right <= n && left < n)
//     {
//         if (totalWindowSum == k)
//         {
//             numOfSubArray++;
//             totalWindowSum -= nums[left++];
//         }
//         else if ((right < n) && totalWindowSum < k && (totalWindowSum > 0))
//             totalWindowSum += nums[right++];
//         else if (totalWindowSum > k || (totalWindowSum <= 0))
//             totalWindowSum -= nums[left++];
//         else
//             right++;
//     }
//     return numOfSubArray;
// }
//--------------------Time Limit Exceeded------------------------------
// int subarraySum(vector<int> &nums, int k)
// {
//     int n = nums.size();
//     int totalWindowSum = 0, numOfSubArray = 0;
//     for (int i = 0; i < n; i++)
//     {
//         totalWindowSum = 0;
//         for (int j = i; j < n; j++)
//         {
//             totalWindowSum += nums[j];
//             if (totalWindowSum == k)
//                 numOfSubArray++;
//         }
//     }
//     return numOfSubArray;
// }
// ---------------------- Wrong --------------------------------
// int subarraySum(vector<int> &nums, int k)
// {
//     int n = nums.size();
//     int totalSum = 0, numOfSubArray = 0;
//     vector<int> cumulativeSum(n, 0);
//     for (int i = 0; i < n; i++)
//     {
//         totalSum += nums[i];
//         cumulativeSum[i] = totalSum;
//     }
//     numOfSubArray = (cumulativeSum[0] == 0) ? 1 : 0;
//     int left = 0, right = 1;
//     while (right < n)
//     {
//         if (cumulativeSum[right] == k)
//         {
//             numOfSubArray++;
//             right++;
//         }
//         else if ((cumulativeSum[right] - cumulativeSum[left]) < k && (cumulativeSum[right] - cumulativeSum[left]) > 0)
//             right++;
//         else
//             left++;
//     }
//     return numOfSubArray;
// }
// ----------------------------------------------------------------------
// int subarraySum(vector<int> &nums, int k)
// {
//     int n = nums.size();             // take the size of the array
//     vector<int> cumulativeSum(n, 0); // make a prefix array to store prefix sum
//     cumulativeSum[0] = nums[0];      // for element at index at zero, it is same
//     // making our prefix array
//     for (int i = 1; i < n; i++)
//         cumulativeSum[i] = (nums[i] + cumulativeSum[i - 1]);
//     unordered_map<int, int> umap; // declare an unordered map
//     int numOfSubArray = 0;        // to store the number of our subarrays having sum as 'k'
//     for (int i = 0; i < n; i++)   // traverse from the prefix array
//     {
//         if (cumulativeSum[i] == k) // if it already becomes equal to k, then increment ans
//             numOfSubArray++;
//         // now, find whether (prefix[i] - k) present in map or not
//         if (umap.find(cumulativeSum[i] - k) != umap.end())
//             numOfSubArray += umap[cumulativeSum[i] - k]; // if yes, then add it our answer
//         umap[cumulativeSum[i]]++;                        // put prefix sum into our map
//     }
//     return numOfSubArray; // and at last, return our answer
// }
// int main()
// {
//     vector<int> nums = {-1, -1, 1};
//     cout << "Subarray Sum Equals K : " << subarraySum(nums, 0) << endl;
//     return 1;
// }

//---------------------------------------------------------424. Longest Repeating Character Replacement -------------------------------------------------------------------------------
// int characterReplacement(string s, int k)
// {
//     int n = s.length(), currStrLen = 0, LongestStrLen = 0, maxCharReplacement = 0;
//     for (int i = 0; i < n && ((n - i) > LongestStrLen); i++)
//     {
//         currStrLen = 1;
//         maxCharReplacement = 0;
//         for (int j = i + 1; j < n && maxCharReplacement <= k; j++)
//         {
//             if (s[i] == s[j])
//                 currStrLen++;
//             else
//                 maxCharReplacement++;
//         }
//         if (currStrLen == n)
//             return currStrLen;
//         if (currStrLen > n / 2)
//         {
//             if (n - currStrLen <= k)
//                 return currStrLen + (n - currStrLen);
//             return currStrLen + k;
//         }
//         LongestStrLen = max(currStrLen, LongestStrLen);
//     }
//     return LongestStrLen + k;
// }
//-----------------------------------------------------------
// int characterReplacement(string s, int k)
// {
//     int n = s.length(), left = 0, right = 0;
//     int currStrLen = 0, LongestStrLen = -1, maxRepeatingChar = 0;
//     unordered_map<char, int> umap;
//     while (right < n)
//     {
//         umap[s[right]]++;
//         maxRepeatingChar = max(maxRepeatingChar, umap[s[right]]);
//         currStrLen = (right - left) + 1;
//         if ((currStrLen - maxRepeatingChar) > k)
//         {
//             umap[s[left]]--;
//             left++;
//         }
//         currStrLen = (right - left) + 1;
//         LongestStrLen = max(LongestStrLen, currStrLen);
//         right++;
//     }
//     return LongestStrLen;
// }
// int main()
// {
//     string s = "AABABBA";
//     cout << "Longest Repeating Character Replacement : " << characterReplacement(s, 1);
//     return 1;
// }

//------------------------------------------------------------------- 525. Contiguous Array -------------------------------------------------------------------------------
//-------------- TRY BUT, IN WRONG DIRECTION ------------------
// int findMaxLength(vector<int> &nums)
// {
//     int maxLength = 0, n = nums.size();
//     int SIO0 = -1, EIO0 = -1, SIO1 = -1, EIO1 = -1;
//     for (int i = 0; i < n; i++)
//     {
//         if (nums[i] == 0 && SIO0 == -1)
//             SIO0 = i;
//         if (nums[i] == 0 && (i == n - 1 || nums[i + 1] != 0))
//             EIO0 = i;
//         if (nums[i] == 1 && SIO1 == -1)
//             SIO1 = i;
//         if (nums[i] == 1 && (i == n - 1 || nums[i + 1] != 1))
//             EIO1 = i;
//         if (EIO1 != -1 && nums[i] == 0 && (i - SIO0 == EIO1 - SIO1))
//         {
//             maxLength = max(maxLength, (i - SIO1) + 1);
//             SIO1 = -1;
//             EIO1 = -1;
//         }
//         if (EIO0 != -1 && nums[i] == 1 && (EIO0 - SIO0 == i - SIO1))
//         {
//             maxLength = max(maxLength, (i - SIO0) + 1);
//             SIO0 = -1;
//             EIO0 = -1;
//         }
//     }
//     return maxLength;
// }
//-------------------------- Time Limit Exceeded -------------------------------------
// int findMaxLength(vector<int> &nums)
// {
//     int maxLength = 0, n = nums.size();
//     int counter[2] = {0};
//     for (int i = 0; i < n && (n - i) > maxLength; i++)
//     {
//         counter[nums[i]]++;
//         for (int j = i + 1; j < n; j++)
//         {
//             counter[nums[j]]++;
//             if (counter[0] == counter[1] && (j - i) + 1 > maxLength)
//                 maxLength = (j - i) + 1;
//         }
//         memset(counter, 0, sizeof(counter));
//     }
//     return maxLength;
// }
//--------------------------------------------------------------------------------------
// int findMaxLength(vector<int> &nums)
// {
//     int n = nums.size();
//     unordered_map<int, int> umap;
//     int totalSum = 0, maxLength = 0;
//     for (int i = 0; i < n; i++)
//         if (nums.at(i) == 0)
//             nums[i] = -1;
//     for (int i = 0; i < n; i++)
//     {
//         totalSum += nums[i];
//         if (totalSum == 0)
//         {
//             maxLength = i + 1;
//             continue;
//         }
//         if (!umap.count(totalSum))
//             umap[totalSum] = i;
//         else
//             maxLength = max(maxLength, (i - umap[totalSum]));
//     }
//     return maxLength;
// }
//-------------------------------------------------------
// int findMaxLength(vector<int> &nums)
// {
//     int n = nums.size();
//     vector<int> vect(2 * nums.size(), INT_MIN);
//     vect[nums.size()] = -1;
//     int totalSum = 0, maxLength = 0;
//     for (int i = 0; i < n; i++)
//     {
//         totalSum += (nums[i] == 0 ? -1 : 1);
//         if (vect[totalSum + n] >= -1)
//             maxLength = max(maxLength, i - vect[totalSum + n]);
//         else
//             vect[totalSum + n] = i;
//     }
//     return maxLength;
// }
// int main()
// {
//     vector<int> nums = {1, 1, 0, 0, 1, 1, 0, 1, 1};
//     cout << "Contiguous Array Length : " << findMaxLength(nums) << endl;
//     return 1;
// }

//------------------------------------------------------------------- 189. Rotate Array -------------------------------------------------------------------------------
// void rotate(vector<int> &nums, int k)
// {
//     int n = nums.size();
//     vector<int> helper(n);
//     for(int i = 0; i < n; i++)
//         helper[(i+k)%n] = nums[i];
//     nums = helper;
// }
//----------------------------------------
// void rotate(vector<int> &nums, int k)
// {
//     int n = nums.size();
//     k = k % n;
//     reverse(nums.begin(), nums.end());
//     reverse(nums.begin(), nums.begin()+k);
//     reverse(nums.begin()+k, nums.end());
// }
//-------------------------------------------
// void rotate(vector<int> &nums, int k)
// {
//     int n = nums.size();
//     k = k % n;
//     int left = 0, right = n - 1;
//     while (left < right)
//     {
//         int helper = nums[left];
//         nums[left++] = nums[right];
//         nums[right--] = helper;
//     }
//     left = 0, right = k - 1;
//     while (left < right)
//     {
//         int helper = nums[left];
//         nums[left++] = nums[right];
//         nums[right--] = helper;
//     }
//     left = k, right = n - 1;
//     while (left < right)
//     {
//         int helper = nums[left];
//         nums[left++] = nums[right];
//         nums[right--] = helper;
//     }
// }
// int main()
// {
//     vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
//     int k = 3;
//     rotate(nums, k);
//     for (auto &item : nums)
//         cout << item << "  ";
//     return 1;
// }

//------------------------------------------------------------ 128. Longest Consecutive Sequence -----------------------------------------------------------------------
// int longestConsecutive(vector<int> &nums)
// {
//     int n = nums.size();
//     if (n == 0)
//         return 0;
//     set<int> s(nums.begin(), nums.end());
//     nums.assign(s.begin(), s.end());
//     n = nums.size();
//     int currentSequenceLength = 1, longestSequenceLength = 0;
//     for (int i = 1; i < n; i++)
//     {
//         if (nums[i] == nums[i - 1] + 1)
//             currentSequenceLength++;
//         else if (currentSequenceLength > longestSequenceLength)
//         {
//             longestSequenceLength = currentSequenceLength;
//             currentSequenceLength = 1;
//         }
//         else
//             currentSequenceLength = 1;
//     }
//     if (currentSequenceLength > longestSequenceLength)
//         longestSequenceLength = currentSequenceLength;
//     return longestSequenceLength;
// }
//--------------------------------------------------------
// int longestConsecutive(vector<int> &nums)
// {
//     int n = nums.size();
//     if (n == 0)
//         return 0;
//     set<int> s(nums.begin(), nums.end());
//     int currentSequenceLength = 1, longestSequenceLength = 0;
//     set<int>::iterator current, previous;
//     for (current = ++s.begin(), previous = s.begin(); current != s.end(); current++, previous++)
//     {
//         if (*current == (*previous) + 1)
//             currentSequenceLength++;
//         else if (currentSequenceLength > longestSequenceLength)
//         {
//             longestSequenceLength = currentSequenceLength;
//             currentSequenceLength = 1;
//         }
//         else
//             currentSequenceLength = 1;
//     }
//     if (currentSequenceLength > longestSequenceLength)
//         longestSequenceLength = currentSequenceLength;
//     return longestSequenceLength;
// }
//--------------------------------------------------------
// int longestConsecutive(vector<int> &nums)
// {
//     int n = nums.size();
//     if (n == 0)
//         return 0;
//     sort(nums.begin(), nums.end());
//     int currentSequenceLength = 1, longestSequenceLength = 0;
//     for (int i = 1; i < n; i++)
//     {
//         if (nums[i] == nums[i - 1])
//             continue;
//         if (nums[i] == nums[i - 1] + 1)
//             currentSequenceLength++;
//         else
//         {
//             longestSequenceLength = max(currentSequenceLength, longestSequenceLength);
//             currentSequenceLength = 1;
//         }
//     }
//     longestSequenceLength = max(currentSequenceLength, longestSequenceLength);
//     return longestSequenceLength;
// }
//------------------------------------------------------------
// int longestConsecutive(vector<int> &nums)
// {
//     int n = nums.size();
//     if (n == 0)
//         return 0;
//     map<int, int> mp;
//     int currentSequenceLength = 1, longestSequenceLength = 0;
//     for (auto &item : nums)
//         mp[item]++;
//     map<int, int>::iterator current, previous;
//     for (current = ++mp.begin(), previous = mp.begin(); current != mp.end(); current++, previous++)
//     {
//         if (current->first == (previous->first) + 1)
//             currentSequenceLength++;
//         else
//         {
//             longestSequenceLength = max(currentSequenceLength, longestSequenceLength);
//             currentSequenceLength = 1;
//         }
//     }
//     longestSequenceLength = max(currentSequenceLength, longestSequenceLength);
//     return longestSequenceLength;
// }
// int main()
// {
//     vector<int> nums = {1, 2, 0, 1};
//     cout << "Longest Consecutive Sequence : " << longestConsecutive(nums) << endl;
//     return 1;
// }

//--------------------------------------------------------------- 49. Group Anagrams -----------------------------------------------------------------------
//------------------------- TLE ---------------------------
// vector<vector<string>> groupAnagrams(vector<string> &strs)
// {
//     vector<vector<string>> result;
//     vector<string> helper;
//     int n = strs.size();
//     vector<int> seen(n, 0);
//     vector<int> frequency(26, 0);
//     vector<int> charOccurred(26, 0);
//     for (int i = 0; i < n; i++)
//     {
//         if (seen[i])
//             continue;
//         helper.push_back(strs.at(i));
//         seen[i] = 1;
//         for (int j = 0; j < strs.at(i).size(); j++)
//             frequency[strs.at(i)[j] - 97]++;
//         for (int k = i + 1; k < n; k++)
//         {
//             if (seen[k])
//                 continue;
//             for (int j = 0; j < strs.at(k).size(); j++)
//                 charOccurred[strs.at(k)[j] - 97]++;
//             if (frequency == charOccurred)
//             {
//                 helper.push_back(strs.at(k));
//                 seen[k] = 1;
//             }
//             charOccurred.assign(26, 0);
//         }
//         result.push_back(helper);
//         frequency.assign(26, 0);
//         helper.clear();
//     }
//     return result;
// }
//-------------------------------------------------------
// vector<vector<string>> groupAnagrams(vector<string> &strs)
// {
//     vector<vector<string>> result;
//     vector<string> helper;
//     int n = strs.size();
//     vector<int> seen(n, 0);
//     vector<string> duplicateStrs = strs;
//     for (int i = 0; i < n; i++)
//     {
//         string item = strs.at(i);
//         sort(item.begin(), item.end());
//         duplicateStrs[i] = item;
//     }
//     for (int i = 0; i < n; i++)
//     {
//         if (seen[i])
//             continue;
//         helper.push_back(strs[i]);
//         seen[i] = 1;
//         for (int j = i + 1; j < n; j++)
//         {
//             if (seen[j])
//                 continue;
//             if (duplicateStrs[i] == duplicateStrs[j])
//             {
//                 helper.push_back(strs[j]);
//                 seen[j] = 1;
//             }
//         }
//         result.push_back(helper);
//         helper.clear();
//     }
//     return result;
// }
//-------------------------------------------------------
// vector<vector<string>> groupAnagrams(vector<string> &strs)
// {
//     int n = strs.size();
//     unordered_map<string, vector<string>> umap;
//     vector<vector<string>> anagrams;
//     // use auto& rather then auto to avoid unnecessary copy
//     for (auto &str : strs)
//     {
//         string helper = str;
//         sort(helper.begin(), helper.end());
//         umap[helper].push_back(str);
//     }
//     for (auto &item : umap)
//         anagrams.push_back(item.second);
//     return anagrams;
// }
//----------------------------------------------------------
// string strSort(string s)
// {
//     int counter[26] = {0};
//     for (char c : s)
//     {
//         counter[c - 'a']++;
//     }
//     string t;
//     for (int c = 0; c < 26; c++)
//     {
//         t += string(counter[c], c + 'a');
//     }
//     return t;
// }
// vector<vector<string>> groupAnagrams(vector<string> &strs)
// {
//     unordered_map<string, vector<string>> mp;
//     for (string s : strs)
//     {
//         mp[strSort(s)].push_back(s);
//     }
//     vector<vector<string>> anagrams;
//     for (auto p : mp)
//     {
//         anagrams.push_back(p.second);
//     }
//     return anagrams;
// }
// int main()
// {
//     vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
//     vector<vector<string>> result = groupAnagrams(strs);
//     for (int i = 0; i < result.size(); i++)
//     {
//         for (int j = 0; j < result.at(i).size(); j++)
//         {
//             cout << result.at(i).at(j) << "  ";
//         }
//         cout << endl;
//     }
//     return 1;
// }

//--------------------------------------------------------------- 134. Gas Station -----------------------------------------------------------------------
//--------------------- TLE --------------------------------
// int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
// {
//     int n = gas.size();
//     for (int i = 0; i < n; i++)
//     {
//         if (gas[i] < cost[i])
//             continue;
//         int gasTank = gas[i];
//         int j = i;
//         for (j; j < i + n; j++)
//         {
//             if (gasTank < cost[j % n])
//                 break;
//             gasTank = gasTank - cost[j % n] + gas[(j + 1) % n];
//         }
//         if (j == i + n)
//             return i;
//     }
//     return -1;
// }
//------------------------ Try to optimize but not work ----------------------------------
// int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
// {
//     int n = gas.size();
//     int largerTank = INT_MIN, tankIndex = 0;
//     int totalGas = 0, totalCost = 0;
//     for (int i = 0; i < n; i++)
//     {
//         totalGas += gas[i];
//         totalCost += cost[i];
//         if (gas[i] < cost[i])
//             continue;
//         if ((gas[i] - cost[i] + gas[(i + 1) % n]) > largerTank)
//         {
//             if ((gas[i] - cost[i] + gas[(i + 1) % n]) == cost[(i + 1) % n] && ((i + 2) % n == i))
//             {
//                 largerTank = gas[i] - cost[i] + gas[(i + 1) % n];
//                 tankIndex = i;
//             }
//             else if ((gas[i] - cost[i] + gas[(i + 1) % n]) > cost[(i + 1) % n])
//             {
//                 largerTank = gas[i] - cost[i] + gas[(i + 1) % n];
//                 tankIndex = i;
//             }
//         }
//     }
//     if (totalCost > totalGas)
//         return -1;
//     return tankIndex;
// }
//---------------------------------------------------------
// int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
// {
//     int n = gas.size();
//     int total_gas = 0, total_cost = 0;
//     int curr_gas = 0, starting_point = 0;
//     for (int i = 0; i < n; i++)
//     {
//         // these two variable are to check if no case is possible
//         total_cost += cost[i];
//         total_gas += gas[i];
//         // for checking the total present gas at index i
//         curr_gas += gas[i] - cost[i];
//         if (curr_gas < 0)
//         {
//             // there is a breakdown....so we will start from next point or index
//             starting_point = i + 1;
//             // reset our fuel
//             curr_gas = 0;
//         }
//     }
//     return (total_gas < total_cost) ? -1 : starting_point;
// }
//-----------------------------------------------------
// int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
// {
//     int n = gas.size();
//     for (int i = 0; i < n; i++)
//     {
//         int totalFuel = 0;
//         int stopCount = 0, j = i;
//         while (stopCount < n)
//         {
//             totalFuel += gas[j % n] - cost[j % n];
//             if (totalFuel < 0)
//                 break; // whenever we reach -ve
//             stopCount++;
//             j++;
//         }
//         if (stopCount == n && totalFuel >= 0)
//             return i; // cover all the stops & our fuel left is 0 or more than that
//     }
//     return -1;
// }
// int main()
// {
//     vector<int> gas = {1, 2};
//     vector<int> cost = {2, 1};
//     cout << "Starting Gas Station : " << canCompleteCircuit(gas, cost) << endl;
//     return 1;
// }
//--------------------------------------------------------------- 438. Find All Anagrams in a String -----------------------------------------------------------------------
// vector<int> findAnagrams(string s, string p)
// {
//     vector<int> result;
//     int i = 0, n = s.size();
//     int frequency[26] = {0};
//     for (int i = 0; i < p.size(); i++)
//         frequency[p[i] - 97]++;
//     int occured[26] = {0};
//     while (i <= (n - p.length()))
//     {
//         bool isAnagram = true;
//         int j = i;
//         while (j < (p.size() + i))
//             occured[s[j++] - 97]++;
//         for (int k = 0; k < p.size(); k++)
//         {
//             if (frequency[p[k] - 97] != occured[p[k] - 97])
//             {
//                 isAnagram = false;
//                 break;
//             }
//         }
//         if (isAnagram)
//             result.push_back(i);
//         memset(occured, 0, sizeof(occured));
//         i++;
//     }
//     return result;
// }
//-------------------------------------------------------------
// vector<int> findAnagrams(string s, string p)
// {
//     if (p.size() > s.size())
//         return {};
//     int n = s.size();
//     vector<int> result;
//     int frequency[26] = {0};
//     for (int i = 0; i < p.size(); i++)
//         frequency[p[i] - 97]++;
//     int occurred[26] = {0};
//     int i = 0;
//     while (i < p.size())
//         occurred[s[i++] - 97]++;
//     int l = 0, r = p.size();
//     while (r <= n)
//     {
//         bool isAnagram = true;
//         for (int j = 0; j < p.size(); j++)
//             if (frequency[p[j] - 97] != occurred[p[j] - 97])
//             {
//                 isAnagram = false;
//                 break;
//             }
//         if (isAnagram)
//             result.push_back(l);
//         if(r == n)
//             break;
//         occurred[s[l] - 97]--;
//         occurred[s[r] - 97]++;
//         l++;
//         r++;
//     }
//     return result;
// }
//-------------------------------------------------------------
// vector<int> findAnagrams(string s, string p)
// {
//     int s_len = s.size();
//     int p_len = p.size();
//     if (p_len > s_len)
//         return {};
//     vector<int> freq_p(26, 0);
//     vector<int> window(26, 0);
//     // first window
//     for (int i = 0; i < p_len; i++)
//     {
//         freq_p[p[i] - 97]++;
//         window[s[i] - 97]++;
//     }
//     vector<int> result;
//     if (freq_p == window)
//         result.push_back(0);
//     for (int i = p_len; i < s_len; i++)
//     {
//         window[s[i - p_len] - 97]--;
//         window[s[i] - 97]++;
//         if (freq_p == window)
//             result.push_back(i - p_len+1);
//     }
//     return result;
// }
// int main()
// {
//     string s = "abab";
//     string p = "ab";
//     vector<int> result = findAnagrams(s, p);
//     for (auto item : result)
//         cout << item << "  ";
//     return 1;
// }

//--------------------------------------------------------------- 11. Container With Most Water -----------------------------------------------------------------------
//-------------------------Time Limit Exceeded---------------------------------
// int maxArea(vector<int> &height)
// {
//     int n = height.size(), mostWaterLevel = 0, currentWaterLevel = 0;
//     for (int i = 0; i < n - 1; i++)
//     {
//         for (int j = n - 1; j > i; j--)
//         {
//             int maxWaterCanFill = min(height[i], height[j]);
//             currentWaterLevel = (j - i) * maxWaterCanFill;
//             if (currentWaterLevel > mostWaterLevel)
//                 mostWaterLevel = currentWaterLevel;
//         }
//     }
//     return mostWaterLevel;
// }
//-----------------------------------------------
// int maxArea(vector<int> &height)
// {
//     int n = height.size(), mostWaterLevel = 0, maxWaterCanFillBetween = 0;
//     int left = 0, right = n - 1;
//     while (left < right)
//     {
//         maxWaterCanFillBetween = min(height[left], height[right]);
//         mostWaterLevel = max(mostWaterLevel, (right-left) * maxWaterCanFillBetween);
//         while(height[left] <= maxWaterCanFillBetween && left < right) left++;
//         while(height[right] <= maxWaterCanFillBetween && left < right) right--;
//     }
//     return mostWaterLevel;
// }
//--------------------------------------------------
// int maxArea(vector<int> &height)
// {
//     int n = height.size(), mostWaterLevel = 0, maxWaterCanFillBetween = 0;
//     int left = 0, right = n - 1;
//     while (left < right)
//     {
//         maxWaterCanFillBetween = min(height[left], height[right]);
//         mostWaterLevel = max(mostWaterLevel, (right-left) * maxWaterCanFillBetween);
//         if(height[left] < height[right]) left++;
//         else right--;
//     }
//     return mostWaterLevel;
// }
// int main()
// {
//     // vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
//     // vector<int> height = {1, 1};
//     // vector<int> height = {1, 3, 2, 5, 25, 24, 5};
//     vector<int> height = {1, 0, 0, 0, 0, 0, 0, 2, 2};
//     cout << "Container With Most Water : " << maxArea(height) << endl;
//     return 1;
// }
//--------------------------------------------------------------- 5. Longest Palindromic Substring -----------------------------------------------------------------------
// string longestPalindrome(string s)
// {
//     string longestPalindrome = "", currentPalindrome = "";
//     int n = s.size();
//     for (int i = 0; i < n && (n - i) > longestPalindrome.size(); i++)
//     {
//         for (int j = n - 1; j >= i && j >= longestPalindrome.size(); j--)
//         {
//             if (s[i] == s[j])
//             {
//                 int l = i, k = j;
//                 int isPalindrome = true;
//                 while (l <= k)
//                     if (s[l++] != s[k--])

//                         isPalindrome = false;
//                 if (isPalindrome)
//                 {
//                     for (l = i; l <= j; l++)
//                         currentPalindrome.push_back(s[l]);
//                 }
//                 if (currentPalindrome.size() > longestPalindrome.size())
//                     longestPalindrome = currentPalindrome;
//                 currentPalindrome.clear();
//             }
//         }
//     }
//     return longestPalindrome;
// }

// int main()
// {
//     // string s = "babad";
//     // string s = "cbbd";
//     // string s = "a";
//     // string s = "eabcb";
//     string s = "aacabdkacaa";
//     cout << "Longest Palindromic Substring : " << longestPalindrome(s);
//     return 1;
// }
//--------------------------------------------------------------- 8. String to Integer (atoi) -------------------------------------------------------------------------------
// int myAtoi(string s)
// {
//     long long int result = 0;
//     int n = s.length();
//     bool isNegative = false;
//     int signCounter = 0, digitFound = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if(signCounter > 1 || (digitFound || signCounter) && (s[i] == 43 || s[i] == 45 || s[i] == 32))
//             break;
//         if ((s[i] >= 65 && s[i] <= 90) || s[i] >= 97 && s[i] <= 122 || s[i] == 46)
//             break;
//         if (s[i] == 43)
//             signCounter++;
//         if (s[i] == 45)
//         {
//             signCounter++;
//             isNegative = true;
//         }
//         if (s[i] >= 48 && s[i] <= 57)
//         {
//             digitFound = 1;
//             if ((result * 10) + (s[i] - 48) >= 2147483648)
//             {
//                 if (isNegative)
//                     return -2147483648;
//                 return 2147483647;
//             }
//             result = (result * 10) + (s[i] - 48);
//         }
//     }
//     if (isNegative)
//         result *= -1;
//     return result;
// }
//---------------------------------------------
// int myAtoi(string s)
// {
//     int n = s.size();
//     double num = 0;
//     int i = 0;
//     while(s[i] == ' ')
//         i++;
//     bool positive = s[i] == '+';
//     bool negative = s[i] == '-';
//     positive == true ? i++ : i;
//     negative == true ? i++ : i;
//     while(i < n && s[i] >= '0' && s[i] <= '9'){
//         num = (num*10) + (s[i] - '0');
//         i++;
//     }
//     num = negative ? -num : num;
//     num = (num > INT_MAX) ? INT_MAX : num;
//     num = (num < INT_MIN) ? INT_MIN : num;
//     return int(num);
// }
// int main()
// {
//     // string s = "-91283472332";
//     // string s = "   -42";
//     // string s = "3.14159";
//     // string s = "+-12";
//     // string s = "00000-42a1234";
//     // string s = "   +0 123";
//     string s = "  +  413";
//     cout << myAtoi(s);
//     return 1;
// }

//------------------------------------------------------------------ 75. Sort Colors -------------------------------------------------------------------------------
// void sortColors(vector<int> &nums)
// {
//     int n = nums.size();
//     for (int i = 0; i < n - 1; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             if (nums[i] > nums[j])
//                 swap(nums[i], nums[j]);
//         }
//     }
// }
//-----------------------------------
// void sortColors(vector<int> &nums)
// {
//     int left = 0, right = nums.size() - 1;
//     while (left < right)
//     {
//         for (int i = left + 1; i <= right; i++)
//             if (nums[left] > nums[i])
//                 swap(nums[left], nums[i]);
//         left++;
//         for (int i = left; i < right; i++)
//             if (nums[right] < nums[i])
//                 swap(nums[right], nums[i]);
//         right--;
//     }
// }
//-------------------------------------
// void sortColors(vector<int> &nums)
// {
//     // unordered_map<int, int> umap;
//     int frequencyCounter[3] = {0};
//     for (auto item : nums)
//         frequencyCounter[item]++;
//     int position = 0;
//     for (int i = 0; i < frequencyCounter[0]; i++)
//         nums[position++] = 0;
//     for (int i = 0; i < frequencyCounter[1]; i++)
//         nums[position++] = 1;
//     for (int i = 0; i < frequencyCounter[2]; i++)
//         nums[position++] = 2;
// }
// int main()
// {
//     vector<int> nums = {2, 0, 2, 1, 1, 0};
//     // vector<int> nums = {2, 0, 1};
//     sortColors(nums);
//     for (int i = 0; i < nums.size(); i++)
//         cout << nums[i] << " ";
//     return 1;
// }
//------------------------------------------------------------------ 56. Merge Intervals -------------------------------------------------------------------------------
// vector<vector<int>> merge(vector<vector<int>> &intervals)
// {
//     vector<vector<int>> answer;
//     sort(intervals.begin(), intervals.end());
//     int n = intervals.size();
//     vector<int> newInterval = intervals[0];
//     for (int i = 0; i < n; i++)
//     {
//         if (intervals[i][0] > newInterval[1])
//         {
//             answer.push_back(newInterval);
//             newInterval = intervals[i];
//         }
//         else if (intervals[i][0] <= newInterval[1] && intervals[i][1] >= newInterval[0])
//         {
//             newInterval[0] = min(intervals[i][0], newInterval[0]);
//             newInterval[1] = max(intervals[i][1], newInterval[1]);
//         }
//     }
//     answer.push_back(newInterval);
//     return answer;
// }
//-------------------------------------------------
// vector<vector<int>> merge(vector<vector<int>> &intervals)
// {
//     vector<vector<int>> answer;
//     int n = intervals.size(), i = 0;
//     sort(intervals.begin(), intervals.end());
//     vector<int> newInterval = intervals[0];
//     while (i < n)
//     {
//         if (intervals[i][0] <= newInterval[1] && intervals[i][1] >= newInterval[0])
//         {
//             newInterval[0] = min(intervals[i][0], newInterval[0]);
//             newInterval[1] = max(intervals[i][1], newInterval[1]);
//         }
//         else if (intervals[i][0] > newInterval[1])
//         {
//             answer.push_back(newInterval);
//             newInterval = intervals[i];
//         }
//         i++;
//     }
//     answer.push_back(newInterval);
//     return answer;
// }
//--------------------------------------------------
// vector<vector<int>> merge(vector<vector<int>> &intervals)
// {
//     vector<vector<int>> answer;
//     sort(intervals.begin(), intervals.end());
//     vector<int> newInterval = intervals[0];
//     int i = 1, n = intervals.size();
//     while (i < n)
//     {
//         if (intervals[i][0] <= newInterval[1])
//             newInterval[1] = max(intervals[i][1], newInterval[1]);
//         else if (intervals[i][0] > newInterval[1])
//         {
//             answer.push_back(newInterval);
//             newInterval = intervals[i];
//         }
//         i++;
//     }
//     answer.push_back(newInterval);
//     return answer;
// }
// int main()
// {
//     // vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
//     // vector<vector<int>> intervals = {{1, 4}, {4, 5}};
//     vector<vector<int>> intervals = {{2, 3}, {2, 2}, {3, 3}, {1, 3}, {5, 7}, {2, 2}, {4, 6}};
//     vector<vector<int>> answer = merge(intervals);
//     for (int i = 0; i < answer.size(); i++)
//     {
//         cout << "{";
//         for (int j = 0; j < answer[i].size(); j++)
//             cout << answer[i][j] << " ";
//         cout << "}" << endl;
//     }
//     return 1;
// }
//------------------------------------------------------------------ 39. Combination Sum -------------------------------------------------------------------------------
//------------------------ Incorrect Solution ----------------------------
// vector<vector<int>> combinationSum(vector<int> &candidates, int target)
// {
//     vector<vector<int>> answer;
//     unordered_map<int, int> hashMap;
//     set<vector<int>> setVector;
//     vector<int> temp;
//     sort(candidates.begin(), candidates.end());
//     int n = candidates.size(), current, required, howManyTimes;
//     for (int i = 0; i < n; i++)
//         hashMap[candidates[i]] = 1;
//     for (int i = 0; i < n; i++)
//     {
//         if (candidates[i] > target)
//             break;
//         if (candidates[i] == target)
//             answer.push_back({candidates[i]});
//         current = candidates[i];
//         while (current <= target)
//         {
//             required = target - current;
//             if (hashMap.count(required))
//             {
//                 howManyTimes = current / candidates[i];
//                 while (howManyTimes)
//                 {
//                     temp.push_back(candidates[i]);
//                     howManyTimes--;
//                 }
//                 temp.push_back(required);
//                 sort(temp.begin(), temp.end());
//                 setVector.insert(temp);
//                 temp.clear();
//             }
//             current += candidates[i];
//         }
//     }
//     for (auto item : setVector)
//         answer.push_back(item);
//     return answer;
// }
//--------------------------------------------------
// vector<vector<int>> combinationSum(vector<int> &candidates, int target)
// {
// }
// int main()
// {
//     // vector<int> candidates = {2, 3, 6, 7};
//     // int target = 7;
//     vector<int> candidates = {2, 3, 5};
//     int target = 8;
//     vector<vector<int>> answer = combinationSum(candidates, target);
// for (int i = 0; i < answer.size(); i++)
// {
//     cout << "{";
//     for (int j = 0; j < answer[i].size(); j++)
//         cout << answer[i][j] << " ";
//     cout << "}" << endl;
// }
//     return 1;
// }
//----------------------------------------------------------- 238. Product of Array Except Self ------------------------------------------------------------------------
//---------------- Time Limit Exceeded -----------------
// vector<int> productExceptSelf(vector<int> &nums)
// {
//     vector<int> answer;
//     int n = nums.size(), product = 1;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (i != j)
//                 product *= nums[j];
//         }
//         answer.push_back(product);
//         product = 1;
//     }
//     return answer;
// }
//----------------------------------------
// vector<int> productExceptSelf(vector<int> &nums)
// {
//     int n = nums.size();
//     vector<int> leftToRight(n);
//     vector<int> rightToLeft(n);
//     int product = 1;
//     for (int i = 0; i < n; i++)
//         leftToRight[i] = (product *= nums[i]);
//     product = 1;
//     for (int i = n - 1; i >= 0; i--)
//         rightToLeft[i] = (product *= nums[i]);
//     for (int i = 0; i < n; i++)
//     {
//         if (i == 0)
//             nums[i] = rightToLeft[i + 1];
//         else if (i == n - 1)
//             nums[i] = leftToRight[n - 2];
//         else
//             nums[i] = leftToRight[i - 1] * rightToLeft[i + 1];
//     }
//     return nums;
// }
//-----------------------------------------
// vector<int> productExceptSelf(vector<int> &leftToRight)
// {
//     int n = leftToRight.size();
//     vector<int> rightToLeft(n);
//     int product = 1;
//     for (int i = n - 1; i >= 0; i--)
//         rightToLeft[i] = (product *= leftToRight[i]);
//     product = 1;
//     for (int i = 0; i < n; i++)
//         leftToRight[i] = (product *= leftToRight[i]);
//     for (int i = 0; i < n; i++)
//     {
//         if (i == 0)
//             rightToLeft[i] = rightToLeft[i + 1];
//         else if (i == n - 1)
//             rightToLeft[i] = leftToRight[n - 2];
//         else
//             rightToLeft[i] = leftToRight[i - 1] * rightToLeft[i + 1];
//     }
//     return rightToLeft;
// }
//------------------------------------------
// vector<int> productExceptSelf(vector<int> &nums)
// {
//     int n = nums.size();
//     vector<int> leftToRight(n);
//     int product = 1;
//     for (int i = 0; i < n; i++)
//         leftToRight[i] = (product *= nums[i]);
//     product = 1;
//     for (int i = n - 1; i >= 0; i--)
//     {
//         if (i == n - 1)
//         {
//             leftToRight[i] = leftToRight[n - 2];
//             product *= nums[i];
//         }
//         else if (i == 0)
//             leftToRight[i] = product;
//         else
//         {
//             leftToRight[i] = leftToRight[i - 1] * product;
//             product *= nums[i];
//         }
//     }
//     return leftToRight;
// }
// int main()
// {
//     vector<int> nums = {1, 2, 3, 4};
//     // vector<int> nums = {-1, 1, 0, -3, 3};
//     vector<int> answer = productExceptSelf(nums);
//     for (auto item : answer)
//         cout << item << "  ";
//     return 1;
// }

//---------------------------------------------------------------------- 15. 3Sum --------------------------------------------------------------------------------------
//------------------ Time Limit Exceeded --------------------
// vector<vector<int>> threeSum(vector<int> &nums)
// {
//     vector<vector<int>> result;
//     set<vector<int>> sv;
//     vector<int> temp;
//     int n = nums.size(), total = 0;
//     for (int i = 0; i < n - 2; i++)
//     {
//         total += nums[i];
//         for (int j = i + 1; j < n - 1; j++)
//         {
//             total += nums[j];
//             for (int k = j + 1; k < n; k++)
//             {
//                 total += nums[k];
//                 if (total == 0)
//                 {
//                     temp.push_back(nums[i]);
//                     temp.push_back(nums[j]);
//                     temp.push_back(nums[k]);
//                     sort(temp.begin(), temp.end());
//                     sv.insert(temp);
//                     temp.clear();
//                 }
//                 total -= nums[k];
//             }
//             total -= nums[j];
//         }
//         total = 0;
//     }
// for (auto item : sv)
//     result.push_back(item);
//     return result;
// }
//------------------Time Limit Exceeded-----------------------------
// vector<vector<int>> threeSum(vector<int> &nums)
// {
//     set<vector<int>> setVector;
//     vector<vector<int>> result;
//     vector<int> temp;
//     unordered_map<int, int> umap;
//     int n = nums.size();
//     for (int i = 0; i < n; i++)
//         umap[nums[i]]++;
//     for (int i = 0; i < n - 1; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             int target = -(nums[i] + nums[j]);
//             if ((target == nums[i]) && (target == nums[j]))
//             {
//                 if (umap[target] > 2)
//                 {
//                     temp.push_back(nums[i]);
//                     temp.push_back(nums[j]);
//                     temp.push_back(target);
//                     sort(temp.begin(), temp.end());
//                     setVector.insert(temp);
//                     temp.clear();
//                 }
//             }
//             else if ((target == nums[i]) || (target == nums[j]))
//             {
//                 if (umap[target] > 1)
//                 {
//                     temp.push_back(nums[i]);
//                     temp.push_back(nums[j]);
//                     temp.push_back(target);
//                     sort(temp.begin(), temp.end());
//                     setVector.insert(temp);
//                     temp.clear();
//                 }
//             }
//             else if (umap[target])
//             {
//                 temp.push_back(nums[i]);
//                 temp.push_back(nums[j]);
//                 temp.push_back(target);
//                 sort(temp.begin(), temp.end());
//                 setVector.insert(temp);
//                 temp.clear();
//             }
//         }
//     }
//     for (auto item : setVector)
//         result.push_back(item);
//     return result;
// }
//------------------- Time Limit Exceed -----------------------------
// vector<vector<int>> threeSum(vector<int> &nums)
// {
//     set<vector<int>> setVector;
//     vector<vector<int>> result;
//     vector<int> temp;
//     unordered_map<int, int> umap;
//     int n = nums.size(), flag = 0;
//     for (int i = 0; i < n; i++)
//         umap[nums[i]]++;
//     for (int i = 0; i < n - 1; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             flag = 0;
//             int target = -(nums[i] + nums[j]);
//             if ((target == nums[i]) && (target == nums[j]))
//             {
//                 if (umap[target] > 2)
//                     flag = 1;
//             }
//             else if ((target == nums[i]) || (target == nums[j]))
//             {
//                 if (umap[target] > 1)
//                     flag = 1;
//             }
//             else if (umap[target])
//                 flag = 1;
//             if (flag)
//             {
//                 temp.push_back(nums[i]);
//                 temp.push_back(nums[j]);
//                 temp.push_back(target);
//                 sort(temp.begin(), temp.end());
//                 setVector.insert(temp);
//                 temp.clear();
//             }
//         }
//     }
//     for (auto item : setVector)
//         result.push_back(item);
//     return result;
// }
//-------------------------------------------------
// vector<vector<int>> threeSum(vector<int> &nums)
// {
//     sort(nums.begin(), nums.end()); // Sorted Array
//     if (nums.size() < 3)
//     { // Base case 1
//         return {};
//     }
//     if (nums[0] > 0)
//     { // Base case 2
//         return {};
//     }
//     vector<vector<int>> answer;
//     for (int i = 0; i < nums.size(); ++i)
//     { // Traversing the array to fix the number.
//         if (nums[i] > 0)
//         { // If number fixed is +ve, stop there because we can't make it zero by searching after it.
//             break;
//         }
//         if (i > 0 && nums[i] == nums[i - 1])
//         { // If number is getting repeated, ignore the lower loop and continue.
//             continue;
//         }
//         int low = i + 1, high = nums.size() - 1; // Make two pointers high and low, and initialize sum as 0.
//         int sum = 0;
//         while (low < high)
//         { // Search between two pointers, just similiar to binary search.
//             sum = nums[i] + nums[low] + nums[high];
//             if (sum > 0)
//             { // If sum is +ve, means, we need more -ve numbers to make it 0, decreament high (high--).
//                 high--;
//             }
//             else if (sum < 0)
//             { // If sum is -ve, means, we need more +ve numbers to make it 0, increament low (low++).
//                 low++;
//             }
//             else
//             {
//                 answer.push_back({nums[i], nums[low], nums[high]});                   // we have found the required triplet, push it in answer vector
//                 int last_low_occurence = nums[low], last_high_occurence = nums[high]; // Now again, to avoid duplicate triplets, we have to navigate to last occurences of num[low] and num[high] respectively
//                 while (low < high && nums[low] == last_low_occurence)
//                 { // Update the low and high with last occurences of low and high.
//                     low++;
//                 }
//                 while (low < high && nums[high] == last_high_occurence)
//                 {
//                     high--;
//                 }
//             }
//         }
//     }
//     return answer; // Return the answer vector.
// }
//-------------------------------------------------
// vector<vector<int>> threeSum(vector<int> &nums)
// {
//     vector<vector<int>> result;
//     sort(nums.begin(), nums.end());
//     if (nums.size() < 3)
//         return result;
//     if (nums[0] > 0)
//         return result;
//     int sum = 0, n = nums.size();
//     for (int i = 0; i < n; i++)
//     {
//         if (nums[i] > 0)
//             break;
//         if (i > 0 && nums[i] == nums[i - 1])
//             continue;
//         int low = i + 1;
//         int high = n - 1;
//         while (low < high)
//         {
//             sum = nums[i] + nums[low] + nums[high];
//             if (sum < 0)
//                 low++;
//             else if (sum > 0)
//                 high--;
//             else
//             {
//                 result.push_back({nums[i], nums[low], nums[high]});
//                 int lastLowOccurence = nums[low];
//                 int lastHighOccurence = nums[high];
//                 while (low < high && nums[low] == lastLowOccurence)
//                     low++;
//                 while (low < high && nums[high] == lastHighOccurence)
//                     high--;
//             }
//         }
//     }
//     return result;
// }
//-------------------------------------------
// vector<vector<int>> threeSum(vector<int> &nums)
// {
//     sort(nums.begin(), nums.end()); // Sorted Array
//     if (nums.size() < 3)
//     { // Base Case 1
//         return {};
//     }
//     if (nums[0] > 0)
//     { // Base Case 2
//         return {};
//     }
//     unordered_map<int, int> hashMap;
//     for (int i = 0; i < nums.size(); ++i)
//     { // Hashing of Indices
//         hashMap[nums[i]] = i;
//     }
//     vector<vector<int>> answer;
//     for (int i = 0; i < nums.size() - 2; ++i)
//     { // Traversing the array to fix the number.
//         if (nums[i] > 0)
//         { // If number fixed is +ve, stop there because we can't make it zero by searching after it.
//             break;
//         }
//         for (int j = i + 1; j < nums.size() - 1; ++j)
//         {                                            // Fixing another number after first number
//             int required = -1 * (nums[i] + nums[j]); // To make sum 0, we would require the -ve sum of both fixed numbers.
//             if (hashMap.count(required) && hashMap.find(required)->second > j)
//             { // If it exists in hashmap and its last occurrence index > 2nd fixed index, we found our triplet.
//                 answer.push_back({nums[i], nums[j], required});
//             }
//             j = hashMap.find(nums[j])->second; // Update j to last occurence of 2nd fixed number to avoid duplicate triplets.
//         }
//         i = hashMap.find(nums[i])->second; // Update i to last occurence of 1st fixed number to avoid duplicate triplets.
//     }
//     return answer; // Return answer vector.
// }
// --------------------------------------------------
// vector<vector<int>> threeSum(vector<int> &nums)
// {
//     vector<vector<int>> result;
//     sort(nums.begin(), nums.end());
//     if (nums.size() < 3)
//         return result;
//     if (nums[0] > 0)
//         return result;
//     int required, n = nums.size();
//     unordered_map<int, int> hashMap;
//     for (int i = 0; i < n; i++)
//         hashMap[nums[i]] = i;
//     for (int i = 0; i < n - 2; i++)
//     {
//         if (nums[i] > 0)
//             break;
//         for (int j = i + 1; j < n - 1; j++)
//         {
//             required = -1 * (nums[i] + nums[j]);
//             if (hashMap.count(required) && hashMap.find(required)->second > j)
//                 result.push_back({nums[i], nums[j], required});
//             j = hashMap.find(nums[j])->second;
//         }
//         i = hashMap.find(nums[i])->second;
//     }
//     return result;
// }
// int main()
// {
//     vector<int> nums = {-1, 0, 1, 2, -1, -4};
//     // vector<int> nums = {-1, 0, 1, 2, -1, -4, -2, -3, 3, 0, 4};
//     // vector<int> nums = {0, 1, 1};
//     // vector<int> nums = {0, 0, 0};
//     // vector<int> nums = {1, 2, -2, -1};
//     vector<vector<int>> result = threeSum(nums);
//     for (auto item : result)
//         cout << item[0] << " : " << item[1] << " : " << item[2] << endl;
//     return 1;
// }

//----------------------------------------------------------------- 3. Longest Substring Without Repeating Characters --------------------------------------------------------------------------
// int lengthOfLongestSubstring(string s)
// {
//     unordered_map<char, int> characterCounter;
//     int longestLenghtSubstring = 0, currentLength = 0, n = s.size();
//     for (int i = 0; i < n; i++)
//     {
//         characterCounter[s[i]] = 1;
//         currentLength = 1;
//         for (int j = i + 1; j < n; j++)
//         {
//             if (characterCounter[s[j]] == 0)
//             {
//                 currentLength++;
//                 characterCounter[s[j]] = 1;
//             }
//             else
//                 break;
//         }
//         if (currentLength > longestLenghtSubstring)
//             longestLenghtSubstring = currentLength;
//         characterCounter.clear();
//     }
//     if (currentLength > longestLenghtSubstring)
//         longestLenghtSubstring = currentLength;
//     return longestLenghtSubstring;
// }
//------------------------------------------------
// int lengthOfLongestSubstring(string s)
// {
//     string subString = "";
//     int longestLenghtSubstring = 0, n = s.size(), i = 0;
//     while (i < n && (subString.size() + (n-i)) > longestLenghtSubstring)
//     {
//         if (subString.find(s[i]) >= 0 && subString.find(s[i]) < subString.size())
//         {
//             if (subString.size() > longestLenghtSubstring)
//                 longestLenghtSubstring = subString.size();
//             subString.clear();
//             i = s.find(s[i]);
//             s.replace(0, i+1, "");
//             i = 0;
//             n = s.size();
//         }
//         else
//             subString.push_back(s[i++]);
//     }
//     if (subString.size() > longestLenghtSubstring)
//         longestLenghtSubstring = subString.size();
//     return longestLenghtSubstring;
// }
//------------------- Sliding Window --------------------------------
// int lengthOfLongestSubstring(string s)
// {
//     string currSubStr = "", longestLenghtSubStr = "";
//     int n = s.size();
//     for (int i = 0; i < n; i++)
//     {
//         int index = currSubStr.find(s[i]);
//         if (index >= 0 && index < n)
//         {
//             if (currSubStr.size() > longestLenghtSubStr.size())
//                 longestLenghtSubStr = currSubStr;
//             currSubStr.replace(0, index + 1, "");
//             currSubStr.push_back(s[i]);
//         }
//         else
//             currSubStr.push_back(s[i]);
//     }
//     if (currSubStr.size() > longestLenghtSubStr.size())
//         longestLenghtSubStr = currSubStr;
//     return longestLenghtSubStr.size();
// }
//--------------------------------------
// int lengthOfLongestSubstring(string s)
// {
//     string currSubStr = "";
//     int longestLenghtSubStr = 0;
//     int n = s.size();
//     for (int i = 0; i < n; i++)
//     {
//         int index = currSubStr.find(s[i]);
//         if (index >= 0 && index < n)
//         {
//             if (currSubStr.size() > longestLenghtSubStr)
//                 longestLenghtSubStr = currSubStr.size();
//             currSubStr.replace(0, index + 1, "");
//         }
//         currSubStr.push_back(s[i]);
//     }
//     if (currSubStr.size() > longestLenghtSubStr)
//         longestLenghtSubStr = currSubStr.size();
//     return longestLenghtSubStr;
// }
// int main()
// {
//     // string s = "abcabcbb";
//     // string s = "pwwkew";
//     // string s = "bbbbb";
//     // string s = "dvdf";
//     // string s = " ";
//     // string s = "abcbad";
//     string s = "aabaab!bb";
//     cout << "Longest Substring Without Repeating Characters : " << lengthOfLongestSubstring(s) << endl;
//     return 1;
// }

//----------------------------------------------------------------- 57. Insert Interval --------------------------------------------------------------------------
//------------------------------- Tried But Failed-------------------------------------
// vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
// {
//     if (intervals.size() == 0)
//         return {{newInterval}};
//     if (intervals[intervals.size() - 1][1] < newInterval[0])
//     {
//         intervals.push_back(newInterval);
//         return intervals;
//     }
//     vector<vector<int>> result;
//     vector<int> temp;
//     int flag = 0, i;
//     for (i = 0; i < intervals.size(); i++)
//     {
//         if (intervals[i][0] > newInterval[0] && temp.empty())
//         {
//             temp.push_back(newInterval[0]);
//             if (intervals[i][1] > newInterval[1]){
//                 temp.push_back(intervals[i][1]);
//                 result.push_back(temp);
//             }
//         }
//         else if (intervals[i][0] <= newInterval[0] && newInterval[0] <= intervals[i][1])
//         {
//             temp.push_back(intervals[i][0]);
//             if (intervals[i][0] <= newInterval[1] && newInterval[1] <= intervals[i][1])
//             {
//                 temp.push_back(intervals[i][1]);
//                 result.push_back(temp);
//                 flag = 1;
//                 i++;
//                 break;
//             }
//         }
//         else if (newInterval[1] < intervals[i][0])
//         {
//             temp.push_back(newInterval[1]);
//             result.push_back(temp);
//             flag = 1;
//             break;
//         }
//         else if (newInterval[1] == intervals[i][0])
//         {
//             temp.push_back(intervals[i][1]);
//             result.push_back(temp);
//             flag = 1;
//             i++;
//             break;
//         }
//         else if (temp.empty())
//         {
//             result.push_back(intervals[i]);
//         }
//     }
//     if (flag)
//     {
//         for (i; i < intervals.size(); i++)
//             result.push_back(intervals[i]);
//     }
//     if (temp.size() == 1)
//     {
//         temp.push_back(newInterval[1]);
//         result.push_back(temp);
//     }
//     return result;
// }
//-------------------------------------------------------
// vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
// {
//     vector<vector<int>> result;
//     int i = 0, n = intervals.size();
//     while (i < n && intervals[i][1] < newInterval[0])
//     {
//         result.push_back(intervals[i]);
//         i++;
//     }
//     while (i < n && newInterval[1] >= intervals[i][0])
//     {
//         newInterval[0] = min(newInterval[0], intervals[i][0]);
//         newInterval[1] = max(newInterval[1], intervals[i][1]);
//         i++;
//     }
//     result.push_back(newInterval);
//     while (i < n)
//     {
//         result.push_back(intervals[i]);
//         i++;
//     }
//     return result;
// }
//------------------------------------------------
// vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
// {
//     vector<vector<int>> result;
//     for (int i = 0; i < intervals.size(); i++)
//     {
//         if (intervals[i][1] < newInterval[0])
//             result.push_back(intervals[i]);
//         else if (intervals[i][0] > newInterval[1])
//         {
//             result.push_back(newInterval);
//             newInterval = intervals[i];
//         }
//         else if (intervals[i][0] <= newInterval[1] && intervals[i][1] >= newInterval[0])
//         {
//             newInterval[0] = min(intervals[i][0], newInterval[0]);
//             newInterval[1] = max(newInterval[1], intervals[i][1]);
//         }
//     }
//     result.push_back(newInterval);
//     return result;
// }
// int main()
// {
//     // vector<vector<int>> intervals = {{1, 3}, {6, 9}};
//     // vector<int> newInterval = {2, 5};
//     vector<vector<int>> intervals = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
//     // vector<vector<int>> intervals = {};
//     vector<int> newInterval = {4, 8};
//     // vector<vector<int>> intervals = {{1, 5}};
//     // vector<int> newInterval = {0, 3};
//     intervals = insert(intervals, newInterval);
//     for (int i = 0; i < intervals.size(); i++)
//     {
//         cout << "{ " << intervals[i][0] << ", " << intervals[i][1] << " }" << endl;
//     }
//     return 1;
// }

//----------------------------------------------------------------- 977. Squares of a Sorted Array --------------------------------------------------------------------------
// vector<int> sortedSquares(vector<int> &nums)
// {
//     vector<int> sortedSquares;
//     int left = 0, right = nums.size() - 1;
//     while (left <= right)
//     {
//         int leftSquare = pow(nums[left], 2);
//         int rightSquare = pow(nums[right], 2);
//         if (rightSquare > leftSquare)
//         {
//             sortedSquares.push_back(rightSquare);
//             right--;
//         }
//         else
//         {
//             sortedSquares.push_back(leftSquare);
//             left++;
//         }
//     }
//     reverse(sortedSquares.begin(), sortedSquares.end());
//     return sortedSquares;
// }
//----------------------------------------
// vector<int> sortedSquares(vector<int> &nums)
// {
//     int n = nums.size();
//     vector<int> sortedSquares(n);
//     int left = 0, right = n - 1;
//     for (int pos = n - 1; pos >= 0; pos--)
//     {
//         if(abs(nums[left]) > abs(nums[right]))
//             sortedSquares[pos] = nums[left] * nums[left++];
//         else
//             sortedSquares[pos] = nums[right] * nums[right--];
//     }
//     return sortedSquares;
// }
// int main()
// {
//     // vector<int> nums = {-4, -1, 0, 3, 10};
//     // vector<int> nums = {-7, -3, 2, 3, 11};
//     vector<int> nums = {-5, -3, -2, -1};
//     nums = sortedSquares(nums);
//     for (auto item : nums)
//         cout << item << "  ";
//     return 1;
// }

//----------------------------------------------------------------- 283. Move Zeroes --------------------------------------------------------------------------
// void moveZeroes(vector<int> &nums)
// {
//     int targetIndex = 0;
//     for (int i = 0; i < nums.size(); i++)
//         if (nums[i] == 0)
//         {
//             targetIndex = i;
//             break;
//         }
//     int currentIndex = targetIndex + 1;
//     while (currentIndex < nums.size() && targetIndex < nums.size())
//     {
//         if (nums[targetIndex] != 0)
//         {
//             targetIndex++;
//             continue;
//         }
//         if (nums[currentIndex] != 0)
//         {
//             int temp = nums[targetIndex];
//             nums[targetIndex] = nums[currentIndex];
//             nums[currentIndex] = temp;
//             targetIndex++;
//             currentIndex++;
//         }
//         else
//             currentIndex++;
//     }
// }
//----------------------------------------------------
// void moveZeroes(vector<int> &nums)
// {
//     int targetIndex = 0;
//     int currentIndex = 0;
//     for (; currentIndex < nums.size(); currentIndex++)
//     {
//         if(nums[currentIndex] != 0)
//             nums[targetIndex++] = nums[currentIndex];
//     }
//     while(targetIndex < nums.size())
//         nums[targetIndex++] = 0;
// }
// int main()
// {
//     vector<int> nums = {0, 1, 0, 3, 12};
//     moveZeroes(nums);
//     for (auto item : nums)
//         cout << item << "  ";
//     return 1;
// }

//----------------------------------------------------------------- 14. Longest Common Prefix --------------------------------------------------------------------------
// string longestCommonPrefix(vector<string> &strs)
// {
//     string longestCommonPrefix = "";
//     for (int i = 0; i < strs[0].size(); i++)
//     {
//         char ch = strs[0][i];
//         for (int j = 1; j < strs.size(); j++)
//         {
//             if (ch != strs[j][i])
//                 return longestCommonPrefix;
//         }
//         longestCommonPrefix.push_back(ch);
//     }
//     return longestCommonPrefix;
// }
//-----------------------------------------------
// string longestCommonPrefix(vector<string> &strs)
// {
//     string longestCommonPrefix = "";
//     sort(strs.begin(), strs.end());
//     string firstString = strs[0];
//     string lastString = strs[strs.size() - 1];
//     for (int i = 0; i < firstString.size(); i++)
//     {
//         if(firstString[i] != lastString[i])
//             return longestCommonPrefix;
//         longestCommonPrefix.push_back(firstString[i]);
//     }
//     return longestCommonPrefix;
// }
// int main()
// {
//     // vector<string> strs = {"flower", "flow", "flight"};
//     // vector<string> strs = {"dog", "racecar", "car"};
//     vector<string> strs = {"a"};
//     cout << "Longest Common Prefix Is : " << longestCommonPrefix(strs) << endl;
//     return 1;
// }

//----------------------------------------------------------------- 217. Contains Duplicate --------------------------------------------------------------------------
// bool containsDuplicate(vector<int> &nums)
// {
//     unordered_map<int, int> digitCounter;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         if(digitCounter[nums[i]])
//             return true;
//         digitCounter[nums[i]]++;
//     }
//     return 0;
// }
//------------------ Great Appoach But Not Working -------------------------
// bool containsDuplicate(vector<int> &nums)
// {
//     int maxElement = -1;
//     int minElement = 0;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         if (maxElement < nums[i])
//             maxElement = nums[i];
//         if (nums[i] < 0 && minElement > nums[i])
//             minElement = nums[i];
//     }
//     int positiveDigitCount[maxElement + 1];
//     int negativeDigitCount[(-1 * minElement) + 1];
//     memset(positiveDigitCount, 0, sizeof(positiveDigitCount));
//     memset(negativeDigitCount, 0, sizeof(negativeDigitCount));
//     for (int i = 0; i < nums.size(); i++)
//     {
//         if (nums[i] > -1)
//         {
//             if (positiveDigitCount[nums[i]])
//                 return true;
//             positiveDigitCount[nums[i]] = 1;
//         }
//         if (nums[i] < 0)
//         {
//             if(negativeDigitCount[-1*nums[i]])
//                 return true;
//             negativeDigitCount[-1*nums[i]] = 1;
//         }
//     }
//     return false;
// }
//-------------------------------------------
// bool containsDuplicate(vector<int> &nums)
// {
//     unordered_set<int> u_set(nums.begin(), nums.end());
//     return nums.size() > u_set.size();
// }
// int main()
// {
//     vector<int> nums = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
//     // vector<int> nums = {1, 2, 3, 4};
//     // vector<int> nums = {1, 2, 3, 1};
//     // vector<int> nums = {1, 5, -2, -4, 0};
//     cout << "Contains Duplicate : " << containsDuplicate(nums) << endl;
//     return 1;
// }

//----------------------------------------------------------------- 169. Majority Element --------------------------------------------------------------------------
// int majorityElement(vector<int> &nums)
// {
//     sort(nums.begin(), nums.end());
//     return nums[nums.size()/2];
// }
// -----------------Boyer-Moore Majority Voting Algorithm--------------------
// int majorityElement(vector<int> &nums)
// {
//     int i, candidate = -1, votes = 0;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         if (votes == 0)
//         {
//             candidate = nums[i];
//             votes = 1;
//         }
//         else
//         {
//             if (candidate == nums[i])
//                 votes++;
//             else
//                 votes--;
//         }
//     }
//     int count = 0;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         if(candidate == nums[i])
//             count++;
//     }
//     if(count > nums.size()/2)
//         return candidate;
//     return -1;
// }
// int main()
// {
//     vector<int> nums = {3,2,3};
//     // vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
//     cout << "Majority Element Is : " << majorityElement(nums) << endl;
//     return 1;
// }

//----------------------------------------------------------------- 53. Maximum Subarray --------------------------------------------------------------------------
// int maxSubArray(vector<int> &nums)
// {
//     int currentSum = 0, maxSubArraySum = INT_MIN;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         currentSum += nums.at(i);
//         if (currentSum < nums.at(i))
//             currentSum = nums.at(i);
//         if (currentSum > maxSubArraySum)
//             maxSubArraySum = currentSum;
//     }
//     return maxSubArraySum;
// }
//---------------- (Kadane’s Algorithm) -------------------
// Pseudocode :-
// Initialize:
//     max_so_far = INT_MIN
//     max_ending_here = 0
// Loop for each element of the array
//   (a) max_ending_here = max_ending_here + a[i]
//   (b) if(max_so_far < max_ending_here)
//             max_so_far = max_ending_here
//   (c) if(max_ending_here < 0)
//             max_ending_here = 0
// return max_so_far
//-------
// int maxSubArray(vector<int> &nums)
// {
//     int max_so_for = INT_MIN;
//     int max_ending_here = 0;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         max_ending_here += nums[i];
//         if(max_ending_here > max_so_for)
//             max_so_for = max_ending_here;
//         if(max_ending_here < 0)
//             max_ending_here = 0;
//     }
//     return max_so_for;
// }
// int main()
// {
//     // vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
//     // vector<int> nums = {1};
//     vector<int> nums = {5, 4, -1, 7, 8};
//     cout << "Maximum Subarray : " << maxSubArray(nums) << endl;
//     return 1;
// }

//----------------------------------------------------------------- 409. Longest Palindrome --------------------------------------------------------------------------
// int longestPalindrome(string s)
// {
//     int longestPalindrome = 0;
//     unordered_map<char, int> characterCounter;
//     for (int i = 0; i < s.length(); i++)
//         characterCounter[s[i]]++;
//     for (auto item : characterCounter)
//         longestPalindrome += (item.second/2) * 2;
//     if(longestPalindrome != s.length())
//         longestPalindrome++;
//     return longestPalindrome;
// }
//--------------------------------------
// int longestPalindrome(string s)
// {
//     int longestPalindrome = 0, counter = 1;
//     sort(s.begin(), s.end());
//     for (int i = 1; i < s.size(); i++)
//     {
//         if (s[i] != s[i - 1])
//         {
//             longestPalindrome += (counter/2)*2;
//             counter = 1;
//         }
//         else
//             counter++;
//     }
//     longestPalindrome += (counter/2)*2;
//     if(longestPalindrome != s.size())
//         longestPalindrome++;
//     return longestPalindrome;
// }
//-----------------------------------------
// int longestPalindrome(string s)
// {
//     int longestPalindrome = 0;
//     int counterForCapitalLetters[26] = {0};
//     int counterForSmallLetters[26] = {0};
//     for (int i = 0; i < s.size(); i++)
//     {
//         if (s[i] >= 97 && s[i] <= 122)
//             counterForSmallLetters[s[i] - 97]++;
//         else
//             counterForCapitalLetters[s[i] - 65]++;
//     }
//     for (int i = 0; i < 26; i++)
//     {
//         longestPalindrome += (counterForSmallLetters[i] / 2) * 2;
//         longestPalindrome += (counterForCapitalLetters[i] / 2) * 2;
//     }
//     if(longestPalindrome != s.size())
//         longestPalindrome++;
//     return longestPalindrome;
// }
// int main()
// {
//     string s = "abcccccddd";
//     // string s = "ab";
//     cout << "Longest Palindrome Length : " << longestPalindrome(s) << endl;
//     return 1;
// }

//-----------------------------------------------------------------242. Valid Anagram--------------------------------------------------------------------------
// bool isAnagram(string s, string t)
// {
//     int counterFor_s[26] = {0};
//     int counterFor_t[26] = {0};
//     for (int i = 0; i < s.size(); i++)
//         counterFor_s[s[i] - 97]++;
//     for (int i = 0; i < t.size(); i++)
//         counterFor_t[t[i] - 97]++;
//     for (int i = 0; i < 26; i++)
//     {
//         if (counterFor_s[i] != counterFor_t[i])
//             return false;
//     }
//     return true;
// }
//---------------------------------------
// bool isAnagram(string s, string t)
// {
//     unordered_map<char, int> counterFor_s;
//     unordered_map<char, int> counterFor_t;
//     for (int i = 0; i < s.size(); i++)
//         counterFor_s[s[i]]++;
//     for (int i = 0; i < t.size(); i++)
//         counterFor_t[t[i]]++;
//     if(counterFor_s.size() != counterFor_t.size())
//         return false;
//     for (auto itr = counterFor_s.begin(); itr != counterFor_s.end(); itr++)
//     {
//         if(itr->second != counterFor_t[itr->first])
//             return false;
//     }
//     return true;
// }
//-----------------------------------------
// bool isAnagram(string s, string t)
// {
//     int counterFor_s[26] = {0};
//     int counterFor_t[26] = {0};
//     for(int i = 0; i < s.size(); i++)
//         counterFor_s[s[i]-97]++;
//     for(int i = 0; i < t.size(); i++)
//         counterFor_t[t[i] - 97]++;
//     for(int i = 0; i < s.size(); i++)
//         if(counterFor_s[s[i] - 97] != counterFor_t[s[i] - 97])
//             return false;
//     for(int i = 0; i < t.size(); i++)
//         if(counterFor_s[t[i] - 97] != counterFor_t[t[i] - 97])
//             return false;
//     return true;
// }
//----------------------------------------
// bool isAnagram(string s, string t)
// {
//     int characterCounter[26] = {0};
//     for(int i = 0; i < s.size(); i++)
//         characterCounter[s[i] - 97]++;
//     for(int i = 0; i < t.size(); i++)
//         characterCounter[t[i] - 97]--;
//     for(int i = 0; i < s.size(); i++)
//         if(characterCounter[s[i] - 97] != 0)
//             return false;
//     for(int i = 0; i < t.size(); i++)
//         if(characterCounter[t[i] - 97] != 0)
//             return false;
//     return true;
// }
//-------------------------------------------
// bool isAnagram(string s, string t)
// {
//     if (s.length() != t.length())
//         return false;
//     int characterCounter[26] = {0};
//     for (int i = 0; i < s.length(); i++)
//     {
//         characterCounter[s[i] - 97]++;
//         characterCounter[t[i] - 97]--;
//     }
//     for(int i = 0; i < s.length(); i++)
//         if(characterCounter[s[i] - 97] != 0)
//             return false;
//     return true;
// }
// int main()
// {
//     string s = "anagram";
//     string t = "nagaram";
//     cout << "isAnagram : " << isAnagram(s, t) << endl;
//     return 0;
// }

//--------------------------------------------------------------125. Valid Palindrome--------------------------------------------------------------------------
// bool isPalindrome(string s)
// {
//     string duplicateString = "";
//     for (int i = 0; i < s.size(); i++)
//     {
//         if (s[i] >= 65 && s[i] <= 90)
//             duplicateString.push_back(s[i] + 32);
//         if ((s[i] >= 97 && s[i] <= 122) || (s[i] >= 48 && s[i] <= 57))
//             duplicateString.push_back(s[i]);
//     }
//     s = duplicateString;
//     reverse(duplicateString.begin(), duplicateString.end());
//     return s == duplicateString;
// }
//-----------------------------------------------
// bool isPalindrome(string s)
// {
//     string duplicateString = "";
//     for (int i = 0; i < s.size(); i++)
//     {
//         if (s[i] >= 65 && s[i] <= 90)
//             duplicateString.push_back(s[i] + 32);
//         if ((s[i] >= 97 && s[i] <= 122) || (s[i] >= 48 && s[i] <= 57))
//             duplicateString.push_back(s[i]);
//     }
//     int i = 0, j = duplicateString.size() - 1;
//     while (i < j)
//     {
//         if(duplicateString[i] != duplicateString[j])
//             return 0;
//         i++;
//         j--;
//     }
//     return 1;
// }
//-------------------------------------------------
// bool isPalindrome(string s)
// {
//     int left = 0, right = s.size() - 1;
//     while (left < right)
//     {
//         if ((s[left] >= 65 && s[left] <= 90) || (s[left] >= 97 && s[left] <= 122) || (s[left] >= 48 && s[left] <= 57))
//         {
//             if (s[left] >= 65 && s[left] <= 90)
//                 s[left] = s[left] + 32;
//         }
//         else
//         {
//             left++;
//             continue;
//             ;
//         }
//         if ((s[right] >= 65 && s[right] <= 90) || (s[right] >= 97 && s[right] <= 122) || (s[right] >= 48 && s[right] <= 57))
//         {
//             if (s[right] >= 65 && s[right] <= 90)
//                 s[right] = s[right] + 32;
//         }
//         else
//         {
//             right--;
//             continue;
//         }
//         if (s[left] == s[right])
//         {
//             left++;
//             right--;
//         }
//         else
//             return false;
//     }
//     return true;
// }

// int main()
// {
//     // string s = "A man, a plan, a canal: Panama";
//     string s = "0P";
//     cout << "isisPalindrome : " << isPalindrome(s) << endl;
// }

//-------------------------------------------------------121. Best Time to Buy and Sell Stock--------------------------------------------------------------------------
//--------------------Time Limit Exceed--------------------------------
// int maxProfit(vector<int> &prices)
// {
//     int profit = 0;
//     for (int i = 0; i < prices.size() - 1; i++)
//     {
//         for (int j = i + 1; j < prices.size(); j++)
//         {
//             if((prices[j] - prices[i]) > profit)
//                 profit = prices[j] - prices[i];
//         }
//     }
//     return profit;
// }
// -----------------------------------------------------
// int maxProfit(vector<int> &prices)
// {
//     int purchasingPrice = prices[0];
//     int currentProfit = 0, previousProfit = 0;
//     for (int i = 1; i < prices.size(); i++)
//     {
//         currentProfit = prices[i] - purchasingPrice;
//         if(currentProfit < 0)
//             purchasingPrice = prices[i];
//         else if(currentProfit > previousProfit)
//             previousProfit = currentProfit;
//     }
//     return previousProfit;
// }
//-------------------------------------------------------
// int maxProfit(vector<int> &prices)
// {
//     int buyingPrice = INT_MAX, sellingPrice = 0;
//     for (int i = 0; i < prices.size(); i++)
//     {
//         if(buyingPrice > prices[i])
//             buyingPrice = prices[i];
//         if(sellingPrice < (prices[i] - buyingPrice))
//             sellingPrice = prices[i] - buyingPrice;
//     }
//     return sellingPrice;
// }

// int main()
// {
//     vector<int> prices = {7,1,5,3,6,4};
//     cout << "Profit : " << maxProfit(prices) << endl;
//     return 0;
// }

//------------------------------------------------------------------13. Roman to Integer--------------------------------------------------------------------------
// int romanToInt(string s)
// {
//     unordered_map<char, int> roman2Int = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
// int result = 0;
// for (int i = 0; i < s.size(); i++)
// {
//     if (s[i] == 'I' && (i + 1) < s.size() && ((s[i + 1] == 'V') || (s[i + 1] == 'X')))
//     {
//         result += roman2Int[s[i + 1]] - roman2Int[s[i]];
//         i++;
//     }
//     else if (s[i] == 'X' && (i + 1) < s.size() && ((s[i + 1] == 'L') || (s[i + 1] == 'C')))
//     {
//         result += roman2Int[s[i + 1]] - roman2Int[s[i]];
//         i++;
//     }
//     else if (s[i] == 'C' && (i + 1) < s.size() && ((s[i + 1] == 'D') || (s[i + 1] == 'M')))
//     {
//         result += roman2Int[s[i + 1]] - roman2Int[s[i]];
//         i++;
//     }
//     else
//         result += roman2Int[s[i]];
// }
//     return result;
// }
//----------------------------------------------------------------------
// int romanToInt(string s)
// {
//     int roman2Int[26] = {0};
//     roman2Int['I'-65] = 1;
//     roman2Int['V'-65] = 5;
//     roman2Int['X'-65] = 10;
//     roman2Int['L'-65] = 50;
//     roman2Int['C'-65] = 100;
//     roman2Int['D'-65] = 500;
//     roman2Int['M'-65] = 1000;
//     cout << roman2Int['M' - 65] << endl;
//     int result = 0;
//     for (int i = 0; i < s.size(); i++)
//     {
//         if (s[i] == 'I' && (i + 1) < s.size() && ((s[i + 1] == 'V') || (s[i + 1] == 'X')))
//         {
//             result += roman2Int[s[i + 1] - 65] - roman2Int[s[i] - 65];
//             i++;
//         }
//         else if (s[i] == 'X' && (i + 1) < s.size() && ((s[i + 1] == 'L') || (s[i + 1] == 'C')))
//         {
//             result += roman2Int[s[i + 1] - 65] - roman2Int[s[i] - 65];
//             i++;
//         }
//         else if (s[i] == 'C' && (i + 1) < s.size() && ((s[i + 1] == 'D') || (s[i + 1] == 'M')))
//         {
//             result += roman2Int[s[i + 1] - 65] - roman2Int[s[i] - 65];
//             i++;
//         }
//         else
//             result += roman2Int[s[i] - 65];
//     }
//     return result;
// }
//---------------------------------------------------------------------------------
// int romanToInt(string s)
// {
//     int roman2Int[26] = {0};
//     roman2Int['I'-65] = 1;
//     roman2Int['V'-65] = 5;
//     roman2Int['X'-65] = 10;
//     roman2Int['L'-65] = 50;
//     roman2Int['C'-65] = 100;
//     roman2Int['D'-65] = 500;
//     roman2Int['M'-65] = 1000;
//     cout << roman2Int['M' - 65] << endl;
//     int result = 0;
//     for (int i = 0; i < s.size(); i++)
//     {
//         // Roman numerals are usually written largest to smallest from left to right.
//         if ((i + 1) < s.size() && roman2Int[s[i]-65] < roman2Int[s[i+1]-65])
//         {
//             result += roman2Int[s[i + 1] - 65] - roman2Int[s[i] - 65];
//             i++;
//         }
//         else
//             result += roman2Int[s[i] - 65];
//     }
//     return result;
// }
//----------------------------------------------------------

// int main()
// {
//     // string s = "III";
//     // string s = "LVIII";
//     string s = "MCMXCIV";
//     cout << "Roman to Integer : " << s << " -> " << romanToInt(s) << endl;
// }

//---------------------------------------------------------------------1. Two Sum--------------------------------------------------------------------------
// vector<int> twoSum(vector<int> &nums, int target)
// {
//     int i, j;
//     for (i = 0; i < nums.size() - 1; i++)
//     {
//         for (j = i + 1; j < nums.size(); j++)
//         {
//             if(nums[i]+nums[j] == target)
//                 return {i, j};
//         }
//     }
//     return {};
// }
//-------------------------------------------------
// vector<int> twoSum(vector<int> &nums, int target)
// {
// unordered_map<int, int> umap;
// for (int i = 0; i < nums.size(); i++)
// {
//     if (umap[target-nums[i]])
//         return {umap[target-nums[i]]-1, i};
//     umap[nums[i]] = i + 1;
// }
// return {};
// }
//--------------------------------------------------
// vector<int> twoSum(vector<int> &nums, int target)
// {
//     unordered_map<int, int> umap;
//     for (int i = 0; i < nums.size(); i++)
//         umap[nums[i]] = i;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         if (umap[target - nums[i]])
//         {
//             if(i == umap[target - nums[i]]) continue;
//             return { i, umap[target - nums[i]] };
//         }
//     }
//     return {};
// }

// int main()
// {
//     // vector<int> nums = {2, 7, 11, 15};
//     // vector<int> nums = {3,2,4};
//     // vector<int> nums = {3, 3};
//     vector<int> nums = {1,3,4,2};
//     int target = 6;
//     nums = twoSum(nums, target);
//     for (auto item : nums)
//     {
//         cout << item << "  ";
//     }
// }

//------------------------------------------------------------------ 443. String Compression --------------------------------------------------------------------------
// void compress(vector<char> &chars)
// {
//     vector<char> result;
//     string num_str;
//     int char_counter = 1, i = 1;
//     for (i = 1; i < chars.size(); i++)
//     {
//         if (chars.at(i) == chars.at(i - 1))
//         {
//             char_counter++;
//         }
//         else
//         {
//             result.push_back(chars.at(i - 1));
//             if (char_counter > 1)
//             {
//                 while (char_counter)
//                 {
//                     num_str.push_back((char_counter % 10) + 48);
//                     char_counter = char_counter / 10;
//                 }
//                 if (num_str.size())
//                 {
//                     for (int i = num_str.size() - 1; i >= 0; i--)
//                     {
//                         result.push_back(num_str.at(i));
//                     }
//                 }
//                 char_counter = 1;
//                 num_str.clear();
//             }
//         }
//     }
//     result.push_back(chars.at(i - 1));
//     if (char_counter > 1)
//     {
//         while (char_counter)
//         {
//             num_str.push_back((char_counter % 10) + 48);
//             char_counter = char_counter / 10;
//         }
//         if (num_str.size())
//         {
//             for (int i = num_str.size() - 1; i >= 0; i--)
//             {
//                 result.push_back(num_str.at(i));
//             }
//         }
//         char_counter = 1;
//         num_str.clear();
//     }
//     cout << "Result : " << result.size() << endl;
// }
//--------------------------------------------------
// void compress(vector<char> &chars)
// {

// }
// int main()
// {
//     // vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
//     // vector<char> chars = {'a'};
//     vector<char> chars = {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
//     compress(chars);
// }