#include <bits/stdc++.h>
using namespace std;
template <typename T, int D>
struct Vector : public vector<Vector<T, D - 1>> {
    static_assert(D > 0);
    template<typename... Args>
    Vector(int sz = 0, Args... args) : vector<Vector<T, D - 1>>(sz, Vector<T, D - 1>(args...)) {}
};
template <typename T>
struct Vector<T, 1> : public vector<T> {
    Vector(int sz = 0, const T& val = T()) : vector<T>(sz, val) {}
};

template <typename T>
struct Matrix : public vector<vector<T>> {
    Matrix(int hei = 0, int wid = 0, const T& val = T()) : vector<vector<T>>(hei, vector<T>(wid, val)) {}
};
using lli = long long int;
using vi = vector<int>;
using vlli = vector<lli>;
using vvi = vector<vi>;
using vvlli = vector<vlli>;
#define forn(i, a, b) for(int i = a; i < b; i++)
#define rof(i, a, b) for(int i = a; i >= b; i--)
#define nl '\n'
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    int n, a, b, c; cin >> n >> a >> b >> c;
    int temp;
    vi dp(n+1);
    vi ab(3);
    ab[0] = a; ab[1] = b; ab[2] = c;
    sort(ab.begin(), ab.end());

    dp[0] = 0;
    forn(i, 1, n+1){
        if(i<ab[0]) dp[i] = -1;
        else{
            if(i-ab[2]>=0){
                dp[i] = max(dp[i-ab[0]], max(dp[i-ab[1]], dp[i-ab[2]]));
            }
            else if(i-ab[1]>=0){
                dp[i] = max(dp[i-ab[0]], dp[i-ab[1]]);
            }
            else dp[i] = dp[i-ab[0]];

            if(dp[i] != -1) dp[i]++;
        }
    }

    cout << dp[n];

}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1;
    while(t--) solve();
    return 0;
}