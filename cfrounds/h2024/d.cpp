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
    int n; cin >> n;
    vlli a(n+1);
    vi suc(n);
    vi pred(n);
    int j = 1;
    int x;
    cin >> x;
    a[0] = x;
    forn(i, 1, n){
        cin >> x;
        if(x!=a[j-1]){
            a[j] = x;
            pred[j] = j-1;
            suc[j] = j+1;
            j++;
        }
    }
    pred[0] = n;
    suc[0] = 1;
    a[n] = 1e8;
    int sz = j;
    priority_queue<pair<int, int>> pq;
    forn(i, 0, sz){
        pq.push(make_pair(a[i], i));
    }

    lli p, q;
    while(pq.size()>1){
        p = pq.top().first;
        q = pq.top().second;
        pq.pop();
        if(p-1 == suc[q]){
            pred[q]--;
            continue;
        }
        if(p-1 == pred[q]){
            suc[q]++;
            continue;
        }
        cout << "NO" << p << nl;
        return;
    }
    if(pq.top().first == 0) cout << "YES" << nl;
    else cout << "no" << nl;
    return;

}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}