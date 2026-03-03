#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
using ll = long long;
using vi = vector<int>;
using vlli = vector<ll>;
using vvi = vector<vi>;
using vvlli = vector<vlli>;
#define forn(i, a, b) for(ll i = a; i < b; i++)
#define rof(i, a, b) for(ll i = a; i >= b; i--)
#define nl '\n'
#define endl '\n'
#define rep(i, a, b) for(int i=a; i<(b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define pb push_back
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

typedef complex<double> C;
typedef vector<double> vd;
int maxsize = 1<<17;
void fft(vector<C> &a){
    int n= sz(a), L = 31 - __builtin_clz(n);
    static vector<complex<long double>> R(2,1);
    static vector<C> rt(2,1);
    for(static int k = 2; k<n; k*=2){
        R.resize(n); rt.resize(n);
        auto x = polar(1.0L, acos(-1.0L) / k);
        rep(i, k, 2*k) rt[i] = R[i] = i&1 ? R[i/2] * x : R[i/2];
    }
    vi rev(n);
    rep(i, 0, n) rev[i] = (rev[i/2] | (i&1) << L) / 2;
    rep(i, 0, n) if(i < rev[i]) swap(a[i], a[rev[i]]);
    for(int k = 1; k<n; k*=2)
        for(int i=0; i<n; i+=2*k) rep(j, 0, k){
            C z = rt[j+k] * a[i+j+k];
            a[i+j+k] = a[i+j]-z;
            a[i+j]+=z;
        }
}

vd conv(const vd& a, const vd &b){
    if(a.empty() || b.empty()) return {};
    vd res(sz(a)+sz(b)-1);
    int L = 32 - __builtin_clz(sz(res)), n = 1 << L;
    vector<C> in(n), out(n);
    copy(all(a), begin(in));
    rep(i, 0, sz(b)) in[i].imag(b[i]);
    fft(in);
    for(C& x: in) x *= x;
    rep(i, 0, n) out[i] = in[-i & (n-1)] - conj(in[i]);
    fft(out);
    rep(i, 0, sz(res)) res[i] = imag(out[i]) / (4*n);
    return res;
}

vector<bool> dfs_vis;

void dfs(int u, vector<vector<int>> grafo) {
	if(dfs_vis[u])
		return;
	
	dfs_vis[u] = true;
	for(int v : grafo[u])
		if(!dfs_vis[v])
			dfs(v, grafo);
}

void solve(){
    string s; cin >> s;
    string t; cin >> t;
    int ssz = s.length(), tsz = t.length();
    int anssz = ssz - tsz + 1;

    auto g = vector<vector<vector<int>>> (anssz, vector<vector<int>>(6));
    //voy a tener anssz grafos distintos, cada uno con aristas i-j con i,j<6
    
    vector<vector<double>> xd(30, vector<double> (maxsize, 0.0));
    int idx = 0;

    vector<double> a,b;

    rep(i, 0, 6){ //primero agrego las aristas en o(n) de las letras i-j
        for(int j = 0; j < 6; j++){
            if(i==j) continue;
            swap(a, xd[idx]); swap(b,xd[idx]);
            idx++;
            vector<double> b(maxsize, 0.0);
            rep(k, 0, ssz){
                a[k] = ((int)s[k]-'a' == i ? 1.0 : 0.0);
            }
            //for(auto x:a) cout << x << ' '; cout << endl;
            for(int k = tsz-1; k>=0; k--){
                b[k] = ((int)t[tsz-1-k]-'a' == j ? 1.0 : 0.0);
            }
            //for(auto x:b) cout << x << ' '; cout << endl;
            //cout <<"antes ";
            vector<double> c = conv(a,b);
            //cout <<"despues";
            // cout << "ahi te va c: \n";
            // rep(k, 0, 16){
            //     cout << fixed << setprecision(10) << c[k] << ' ';
            // }
            // cout << endl;
            // return;
            rep(k, 0, anssz){
                //cout << c[k+t.size()-1] << ' ';
                if(round(c[k+t.size()-1]) > 0){
                    g[k][i].push_back(j);
                    g[k][j].push_back(i);
                    //cout << i << ' ' << j << endl;
                }
            }
            //cout << endl;
            //return;
        }
        //return;
    }



    rep(k, 0, anssz){
        int letters = 0;
        int components = 0;
        dfs_vis = vector<bool> (6, false);
        rep(i, 0, 6){
            if(g[k][i].size() != 0){
                letters++;
                if(!dfs_vis[i]){
                    components++;
                    dfs(i, g[k]);
                }
            }
        }
        // cout << "k= " << k << endl;
        // rep(i, 0, 6){
        //     cout << i << ": ";
        //     for(auto xd:g[k][i]) cout << xd << ' ';
        //     cout << endl; 
        // }
        cout << letters-components;
        cout << ' ';
    }
    cout << endl;
    return;

}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    ll t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}