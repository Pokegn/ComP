#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
using lli = long long int;
using vi = vector<int>;
using vlli = vector<lli>;
using vvi = vector<vi>;
using vvlli = vector<vlli>;
#define forn(i, a, b) for(lli i = a; i < b; i++)
#define rof(i, a, b) for(lli i = a; i >= b; i--)
#define nl '\n'
#define pb push_back
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

vector<vector<vector<vector<lli>>>> ans;
vvlli a;
vector<vector<vector<bool>>> possible;
vlli rcost, ccost;

void calculate(lli l, lli r, lli lx, lli rx){
    if(lx == 2){
        calculate(l, r, 0, rx);
        calculate(l, r, 1, rx);
        return;
    }
    if(rx == 2){
        calculate(l, r, lx, 0);
        calculate(l, r, lx, 1);
        return;
    }
    if(ans[l][r][lx][rx] != -1000000000000000000) return;
    if(l == r){
        if(lx!=rx) ans[l][r][lx][rx] = -1;
        else ans[l][r][lx][rx] = (lx == 1 ? rcost[l]:0);
        return;
    }

    lli m = (l+r)/2;
    lli mini = 1e18;
    if(possible[m][0][1]){
        calculate(l, m, 2, 0);
        calculate(m+1, r, 1, 2);

        if(ans[l][m][lx][0] >= 0 && ans[m+1][r][1][rx] >= 0)
        mini = min(mini, ans[l][m][lx][0]+ans[m+1][r][1][rx]);
    }
    if(possible[m][1][1]){
        calculate(l, m, 2, 1);
        calculate(m+1, r, 1, 2);

        if(ans[l][m][lx][1] >= 0 && ans[m+1][r][1][rx] >= 0)
        mini = min(mini, ans[l][m][lx][1]+ans[m+1][r][1][rx]);
    }
    if(possible[m][0][0]){
        calculate(l, m, 2, 0);
        calculate(m+1, r, 0, 2);

        if(ans[l][m][lx][0] >= 0 && ans[m+1][r][0][rx] >= 0)
        mini = min(mini, ans[l][m][lx][0]+ans[m+1][r][0][rx]);
    }
    if(possible[m][1][0]){
        calculate(l, m, 2, 1);
        calculate(m+1, r, 0, 2);

        if(ans[l][m][lx][1] >= 0 && ans[m+1][r][0][rx] >= 0)
        mini = min(mini, ans[l][m][lx][1]+ans[m+1][r][0][rx]);
    }

    if(mini == 1e18) ans[l][r][lx][rx] = -1;
    else ans[l][r][lx][rx] = mini;
    return;
}

void solve(){
    lli n; cin >> n;
    a = vvlli (n, vlli(n));
    possible = vector<vector<vector<bool>>> (n, vector<vector<bool>>(2, vector<bool>(2, true)));
    ans = vector<vector<vector<vector<lli>>>> (n, vector<vector<vector<lli>>>(n, vvlli(2, vlli(2, -1000000000000000000)))); //dimensiones [n-1][n-1][2][2]
    rcost = vlli (n);
    ccost = vlli (n);

    forn(i, 0, n){
        forn(j, 0, n){
            cin >> a[i][j];
        }
    }

    forn(i, 0, n) cin >> rcost[i];
    forn(i, 0, n) cin >> ccost[i];

    forn(i, 0, n-1){
        forn(j, 0, n){
            if(a[i][j] == a[i+1][j]){
                possible[i][0][0] = false;
                possible[i][1][1] = false;
            }
            if(a[i][j] == a[i+1][j]+1){
                possible[i][0][1] = false;
            }
            if(a[i][j] == a[i+1][j]-1){
                possible[i][1][0] = false;
            }
        }
    }

    calculate(0, n-1, 2, 2);

    lli ansa = 1e18;
    if(ans[0][n-1][0][0]>=0) ansa = min(ansa, ans[0][n-1][0][0]);
    if(ans[0][n-1][1][0]>=0) ansa = min(ansa, ans[0][n-1][1][0]);
    if(ans[0][n-1][0][1]>=0) ansa = min(ansa, ans[0][n-1][0][1]);
    if(ans[0][n-1][1][1]>=0) ansa = min(ansa, ans[0][n-1][1][1]);

    //cout << ansa << nl;

    forn(i, 0, n){
        forn(j, 0, i){
            lli temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }

    possible = vector<vector<vector<bool>>> (n, vector<vector<bool>>(2, vector<bool>(2, true)));
    forn(i, 0, n-1){
        forn(j, 0, n){
            if(a[i][j] == a[i+1][j]){
                possible[i][0][0] = false;
                possible[i][1][1] = false;
            }
            if(a[i][j] == a[i+1][j]+1){
                possible[i][0][1] = false;
            }
            if(a[i][j] == a[i+1][j]-1){
                possible[i][1][0] = false;
            }
        }
    }

    ans = vector<vector<vector<vector<lli>>>> (n, vector<vector<vector<lli>>>(n, vvlli(2, vlli(2, -1000000000000000000)))); //dimensiones [n-1][n-1][2][2]
    forn(i, 0, n) rcost[i] = ccost[i];
    calculate(0, n-1, 2, 2);

    lli ansb = 1e18;
    if(ans[0][n-1][0][0]>=0) ansb = min(ansb, ans[0][n-1][0][0]);
    if(ans[0][n-1][1][0]>=0) ansb = min(ansb, ans[0][n-1][1][0]);
    if(ans[0][n-1][0][1]>=0) ansb = min(ansb, ans[0][n-1][0][1]);
    if(ans[0][n-1][1][1]>=0) ansb = min(ansb, ans[0][n-1][1][1]);
    
    lli ansf = ansa+ansb;
    if(ansa == 1e18 || ansb == 1e18) ansf = -1;
    cout << ansf << nl;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}