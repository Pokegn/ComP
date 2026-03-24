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
typedef long long ll;
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    int rr,gg,bb; cin >> rr >>gg>>bb;
    string s = "";
    vector<pair<int, char>> color = {{rr, 'R'}, {gg, 'G'}, {bb, 'B'}};
    sort(all(color), greater<pair<int, char>>());
    if(color[0].fi > color[1].fi + color[2].fi){
        int reps = color[1].fi;
        rep(i, 0, reps){
            s+= color[0].se; color[0].fi--;
            s+= color[1].se; color[1].fi--;
        }
        reps = color[2].fi;
        rep(i, 0, reps){
            s+= color[0].se; color[0].fi--;
            s+= color[2].se; color[2].fi--;
        }
        s+= color[0].se;
        cout << s << endl;
        return;
    }

    while(color[1].fi != color[2].fi){
            s+= color[1].se; color[1].fi--;
            s+= color[0].se; color[0].fi--;
    }
    while(color[0].fi > color[1].fi && color[1].fi > 0){
        s+=color[1].se; color[1].fi--;
        s+= color[0].se; color[0].fi--;
        s+= color[2].se; color[2].fi--;
        s+= color[0].se; color[0].fi--;
    }

    //color 1 == color2 == color3
    vector<string> posibles = {"RGB", "RBG", "GBR", "GRB", "BGR", "BRG"};
    //cout << "hasta ahora es " << s << endl;
    while(color[0].fi > 0){
        int sz = s.length();
        string god;
        for(auto p:posibles){
            god = "";
           // cout << ' ';
            if(sz-1 >= 0 && s[sz-1] == p[0]) continue;
           // cout << "a";
            if(sz-3 >= 0 && s[sz-3] == p[0]) continue;
                      //  cout << "a";

            if(sz-2 >= 0 && s[sz-2] == p[1]) continue;
                       // cout << "a";

            if(sz-1 >= 0 && s[sz-1] == p[2]) continue;
                       // cout << "a";

            god = p;
            break;
        }
       // cout << "god is " << god << endl;
        s+=god;
        color[0].fi--;
    }

    cout << s << endl;
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}