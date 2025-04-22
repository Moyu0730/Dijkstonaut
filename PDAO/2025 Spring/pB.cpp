#include <bits/stdc++.h>
using namespace std;
#define opt ios::sync_with_stdio(false); cin.tie(nullptr)
#define int long long

const int MAXN = 1e5 + 50;
#define nL (v<<1)
#define nR (v<<1|1)

struct Node {
    int val = 0;    // 区间最大值
    int sum = 0;    // 区间和
    int tag = 0;    // 懒标记
} SEG[MAXN<<2];

int arr[MAXN];
int n, q, op, a, b, c;

// build 时同时初始化 val 和 sum
void build(int L, int R, int v) {
    if (L == R) {
        SEG[v].val = SEG[v].sum = arr[L];
        return;
    }
    int M = (L + R) >> 1;
    build(L, M, nL);
    build(M+1, R, nR);
    SEG[v].val = max(SEG[nL].val, SEG[nR].val);
    SEG[v].sum = SEG[nL].sum + SEG[nR].sum;
}

// 向下传递 tag
void push(int L, int R, int v) {
    if (!SEG[v].tag) return;
    int M = (L + R) >> 1;
    int t = SEG[v].tag;
    // 左儿子
    SEG[nL].tag += t;
    SEG[nL].val += t;
    SEG[nL].sum += t * (M - L + 1);
    // 右儿子
    SEG[nR].tag += t;
    SEG[nR].val += t;
    SEG[nR].sum += t * (R - M);
    // 清空自己
    SEG[v].tag = 0;
}

// 区间加 val
void modify(int L, int R, int l, int r, int vval, int v) {
    if (r < L || R < l) return;
    if (l <= L && R <= r) {
        SEG[v].val += vval;
        SEG[v].sum += vval * (R - L + 1);
        SEG[v].tag += vval;
        return;
    }
    push(L, R, v);
    int M = (L + R) >> 1;
    modify(L, M, l, r, vval, nL);
    modify(M+1, R, l, r, vval, nR);
    SEG[v].val = max(SEG[nL].val, SEG[nR].val);
    SEG[v].sum = SEG[nL].sum + SEG[nR].sum;
}

// 区间最大值查询
int query_max(int L, int R, int l, int r, int v) {
    if (r < L || R < l) return LLONG_MIN;
    if (l <= L && R <= r) {
        return SEG[v].val;
    }
    push(L, R, v);
    int M = (L + R) >> 1;
    return max(query_max(L, M, l, r, nL),
               query_max(M+1, R, l, r, nR));
}

// 区间和查询
int query_sum(int L, int R, int l, int r, int v) {
    if (r < L || R < l) return 0;
    if (l <= L && R <= r) {
        return SEG[v].sum;
    }

    // push(L, R, v);
    int M = (L + R) >> 1;
    return query_sum(L, M, l, r, nL) + query_sum(M+1, R, l, r, nR);
}

signed main(){
    opt;
    cin >> n >> q;
    for(int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    build(1, n, 1);

    while(q--){
        cin >> op >> a >> b >> c;
        if (op == 1) {
            modify(1, n, a+1, b+1, c, 1);
        } else if (op == 2) {
            modify(1, n, a+1, b+1, -c, 1);
        } else {
            // op == 3：在所有 i..i+a 的窗口中
            int best_mx = LLONG_MIN;
            int best_start = 1;
            long long best_sum = 0;
            for (int i = 1; i + a <= n; ++i) {
                int cur_mx  = query_max(1, n, i, i + a, 1);
                long long cur_sum = query_sum(1, n, i, i + a, 1);

                if( cur_mx > best_mx ){
                    best_mx = cur_mx;
                    best_start = i;
                    best_sum = cur_sum;
                }
            }
            cout << best_start << " " << best_start + a << " " << best_mx * b + best_sum * c << "\n";
        }
    }
    return 0;
}
