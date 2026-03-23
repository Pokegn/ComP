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

int num(string s){
    if(s == "single"){
        return 0;
    }
    if(s == "double"){
                return 1;

    }
    if(s == "triple"){
        return 2;

    }
    if(s == "tetris"){
        return 3;
    }
    return 0;
}

void solve(){
    int n; cin >> n;
    ll rows = 0;
    string s;
    int k;
    vector<ll> points = {760, 1900, 5700, 22800};
    ll score = 0;
    rep(i,0,n){
        cin >> s;
        k = num(s);
        score += points[k];
        rows+=k+1;
        if(rows/10 >= 13){
            ll dif = rows/10 - 12;
            points[0] = 760 + 40*dif;
            points[1] = 1900 + 100*dif;
            points[2] = 5700 + 300*dif;
            points[3] = 22800 + 1200*dif;
        }
    }

    cout << score << ' ' << (rows <= 130 ? 18 : 18+rows/10-12) << endl;
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    //cin >> t;
    while(t--) solve();
    return 0;
}