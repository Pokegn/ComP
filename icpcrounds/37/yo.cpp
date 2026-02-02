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
    ll dp[701][10][701]; //dp[i][j][k]
    //tomo i digitos
    //pienso en agregar un digito j
    //cuento cuantas veces esta en la posicion k (creo que de derecha a izq)
    for(int i=1; i<=700; i++){
        for(int j=0; j<=9; j++){
            for(int k=0; k<=700; k++){
                for(int next = 9; next>=)
                dp[i][j][k]
            }
        }
    }

}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    ll t=1;
    cin >> t;
    while(t--) solve();
    return 0;
}