#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define endl '\n'
#define IOS iostream::sync_with_stdio(0); cin.tie(0);
#define MOD 998244353

void solve();

ll fexp(ll a, ll b, ll m){
    a%=m;
    ll res = 1;
    while(b>0){
        if(b&1)
            res = res*a%m;
        a = a*a%m;
        b>>=1;
    }
    return res;
}

int main(){
    IOS;
    int tt = 1;
    //cin >> tt;
    while(tt--)
        solve();
    return 0;
}

void solve(){
    ll n; cin >> n;
    ll ans = 0;
    ans+=3*fexp(4, n-1, MOD); //no 1 no 9
    ans%=MOD;


    //si 1
    //si 1 no 0
    ans+=fexp(4, n-1, MOD); //1
    if(n>=2){ //91
        ans+=fexp(4, n-2, MOD);
        ans%=MOD;
    }
    if(n>=3){ //901, 981
        ans+=2*fexp(4, n-3, MOD);
        ans%=MOD;
    }
    if(n>=4){ //9081 y 9801
        ans+=2*fexp(4, n-4, MOD);
        ans%=MOD; 
    }
    ll ii = 2;
    while(n>=ii){ //8000000000001
        ans+=fexp(4, n-ii, MOD);
        ans%=MOD; 
        ii++;
    }
    


    ans%=MOD;
    //no 1, si 9
    //no 49
    ans+=fexp(4, n-1, MOD); //solo 9
    if(n>=2) for(ll i=1; i<=n-1; i++){ //60696069
        ll sumando = 2*fexp(3, i-1, MOD);
        sumando%=MOD;
        sumando*=fexp(4, n-i-1, MOD);
        sumando%=MOD;
        ans+=sumando;
        ans%=MOD;
    }

    //si 49
    if(n>=2){
        ans+=fexp(4, n-2, MOD);
        ans%=MOD;
    }

    if(n>=3){
        ans+=2*fexp(4, n-3, MOD);
        ans%=MOD;
    }

    if(n>=4){
        ans+=3*fexp(4, n-4, MOD);
        ans%=MOD;
    }

    if(n>=5){
        ans+=4*fexp(4, n-5, MOD);
        ans%=MOD;
    }
    if(n>=6){
        ans+=3*fexp(4,n-6, MOD);
        ans%=MOD;
    }

    if(n>=7){
        ans+=3*fexp(4,n-7, MOD);
        ans%=MOD;
    }


    ii = 3;
    while(n>=ii){ //8000000000001
        ans+=fexp(4, n-ii, MOD);
        ans%=MOD; 
        ii++;
    }

    //ahora con 469 y 0
    //no hay  nada xd

    //ya tengo todos los casos de si 49 


    cout << ans << endl;
    return;

    // ans+=fexp(4, n-3, MOD);
    // ans+=fexp(4, n-2, MOD);
    // ans+=fexp(4, n-2, MOD);
    

}