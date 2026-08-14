#include <iostream>
#include <vector>
#include <string>
#include <numeric>

using namespace std;
typedef long long ll;

ll combs(ll x) {
    if (x <= 1) return 0;
    return (x * (x - 1)) / 2;
}

void solve() {
    int n, m; 
    if (!(cin >> n >> m)) return;
    
    string str; 
    cin >> str;
    
    vector<int> s(n);
    for (int i = 0; i < n; ++i) {
        s[i] = str[i] - '0';
    }
    
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v; 
        cin >> u >> v; 
        u--; v--;
        if (u != v) {
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }
    
    // STRICTLY LOCAL variables to prevent data leakage between test cases
    vector<int> parent(n);
    iota(parent.begin(), parent.end(), 0); // Fills 0, 1, ..., n-1
    vector<ll> sizee(n, 0);
    vector<int> rnk(n, 0); // Prevents stack-overflow during union_meco
    ll ans = 0;

    // Y-combinator style lambda for deep recursion safety
    auto find_set = [&](auto& self, int v) -> int {
        if (v == parent[v]) return v;
        return parent[v] = self(self, parent[v]);
    };

    auto union_meco = [&](int a, int b) {
        a = find_set(find_set, a);
        b = find_set(find_set, b);
        if (a != b) {
            // Union by rank strictly for pre-processing structural integrity
            if (rnk[a] < rnk[b]) swap(a, b);
            parent[b] = a;
            if (rnk[a] == rnk[b]) rnk[a]++;
        }
    };

    auto union_sets = [&](int a, int b) {
        a = find_set(find_set, a);
        b = find_set(find_set, b);
        if (a != b) {
            // Union by size for actual pair calculation
            if (sizee[a] < sizee[b]) swap(a, b);
            ans -= combs(sizee[a]); 
            ans -= combs(sizee[b]);
            sizee[a] += sizee[b];
            ans += combs(sizee[a]);
            parent[b] = a;
        }
    };

    // 1. Pre-process s=1 nodes (Your logic)
    for (int i = 0; i < n; ++i) {
        if (s[i] == 1) {
            for (int j : g[i]) {
                if (j > i) {
                    union_meco(j, i);
                }
            }
        }
    }
    
    vector<ll> respuestas(n);
    
    // 2. Resolve backwards
    for (int i = n - 1; i >= 0; i--) {
        int root = find_set(find_set, i);
        ans -= combs(sizee[root]);
        sizee[root]++;
        ans += combs(sizee[root]);
        
        for (int j : g[i]) {
            if (j > i) {
                union_sets(i, j);
            }
        }
        respuestas[i] = ans;
    }

    // Print all answers
    for (int i = 0; i < n; ++i) {
        cout << respuestas[i] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; 
    // cin >> t; // Un-comment if problem secretly runs multi-tests
    while (t--) solve();
    return 0;
}