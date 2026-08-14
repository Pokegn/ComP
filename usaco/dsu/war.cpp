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

const int MAXN = 100002;
int parent[MAXN];
int enemy[MAXN]; //oh the misery
int sizee[MAXN];

int find_set(int u){
    if(parent[u] == u) return u;
    return parent[u] = find_set(parent[u]);
}

void make_set(int u){
    parent[u] = u;
    enemy[u] = -1;
    sizee[u] = 1;
}

void union_sets2(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if(a!=b){
        if(sizee[a] < sizee[b]) swap(a, b);
        sizee[a] += sizee[b];
        parent[b] = a;
    }
}

void union_sets(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if(a!=b){
        if(sizee[a] < sizee[b]) swap(a, b);
        sizee[a] += sizee[b];
        parent[b] = a;
    }

    if(enemy[b] != -1){
        if(enemy[a] == -1){
            enemy[a] = find_set(enemy[b]);
        }
        else{
            union_sets2(enemy[a], enemy[b]);
            enemy[a] = find_set(enemy[a]);
        }
    }
    if(enemy[a] != -1) enemy[enemy[a]] = a;
}

void solve(){
    int n; cin >> n;
    rep(i, 0, n){
        make_set(i);
    }
    int q,a,b;
    cin >> q >> a >> b;
    while(q!=0 || a!=0 || b!=0){
        a = find_set(a);
        b = find_set(b);
        if(q == 1){
            if(enemy[a] == b){
                cout << -1 << endl;
            }
            else{
                union_sets(a, b);
            }
        }
        if(q == 2){
            if(a == b){
                cout << -1 << endl;
            }
            else{
                if(enemy[a] != -1) union_sets(enemy[a], b);
                else if(enemy[b] != -1) union_sets(enemy[b], a);
                else{
                    enemy[a] = b;
                    enemy[b] = a;
                }
            }
        }
        if(q == 3){
            if(a == b){
                cout << 1 << endl;
            }
            else cout << 0 << endl;
        }
        if(q == 4){
            if(enemy[a] == b){
                cout << 1 << endl;
            }
            else cout << 0 << endl;
        }
        cin >> q >> a >> b;
    }
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    //cin >> t;
    while(t--) solve();
    return 0;
}