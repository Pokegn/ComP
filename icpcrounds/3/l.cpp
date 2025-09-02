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

vlli primo(1000010, 1);
void xd(){
    primo[0] = primo[1] = 0;
    forn(i, 2, 1000011){
        if(primo[i] && (lli)i*i <= 1000010){
            for(lli j = i*i; j<=1000010; j+=i) primo[j] = 0;
        }
    } 
}

void solve(){
    long double n; cin >> n;
    if(floor(sqrt(n)) != sqrt(n)){
        cout << "NO" << nl;
        return;
    }
    lli sq = (lli)floor(sqrt(n));
    //cout << sq << ' ';
    if(primo[sq] == 1) cout << "YES" << nl;
    else cout << "NO" << nl;
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    xd();
    lli t; cin >> t; while(t--)
    solve();
    return 0;
}
