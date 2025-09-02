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

void solve(){
    lli n; cin >> n;
    lli spacing; cin >> spacing;
    vlli x1(n), y1(n), x2(n), y2(n);
    forn(i, 0, n) cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
    forn(i, 0, n){
        x2[i] += spacing;
    }

    lli gridx1 = x1[0], gridx2 = x2[0], gridy1 = y1[0], gridy2 = y2[0];
    forn(i, 1, n){
        gridx1 = min(gridx1, x1[i]);
        gridx2 = max(gridx2, x2[i]);
        gridy1 = min(gridy1, y1[i]);
        gridy2 = max(gridy2, y2[i]);
    }

    vector<pair<lli, lli>> rxtoid(n);
    forn(i, 0, n){
        rxtoid[i] = {x2[i], i};
    }

    sort(rxtoid.begin(), rxtoid.end());

    //forn(i,0 ,n) cout << i << ' ' << rxtoid[i].first << ' ' << x2[rxtoid[i].second] << nl;

    lli newx;
    forn(i, 0, n){
        newx = gridx1;
        forn(j, 0, i){
            if(!(y2[rxtoid[i].second] < y1[rxtoid[j].second] || y2[rxtoid[j].second] < y1[rxtoid[i].second])){
                newx = max(newx, x2[rxtoid[j].second]);
            }
        }
        //newx = min(newx, x1[rxtoid[i].second]);
        x2[rxtoid[i].second] = newx + x2[rxtoid[i].second] - x1[rxtoid[i].second];
        x1[rxtoid[i].second] = newx;
    }

    if(gridx2 - x2[rxtoid[n-1].second] < 0) cout << 0 << nl;
    //forn(i,0 ,n) cout << i << ' ' << rxtoid[i].first << ' ' << x2[rxtoid[i].second] << nl;
    else cout << (gridy2-gridy1) * (gridx2 - x2[rxtoid[n-1].second]) << nl;

    vector<pair<lli, lli>> lxtoid(n);
    forn(i, 0, n){
        lxtoid[i] = {x1[i], i};
    }

    sort(lxtoid.begin(), lxtoid.end(), greater<pair<lli, lli>>());

    //forn(i,0 ,n) cout << i << ' ' << lxtoid[i].first << ' ' << x2[lxtoid[i].second] << nl;

    forn(i, 0, n){
        newx = gridx2;
        forn(j, 0, i){
            if(!(y2[lxtoid[i].second] < y1[lxtoid[j].second] || y2[lxtoid[j].second] < y1[lxtoid[i].second])){
                newx = min(newx, x1[lxtoid[j].second]);
            }
        }
        //newx = min(newx, x1[lxtoid[i].second]);
        x1[lxtoid[i].second] = newx + x2[lxtoid[i].second] - x1[lxtoid[i].second];
        x1[lxtoid[i].second] = newx;
    }

    if(gridx2 - x2[lxtoid[n-1].second] < 0) cout << 0 << nl;
    //forn(i,0 ,n) cout << i << ' ' << lxtoid[i].first << ' ' << x2[lxtoid[i].second] << nl;
    else cout << (gridy2-gridy1) * (gridx2 - x2[lxtoid[n-1].second]) << nl;

}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t; while(t--) solve();
    return 0;
}