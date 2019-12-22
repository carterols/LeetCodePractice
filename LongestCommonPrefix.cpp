#include <string>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs) { 
    int size = strs.size();
    if (size == 0) return "";
    if (size == 1) return strs[0];
    
    int i = 0;
    for (i = 0; strs[0].length(); i++) {
        for (int j = 1; j < size; j++) {
            if (i >= strs[j].length() || strs[j][i] != strs[0][i]) {
                return strs[0].substr(0, i);
            }
        }
    }
    
    return strs[0].substr(0, i);
}