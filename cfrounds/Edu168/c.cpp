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
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    lli n; cin >> n;
    string s; cin >> s;
    lli xd = 0;
    forn(i, 0, n){
        if(s[i] == '_'){
            if(xd>0){
                s[i] = ')';
                xd--;
            } 
            else{
                s[i] = '(';
                xd++;
            } 
        }
        else{
            if(s[i] == ')') xd--;
            if(s[i]== '(') xd++;
        }
    }

    //cout << s << nl;
    stack<lli> cerrar;
    lli u;
    lli ans = 0;
    forn(i, 0, n){
        if(s[i] == '('){
            cerrar.push(i);
        }
        if(s[i] == ')'){
            //if(cerrar.empty() == true) cout <<"xd";
            u = cerrar.top();
            cerrar.pop();
            ans+=i-u;
        }
    }

    cout << ans << nl;
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}