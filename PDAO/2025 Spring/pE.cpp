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
// const int INF = 0x7FFFFFFF;
// const int MEMINF = 0x3F;
// const int MEMINF_VAL = 0x3F3F3F3F;
// const int MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

int n, x, sum, d;
vector<int> a, b, c;

signed main(){
    opt;

    cin >> n;

    c.resize(n);
    for( int i = 0 ; i < n ; i++ ){
        cin >> x;
        a.pb(x);
    }
    for( int i = 0 ; i < n ; i++ ){
        cin >> x;
        b.pb(x);
    }

    for( int i = 0 ; i < n ; i++ ){
        c[i] = abs(a[i] - b[i]);
        sum += c[i];
    }

    sort(all(a));

    // cout << sum << "\n";

    int dif = 0;
    for( int i = 0 ; i < n ; ++i ){
        int ind = lower_bound(all(a), b[i]) - a.begin();

        int larger = a[ind];
        int lower = ( ind == 0 ) ? a[ind] : a[ind - 1];

        if( abs(b[i] - larger) < abs(b[i] - lower) ){
            // cout << " | " << larger << "\n";
            dif = max(dif, abs(c[i] - abs( b[i] - larger)));
        }else{
            // cout << " | " << lower << "\n";
            dif = max(dif, abs(c[i] - abs(b[i] - lower)));
        }
    }

    // cout << dif << "\n";

    cout << sum - dif << "\n";
}