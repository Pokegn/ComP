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
typedef long long ll;
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    string s1, s2; cin >> s1 >> s2;
    string y1 = "";
    y1 += s1[0];
    rep(i, 1, s1.length()){
        if(s1[i] == '0') y1+=y1[i-1];
        else{
            y1+=(y1[i-1] == '0' ? '1' : '0');
        }
    }
    string obj = "";
    rep(i, 0, s1.length()){
        if(y1[i] == s2[i]) obj+='0';
        else obj+='1';
    }

    //cout << s1 << ' ' << s2 << ' ' << y1 << ' ' << obj << ' ';

    int ans = 0;
    vector<int> cosos;
    int junticos = 1;
    rep(i, 1, obj.size()){
        if(obj[i] == obj[i-1]){
            junticos++;
        }
        else{
            if(cosos.size() != 0 || obj[i] == '0') cosos.push_back(junticos);
            junticos = 1;
        }
    }
    if(cosos.size() != 0 || obj[obj.size()-1] == '1') cosos.push_back(junticos);

    vector<int> flip(cosos.size());
    vector<int> noflip(cosos.size());

    int sz = cosos.size();
    vector<int> color(sz);
    rep(i, 0, sz) color[i] = (i%2 == 0 ? 1 : 0);
    
    //for(auto c: cosos) cout << c << ' ';

    ans = 0;
    int uno = 1;
    rep(i, 0, sz){
        if(color[i] != uno) continue;
        if(cosos[i] == 1){
            ans++;
        }
        else{
            ans++;
            uno = 1-uno;
        }
    }

    cout << ans << endl;
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}