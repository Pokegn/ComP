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
    vlli p(n);
    forn(i, 0, n) cin >> p[i];
    vlli q(n);
    forn(i, 0, n) q[i] = n+1-p[i];
    int paridad = 1;
    lli xd1= 0;
    lli xd2= 0;
    forn(i, 0, n){
        if(paridad == 1){
            if(p[i] == 1) xd1 = 1;
        }
        else if(p[i] == 1) xd2 = 1;
        paridad*=-1;
    }

    priority_queue<pair<lli, lli>, vector<pair<lli, lli>>, greater<pair<lli, lli>>> q1, q2;
    paridad = 1;
    forn(i, 0, n){
        if(paridad == 1){
            q1.push({q[i], i});
        }
        else q2.push({q[i], i});
        paridad*=-1;
    }
    lli curr = 1;
    while(!q1.empty()){
        auto top = q1.top();
        q1.pop();
        q[top.second] = curr;
        curr++;
    }
    curr = 1;
    while(!q2.empty()){
        auto top = q2.top();
        q2.pop();
        q[top.second] = curr;
        curr++;
    }

    forn(i, 0, n){
        if(xd1 ==1){ //los pares tienen al 1
            if(i%2 != 0) q[i]+=n/2;
        }
        else{
            if(i%2 == 0) q[i]+=n/2;
        }
    }
    forn(i,0, n) cout << q[i] << ' ';
    cout << nl;
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}