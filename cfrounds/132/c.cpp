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

void solve(){
    string s; cin >> s;
    lli n = s.length();
    lli left = 0;
    lli right = 0;
    vlli qs;
    forn(i, 0, n){
        if(s[i] == '(') left++;
        if(s[i] == ')') right++;
        if(s[i] == '?') qs.push_back(i);
    }
    lli leftq = n/2 - left;
    lli rightq = n/2 - right;
    if(left+right == n || (right == n-right || left == n-left)){
        cout << "YES" << nl;
        return;
    }
    lli j = 0;
    string r = "";
    forn(i, 0, n){
        if(s[i] != '?') r+=s[i];
        else{
            if(j<leftq-1) r+='(';
            if(j == leftq-1) r+=')';
            if(j == leftq) r+='(';
            if(j > leftq) r+=')';
            j++;
        }
    }

    lli balance = 0;
    forn(i, 0, n){
        if(r[i] == '(') balance++;
        else balance--;
        if(balance < 0){
            cout << "YES" << nl;
            return;
        }
    }
    cout << "NO" << nl;
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}