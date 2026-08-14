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

const int MAXN = 200001;
int sizee[MAXN];
int parent[MAXN];
ll h,w;

int find_set(int u){
    if(parent[u] == u) return u;
    return parent[u] = find_set(parent[u]);
}

void make_set(int u){
    parent[u] = u;
    sizee[u] = 1;
}

void union_sets(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if(a!=b){
        if(sizee[a] < sizee[b]) swap(a,b);
        parent[b] = a;
        sizee[a] += b;
    }
}

ll mint(pair<ll, ll> p1, pair<ll, ll> p2, ll r1, ll r2){
    ll dist = (p1.fi-p2.fi) * (p1.fi-p2.fi)
        + (p1.se-p2.se) * (p1.se-p2.se);
    ld lol = ld(dist); lol = sqrt(lol); //la distancia es igual 
    ld r1l = (ld)r1;
    ld r2l = (ld)r2;
    ld ret = (lol - r1l - r2l)/2;
    ll ans;
    if(abs(ret - round(ret)) <= 0.000001) ans = llround(ret)+1;
    else ans = llround(ceil(ret));
    if(ans < 0) return 0;
    return ans;
}

ll distSide(pair<ll, ll> p, ll i, ll r){ //drul
    ll x = p.fi, y = p.se;
    ll ret;
    if(i == 1){
        ret = y;
    }
    if(i == 2){
        ret = (w-x);
    }
    if(i == 3){
        ret = (h-y);
        
    }
    if(i == 4){
        ret = x;
    }
    ret -= r;
    if(ret < 0) return 0;
    return ret/2+1;
}

//4          3

//1          2

void solve(){
    ll n,m; cin >> n >> m;
    //n circulos, m personas
    cin >> w >> h;
    vector<pair<ll, pair<ll, ll>>> trees(n+5);
    vector<pair<ll, ll>> people(m);
    ll x,y,ent,r;

    rep(i, 0, n){
        cin >> x >> y >> r;
        trees[i] = {r, {x,y}};
    }
    rep(i, 0, m){
        cin >> r >> ent;
        people[i] = {r, ent};
    }

    //estos son los lados
    trees[n+1] = trees[n+2] = trees[n+3] = trees[n+4] = {-1, {-1, -1}};
    
    vector<pair<ll, pair<ll, ll>>> edges;
    rep(i, 0, n){
        rep(j, i+1, n){
            ll t = mint(trees[i].se, trees[j].se, trees[i].fi, trees[j].fi);
            edges.push_back({t, {i, j}});
        }
    }

    rep(i, 0, n){
        edges.push_back({distSide(trees[i].se, 1, trees[i].fi), {i, n+1}});
        edges.push_back({distSide(trees[i].se, 2, trees[i].fi), {i, n+2}});
        edges.push_back({distSide(trees[i].se, 3, trees[i].fi), {i, n+3}});
        edges.push_back({distSide(trees[i].se, 4, trees[i].fi), {i, n+4}});
    }

    rep(i, 0, n+5) make_set(i);

    ll united[5][5];
    rep(i, 1, 5) rep(j, 1, 5) united[i][j] = 1000000000;
    sort(all(edges));
    for(auto e : edges){
        int time = e.fi;
        int a = e.se.fi, b = e.se.se;
        //cout << "edge " << time << ' ' << a << ' ' << b << endl;
        union_sets(a, b);
        rep(i, 1, 5) rep(j, i+1, 5){
            if(find_set(n+i) == find_set(n+j) && united[i][j] == 1000000000){
                united[i][j] = time;
                united[j][i] = time;
            }
        }
    }
    // rep(i, 1, 5){
    //     rep(j, 1, 5){
    //         if(united[i][j] == 1000000) cout << -1 << ' ';
    //         else cout << united[i][j] << ' ';
    //    }
    //    cout << endl;

    // }
    // cout << endl;

    ll canGo[5][5]; rep(i,1,5) rep(j,1,5) canGo[i][j] = 1000000000;
    rep(i, 1, 5) canGo[i][i] = 1000000000;
    canGo[1][2] = min({canGo[1][2], united[1][4], united[1][3], united[1][2]});
    canGo[2][1] = canGo[1][2]; //ya

    canGo[1][3] = min({canGo[1][3], united[1][3], united[1][4], united[2][3], united[2][4]});
    canGo[3][1] = canGo[1][3];

    canGo[1][4] = min({canGo[1][4], united[1][4], united[2][4], united[3][4]});
    canGo[4][1] = canGo[1][4];

    canGo[2][3] = min({canGo[2][3], united[1][2], united[2][3], united[2][4]});
    canGo[3][2] = canGo[2][3];

    canGo[2][4] = min({canGo[2][4], united[1][2], united[1][3], united[2][4], united[3][4]});
    canGo[4][2] = canGo[2][4];

    canGo[3][4] = min({canGo[3][4], united[1][3], united[2][3], united[3][4]});
    canGo[4][3] = canGo[3][4];

    // rep(i, 1, 5){
    //     rep(j, 1, 5){
    //         if(canGo[i][j] == 1000000) cout << -1 << ' ';
    //         else cout << canGo[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    rep(i, 0, m){
        ll entrance; r = people[i].fi, entrance = people[i].se;
        vector<int> canEnter;
        rep(j, 1, 5){
            if(r < canGo[entrance][j]) canEnter.push_back(j);
        }
        sort(all(canEnter));
        for(auto resp : canEnter) cout << resp;
        cout << endl;
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