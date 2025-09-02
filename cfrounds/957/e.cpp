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

lli search(lli a, lli n){
    lli checando = 0;
    vector<char> s;
    lli b;
                                                                                lli xd = n;
                                                                                while(xd>0){
                                                                                    s.push_back((char)('0'+xd%10));
                                                                                    xd/=10;
                                                                                }
                                                                                
    reverse(s.begin(), s.end());
    lli sz = s.size();
    // forn(i, 0, sz) cout << s[i];
    // cout << nl;
    forn(i, 1, 10){
        checando*=10;
        checando+=(s[(i-1)%sz]-'0');
        b = n*a-checando;
        if(b<=0) continue;
        if(b==sz*a-i){
            //cout << checando << 'x' << nl;
            return b;
        } 
        else continue;
    }
    return -1;
}

void solve(){
    lli n; cin >> n;
    vector<pair<lli, lli>> ans;
    lli b;
    lli anss = 0;
    forn(a, 1, 10001){
        lli xd = search(a, n);
        if(xd !=-1){
            ans.push_back({a, xd});
        }
    }
    anss = ans.size();
    cout << anss<< nl;
    forn(i, 0, anss){
        cout << ans[i].first    << ' ' << ans[i].second << nl;
    }
}
 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}