#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
using lli = long long int;
using vi = vector<int>;
using vlli = vector<lli>;
using vvi = vector<vi>;
using vvlli = vector<vlli>;
#define forn(i, a, b) for(int i = a; i < b; i++)
#define rof(i, a, b) for(int i = a; i >= b; i--)
#define nl '\n'
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

vector<bool> isprime(1e6, true);
vlli primes;

void primos(){
    isprime[1] = false;
    forn(i, 2, 1e6){
        if(isprime[i]){
            primes.push_back(i);
            lli xd = 2*i;
            while(xd<1e6){
                isprime[xd] = false;
                xd+=i;
            }
        }
    }
}

bool isperiod(string s, lli p){
    lli sz = s.length();
    if(sz%p != 0) return false;

    forn(i, 0, p-1){
        for(lli j = p+i; j<sz; j+=p){
            if(s[j] != s[j-p]) return false;
        }
    }
    return true;
}

lli respuesta(string s){
    lli sz = primes.size();
    lli len = s.length();
    forn(i, 0, sz){
        if(primes[i]>sz/2) return len;
        if(isperiod(s, primes[i])){
            string r = "";
            forn(i, 0, primes[i]) r+=s[i];
            return respuesta(r);
        }
    }
    return len;
}

void solve(){
    string s;
    lli res;
    while(true){
        cin >> s;
        res = respuesta(s);
        //cout << res << nl;
        if(s == ".") break;
        lli sz = s.size();
        cout << sz/res << nl;
    }
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    primos();
    int t=1;
    while(t--) solve();
    return 0;
}