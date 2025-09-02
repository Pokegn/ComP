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
    lli b1, q, l, m; cin >> b1 >> q >> l >> m;
    vlli a(m);
    forn(i, 0, m) cin >> a[i];
    if(abs(b1) > l){
        cout << 0 << nl;
        return;
    }
    if(b1 == 0){
        forn(i, 0, m){
            if(a[i] == 0){
                cout << 0 << nl;
                return;
            }
        }
        cout << "inf" << nl;
        return;
    }
    if(q == 0){
        bool in = true;
        forn(i, 0, m){
            if(a[i] == 0){
                in = false;
            }
        }
        if(in == false){
            forn(i, 0, m){
                if(a[i] == b1){
                    cout << 0 << nl;
                    return;
                }
            }
            cout << 1 << nl;
            return;
        }
        else{
            cout << "inf" << nl;
            return;
        }

    }
    if(q == 1){
        if(abs(b1) <= l){
            for(auto x:a){
                if(x == b1){
                    cout << 0 << nl;
                    return;
                }
            }
            cout << "inf" << nl;
        }
        else{
            cout << 0 << nl;
        }
        return;
    }
    if(q == -1){
        lli xd1 = 1;
        lli xd2 = 1;
        if(abs(b1) <= l){
            for(auto x:a){
                if(x == b1){
                    xd1 = 0;
                }
                if(x == -b1){
                    xd2 = 0;
                }
            }
            if(xd1+xd2 > 0){
                cout << "inf" << nl;
            }
            else{
                cout << 0 << nl;
            }
        }
        else{
            cout << 0 << nl;
        }
        return;
    }

    vlli auniquesorted(0);
    sort(a.begin(), a.end());
    auniquesorted.push_back(a[0]);
    forn(i, 1, m){
        if(a[i] > a[i-1]) auniquesorted.push_back(a[i]);
    }
    a = auniquesorted;
    lli n = a.size();
    lli cunt = 0;
    forn(i, 0, n){
        if(a[i]%b1 != 0) continue;
        if(a[i] == 0) continue;
        if(abs(a[i]) > l) continue;
        a[i]/=b1;
        bool flag = false;

        while(abs(a[i]) > 1){
            if(a[i]%q != 0) flag = true;
            a[i]/=q;
        }
        if(flag) continue;
        if(a[i] == 1) cunt++;
    }
    lli maxi = 0;
    while(l>=abs(b1)){
        maxi++;
        l/=abs(q);
    }
    cout << maxi - cunt << nl;

}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    // cin >> t;
    while(t--) solve();
    return 0;
}