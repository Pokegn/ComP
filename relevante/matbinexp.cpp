#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using vi = vector<int>;
using vlli = vector<lli>;
using vvi = vector<vi>;
using vvlli = vector<vlli>;
#define MOD 1000000007

//sz es el tamaño de la recursion
//o sea que si f(n) = 3f(n−2)+3f(n−4)+3f(n−6)+3f(n−8) el tamaño es (8)+1 = 9
int sz = 9;

void multmat(vector<vector<lli>> &a, vector<vector<lli>> b){
    vector<vector<lli>> ans(9, vector<lli> (9, 0));

    for(int i=0; i<sz; i++){
        for(int j = 0; j<sz; j++){
            for(int k=0; k<sz; k++){
                ans[i][j] = (ans[i][j] + a[i][k]*b[k][j])%MOD;
            }
        }
    }

    for(int i=0; i<sz; i++){
        for(int j=0; j<sz; j++){
            a[i][j] = ans[i][j];
        }
    }
    return;
}

lli findans(lli n){
    if(n<0) return 0;
    vector<vector<lli>> ans = //la diagonal es 1
                            {{1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 0, 0}, 
                            {0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 0, 0}, 
                            {0, 0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 1}};
                            
    vector<vector<lli>> a = {{0, 0, 3, 0, 3, 0, 3, 0, 3}, {1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 1, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 0}};

    while(n>0){  //matrix binexp
        if(n%2 == 1){
            multmat(ans, a); //multmat
        }
        multmat(a, a);
        n>>=1;
    }
    
    lli ret = 0;
    ret = (18*ans[8][0]+3*ans[8][1]+9*ans[8][2]+3*ans[8][3]+3*ans[8][5]+ans[8][8])%MOD;
    //
    return ret;
}

int main(){
    int t; cin >> t;
    lli n;
    lli ans=0;
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