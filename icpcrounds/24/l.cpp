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
    int n; cin >> n;
    vlli k(n);
    for(int i=0; i<n; i++) cin >> k[i];
    vvlli p(n), w(n);
    vvlli order(n);
    for(int i=0; i<n; i++){
        p[i].resize(k[i], 0);
        w[i].resize(k[i], 0);
        order[i].resize(k[i], 0);
    }
    vector<ll> suma(n, 0);
    for(int i=1; i<n; i++){
        suma[i] = suma[i-1]+k[i-1];
    }
    vlli allp, allw;
    for(int i=0; i<n; i++){
        for(int j=0; j<k[i]; j++){
            cin >> p[i][j];
            allp.push_back(p[i][j]);
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<k[i]; j++){
            cin >> w[i][j];
            allw.push_back(w[i][j]);
        }
    }

    for(int i=0; i<n; i++){
        vlli a(k[i]);
        for(int j=0; j<k[i]; j++) a[j] = j;
        for(int j=0; j<k[i]; j++){
            for(int r=1; r<k[i]; r++){
                if(p[i][a[r-1]]*w[i][a[r]] > p[i][a[r]]*w[i][a[r-1]]) swap(a[r], a[r-1]);
            }
        }
        for(int j=0; j<k[i]; j++) order[i][j] = a[j]+suma[i];
    }

    vector<ll> bigw(n, 0);
    vector<ll> bigp(n, 0);
    for(int i=0; i<n; i++){
        for(int j=0; j<k[i]; j++){
            bigw[i]+=w[i][j];
            bigp[i]+=p[i][j];
        }
    }

    vlli bigorder(n);
    for(int i=0; i<n; i++) bigorder[i] = i;
    for(int i=0; i<n; i++){
        for(int j=1; j<n; j++){
            if(bigp[bigorder[j-1]]*bigw[bigorder[j]] > bigp[bigorder[j]]*bigw[bigorder[j-1]]) swap(bigorder[j], bigorder[j-1]);
        }
    }

    ll ans = 0;
    ll currt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<k[bigorder[i]]; j++){
            currt += allp[order[bigorder[i]][j]];
            ans += allw[order[bigorder[i]][j]]*currt;
            //cout << allp[order[bigorder[i]][j]] << ' ' << allw[order[bigorder[i]][j]] << ' ' <<endl;
        }
    }
    cout << ans << endl;

    for(int i=0; i<n; i++){
        for(int j=0; j<k[bigorder[i]]; j++){
            cout << order[bigorder[i]][j]+1 << ' ';
        }
    }
    cout << endl;
    


}

int main(){
    freopen("student.in", "r", stdin);
    freopen("student.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(false);
    ll t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}