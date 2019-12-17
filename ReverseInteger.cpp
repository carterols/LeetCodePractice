const int INT_MAX = 2147483647;
const int INT_MIN = -2147483648;
int reverse(int x) {
    int output = 0;
    while (x != 0) {
        int rem = x % 10;
        x /= 10;
        if (output > INT_MAX / 10 || (output == INT_MAX / 10 && rem > 7 ))
            return 0;
        if (output < INT_MIN / 10 || (output == INT_MIN / 10 && rem < -8))
            return 0;
        output = (output * 10) + rem;
    }
    
    return output;
}