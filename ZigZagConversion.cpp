#include <string>

using namespace std;

string convert(string s, int numRows) {
    string output;
    int numDiag = numRows > s.size() || numRows < 3 ? 0 : numRows - 2;
    int itr = 0;
    
    if (s.size() <= numRows) {
        return s;
    }
    
    while (itr < numRows && itr < s.size()) {
        int i = itr;
        while (i < s.size()) {
            output += s[i];
            if ((i == itr || (i - itr) % (numRows + numDiag) == 0) && isDiagonalRow(itr, numRows)) {
                int inc = (i + numRows + numDiag - (itr * 2));
                if (inc >= 0 && inc < s.size()) {
                    output += s[inc];
                }
            }
            i += numRows + numDiag;
        }
        itr++;
    }
    
    return output;
}

bool isDiagonalRow(int i, int numRows) {
    if (i < numRows - 1 && i > 0) {
        return true;
    } else {
        return false;
    }
}