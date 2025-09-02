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

lli pos(lli x){
    if(x<0) return -x;
    return x;
}

void solve(){
    lli n; cin >> n;
    vlli a(n); forn(i, 0, n) cin >> a[i];
    
    vlli count(n+1, 0);
    vlli ans;
    lli amountelected = 0;
    forn(i,0, n) count[a[i]]++;
    vector<bool> elected(n+1, 0);
    vector<lli> lastseen(n+1, -1);
    lli cutoff = 0;

    priority_queue <lli, vector<lli>, greater<lli>> minh;
    priority_queue <lli> maxh;
    lli top; 

    forn(i, 0, n){
        lastseen[a[i]] = i;
        if(elected[a[i]]) continue;
        minh.push(a[i]);
        maxh.push(a[i]);
        count[a[i]]--;
        if(count[a[i]] == 0){
            while(!elected[a[i]]){
                if(ans.size()%2 != 0){
                    top = minh.top();
                    minh.pop();
                    if(elected[top]) continue;
                    if(lastseen[top] < cutoff) continue;
                    ans.push_back(top);
                    elected[top] = true;
                }
                else{
                    top = maxh.top();
                    maxh.pop();
                    if(elected[top]) continue;
                    if(lastseen[top] < cutoff) continue;
                    ans.push_back(top);
                    elected[top] = true;
                }
            }
            while(a[cutoff] != a[i]) cutoff++;

            // while(!minh.empty()){
            //     minh.pop();
            // }
            // while(!maxh.empty()){
            //     maxh.pop();
            // }
        }
    }

    lli sz = ans.size();
    cout << sz << nl;
    forn(i, 0, sz) cout<< ans[i] << ' ';
    cout << nl;
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}