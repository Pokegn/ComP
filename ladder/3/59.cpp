#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, k; cin >> n >> k;
    vector<vector<long long int>> dp(n+1, vector<long long int>(k+1,0));

    for(int i=1; i<=n; i++){
        dp[i][1] = 1;
    }

    for(int j=1; j<k; j++){
        for(int i=1; i<=n; i++){
            
            //para cada
            for(int x=i; x<=n; x+=i){
                dp[x][j+1]=(dp[x][j+1]+dp[i][j])%1000000007;
            }


        }
    }

    long long int ans=0;
    for(int i=1; i<=n; i++){
        ans = (ans+dp[i][k])%1000000007;
    }

    cout << ans;

}