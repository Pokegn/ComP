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

lli digitoshastan(lli n){
    lli resta = 0;
    lli ans = 0;
    while(resta < n){
        ans += n-resta;
        resta = resta *10+9;
    }
    return ans;
}

void solve(){
    lli n,x; cin >> n >> x;
    lli resta = 0;
    lli unoaxmenos1 =0 ;
    while(resta < x-1){
        unoaxmenos1+= x-1-resta;
        resta = resta*10+9;
    }

    n+=unoaxmenos1;
    lli unohastak = n;
    lli digitos = 1;
    lli temp = 10;

    while(true){
        if(digitoshastan(temp) > unohastak){
            break;            
        }
        digitos++;
        temp*=10;
    }

    resta = 0;
    lli restatotal = 0;
    forn(i, 0, digitos){
        restatotal += resta;
        resta = resta*10+9;
    }

    //cout << digitos << nl;

    if((unohastak+restatotal)%digitos == 0){
        cout << (unohastak+restatotal)/digitos - x + 1<< nl;
    }
    else{
        cout << -1 << nl;
    }

}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    lli t; cin >> t;
    while(t--)
    solve();
    return 0;
}