#include <string>
#include <map>

using namespace std;

map<char, int> pairs = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
};

int romanToInt(string s) {
    int result = 0, i;
    if (s.length() == 0) return 0;
    
    for (i = 0; i < s.length() - 1; i++) {
        int first = pairs.find(s[i])->second, second = pairs.find(s[i + 1])->second;
        if (first < second) {
            result += (second - first);
            i++;
        } else {
            result += first;
        }
    }
    
    if (i < s.length()) result += pairs.find(s[i])->second;
    return result;
}