#include<bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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
const int MAXN = 2e2 + 50;
const int Mod = 1e9 + 7;
const long long LLINF = 0x7FFFFFFFFFFFFFFF;
const int INF = 0x7FFFFFFF;

int n, m, MIN, res;
int arr[MAXN][MAXN];

bool valid(pii nxt){
    return nxt.F == 0 || nxt.F == n - 1 || nxt.S == 0 || nxt.S == m - 1;
}

signed main(){
    opt;

    cin >> n >> m;

    MIN = INF;
    for( int i = 0 ; i < n ; ++i ){
        for( int j = 0 ; j < m ; ++j ){
            cin >> arr[i][j];
        }
    }

    for( int i = 0 ; i < n ; ++i ){
        for( int j = 0 ; j < m ; ++j ){

            if( m > 2 && n > 2 ){
                if( i == 0 ){
                    if( j == 0 || j == m - 1 ) continue;

                    MIN = min(MIN, max(arr[i][j], arr[i+1][j]));
                }else if( i == n - 1 ){
                    if( j == 0 || j == m - 1 ) continue;

                    MIN = min(MIN, max(arr[i][j], arr[i-1][j]));
                }else if( j == 0 ){
                    MIN = min(MIN, max(arr[i][j], arr[i][j+1]));
                }else if( j == m - 1 ){
                    MIN = min(MIN, max(arr[i][j], arr[i][j-1]));
                }

                // cout << i << " " << j << " | " << arr[i][j] << " " << max(arr[i][j], arr[i+1][j]) << "\n";
            }
        }
    }

    if( m <= 2 || n <= 2 ){
        cout << "0\n";
        exit(0);
    }

    // cout << MIN << "\n-----\n";

    for( int i = 1 ; i < n - 1 ; ++i ){
        for( int j = 1 ; j < m - 1 ; ++j ){
            // cout << max((ll)0, MIN - arr[i][j]) << " ";
            res += max((ll)0, MIN - arr[i][j]);
        }
        // cout << "\n";
    }

    cout << res << "\n";
}
