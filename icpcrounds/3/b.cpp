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

void solve(){
    string st; cin >> st;
    int n = st.length();
    vi s(n);
    forn(i, 0, n) s[i] = (int)(st[i]-'0');
    vi scopy(n);
    lli ans = 1;
    lli sumalastkmenos1 = 0;
    vi este(n, 0);
    forn(k, 2, n+1){
        este = vi(n, 0);
        forn(obj, 0, 10){

            sumalastkmenos1 = 0;
            forn(i, 0, n) scopy[i] = s[i];
            forn(i, 0, n+1-k){
                if(i-k>=0) sumalastkmenos1 -= este[i-k];
                este[i] = obj-(scopy[i]+sumalastkmenos1)%10;
                
                if(este[i]<0) este[i]=(este[i]%10+10)%10;

                sumalastkmenos1 += este[i];
            }
            bool flag = true;
            forn(i, n+1-k, n){;
                if(i-k>=0) sumalastkmenos1 -= este[i-k];
                if((scopy[i]+sumalastkmenos1)%10 != obj) flag = false;
            }
            if(flag) ans = max(ans, k);
            // if(obj == 7){
            //     forn(i, 0, n) cout << scopy[i] << ' ';
            //     cout << nl;
            // }
        }
    }
    cout << ans << nl;
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--)
    solve();
    return 0;
}
