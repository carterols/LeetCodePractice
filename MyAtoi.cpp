#include <string>
using namespace std;

int myAtoi(string str) {
    int result = 0, pos = 0;
    bool encounteredNum = false;
    
    for (size_t i = 0; i < str.size(); i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            encounteredNum = true;
            if (pos == 0)
                pos = 1;
            int intToAdd = (str[i] - '0') * pos;

            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && intToAdd > 7))
                return INT_MAX;
            if (result < INT_MIN / 10 || (result == INT_MIN / 10 && intToAdd < -8))
                return INT_MIN;
            
            result = (result * 10) + intToAdd;

        } else if (str[i] == '-' && pos == 0) {
            pos = -1;
            encounteredNum = true;
        } else if (str[i] == '+' && pos == 0) {
            pos = 1;
            encounteredNum = true;
        } else if (str[i] != ' ' && !encounteredNum) {
            return 0;
        } else if (encounteredNum && (str[i] > '9' || str[i] < '0')) {
            return result;
        } 
    }
    return (!encounteredNum ? 0 : result);
}