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

ll anscon1(ll n){
    string s = to_string(n);
    ll ret = 0;

    ll potencia = s.size()-1;
    ret += (ll)(s[0]-'0')*(1); //dos o menos 
    ret += 9*(potencia); // si hago el primer digito 0 tengo una opcion mas


    return ret;
    // s[0] = 0;
    // ll nuevo_n = stoll(s);
    // ret += anscon2(nuevo_n);
}

ll anscon2(ll n){
    string s = to_string(n);
    ll ret = 0;

    ll potencia = s.size()-1;
    ret += (ll)(s[0]-'0')*(9*(potencia)+1); //dos o menos 
    ret += 81*(potencia*(potencia-1))/2; // si hago el primer digito 0 tengo una opcion mas

    s[0] = '0';
    ll nuevo_n = stoll(s);
    ret += anscon1(nuevo_n);
    return ret;
}

ll anscon3(ll n){
    string s = to_string(n);
    ll ret = 0;

    ll potencia = s.size()-1;
    ret += (ll)(s[0]-'0')*(81*(potencia*(potencia-1))/2 + 9*(potencia)+1); //dos o menos 
    ret += 729*(potencia*(potencia-1)*(potencia-2))/6; // si hago el primer digito 0 tengo una opcion mas

    s[0] = '0';
    ll nuevo_n = stoll(s);
    ret += anscon2(nuevo_n);
    return ret;
}

void solve(){
    ll l,r; cin >> l >> r;
    cout << anscon3(r)-anscon3(l-1) << endl;
    return;
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    ll t=1;
    cin >> t;
    while(t--) solve();
    return 0;
}