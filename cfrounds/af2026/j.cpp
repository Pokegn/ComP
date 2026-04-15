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

void solve(){
    vector<string> s;
    string st;
    while(cin >> st){
        s.push_back(st);
    }
    bool flag = true;
    if(s.size() == 5){
        if(s[0] != "Are" || s[1] != "you" || s[2] != "a" || s[3] != "verified" || s[4] != "human?") flag = false;
    }
    else flag = false;

    if(flag == true){
        cout << "Yes, I can attest to my status as a thoroughly validated, carbon-based biological entity." << endl;
    }
    else cout << "gary" << endl;

}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    //cin >> t;
    while(t--) solve();
    return 0;
}