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

const int inf = 1e9;
struct Node{
    Node *l = 0, *r = 0;
    int lo, hi, mset = inf, madd = 0, val = -inf;
    Node(int lo, int hi): lo(lo), hi(hi){} //Large interval of -inf
    Node(vi &v, int lo, int hi) : lo(lo), hi(hi){
        if(lo+1 < hi){
            int mid = lo + (hi-lo)/2;
            l = new Node(v, lo, mid); r = new Node(v, mid, hi);
            val = max(l -> val, r -> val);
        }
        else val = v[lo];
    }
    int query(int L, int R){
        if(R <= lo || hi <= L) return -inf;
        if(L <= lo && hi <= R) return val;
        push();
        return max(l -> query(L, R), r->query(L, R));
    }
    void set(int L, int R, int x){
        if(R <= lo || hi <= L) return;
        if(L <= lo && hi <= R) mset = val = x, madd = 0;
        else{
            push(), l->set(L, R, x), r->set(L, R, x);
            val = max(l->val, r->val);
        }
    }
    void add(int L, int R, int x){
        if(R<=lo || hi <= L) return;
        if(L <= lo && hi <= R){
            if(mset != inf) mset += x;
            else madd += x;
            val += x;
        }
        else{
            push(), l -> add(L,R,x), r->add(L,R,x);
            val = max(l->val, r->val);
        }
    }
    void push(){
        if(!l){
            int mid = lo + (hi-lo)/2;
            l = new Node(lo, mid); r = new Node(mid, hi);
        }
        if(mset!=inf)
            l->set(lo, hi, mset), r->set(lo, hi, mset), mset = inf;
        else if(madd)
        l->add(lo,hi,madd), r->add(lo, hi, madd), madd = 0;
    }
};

void solve(){
    
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}