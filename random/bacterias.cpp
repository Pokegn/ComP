#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

void multmat(vector<vector<long long int>> &a, vector<vector<long long int>> b){
    vector<vector<long long int>> ans(9, vector<long long int> (9, 0));

    for(int i=0; i<9; i++){
        for(int j = 0; j<9; j++){
            for(int k=0; k<9; k++){
                ans[i][j] = (ans[i][j] + a[i][k]*b[k][j])%MOD;
            }
        }
    }

    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            a[i][j] = ans[i ][j ];
        }
    }
    return;
}

long long int findans(long long int n){
    if(n<0) return 0;
    vector<vector<long long int>> ans =
                                    {{1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 0, 0}, 
                                    {0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 0, 0}, 
                                    {0, 0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 1}};
    vector<vector<long long int>> a = {{0, 0, 3, 0, 3, 0, 3, 0, 3}, {1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 0, 0, 0, 0}, 
                                        {0, 0, 1, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0, 0},
                                        {0, 0, 0, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 0}};

    while(n>0){
        if(n%2 == 1){
            multmat(ans, a);
        }
        multmat(a, a );
        n>>=1;
    }
    
    long long int ret = 0;
    ret = (18*ans[8][0]+3*ans[8][1]+9*ans[8][2]+3*ans[8][3]+3*ans[8][5]+ans[8][8])%MOD;
    // for(int i=0; i<9; i++){
    //     for(int j=0; j<9; j++){
    //         cout << ans[i][j ] << ' ';
    //     }
    //     cout << '\n';
    // }
    return ret;
}

int main(){
    int t; cin >> t;
    long long int n;
    long long int ans=0;
    while(t--){
        ans =0 ;
        cin >> n;
        if(n%2==1){
            n-=1;
        }
        for(long long i = n-18; i<=n; i+=2) ans = (ans+findans(i/2)) %MOD;
        cout << ans << '\n';
    }
}