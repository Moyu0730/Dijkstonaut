#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int N, R, M;
    cin >> N >> R >> M;

    vector<pair<int, int>> missions(M);  // {agents_required, benefit}
    for (int i = 0; i < M; ++i) {
        cin >> missions[i].first >> missions[i].second;
    }

    // dp[agents][benefit] = number of ways to achieve this state
    vector<vector<int>> dp(N + 1, vector<int>(R + 1, 0));
    dp[0][0] = 1; // base case: 0 agents, 0 benefit

    for (auto& mission : missions) {
        int g = mission.first; // agents required
        int b = mission.second; // benefit gained

        // 避免重複使用任務，必須倒序處理
        for (int a = N; a >= g; --a) {
            for (int r = R; r >= 0; --r) {
                int new_benefit = min(R, r + b);
                dp[a][new_benefit] = (dp[a][new_benefit] + dp[a - g][r]) % MOD;
            }
        }
    }

    // 計算總數
    int total = 0;
    for (int a = 0; a <= N; ++a) {
        total = (total + dp[a][R]) % MOD;
    }

    cout << total << endl;
    return 0;
}