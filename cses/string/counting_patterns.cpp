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
 
struct AhoCorasick {
    enum {alpha = 26, first = 'a'}; //change
    struct Node{
        //nmatches is optional
        int back, next[alpha], start = -1, end = -1, nmatches = 0;
        Node(int v) { memset(next, v, sizeof(next)); }
    };
    vector<Node> N;
    vi backp;
    void insert(string &s, int j){
        assert(!s.empty());
        int n = 0;
        for(char c: s){
            int &m = N[n].next[c-first];
            if(m == -1) { n = m = sz(N); N.emplace_back(-1); }
            else n = m;
        }
        if(N[n].end == -1) N[n].start = j;
        backp.push_back(N[n].end);
        N[n].end = j;
        N[n].nmatches++;
    }
    
    AhoCorasick(vector<string> &pat) : N(1, -1){
        rep(i,0, sz(pat)) insert(pat[i], i);
        N[0].back = sz(N);
        N.emplace_back(0);
 
        queue<int> q;
        for(q.push(0); !q.empty(); q.pop()){
            int n = q.front(), prev = N[n].back;
            rep(i,0,alpha){
                int &ed = N[n].next[i], y = N[prev].next[i];
                if(ed == -1) ed = y;
                else{
                    N[ed].back = y;
                    (N[ed].end == -1 ? N[ed].end : backp[N[ed].start]) = N[y].end;
                    N[ed].nmatches += N[y].nmatches;
                    q.push(ed);
                }
            }
        }
    }
 
    vi find(string word){
        int n = 0; 
        vi res; //ll count = 0;
        for(char c: word){
            n = N[n].next[c-first];
            res.push_back(N[n].end);
            //count += N[n].nmatches;
        }
        return res;
    }
    
    vi findAll(vector<string> &pat, string word){
        vi r = find(word);
        // vector<vi> res(sz(word));
        vi res(sz(pat));
        rep(i,0,sz(word)){
            int ind = r[i];
            while(ind != -1){
                res[ind]++;
                ind = backp[ind];
            }
        }
        return res;
    }
};
 
void solve(){
    string s; cin >> s;
    int k; cin >> k;
    
    vector<string> st(k); rep(i, 0, k) cin >> st[i];
    unordered_map<string, int> mamamierda;
    vi trueidx(k);
    vector<string> dict;
    int asigno = 0;
    rep(i,0,k){
        int &x = mamamierda[st[i]];
        if(x != 0){ //si ya se asigno
            trueidx[i] = x-1;
        }
        else{
            x = asigno+1;
            trueidx[i] = asigno;
            dict.push_back(st[i]);
            asigno++;
        }
    } 

    k = sz(dict);
    auto ac = AhoCorasick(dict);
    
    vi ans = ac.findAll(dict, s);
    
    rep(i, 0, sz(st)){
        int idx = trueidx[i];
        cout << ans[idx] << endl;
    }
}
 
 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    // cin >> t;
    while(t--) solve();
    return 0;
}