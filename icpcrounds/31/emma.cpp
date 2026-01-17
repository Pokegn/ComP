#include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    lli binexp(lli a, lli b, lli m) {
    a %= m;
    lli res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
} //llamas fexp(x, m-2, m)


    void solve(){
        lli n,m,MOD;
        cin>>n>>m>>MOD;
        vector<lli> pot (n+1,1);
       
        pot[1]=binexp(m, MOD-2, MOD);
   //     deb(pot[1]);
        for(lli i=2; i<=n; ++i){
            pot[i]=pot[i-1]*pot[1];
            pot[i]%=MOD;
        }
        lli S=0;
        for(lli i=1; i<=n; ++i){
            lli aux=pot[i/2];
            aux*=(n-i+1);
            aux%=MOD;
    //        deb(aux);
            S+=aux;
            S%=MOD;
        }

        vector<lli> pref (n+1,1);
        for(lli i=1; i<=n; ++i) {
            pref[i]=pref[i-1]+pot[i];
            pref[i]%=MOD;
        }
      //  deb(S);
        lli ans=0;
        for(lli i=1; i<=n; ++i){
    //        deb(pref[i/2]);
            lli aux=S-pref[i/2];
            aux+=MOD;
            aux%=MOD;
            if(i%2==0){
                aux++;
                aux%=MOD;
            }
            aux+=((i+1)/2);
       //     deb(aux);
            aux%=MOD;
            aux*=pot[i/2];
         //   deb(aux);
            aux%=MOD;
            aux*=(n-i+1);
           // deb(aux);
            aux%=MOD;
            ans+=aux;
            ans%=MOD;
           // deb(aux);
        }
        cout<<ans<<endl;


    }

    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int t=1;
        cin>>t;
        while(t--){
            solve();
        }
    }