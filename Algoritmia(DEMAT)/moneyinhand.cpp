#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cmath>

using namespace std;

int main(){



    int n, x; cin >> n >> x;
    vector<int> A(n);
    vector<int> B(n);
    vector<vector<bool>> dp(n+1, vector<bool>(x+1, 0));
    for(int i=0; i<n; i++){
        cin >> A[i+1] >> B[i+1];
    }

    dp[0][0] = 1;
    int count=0;
    int curr=0;
    for(int i=1; i<n+1; i++){
        count = B[i];
        curr=x;
        int j=0;
        while(count-- && curr>=A[i]){
            if(dp[i-1][x-j*curr]){
                dp[i][j]
            }
        }
    }

    vector<pair<int, int>> dp(n);


}