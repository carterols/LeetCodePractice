#include <string>

using namespace std;

bool isMatch(string s, string p) {
    // Initialize table to false
    bool tab[p.size()+1][s.size()+1] = {false};
    
    tab[0][0] = true;
    
    for (int j = 1; j < s.size() + 1; j++)
        tab[0][j] = s.size() == 0;
    
    for (int i = 1; i < p.size() + 1; i++) {
        bool star = p[i-1] == '*';
        tab[i][0] = star && tab[i-2][0];
        for (int j = 1; j < s.size() + 1; j++) {
            tab[i][j] = star 
            && tab[i-2][j] 
            || (p[i-1-star] == '.' 
            || p[i-1-star] == s[j-1]) 
            && tab[i-1+star][j-1];
        }
    }
    
    return tab[p.size()][s.size()];
}