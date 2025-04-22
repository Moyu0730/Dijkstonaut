/* Question : OJ Number */

#include<bits/stdc++.h>
using namespace std;

/* Pragma */
#pragma GCC optimize("Ofast")
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

/* Self Define */
#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pirq(type) priority_queue<type, vector<type>, greater<type>>
#define mem(x, value) memset(x, value, sizeof(x));
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define pdd pair<double, double>
#define pb push_back
#define F first
#define S second
#define X first
#define Y second
#define int long long
#define ll long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 1e8 + 50;
// const int Mod = 1e9 + 7;
// const long long LLINF = 0x7FFFFFFFFFFFFFFF;
const int INF = 0x7FFFFFFF;
// const int MEMINF = 0x3F;
// const int MEMINF_VAL = 0x3F3F3F3F;
// const int MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;


int res, MAX, MIN, MAXV, MINV;
int n, arr[MAXN];

signed main(){
    opt;

    cin >> n;

    MAX = -1;
    MIN = INF;
    MAXV = -1;
    MINV = INF;
    for( int i = 0 ; i < n ; ++i ){
        cin >> arr[i];

        if( arr[i] < MINV ){
            MIN = i;
            MINV = arr[i];
        }

        if( arr[i] >= MAXV ){
            MAXV = arr[i];
            MAX = max(i, MAX);
        }
    }

    // cout << "MIN : " << MIN << "\n";
    // cout << "MAX : " << MAX << "\n";

    for( int i = MIN ; i > 0 ; --i ){
        swap(arr[i], arr[i-1]);

        if( i - 1 == MAX ) MAX += 1;

        ++res;
    }

    // for( int i = 0 ; i < n ; ++i ){
    //     cout << arr[i] << " ";
    // }
    // cout << "\n";

    // cout << "MIN : " << MIN << "\n";
    // cout << "MAX : " << MAX << "\n";

    for( int i = MAX ; i < n - 1 ; ++i ){
        swap(arr[i], arr[i+1]);

        ++res;
    }

    // for( int i = 0 ; i < n ; ++i ){
    //     cout << arr[i] << " ";
    // }
    // cout << "\n";

    cout << res << "\n";
}