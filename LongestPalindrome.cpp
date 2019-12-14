#include <string>

using namespace std;
string longestPalindrome(string s) {
//         We want to limit repeating strings
//         Keep track of palindromes in 2D table
        // b | a | b | a | d 
    //   b|T   F   T   F   F
    //   a|F   T   F   T   F
    //   b|T   F   T   F   F
    //   a|F   T   F   T   F
    //   d|F   F   F   F   T
        
        int size = s.size();
        if (size == 0 || size == 1) {
            return s;
        } 
        bool tab[size][size];
        
        // Initialize table to false except for the diagonal.
        for (size_t i = 0; i < size; i++) {
            for (size_t j = 0; j < size; j++) {
                if (i == j)
                    tab[i][j] = true;
                else 
                    tab[i][j] = false;
            }
        }
        
        // initialize maxSize to 1 because all strings of length 1 are palindromes
        int maxSize = 1;
        int startIdx = 0;
        
        // check for all palindromes length 2
        for (size_t i = 0; i < size - 1; i++) {
            if (s[i] == s[i+1]) {
                tab[i][i+1] = true;
                startIdx = i;
                maxSize = 2;
            }
        }
        
        // check for rest of palindromes
        for (size_t i = 3; i <= size; ++i) {
            for (size_t j = 0; j < size - i+1; ++j) {
                // This gets the last index of the substring starting at j with length i
                int k = j + i - 1;
                
                // check if down-left item in table is a palindrome. If so, then check if comparing characters match. 
                // If both cases are true, then we can add a true to the table at tab[j][k]
                if (tab[j + 1][k - 1] && s[j] == s[k]) {
                    tab[j][k] = true;
                    
                    // update the startIdx and maxLength if greater than previous maxLength
                    if (i > maxSize) {
                        startIdx = j;
                        maxSize = i;
                    }
                    
                }
            }
        }

        return s.substr(startIdx, maxSize);
    }