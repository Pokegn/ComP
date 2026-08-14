#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
#define rep(i, a, b) for(int i=a; i<(b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define endl '\n'
#define pb push_back
#define fi first
#define se second
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    int n; cin >> n; int m; cin >> m;
    vector<int> a(m); rep(i,0,m) cin >> a[i];
    vector<set<int>> b(1001);
    rep(i, 0, m) b[a[i]].insert(i+1); //cuantos, quien
    vector<int> ans;
    
    int prime = -1;
    rep(i, 1, 1001) if(b[i].size() > 0) prime = i;
    prime = *b[prime].begin(); //priorizo quitar de este    

    int ins = 0;
    while(ins < n-1){
        int quitox = -1;
        rep(i, 1, 1001) if(b[i].size() > 0) quitox = i;
        if(quitox == -1) break;
        int x;
        if(b[quitox].find(prime) != b[quitox].end()){
            x = prime;
            b[quitox].erase(x);
            // b[quito-1].insert(x);
        }
        else{
            x = *b[quitox].begin();
            b[quitox].erase(x);
        }
        if(ans.size() == 0 || ans.back() != x){
            ans.push_back(x);
            b[quitox-1].insert(x);
            ins++;
            continue;
        }

        int temp = quitox;
        int quitoy = -1;
        rep(i, 1, 1001) if(b[i].size() > 0) quitoy = i;
        if(quitoy == -1) break;
        int y;
        if(b[quitoy].find(prime) != b[quitoy].end()){
            y = prime;
            b[quitoy].erase(y);
        }
        else{
            y = *b[quitoy].begin();
            b[quitoy].erase(y);
        }
        b[quitoy-1].insert(y);
        ans.push_back(y);
        b[temp].insert(x);
        ins++;
    }
    if(ins < n-1) cout << -1 << endl;
    else{
        set<int> libres;
        rep(i, 1, 1001){
            for(auto x: b[i]) if(x!=prime && x!=ans.back()) libres.insert(x);
        }

        if(libres.size() == 0){
            cout << -1 << endl;
            return;
        }
        else{
            int x = *libres.begin();
            ans.push_back(x);
        }        

        rep(i, 0, n) cout << ans[i] << ' ';
        cout << endl;
    }

}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
   // cin >> t;
    while(t--) solve();
    return 0;
}