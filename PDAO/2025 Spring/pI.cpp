#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <map>
#include <algorithm>
using namespace std;

const int MAX = 1005;

int M, N;
int grid[MAX][MAX];
int result[MAX][MAX];
int in_deg[MAX * MAX];
vector<int> adj[MAX * MAX];

// 用來映射 (i, j) 為一個唯一節點
int node(int i, int j) {
    return i * N + j;
}

int main() {
    cin >> M >> N;

    vector<tuple<int, int, int>> cells; // {value, i, j}

    for (int i = 0; i < M; ++i)
        for (int j = 0; j < N; ++j) {
            cin >> grid[i][j];
            cells.emplace_back(grid[i][j], i, j);
        }

    // 對每列處理拓撲邊
    for (int i = 0; i < M; ++i) {
        vector<pair<int, int>> row;
        for (int j = 0; j < N; ++j)
            row.emplace_back(grid[i][j], j);

        sort(row.begin(), row.end()); // 從小到大
        for (int k = 1; k < N; ++k) {
            int u = node(i, row[k - 1].second);
            int v = node(i, row[k].second);
            adj[u].push_back(v);
            in_deg[v]++;
        }
    }

    // 每欄也做同樣處理
    for (int j = 0; j < N; ++j) {
        vector<pair<int, int>> col;
        for (int i = 0; i < M; ++i)
            col.emplace_back(grid[i][j], i);

        sort(col.begin(), col.end());
        for (int k = 1; k < M; ++k) {
            int u = node(col[k - 1].second, j);
            int v = node(col[k].second, j);
            adj[u].push_back(v);
            in_deg[v]++;
        }
    }

    // 拓撲排序
    queue<int> q;
    vector<int> dp(M * N, 1); // 每格最少 1

    for (int i = 0; i < M * N; ++i)
        if (in_deg[i] == 0)
            q.push(i);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            dp[v] = max(dp[v], dp[u] + 1);
            if (--in_deg[v] == 0)
                q.push(v);
        }
    }

    // 將 dp 值寫回 matrix
    for (int i = 0; i < M; ++i)
        for (int j = 0; j < N; ++j)
            result[i][j] = dp[node(i, j)];

    // 輸出結果
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j)
            cout << result[i][j] << " ";
        cout << "\n";
    }

    return 0;
}