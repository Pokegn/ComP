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

void solve(){
    map<pair<lli, lli>, lli> mapa;
    lli n; cin >> n;
    vector<pair<lli, lli>> a(n);
    lli parx = 0;
    lli imparx = 0;
    forn(i, 0, n){
        lli x,b; cin >> x >> b;
        if(x%2 == 1) imparx++;
        else parx++;
        mapa[{x,b}] = 1;
        a[i].first = b; //y,x
        a[i].second = x;
    }

    sort(a.begin(), a.end(), greater<pair<lli, lli>>());
    forn(i, 0, n){
        lli y = a[i].first;
        lli x = a[i].second;
        
        if(mapa[{x,y}] == 0) continue;
        if(mapa[{y-1,x}] == 1 && mapa[{y-1,x-1}] ==1 &&  mapa[{y-2,x-1}] == 1){
            if(mapa[{x-1,y}] == 1){
                if(imparx > parx){
                    if(x%2 == 1){
                        cout << x << ' ' << y << nl;
                        return;
                    }
                    else{
                        cout << x-1 << ' ' << y << nl;
                        return;
                    }
                }
                else{
                    if(x%2 != 1){
                        cout << x << ' ' << y << nl;
                        return;
                    }
                    else{
                        cout << x-1 << ' ' << y << nl;
                        return;
                    }
                }
            }
            else{
                mapa[{x,y}] = 0;
                mapa[{y-1,x}] = 0; mapa[{y-1,x-1}] = 0; mapa[{y-2,x-1}] = 0;
            }
        }
        else{
            cout << x << ' ' << y << nl;
            return;
        }
    }
    
    
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}