#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
#define rep(i, a, b) for(int i=a; i<(b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define endl '\n'
#define pb push_back
#define fi first
#define se second
//#define fin dp[k][starr][stchange] = ret; return
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

//o quitamos hasta k
//o elegimos hasta k fuera
//elijo k y los cambio al reves

const ll INF = 1000000000000010;
vector<vector<vector<ll>>> dp;
int n,k;
vector<ll> a;
//starr = 0 antes, 1 adentro, 2 afuera
ll d(int i, int krem, int state, bool change){
    ll ret = -INF;
    if(change && (krem == k)) return -INF;
    if(i >= n) return -INF;
    if(i == 0){
        if((state == 0) || (state == 2)){
            if(!change) ret = 0;
            else ret = a[0];
        }
        else{
            if(!change) ret = a[0];
            else ret = 0;
        }
        return ret;
    }
    if(state-1 >= 0){ //state anterior
        if(change == 0){
            ret = max(ret, dp[krem][state-1][1]);
            ret = max(ret, dp[krem][state-1][0]);
        }
        if(change == 1){
            if(krem+1 < k) ret = max(ret, dp[krem+1][state-1][1]);
            if(krem == k-1) ret = max(ret, dp[krem+1][state-1][0]);
        }
    }
    //mismo state
    if(change == 0){
        ret = max(ret, dp[krem][state][1]);
        ret = max(ret, dp[krem][state][0]);
    }
    if(change == 1){
        if(krem+1 < k) ret = max(ret, dp[krem+1][state][1]);
        if(krem == k-1) ret = max(ret, dp[krem+1][state][0]);
    }
    //return
    if(ret == -INF) return ret;
    else{
        if((state == 1) && (!change)) ret += a[i];
        if((state != 1) && (change)) ret += a[i];
    }
    return ret;
}

void solve(){
    cin >> n >> k;
    a = vector<ll>(n);
    rep(i, 0, n) cin >> a[i];
    dp = vector<vector<vector<ll>>>(k+1,
             vector<vector<ll>>(3,
                 vector<ll>(3, -INF)));

    rep(j, 0, k+1){
            rep(p, 0, 3){
                rep(q, 0, 3){
                    dp[j][p][q] = d(0, j, p, q);
            }
        }
    }

    rep(i, 1, n){
        auto dp_temp = dp;
        rep(j, 0, k+1){
            rep(p, 0, 3){
                rep(q, 0, 3){
                    dp_temp[j][p][q] = d(i, j, p, q);
                }
            }
        }
        swap(dp, dp_temp);
    }

    ll ans = 0;
    ll maxi = -INF;
    rep(i, 0, n) maxi = max(maxi, a[i]);
    if(maxi < 0){
        cout << maxi << endl;
        return;
    }

    rep(j, 0, k+1){
        rep(p, 0, 3){
            rep(q, 0, 3){
                maxi = max(maxi, dp[j][p][q]);
            }
        }
    }

    cout << maxi << endl;
    return;

}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}