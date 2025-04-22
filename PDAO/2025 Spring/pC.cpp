// /* Question : OJ Number */

// #include<bits/stdc++.h>
// using namespace std;

// /* Pragma */
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

// /* Self Define */
// #define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
// #define pirq(type) priority_queue<type, vector<type>, greater<type>>
// #define mem(x, value) memset(x, value, sizeof(x));
// #define all(v) v.begin(), v.end()
// #define pii pair<int, int>
// #define pdd pair<double, double>
// #define pb push_back
// #define F first
// #define S second
// #define X first
// #define Y second
// #define int long long
// #define ll long long

// const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
// const int MAXN = 1e3 + 50;
// const int Mod = 1e9 + 7;
// const long long LLINF = 0x7FFFFFFFFFFFFFFF;
// const int INF = 0x7FFFFFFF;
// const int MEMINF = 0x3F;
// const int MEMINF_VAL = 0x3F3F3F3F;
// const int MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

// int t, pos, res;
// char op;
// int arr[MAXN];

// signed main(){
//     opt;

//     cin >> t;

//     while( t-- ){
//         cin >> op >> pos;

//         if( op == 'I' ){
//             for( int i =  pos ; i < 1000 ; ++i ){
//                 if( arr[i] == 0 ){
//                     ++res;
//                     arr[i] = 1;
//                 }
//             }
//         }

//         if( op == 'D' ){

//         }
//     }
// }

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;

    const int MAX_POS = 1000;
    vector<int> slots(MAX_POS, -1); // -1 表示空位
    int total_moves = 0;
    int class_id = 1;

    for (int i = 0; i < N; ++i) {
        string op;
        int pos;
        cin >> op >> pos;

        if (op == "I") {
            // 插入一門課，從 pos 開始找第一個空位往右移
            int move_count = 0;
            int cur = pos;

            // 找到第一個空位
            while (cur < MAX_POS && slots[cur] != -1) {
                ++cur;
            }

            // 把所有課右移一格
            for (int j = cur; j > pos; --j) {
                slots[j] = slots[j - 1];
                ++move_count;
            }

            // 插入新課
            slots[pos] = class_id++;
            ++move_count; // 插入算一步

            total_moves += move_count;
        } else if (op == "D") {
            // 刪除一門課，只要該位置不是空的
            if (slots[pos] != -1) {
                slots[pos] = -1; // 留空
                ++total_moves; // 刪除算一步
            }
        }
    }

    cout << total_moves << endl;
    return 0;
}