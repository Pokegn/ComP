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

void solve(){
    lli n, m; cin >> n >> m;
    vlli a(n);
    vlli b(n);
    vlli c(m);
    forn(i, 0, n) cin >> a[i];
    forn(i, 0, n) cin >> b[i];
    forn(i, 0, m) cin >> c[i];
    vector<pair<lli, lli>> costo(n);
    forn(i, 0, n) costo[i] = {a[i]-b[i], a[i]};
    sort(costo.begin(), costo.end());


    forn(i, 1, n){
        costo[i].second = min(costo[i].second, costo[i-1].second);
    }

    vector<lli> necesito(n);
    forn(i, 0, n){
        necesito[i] = costo[i].second;
    } 

    vector<pair<lli, lli>> necesito2(n);
    forn(i, 0, n){ //a[i], a[i]-b[i]
        necesito2[i].first = costo[i].second;
        necesito2[i].second = costo[i].first;
    }
    reverse(necesito2.begin(), necesito2.end());
    // forn(i, 0, n){
    //     cout << necesito2[i].first << ' ' << necesito2[i].second << nl;
    // }
    // return;

    lli menor = necesito2[0].first;

    vlli ans(2e6+3);
    forn(i, 0, 2e6+3){
        if(i < menor){
            ans[i] = 0;
        }
        else{

            auto bound = upper_bound(necesito2.begin(), necesito2.end(), pair<lli, lli> {i, 1e10});
            if(bound == necesito2.end()) bound = necesito2.begin()+n;
            ans[i] = 2 + ans[(i-(bound-1)->second)];
        }
    }

    
    lli ansm = 0;
    forn(i, 0, m){
        if(c[i] < 1e6+2){
            ansm+=ans[c[i]];
            continue;
        }
        //ansm+= ans[c[i]];
        lli xd = (c[i]-necesito2[n-1].first)/necesito2[n-1].second; //lo que tengo menos
        ansm+= 2*xd;
        ansm+= ans[c[i] - xd*necesito2[n-1].second];
        //cout << c[i] - xd*necesito2[n-1].second << ' ' << nl;
    }
    cout << ansm << nl;
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}