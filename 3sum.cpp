#include <vector>
#include <bits/stdc++.h> 

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    if (nums.size() < 3)
        return {};

    int size = nums.size(), beg, end;
    vector<vector<int>> result;

    sort(nums.begin(), nums.end());

    for (size_t i = 0; i < size; i++)
    {
        if ((i > 0) && (nums[i] == nums[i - 1]))
            continue;
        beg = i + 1;
        end = size - 1;

        while (beg < end)
        {
            int sum = nums[i] + nums[beg] + nums[end];

            if (sum < 0)
                beg++;
            else if (sum > 0)
                end--;
            else
            {
                result.push_back({nums[i], nums[beg], nums[end]});
                while (beg < end && nums[beg + 1] == nums[beg])
                    beg++;
                while (beg < end && nums[end - 1] == nums[end])
                    end--;
                beg++;
                end--;
            }
        }
    }
    return result;
}