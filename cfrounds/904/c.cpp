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
    lli n, m; cin >> n >> m;
    vector<pair<lli, lli>> pairs(n, {0,0});
    forn(i, 0, n){
        cin >> pairs[i].first >> pairs[i].second;
    }
    map<lli, lli> vis;
    vlli indices;
    forn(i, 0, n){
        if(vis[pairs[i].first] == 0){
            indices.push_back(pairs[i].first);
            vis[pairs[i].first] = 1;
        }
        if(vis[pairs[i].second] == 0){
            indices.push_back(pairs[i].second);
            vis[pairs[i].second] = 1;
        }
    } //tengo mis indices
    sort(indices.begin(), indices.end()); //ordenados
    lli indsz = indices.size();
    map<lli, lli> index;
    forn(i, 0, indsz){
        index[indices[i]] = i; //indices dice cual es el indice de cada elemento que se metio
    }

    vlli comp(indsz+1, 0);
    forn(i, 0, n){
        comp[index[pairs[i].first]]++;
        comp[index[pairs[i].second]+1]--;
    }
    forn(i,1 , indsz){
        comp[i] += comp[i-1];
    }


    vlli compder(indsz+1, 0);
    vlli compizq(indsz+1, 0);
    forn(i, 0, n){
        if(pairs[i].first == 1){
            compizq[index[pairs[i].second]]++;
        }
        if(pairs[i].second == m){
            compder[index[pairs[i].first]]++;
        }
    }

    forn(i, 1, indsz){
        compder[i] += compder[i-1];
    }
    rof(i, indsz-2, 0){
        compizq[i] += compizq[i+1];
    }

    lli ans = 0;
    forn(i,0,indsz){
        ans = max(ans, max(comp[i]-compizq[i], comp[i]-compder[i]));
    }
    cout << ans << nl;
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}