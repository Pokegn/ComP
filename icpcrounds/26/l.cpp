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
    int n,q; cin >> n >> q;
    vlli a(n+1, 3);
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    vlli potpar(n+1, 0);
    vlli impar(n+1, 0);
    vlli unos(n+1, 0);

    for(int i=1; i<=n; i++){
        potpar[i] = potpar[i-1];
        impar[i] = impar[i-1];
        unos[i] = unos[i-1];
        if(a[i]%2 == 1 && a[i]!=1) impar[i]+=a[i];
        if(a[i] == 1) unos[i]+=a[i];
        else{
            ll temp = a[i];
            while(a[i]%2 == 0) a[i]/=2;
            if(a[i] == 1) potpar[i]+=temp;
        }
    }

    int l, r;
    ll p1 = 0, p2 = 0;
    for(int i=0; i<q; i++){
        p1 = 0, p2 = 0;
        cin >> l >> r;
        p1 += potpar[r] - potpar[l-1];
        p2 += impar[r] - impar[l-1];
        if((unos[r]-unos[l-1])%2 == 1) p1++;
        //cout << p1 << ' ' << p2 << endl;
        if(p1 > p2) cout << "A" << endl;
        else{
            if(p2 > p1) cout  << "B" << endl;
            else{
                cout << "E" << endl;
            }
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    ll t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}