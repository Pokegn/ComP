#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
using ll = long long;
using vi = vector<int>;
using vlli = vector<ll>;
using vvi = vector<vi>;
using vvlli = vector<vlli>;
#define forn(i, a, b) for(ll i = a; i < b; i++)
#define rof(i, a, b) for(ll i = a; i >= b; i--)
#define nl '\n'
#define endl '\n'
#define pb push_back
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    ll n,x; cin >> n >> x;
    vlli a(n); for(ll i=0; i<n; i++) cin>> a[i];
    map<ll, ll> m;
    for(ll i=0; i<n; i++) m[a[i]]++;
    ll mx2 = m[x/2];
    if(x%2 == 0){
        if(n - mx2 - mx2 < -1){
            cout << "*" << endl;
            return;
        }
    }

    for(ll i=0; i<n; i++){
        if(2*a[i] == x) continue;
        if(m[a[i]]+m[x-a[i]] == n){
            if(m[x-a[i]] == 0){
                for(ll j=0; j<n; j++){
                    cout << a[j] << ' ';
                }
                cout << endl;
                return;
            }
            cout << "*" << endl;
            return;
        }
    }


    bool casoespecial = false;
    for(ll i=0; i<n; i++){
        if(x%2 !=0) continue;
        if(a[i] == x/2) continue;
        if(m[a[i]]+m[x-a[i]] + mx2 == n) casoespecial = true;
    }

    vlli f1(0), f2(0), f3(0); //f1 es con par primero, f2 es sin par primero, f3 es con par segundo
    map<ll, bool> vis;
    for(ll i=0; i<n; i++){
        if(2*a[i] == x) continue;
        if(vis[a[i]]) continue;
        vis[a[i]] = true;
        vis[x-a[i]] = true;
        if(m[x-a[i]] > 0){
            f1.push_back(min(a[i], x-a[i]));
            f3.push_back(max(a[i], x-a[i]));
        }
        else f2.push_back(a[i]);
    }

    ll count = 0;
    ll especialcount = 0;
    if(casoespecial){
        if(n - mx2 - mx2 > -1){
            especialcount = 1;
            count++;
        } 
    }
    if(x%2 == 0 && count< mx2 && especialcount == 0){
        cout << x/2 << ' ';
        count++;
    }

    bool last = false;
    for(auto xd: f1){
        auto imax = m[xd];
        for(ll i=0; i<imax; i++){
            cout << xd << ' ';
            if(x%2 == 0 && count< mx2){
                cout << x/2 << ' ';
                count++;
                last = true;
            }
            else last = false;
        }
    }

    if(especialcount == 1){
        if(last == false){
            cout << x/2 << ' ';
        }
        else count--;
        
    }

    for(auto xd: f2){
        auto imax = m[xd];
        for(ll i=0; i<imax; i++){
            cout << xd << ' ';
            if(x%2 == 0 && count< mx2){
                cout << x/2 << ' ';
                count++;
            }
        }
    }
    for(auto xd: f3){
        auto imax = m[xd];
        for(ll i=0; i<imax; i++){
            cout << xd << ' ';
            if(x%2 == 0 && count< mx2){
                cout << x/2 << ' ';
                count++;
            }
            
        }
    }
    if(x%2 == 0 && count< mx2){
        cout << x/2 << ' ';
        count++;
    }
    cout << endl;
    return;
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    ll t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}