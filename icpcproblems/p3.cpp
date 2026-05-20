#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
#define rep(i, a, b) for(long long i=a; i<(b); ++i)
typedef long long ll;

ll fexp(ll a, ll b, ll m) { //calcular a^b mod m
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void solve(){
    ll B = 6; //B grande
    ll p = 6962933; //el primo
    ll g = 19; //el valor de la tentativa raiz primitiva
    ll b = -1; //donde guardaremos el valor encontrado de b chica
    rep(i, 1, p){
        if(fexp(g, i, p) == B){
            cout << "b es igual a " << i << endl; //la respuesta es 6026568
            b = i;
        }
    }
    //cout << fexp(g, b, p) << endl;
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}