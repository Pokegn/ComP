#include <bits/stdc++.h>
#define ll long long
#define MOD 998244353
using namespace std;

void solve();

vector<ll> pot3(3001), pot2(3001);

long long fexp(long long a, long long b, long long m = MOD) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

ll rang(ll a, ll b){
    if(b-a+1<0) return 0;
    return b-a+1;
}


int main(){
    int tt = 1;
    //cin >> tt;  

    pot2[0] = 1;
    pot3[0] = 1;
    for(int i=1; i<3001; i++){
        pot2[i] = pot2[i-1]*2;
        pot2[i]%=MOD;
        pot3[i] = pot3[i-1]*3;
        pot3[i]%=MOD;
    }

    while(tt--)
        solve();
    
    return 0;
}

void solve(){
    int n; cin >> n;
    ll M1, M2, M3, m1, m2, m3;
    ll ans = 0;
    vector<ll> a(n); for(int i=0; i<n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    m1 = 0;
    ll add;
     for(int i=1; i<n-1; i++){
         for(int j=i+1; j<n; j++){ 
            m2 = i;
            m3 = j;
            ll maxM3, maxM2, maxM1;
            ll derrang;
            derrang = a[m2]+a[m1]-1;
            maxM3 = upper_bound(a.begin(), a.end(), derrang)-a.begin()-1;
            if(a[n-1] <= derrang) maxM3 = n-1;

            derrang = a[m1]+a[m3]-1;
            maxM2 = upper_bound(a.begin(), a.end(), derrang)-a.begin()-1;
            if(a[n-1] <=derrang) maxM2 = n-1;  

            derrang = a[m2]+a[m3]-1;
            maxM1 = upper_bound(a.begin(), a.end(), derrang)-a.begin()-1;           //i M1 y j m2
            if(a[n-1] <= derrang) maxM1 = n-1;

            if(maxM3 < m3 || maxM2 < m2 || maxM1 < m1 || maxM1 < n-1){
                continue;
            }

            //de 0 a i estan fijos
            //de i+1 a j-1 pueden estar en los primeros dos
            //j esta fijo
            //de j+1 a maxM3 pueden estar en cualquiera
            //de maxM3+1 a maxM2 pueden estar en 1 o 2
            //de maxM2+1 a maxM1 pueden estar en 1

            add = 1;
            add*=pot2[rang(i+1, j-1)];
            add%=MOD;
            add*=pot3[rang(j+1, maxM3)];
            add%=MOD;
            add*=pot2[rang(maxM3+1, maxM2)];
            add%=MOD;

            ans+=add;
            ans%=MOD;
            // if(add!=0){
            //     cout << 0 << ' ' << maxM1 << ' ' << i << ' ' << maxM2 << ' ' << j << ' ' << maxM3 << ' ' << add << endl;
            // }
        }
    }
    cout << ans << '\n';
}

