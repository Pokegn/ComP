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
    string s; cin >> s;
    int sz = s.length();

    rep(i, 0, sz){
        if(s[i] >= 'A' && s[i] <= 'Z') s[i]+=('a'-'A');
    }

    int dospts = -1;//en i y i+1
    rep(i, 0, sz-1){
        if(s[i] == ':' && s[i+1] == ':'){
            dospts = i;
        }
    }

    vector<string> blocks;
    string currblock = "";
    rep(i, 0, sz){
        if(s[i] == ':'){
            if(currblock != ""){
                blocks.push_back(currblock);
                currblock = "";
            } 
            if(i == dospts){
                blocks.push_back("SEXO");
            }
        }
        else{
            currblock+=s[i];
        }
    }
    if(currblock!="") blocks.push_back(currblock);

    // for(auto b:blocks){
    //     cout << b << ' ';
    // }
    // cout << endl;

    string ceros = "";
    if(dospts != -1){
        int faltan = 8 - (blocks.size()-1);
        rep(i, 0, faltan){
            ceros += "0000";
            if(i!=faltan-1) ceros+=":";
        }
    }

    string ans = "";
    int bsz = blocks.size();
    for(int i=0; i<bsz; i++){
        auto st = blocks[i];
        if(st == "SEXO"){
            ans += ceros;
        }
        else{
            int add0 = 4-st.length();
            rep(j, 0, add0) ans+='0';
            ans+=st;
        }
        if(i < bsz-1) ans += ":";
    }
    cout << ans << endl;
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    //cin >> t;
    while(t--) solve();
    return 0;
}