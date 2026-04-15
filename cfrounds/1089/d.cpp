#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
#define rep(i, a, b) for(int i=a; i<(b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define endl '\n'
#define pb push_back
typedef long long ll;
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

pair<ll, ll> gitgud(string s){
    string temp = "(" + s + ")";
    swap(temp, s);
    ll n = s.length()/2;
    vector<vector<ll>> grafo(n);
    stack<ll> st;
    st.push(0);
    ll top = 0;
    ll curr = 1;
    rep(i, 1, s.length()-1){
        top = st.top();
        if(s[i] == '('){
            st.push(curr);
            grafo[top].push_back(curr);
            grafo[curr].push_back(top);
            curr++;
        }
        else{
            st.pop();
        }
    }

    // return {-1,-1};

    ll leaves = 0;
    rep(i, 0, curr){
        if(grafo[i].size() == 1) leaves++;
    }

    ll highmult = -1;
    rep(i, 0, curr){
        if(grafo[0].size() == 2){
            highmult = 0; break;
        }
        if(grafo[i].size() > 2){
            highmult = i;
            break;
        }
    }

    return {leaves, highmult};
}

void solve(){
    int n; cin >> n;
    string s1; cin >> s1;
    auto p1 = gitgud(s1);
    string s2; cin >> s2;
    auto p2 = gitgud(s2);
    //cout << p1.first << ' ' << p1.second << ' ' << p2.first << ' ' << p2.second << ' ';
    if(p1 == p2){
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}