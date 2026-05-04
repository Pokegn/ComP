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
typedef long long ll;
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    int n,k,q; cin >> n >> k >> q;
    vector<pair<int, int>> ev;
    map<int, int> person;
    map<int, int> ileft;
    map<int, int> idx;
    int curr = 0;
    rep(i, 0, q){
        int p,l,r; cin >> p >> l >> r;
        ev.push_back({l, -1});
        ev.push_back({r, 1});
        person[l] = p;
        person[r] = p;
        ileft[r] = l;

        idx[l] = curr;
        curr++;

    }

    int sz = ev.size();
    sort(all(ev));

    vector<int> ans(q, 0);

    int ppl = n;
    rep(i, 0, sz){
        if(ev[i].second == -1){
            ppl--;
        }
        
        if(ev[i].second == 1){
            int r = ev[i].first;
            if(ppl == 0){
                ans[idx[ileft[r]]] = 1;
                //cout << i << ' ' << ileft[r] << ' ' << r << endl;
            }
            
            ppl++;
        }
    }


    int keys = k;
    rep(i, 0, sz){ //feasibility
        if(ev[i].second == -1){
            int l = ev[i].first;
            if(ans[idx[l]] == 1){
                keys--;
            }
            if(keys < 0){
                cout << "impossible" << endl;
                return;
            }
        }
        
        if(ev[i].second == 1){
            int r = ev[i].first;
            if(ans[idx[ileft[r]]] == 1){
                keys++;
            }
            
        }
        // cout <<keys;
        // cout << endl;
    }

    rep(i, 0, q){
        cout << ans[i];
    }
    cout << endl;
    return;

}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    //cin >> t;
    while(t--) solve();
    return 0;
}