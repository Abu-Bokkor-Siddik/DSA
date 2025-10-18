#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> prefixMap;
        prefixMap[0] = 1;

        int prefixSum = 0, count = 0;

        for (int num : nums)
        {
            prefixSum += num;

            if (prefixMap.find(prefixSum - k) != prefixMap.end())
            {
                count += prefixMap[prefixSum - k];
            }
            prefixMap[prefixSum]++;
        }

        return count;
    }
};

int main()
{
    Solution solution;
    int n, k;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << "Enter target sum (k): ";
    cin >> k;

    int result = solution.subarraySum(nums, k);
    cout << "Number of subarrays with sum " << k << ": " << result << endl;

    return 0;
}
