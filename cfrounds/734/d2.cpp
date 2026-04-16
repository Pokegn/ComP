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
    int n,m,k; cin >> n >> m >> k;
    bool swapped = false;
    if(n%2 == 1){
        swapped = true;
        swap(n,m);
        k = (n*m)/2-k;
    }
    
    vector<vector<char>> ans(n, vector<char>(m));
    rep(i, 0, n){
        rep(j, 0, m){
            ans[i][j] = (char)('a' + (i%4) + 4*(j%4));
        }
    }
    vector<vector<int>> xd(n, vector<int>(m, 0)); // 1 vertical 2 horizontal

    k = (n*m)/2-k; //verticales

    if(m%2 == 0){
        if(k%2 == 1){
            cout << "NO" << endl;
            return;
        }
        cout << "YES" << endl;
        int count = 0; //quiero

        for(int j = 0; j<m; j+=2){
            for(int i = 0; i<n; i+=2){
                if(count < k){
                    xd[i][j] = 1;
                    xd[i][j+1] = 1;
                    count+=2;
                }
                else{
                    xd[i][j] = 2;
                    xd[i+1][j] = 2;
                }
            }
        }
    }

    else{
        if(k < (n/2) || (k - (n/2)) % 2 != 0){
            cout <<"NO" << endl;
            return;
        }
        cout <<"YES" << endl;
        int count = 0;
        for(int j = 0; j<m-1; j+=2){
            for(int i = 0; i<n; i+=2){
                if(count < k - (n/2)){
                    xd[i][j] = 1;
                    xd[i][j+1] = 1;
                    count+=2;
                }
                else{
                    xd[i][j] = 2;
                    xd[i+1][j] = 2;
                }
            }
        }
        for(int i=0; i<n; i+=2){
            xd[i][m-1] = 1;
        }
    }

    rep(i, 0, n){
        rep(j, 0, m){
            if(xd[i][j] == 1){
                ans[i+1][j] = ans[i][j];
            }
            if(xd[i][j] == 2){
                ans[i][j+1] = ans[i][j];
            }
        }
    }

    if(swapped == false){
        rep(i, 0, n){
            rep(j, 0, m){
                cout << ans[i][j];
            }
            cout << endl;
        }
    }
    else{
        rep(i, 0, m){
            rep(j, 0, n){
                cout << ans[j][i];
            }
            cout << endl;
        }
    }


}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}