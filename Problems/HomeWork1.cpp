#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int max_length = 0;

        for (int i = 0; i < s.size(); i++)
        {
            string current_value = "";

            for (int j = i; j < s.size(); j++)
            {
                if (current_value.find(s[j]) != string::npos)
                {
                    break;
                }
                current_value += s[j];
                max_length = max(max_length, (int)current_value.size());
            }
        }

        return max_length;
    }
};

int main()
{
    Solution solution;
    string input;

    cout << "Enter a string: ";
    getline(cin, input);

    int result = solution.lengthOfLongestSubstring(input);
    cout << "Length of longest substring without repeating characters: " << result << endl;

    return 0;
}
