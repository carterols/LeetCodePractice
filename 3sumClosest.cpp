#include <vector>
#include <bits/stdc++.h>

using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    if (nums.size() < 3)
        return {};

    int size = nums.size(), beg, end;
    int closest = nums[0] + nums[1] + nums[2];

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

            if (sum < target) beg++;
            else if (sum > target) end--;
            else return sum;
            
            if (abs(target - sum) < abs(target - closest)) 
                closest = sum;
        }
    }
    return closest;
}