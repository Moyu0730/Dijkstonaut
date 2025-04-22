#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int dp[1001][1001][3]; // dp[c1][c2][mod]

bool dfs(int c1, int c2, int mod) {
    if (dp[c1][c2][mod] != -1) return dp[c1][c2][mod];

    if (c1 == 0 && c2 == 0) {
        return false; // 所有數字已被選完，後手獲勝
    }

    // 嘗試選擇 mod1 的數字
    if (c1 > 0) {
        int nextMod = (mod + 1) % 3;
        if (nextMod != 0 && !dfs(c1 - 1, c2, nextMod)) {
            return dp[c1][c2][mod] = true;
        }
    }

    // 嘗試選擇 mod2 的數字
    if (c2 > 0) {
        int nextMod = (mod + 2) % 3;
        if (nextMod != 0 && !dfs(c1, c2 - 1, nextMod)) {
            return dp[c1][c2][mod] = true;
        }
    }

    return dp[c1][c2][mod] = false;
}

int main() {
    int n, x;
    cin >> n;
    int c0 = 0, c1 = 0, c2 = 0;

    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (x % 3 == 0) c0++;
        else if (x % 3 == 1) c1++;
        else c2++;
    }

    memset(dp, -1, sizeof(dp));
    bool firstWins;

    if (c0 % 2 == 0) {
        firstWins = dfs(c1, c2, 0);
    } else {
        firstWins = !dfs(c1, c2, 0); // 輪次交換
    }

    cout << (firstWins ? "Yes" : "No") << endl;
    return 0;
}