#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
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
#define forn(i, a, b) for(lli i = a; i < b; i++)
#define rof(i, a, b) for(lli i = a; i >= b; i--)
#define nl '\n'
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

vlli maximos(300000);

void calcula(){
    forn(i, 1, 300000){
        if(i == 1){
            maximos[1] = 0;
            continue;
        }
        if(i == 2){
            maximos[2] = 2;
            continue;
        }
        maximos[i] = maximos[i-2] + 2*(i-1);
    }
}

void solve(){
    lli n, k; cin >> n >> k;
    if(k > maximos[n] || k%2 == 1){
        cout << "NO" << nl;
        return;
    }
    cout << "YES" << nl;
    if(n == 1){
        cout << 1 << nl;
        return;
    }
    if(n == 2 && k == 0){
        cout << 1 << ' ' << 2 << nl;
        return;
    }
    if(n == 2 && k == 2){
        cout <<  2 << ' ' << 1 << nl;
        return;
    }
    vlli ans(n+1, 0);
    iota(ans.begin(), ans.begin()+n+1, 0);
    lli i = 1;
    while(k>0){
        if(k<2*(n-2*i+1)){
            lli xd = k/2;
            k = 0;
            lli j = i;
            while(xd--){
                ans[j]++;
                j++;
            }
            ans[j] = i;
        }
        else{
            k-=2*(n-2*i+1);
            swap(ans[i], ans[n-i+1]);
        }
        i++;
    }
    

    forn(i, 1, n+1) cout << ans[i] << ' ';
    cout << nl;
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    calcula();
    //cout << maximos[200000] << nl;
    //forn(i, 1, 6) cout << maximos[i] << ' ';
    int t; cin >> t;
    while(t--) solve();
    return 0;
}