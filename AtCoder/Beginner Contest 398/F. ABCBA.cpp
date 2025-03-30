/* Question : AtCoder Beginner Contest 398 - F. ABCBA */

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
#define vsort(x) sort(x.begin(), x.end());
#define pii pair<int, int>
#define pdd pair<double, double>
#define pb push_back
#define F first
#define S second
#define X first
#define Y second
#define int long long
#define ll long long

#define n str.size()

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 1e8 + 50;
const int Mod = 1e9 + 7;
const long long LLINF = 0x7FFFFFFFFFFFFFFF;
const int INF = 0x7FFFFFFF;
const int MEMINF = 0x3F;
const int MEMINF_VAL = 0x3F3F3F3F;
const int MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

const int p = 48763;

string str;
int poshsh[MAXN], neghsh[MAXN], ksm[MAXN];

void pre(){
    int power = p;
    for( int i = 0 ; i < str.size() ; ++i ){
        poshsh[i] = (i == 0) ? str[i] : poshsh[i-1] * p + str[i];
        neghsh[i] = (i == 0) ? str[str.size()-i-1] : str[str.size()-i+1] * p + str[str.size()-i];
        ksm[i] = (i == 0) ? 1 : ksm[i-1] * p;

        poshsh[i] %= Mod;
        neghsh[i] %= Mod;
        ksm[i] %= Mod;
    }
}

int getposhsh( int l, int r ){
    return 
}

int bs( int low, int high ){
    int len = 0, step = n;
    while( step > 0 ){
        if(  )
    }
}

signed main(){
    opt;

    cin >> str;

    pre();

    res = n + 5;
    for( int i = n / 2 ; i < n ; ++i ){
        if( n % 2 == 0 ){
            res = min(res, bs(i-1, i));
            res = min(res, bs(i-1, i+1));
        }else{
            res = min(res, bs(i, i+1));
            res = min(res, bs(i-1, i+1));
        }
    }
}