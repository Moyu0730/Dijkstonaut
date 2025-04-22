/* Question : OJ Number */

#include <bits/stdc++.h>
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

const int MAXN = 1e5 + 50;
const ll LLINF = 0x7FFFFFFFFFFFFFFF;
const int INF = 0x7FFFFFFF;
const int Mod = 1e9 + 7;

string str;

string get() {
    struct Item { bool is_marker; unordered_map<string, ll> cnts; };
    vector<Item> stk;
    int n = str.size(), i = 0;
    while (i < n) {
        char c = str[i];
        if (c == '(') {
            stk.pb({true, {}});
            i++;
        } else if (c == ')') {
            i++;
            ll times = 0; int st = i;
            while (i < n && isdigit(str[i])) times = times * 10 + (str[i++] - '0');
            if (i == st) times = 1;
            unordered_map<string, ll> merged;
            while (!stk.empty() && !stk.back().is_marker) {
                for (auto &kv : stk.back().cnts) merged[kv.first] += kv.second;
                stk.pop_back();
            }
            if (!stk.empty() && stk.back().is_marker) stk.pop_back();
            for (auto &kv : merged) kv.second *= times;
            stk.pb({false, merged});
        } else if (isupper(c)) {
            string elem;
            elem.push_back(c); i++;
            while (i < n && islower(str[i])) elem.push_back(str[i++]);
            ll cnt = 0; int st = i;
            while (i < n && isdigit(str[i])) cnt = cnt * 10 + (str[i++] - '0');
            if (i == st) cnt = 1;
            unordered_map<string, ll> mp;
            mp[elem] = cnt;
            stk.pb({false, mp});
        } else {
            i++;
        }
    }

    unordered_map<string, ll> res;
    while (!stk.empty()) {
        if (!stk.back().is_marker)
            for (auto &kv : stk.back().cnts) res[kv.first] += kv.second;
        stk.pop_back();
    }

    vector<string> keys;
    for (auto &kv : res) keys.pb(kv.first);
    sort(all(keys));

    string out;
    for (auto &e : keys) {
        out += e;
        if (res[e] > 1) out += to_string(res[e]);
    }
    return out;
}

signed main() {
    opt;
    string s, t;
    int a, b;
    cin >> a >> b;
    cin >> str;
    s = get();
    // cout << s << '\n';
    cin >> str;
    t = get();
    // cout << t << '\n';

    if( s == t ) cout << "Yes\n";
    else cout << "No\n";
}