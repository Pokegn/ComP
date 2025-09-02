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
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    string s, t; cin >> s >> t;
    lli slen = s.length(), tlen = t.length();
    vvlli dp(slen, vlli(tlen, 0));
    if(s[0] == t[0]) dp[0][0] = 1;

    forn(i, 1, slen){
        if(s[i] == t[0]) dp[i][0] = 1;
        else dp[i][0] = dp[i-1][0];
    }

    forn(i, 1, tlen){
        if(s[0] == t[i]) dp[0][i] = 1;
        else dp[0][i] = dp[0][i-1];
    }
    lli diagval;
    
    forn(i, 1, slen){
        forn(j, 1, tlen){
            if(i>0 && j>0) diagval = (s[i] == t[j] ? dp[i-1][j-1] : dp[i-1][j-1]+1);
            else diagval = 0;
            dp[i][j] = max(dp[i][j], diagval);
            if(i>0) dp[i][j] = max(dp[i][j], dp[i-1][j]);
            if(j>0) dp[i][j] = max(dp[i][j], dp[i][j-1]);
        }
    }

    lli si = slen-1;
    lli ti = tlen-1;
    string ans;
    while(si>0 || ti>0){
        if(s[si] == t[ti]){
            ans+=s[si];
            si--;
            ti--;
            continue;
        }
        if(si>0){
            if(dp[si-1][ti] == dp[si][ti]){
                si--;
                continue;
            }
        }
        if(ti>0){
            if(dp[si][ti-1] == dp[si][ti]){
                ti--;
                continue;
            }
        }
    }

    reverse(ans.begin(), ans.end());
    cout << ans << nl;

    // forn(i, 0, slen){
    //     forn(j, 0, tlen){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << nl;
    // }
    // cout << dp[slen-1][tlen-1] << nl;
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}