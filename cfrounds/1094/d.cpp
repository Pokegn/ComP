#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template<class T>
struct custom_compare {
    bool operator()(const T& a, const T& b) const {
        if (a == b) return true; // Keep duplicates
        return a > b;
    }
};

template<class T> using ordered_multiset = tree<T, null_type, custom_compare<T>, rb_tree_tag, tree_order_statistics_node_update>;
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

const int MAXX = 200000;

// Declaring segment tree
int st[4 * MAXX];

// Function to initialize segment tree
// with leaves filled with ones
void build(int x, int lx, int rx)
{
    // Base Case
    if (rx - lx == 1) {
        st[x] = 1;
        return;
    }

    // Split into two halves
    int m = (lx + rx) / 2;

    // Build the left subtree
    build(x * 2 + 1, lx, m);

    // Build the right subtree
    build(x * 2 + 2, m, rx);

    // Combining both left and right
    // subtree to parent node
    st[x] = st[x * 2 + 1]
            + st[x * 2 + 2];

    return;
}

// Function to make index x to 0
// and then update segment tree
void update(int i, int x,
            int lx, int rx)
{
    // Base Case
    if (rx - lx == 1) {
        st[x] = 0;
        return;
    }

    // Split into two halves
    int m = (lx + rx) / 2;

    // Update Query
    if (i < m)
        update(i, x * 2 + 1, lx, m);
    else
        update(i, x * 2 + 2, m, rx);

    // Combining both left and right
    // subtree to parent node
    st[x] = st[x * 2 + 1]
            + st[x * 2 + 2];

    return;
}

// Function to find the Kth element
int getans(int x, int lx, int rx,
           int k, int n)
{
    // Base Condition
    if (rx - lx == 1) {
        if (st[x] == k)
            return lx;
        return n;
    }

    // Split into two halves
    int m = (lx + rx) / 2;

    // Check if kth one is in left subtree
    // or right subtree of current node
    if (st[x * 2 + 1] >= k)
        return getans(x * 2 + 1,
                      lx, m, k, n);
    else
        return getans(x * 2 + 2, m,
                      rx, k - st[x * 2 + 1],
                      n);
}

// Function to generate the original
// permutation
void getPermutation(int inv[], int n)
{
    // Build segment tree
    build(0, 0, n);

    // Stores the original permutation
    vector<int> ans;

    for (int i = n - 1; i >= 0; i--) {

        // Find kth one
        int temp = getans(0, 0, n,
                          st[0] - inv[i], n);

        // Answer for arr[i]
        ans.push_back(temp + 1);

        // Setting found value back to 0
        update(max(0, temp), 0, 0, n);
    }

    // Print the permutation
    for (int i = n - 1; i >= 0; i--)
        cout << ans[i] << " ";

    return;
}

void solve(){
    int n; cin >> n;
    vector<ll> a(n); rep(i, 0, n) cin >> a[i];
    vector<ll> cum(n);
    cum[0] = a[0];
    rep(i, 1, n) cum[i] = cum[i-1] + a[i];
    vector<ll> minus(n); rep(i, 0, n) minus[i] = -cum[i];
    int count[n];
    count[n-1] = 0;
    ordered_multiset<ll> X;

    X.insert(minus[n-1]);
    for(int i = n-2; i>=0; i--){
        X.insert(minus[i]);
        X.insert(a[i]);
        count[i] = X.order_of_key(a[i]);
        X.erase(X.find_by_order(a[i]));
    }
    
    for(auto x: count) cout << x << ' ';
    cout << endl;
    getPermutation(count, n);
    cout << endl;
    cout << endl;
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}