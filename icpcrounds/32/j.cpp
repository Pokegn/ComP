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

ll calcula1(int i, int j, int x, int y, int n){//i es el inferior, j el superior, y el rango actual es [y,x]
    ll ret =0;
    ll tamano = x-y+1;
    set<int> ocupados;
    if(y<= i && i<=x) ocupados.insert(i);
    if(y<=j && j<=x) ocupados.insert(j);
    tamano-=ocupados.size();
    if(tamano<=0) return 0;

    if(i<j){
    if(y<i && x>i && j>x){ //caso 1
        ret = fexp(2, rang(y, i-1), MOD); ret%=MOD;
        ret *= fexp(3, rang(i+1,x), MOD); ret%=MOD;
        ret *= fexp(2, rang(x+1, j-1), MOD); ret%=MOD;
        return ret-1;
    }
    if(y<i && x<i){ //caso 2
        ret = fexp(2, rang(y, x), MOD); ret%=MOD;
        ret *= fexp(2, rang(i+1, j-1), MOD); ret%=MOD;
        return ret-1;
    }
    if(y>j && x>j){ //caso 3
        ret = fexp(2, rang(y, x), MOD); ret%=MOD;
        ret *= fexp(2, rang(i+1, j-1), MOD); ret%=MOD;
        return ret-1;
    }
    if(y<j && x>j && y>i){ //caso 4
        ret = fexp(2, rang(i+1, y-1), MOD); ret%=MOD;
        ret *= fexp(3, rang(y, j-1), MOD); ret%=MOD;
        ret *= fexp(2, rang(j+1, x), MOD); ret%=MOD;
        return ret-1;
    }
    if(i<y && j>x){ //caso 5
        ret = fexp(2, rang(i+1,y-1)); ret%=MOD;
        ret *= fexp(3, rang(y,x)); ret%=MOD;
        ret *= fexp(2, rang(x+1,j-1)); ret%=MOD;
        return ret-1;
    }
    if(y<i && j<x){ //caso 6
        ret = fexp(2, rang(y,i-1), MOD);
        ret *= fexp(3, rang(i+1, j-1), MOD);
        ret *= fexp(2, rang(j+1, x), MOD);
        return ret-1;
    }
    }   
    else{
    swap(i,j);
    if(y<i && x>i && j>x){ //caso 1
        if(j-x<=1) return 0;
        ret = fexp(2, rang(y, i-1), MOD); ret%=MOD;
        return ret-1;
    }
    if(y<i && x<i){ //caso 2
        if(rang(i+1, j-1)>0) return 0;
        ret = fexp(2, rang(y, x), MOD); ret%=MOD;
        return ret-1;
    }
    if(y>j && x>j){ //caso 3
        if(rang(i+1, j-1)>0) return 0;
        ret = fexp(2, rang(y, x), MOD); ret%=MOD;
        return ret-1;
    }
    if(y<j && x>j && y>i){ //caso 4
        if(rang(i+1, y-1)>0) return 0;
        ret = fexp(2, rang(j+1, x), MOD); ret%=MOD;
        return ret-1;
    }
    if(i<y && j>x){ //caso 5
        if(rang(i+1, y-1)>0 || rang(x+1, j-1)>0) return 0;
        return 1;
    }
    if(y<i && j<x){ //caso 6
        ret = fexp(2, rang(y,i-1), MOD);
        ret *= fexp(2, rang(j+1, x), MOD);
        return ret-1;
    }
    }  
    return 0;
}

void solve(){
    int n; cin >> n;
    ll M1, M2, m1, m2;
    ll ans = 0;
    vector<ll> a(n); for(int i=0; i<n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    ll antesans;
     for(int i=1; i<n; i++){
         for(int j=0; j<n-1; j++){ 
            
            //i M1 y j m2
            //if(i==j) continue; //
            antesans = ans;
            //cout << i << ' ' << j << ' ';
            M1 = a[n-1];
            m1 = a[i];
            m2 = a[0];
            M2 = a[j];

            ll izqrang = max(M1-m2, M2-m1)+1; //primer conjunto es de l1 a a[n-1] y el otro es de a[0] a r2
            ll derrang = m2+m1-1;
           // cout << ans << ' ' << izqrang << ' ' << derrang << '\n';
    
            ll maxM3 = upper_bound(a.begin(), a.end(), derrang)-a.begin()-1;
            ll minm3 = lower_bound(a.begin(), a.end(), izqrang) -a.begin();
            while(maxM3==0 || maxM3==i || maxM3==j || maxM3==n-1) maxM3--;
            while(minm3==0 || minm3==i || minm3==j || minm3==n-1) minm3++;
            ll calc = calcula1(i,j,maxM3, minm3, n);
            if(i!=j){
                ans+=calc; ans%=MOD;
                // if(calc>0){
                //     cout << calc << ' ' << "rango1" << ' ' << i << ' ' << n-1 << " rango2 " << ' ' << 0 << ' ' << j << " rango3 "<< minm3 << ' ' << maxM3 <<endl;
                //     cout << endl;
                // }
            }
            //ans-=fexp(2, r2-l1+1, MOD);
            ans = (ans+MOD)%MOD;
            //cout << ans << '\n';
            //cout << ans-antesans << ' ';
            antesans = ans;
            
            if(j-i >= 0 && i!=n-1 && j!=0){
                swap(m1, m2);
                izqrang = max(M1-m2, M2-m1)+1; //primer conjunto es de l1 a a[n-1] y el otro es de a[0] a r2
                derrang = m2+m1-1;
                maxM3 = upper_bound(a.begin(), a.end(), derrang)-a.begin()-1;
                minm3 = lower_bound(a.begin(), a.end(), izqrang) -a.begin();
                while(maxM3==0 || maxM3==i || maxM3==j || maxM3==n-1) maxM3--;
                while(minm3==0 || minm3==i || minm3==j || minm3==n-1) minm3++;

                calc = calcula1(i,j,maxM3, minm3, n);
                ans+=calc*fexp(2, MOD-2, MOD); ans%=MOD;
                // if(calc>0 || (i == j && i == 1)){
                //     cout << calc << ' ' << "rango1" << ' ' << 0 << ' ' << n-1 << " rango2 " << ' ' << i << ' ' << j << " rango3 "<< minm3 << ' ' << maxM3 <<endl;
                //     cout << endl;
                // }

                //ans-=fexp(2, j-i+1, MOD)*fexp(2, MOD-2, MOD); ans%=MOD;
            }
            //cout << ans << '\n';
            //cout << ans-antesans << endl;
        }
    }
    //cout << calcula1(1,1,)
    cout << ans << '\n';
}