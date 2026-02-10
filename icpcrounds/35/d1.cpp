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
    // cin >> tt;
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
    ans+=fexp(4, n-1, MOD);
    if(n>=2){
        ans+=2*fexp(4, n-2, MOD);
        ans%=MOD;
    }
    if(n>=3){
        ans+=2*fexp(4, n-3, MOD);
        ans%=MOD;
    }
    //si 1 si 0
    //no hay 2 8s, ni 2 9s
    //si 8 si 9
    //empieza con 8 y acaba con 0091, 0901
                                                                //ll ii = 1;
                                                                // while(n>=ii){
                                                                //     if(ii>=4){
                                                                //         ans+=2*fexp(4, n-ii, MOD);
                                                                //         ans%=MOD; 
                                                                //     }
                                                                //     if(ii>=5){
                                                                //         ans+=3*fexp(4, n-ii, MOD);
                                                                //         ans%=MOD; 
                                                                //     }
                                                                //     if(ii>=3){
                                                                //         ans+=fexp(4, n-ii, MOD);
                                                                //         ans%=MOD; 
                                                                //     }
                                                                //     ii++;
                                                                // }
    ll ii = 4;
    while(n>=ii){
        ans+=fexp(4, n-ii, MOD);
        ans%=MOD; 
        ii++;
    }
    ii = 4;
    while(n>=ii){
        ans+=fexp(4, n-ii, MOD);
        ans%=MOD; 
        ii++;
    }
    
    if(n>=4){ //9081 y 9801
        ans+=2*fexp(4, n-4, MOD);
        ans%=MOD; 
    }

    //si 8 no 9
    ii = 3;
    while(n>=ii){
        ans+=fexp(4, n-ii, MOD);
        ans%=MOD; 
        ii++;
    }

    //no 8 si 9
    //901 namas
    if(n>=3){
        ans+=fexp(4, n-3, MOD);
        ans%=MOD;
    }


    ans%=MOD;
    //no 1, 
    //si 9
    //no 49
    ans+=fexp(4, n-1, MOD); //9xxxx. i nums a la izq de 9
    if(n>1) for(ll i=1; i<=n-1; i++){
        ll sumando = 2*fexp(3, i-1, MOD);
        sumando%=MOD;
        sumando*=fexp(4, n-i-1, MOD);
        sumando%=MOD;
        ans+=sumando;
        ans%=MOD;
    }

    //si 49
    //no 0
    if(n>=2){
        ans+=fexp(4, n-2, MOD);
        ans%=MOD;
    }

    if(n>=3){
        ans+=3*fexp(4, n-3, MOD);
        ans%=MOD;
    }

    if(n>=4){
        ans+=2*fexp(4, n-4, MOD);
        ans%=MOD;
    }

    if(n>=5){
        ans+=fexp(4, n-5, MOD);
        ans%=MOD;
    }

    //si 49 si 0
    // if(n>=4){
    //     ans+=fexp(4,n-4, MOD);
    //     ans%=MOD;
    // }

    //los 4 de la forma 6000049
    if(n>=4){
        ans+=fexp(4,n-4, MOD);
        ans%=MOD;
    }

    if(n>=5){
        ans+=fexp(4,n-5, MOD);
        ans%=MOD;
    }

    if(n>=6){
        ans+=fexp(4,n-6, MOD);
        ans%=MOD;
    }

    if(n>=7){
        ans+=fexp(4,n-7, MOD);
        ans%=MOD;
    }

    //con 2 6's
    if(n>=5){
        ans+=fexp(4,n-5, MOD);
        ans%=MOD;
    }

    if(n>=6){
        ans+=fexp(4,n-6, MOD);
        ans%=MOD;
    }

    if(n>=7){
        ans+=fexp(4,n-7, MOD);
        ans%=MOD;
    }

    //con 3 6's
    if(n>=6){
        ans+=fexp(4,n-6, MOD);
        ans%=MOD;
    }

    if(n>=7){
        ans+=fexp(4,n-7, MOD);
        ans%=MOD;
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