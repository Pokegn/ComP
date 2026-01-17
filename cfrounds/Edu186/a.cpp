#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
using ll = long long int;
using vi = vector<int>;
using vlli = vector<ll>;
using vvi = vector<vi>;
using vvlli = vector<vlli>;
#define forn(i, a, b) for(ll i = a; i < b; i++)
#define rof(i, a, b) for(ll i = a; i >= b; i--)
#define nl '\n'
#define pb push_back
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    int a6 = 0;
    int a5 = 0;
    bool is5 = 0;
    bool is6 = 0;
    for(int i=0; i<n-3; i++){
        if(s[i] == '2' && s[i+1] == '0' && s[i+2] == '2' && s[i+3] == '5'){
            is5 = true;
        }
        if(s[i] == '2' && s[i+1] == '0' && s[i+2] == '2' && s[i+3] == '6'){
            is6 = true;
        }
    }
    if(is5 == true && is6 == false){
        cout << "1" << endl;
        return;
    }
    else{
        cout << "0" << endl;
        return;
    }
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}