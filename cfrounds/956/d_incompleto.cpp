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


vlli segtree(1000000);
vlli pos;
void segbuild(lli v, lli l, lli r){
    if(l == r) segtree[v] = pos[l];
    else{
        int mid = (l+r)/2;
        segbuild(2*v+1, l, mid);
        segbuild(2*v+2, mid+1, r);
        segtree[v] = segtree[2*v+1]+segtree[2*v+2];
    }
}

void update(lli v, lli x, lli i, lli l, lli r){
    if(l == r){
        segtree[v] += x;
        return;
    }
    int mid = (l+r)/2;
    if(i<=mid){
        update(2*v+1, x, i, l, mid);
        segtree[v] = segtree[2*v]+segtree[2*v+1];
        return;
    }
    update(2*v+2, x, i, mid+1, r);
    segtree[v] = segtree[2*v+1]+segtree[2*v+2];
    return;
}

int query(lli v, lli l, lli r, lli s, lli e){
    if(s>r || e<l) return 0;
    if(s<=l && r<=e){
        return segtree[v];
    }
    int mid = (l+r)/2;
    return query(2*v+1, l, mid, s, e)+query(2*v+2, mid+1, r, s, e);
}

void solve(){
    lli n; cin >> n;
    vlli a(n); forn(i,0, n) cin >> a[i];
    vlli b(n); forn(i,0, n )cin>> b[i];
    pos.assign(n, 0);
    // vlli sorted(n); forn(i,0 ,n) sorted[i] = a[i];
    // sort(sorted.begin(), sorted.end());
    map<lli, lli> locasion1;
    map<lli, lli> locasion2;
    forn(i, 0, n){
        locasion1.insert({a[i], i+1}); //donde esta a[i]
        locasion2.insert({b[i], i+1}); //donde esta b[i]   
    }
    forn(i, 0, n){
        //pos[i] = locasion1[]
    }
    segbuild(0, 0, n-1);

    lli cambios = 0;
    forn(i, 0, n){
        if(locasion2[a[i]] == 0){
            cout << "NO" << nl;
            return;
        }
        cambios+=(locasion2[a[i]]-locasion1[a[i]]);
        //suum
    }

    if(cambios %2 == 0){
        cout << "YES" << nl;
    }
    else cout << "NO" << nl;

}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}