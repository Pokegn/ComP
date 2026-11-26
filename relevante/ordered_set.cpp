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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve(){
    int n; cin >> n;
    ordered_multiset<ll> opened_ends;
    ordered_multiset<ll> closed_starts;

    vector<pair<ll, ll>> a;
    vector<pair<ll,ll>> ranges(n+1);
    vector<ll> contains(n+1), is_contained(n+1);
    rep(i,1,n+1){
        int x,y; cin >> x >> y;
        a.push_back({x, i});
        a.push_back({y,-i});
        ranges[i] = {x,y};
    }

    sort(all(a));

    for(auto p: a){
        int idx;

        //calcular respuesta
        if(p.se > 0){ //open
            idx = p.se;
            //en cuantos esta es opened_ends
            auto it = opened_ends.lower_bound(a[idx].se);
            if(it == opened_ends.end()) is_contained[idx] = 0;
            else{
                is_contained[idx] = sz(opened_ends) - (int)(opened_ends.order_of_key(*it));
            }
        }
        else{ //end
            idx = -p.se;
            //cuantos tiene es closed_starts
            auto it = closed_starts.upper_bound(a[idx].fi);
            if(it == closed_starts.end()) contains[idx] = sz(closed_starts);
            else{
                contains[idx] = (int)(closed_starts.order_of_key(*it));
            }
        }


        //actualizar
        if(p.se > 0){ //open
            opened_ends.insert(p.fi);
        }
        else{ //end
            closed_starts.insert(ranges[idx].fi);
            opened_ends.erase(opened_ends.find_by_order(opened_ends.order_of_key(p.fi)));
        }
    }

    rep(i, 1, n+1){
        cout << contains[i] << ' ';
    }
    cout << endl;
    rep(i, 1, n+1){
        cout << is_contained[i] << ' ';
    }
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}