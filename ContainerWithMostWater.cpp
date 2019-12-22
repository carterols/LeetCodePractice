#include <vector>

using namespace std;

#define INT_MIN 0

int maxArea(vector<int>& height) {
    int i = 0, j = height.size() - 1;
    int maxArea = INT_MIN;
    
    while (i < j) {
        int minHeight = min(height[i], height[j]);
        maxArea = max(maxArea, minHeight * (j - i));
    
        if (height[i] > height[j]) {
            j--;
        } else {
            i++;
        }
        
    }
    
    return maxArea;
}