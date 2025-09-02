#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
//template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
//using lli = long long int;
//using vi = vector<int>;
//using vlli = vector<lli>;
//using vvi = vector<vi>;
//using vvlli = vector<vlli>;
#define forn(i, a, b) for(int i = a; i < b; i++)
#define rof(i, a, b) for(int i = a; i >= b; i--)
#define nl '\n'
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    int n,q; cin >> n >> q;
    map<string, int> xd;
    string s;
    vector<string> che(q);
    vector<string> todo(n);
    forn(i, 0, n) cin >> todo[i];
    forn(i, 0, q){
        cin >> s;
        che[i] = s;
        xd[s] = 0;
    }

    forn(i, 0, n){
        s = todo[i];
        int len = s.length();
        string temp = "";
        forn(j, 0, len){
            temp+=s[j];
            if(xd.find(temp) != xd.end()) xd[temp]++;
        }
    }

    forn(i, 0, q){
        cout << xd[che[i]] << nl;
    }
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1;
    while(t--) solve();
    return 0;
}