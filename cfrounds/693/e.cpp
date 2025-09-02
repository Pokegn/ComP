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

vlli h;
vlli w;

    // lli binsearchh(lli x, lli l, lli r){
    //     if(l == r){
    //         if(h[l] > x) return l;
    //         return -1;
    //     }
    //     lli m = (l+r)/2;
    //     if()
    // }

//quiero un vector que me diga el indice con el mayor valor de h entre x y n-1 para un w sorteado
//y otro que me diga el indice con el mayor valor de w entre x y n-1 para un h sorteado


void solve(){
    lli n; cin >> n;
    h = vlli(n);
    w = vlli(n);
    forn(i, 0, n){
        cin >> h[i] >> w[i];
    }
    vector<pair<lli, lli>> byh(n);
    vector<pair<lli, lli>> byw(n);
    forn(i, 0, n){
        byh[i] = {h[i], i};
        byw[i] = {w[i], i};
    }
    sort(byh.begin(), byh.end());
    sort(byw.begin(), byw.end());
    forn(i, 0, n){
        swap(byh[i].first, byh[i].second);
        swap(byw[i].first, byw[i].second);
    }

    vlli maxw(n);
    vlli maxh(n);
    maxw[n-1] = n-1;
    maxh[n-1] = n-1;
    rof(i, n-2, 0){
        if(w[byh[i].first] > w[byh[i+1].first]) maxw[i] = i;
        else maxw[i] = maxw[i+1];
        if(h[byw[i].first] > h[byw[i+1].first]) maxh[i] = i;
        else maxh[i] = maxh[i+1];
    }

    forn(i, 0, n){
        
    }
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}