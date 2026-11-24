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

void solve(){
    int x,y,m; cin >> x >> y >> m;
    string s; cin >> s;
    int ans = x+y;
    rep(ii,1,m+1){ //de cuantos
        int mas = 0, menos = 0;
        // rep(i,0,ii){ //me agarro el prefix de 0 a ii-1
        //     if(s[i] == '+') mas++;
        //     else menos++;
        // }
        
        // int ocupobajar = (menos - x + 1)/2 ;
        bool factible = true;

        int tempx = x, tempy = y;
        rep(i, 0, ii){
            if(s[i] == '+'){
                if(y > 0) y++;
                else{
                    if(x == 0) factible = false;
                    y++,x--;
                }
            } 
            else{
                if(x == 0){
                    if(y == 0) factible = false;
                    y--, x++;
                    
                }
                else if(y > 1) y--,x++;
                else{
                    if(x == 0) factible = false;
                    x--;
                }
            }
        }
        if(factible) ans = max(ans, x+y);
        swap(tempx, x);
        swap(tempy, y);

    }
    cout << ans << endl;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}