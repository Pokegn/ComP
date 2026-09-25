#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
#define pb push_back
#define victor vector
#define rep(i, a, b) for(int i=a; i<(b); ++i)
int INF = 10000000;

void solve(){
    int n; cin >> n; int k; cin >> k;
    vector<ll> a(n); vector<int> cinco(n, 0), dos(n, 0);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++){
        ll m = a[i];
        while(m%2 == 0){
            m/=2;
            dos[i]++;
        }
        while(m%5 == 0){
            m/=5;
            cinco[i]++;
        }
    }

    vector<vector<int>> dp(n+1, vector<int>(5001, -INF));
    dp[0][0] = 0;
    dp[1][cinco[0]] = dos[0];
    rep(idx, 0, n-1){ //para cada indice proceso el siguiente numero
        vector<vector<int>> temp(n+1, vector<int>(5001, -INF));
        rep(ki, 0, k+1){ //para cada cantidad de usados posible, proceso que
            //si agrego uno entonces me afecta en si tenia j ya usados
            //y le ganaba
            rep(p, 0, 5001){ //la potencia de 5
                temp[ki][p] = max(temp[ki][p], dp[ki][p]);
                if(ki+1 <= k) temp[ki+1][min(5000, p+cinco[idx+1])] = 
                    max(temp[ki+1][min(5000, p+cinco[idx+1])], 
                    dp[ki][p]+dos[idx+1]); 
            }
        }
        swap(temp, dp);
    }

    int ans = 0;
    rep(p, 0, 5001){
        ans = max(ans, min(p, dp[k][p]));
    }
    cout << ans << endl;
    return;
}

int main() {
    solve();
}