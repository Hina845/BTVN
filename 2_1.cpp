#include <vector>
#include <iostream>

using namespace std;

bool check_palin(string s) {
    vector<vector<bool>> dp(s.size()+1, vector<bool>(s.size(), 0));
    for (int i = 0; i <= s.size(); i++) {
        dp[0][i] = 1;
        dp[1][i] = 1;
    }
    for (int i = 2; i <= s.size(); i++) {
        for (int j = i-1; j < s.size(); j++) {
            dp[i][j] = (dp[i-2][j-1] && s[j] == s[j-i+1]);
        }
    }
    return dp.back().back();
}

int main() {
    string s; cin >> s;
    cout << check_palin(s);
}