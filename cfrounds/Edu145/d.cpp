#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
#define rep(i, a, b) for(int i=a; i<(b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define endl '\n'
#define pb push_back
typedef long long ll;
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    string s; cin >> s;
    int n = s.length();
    vector<int> cerosizq(n);
    vector<int> unosizq(n); //sin incluirme
    int ceros = 0, unos = 0;

    rep(i, 0, n){
        unosizq[i] = unos;
        cerosizq[i] = ceros;
        if(s[i] == '0') ceros++;
        else unos++;
    }

    if(unos == n || ceros == n){
        cout << 0 << endl;
        return;
    }

    ll ans = unos;
    ll cuantosunos = 0;
    vector<ll> score(n, -1);
    rep(i, 0, n){
        if(s[i] == '0') continue;
        score[i] =  (ceros - cerosizq[i]) + cuantosunos;
        ans = min(ans, score[i]);
        cuantosunos++;
    }  

    ll maxsex = 0;
    rep(i, 0, n){
        if(s[i] == '0') continue;
        if(score[i] != ans) continue;
        ll cerosder = 0, unosizq = 0;
        //unosizq
        int idx = i-2;
        if(i-2>=0 && s[i-1] == '0' && s[i-2] == '1') maxsex = 1;
        if(i+1<n && s[i+1] == '0') maxsex = 1;
        // if(i-1 >=0 && s[i-1] == '0')
        // while(idx >= 0 && s[idx] == '1'){
        //     idx--;
        //     unosizq++;
        // }
        // maxsex = max(maxsex, unosizq);
        // idx = i+1;
        // while(idx < n && s[idx] == '0'){
        //     idx++;
        //     cerosder++;
        // }
        // maxsex = max(maxsex, cerosder);
    }

    //cout << ans << ' ' << maxsex << endl;
    ans = -maxsex + ((1000000000001)) * ans;
    cout << ans << endl;
    return;
}



int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}