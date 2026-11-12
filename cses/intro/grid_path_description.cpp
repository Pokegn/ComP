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
    string s; cin >> s;
    vector<vector<int>> caminos;
    caminos.push_back({0});

    rep(iii, 0, 26){
        vector<vector<int>> newcaminos;
        for(auto cam: caminos){
            vector<bool> vis(49, false);
            for(auto v: cam) vis[v] = true;

            int b = cam.back();
            if(b%7 > 0 && !vis[b-1]){
                cam.push_back(b-1);
                newcaminos.push_back(cam);
                cam.pop_back();
            }
            if(b%7 < 6 && !vis[b+1]){
                cam.push_back(b+1);
                newcaminos.push_back(cam);
                cam.pop_back();
            }
            if(b-7 >= 0 && !vis[b-7]){
                cam.push_back(b-7);
                newcaminos.push_back(cam);
                cam.pop_back();
            }
            if(b+7 < 49 && !vis[b+7]){
                cam.push_back(b+7);
                newcaminos.push_back(cam);
                cam.pop_back();
            }
        }
        swap(newcaminos, caminos);
    }    
    cout << caminos.size() << ' ';
    for(auto x: caminos.back()){
        cout << x << ' ';
    }
    cout << endl;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    // cin >> t;
    while(t--) solve();
    return 0;
}