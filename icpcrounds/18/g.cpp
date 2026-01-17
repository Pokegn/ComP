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
int sz = 5;

void multmat(vector<vector<lli>> &a, vector<vector<lli>> b){
    vector<vector<lli>> ans(5, vector<lli> (5, 0));

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
                            {{1, 0, 0, 0, 0}, {0, 1, 0, 0, 0}, {0, 0, 1, 0, 0}, 
                            {0, 0, 0, 1, 0}, {0, 0, 0, 0, 1}};
                            
    vector<vector<lli>> a = {{0, 1, 0, 0, 0}, {0, 0, 1, 0, 0}, 
                            {0, 0, 0, 1, 0}, {0, 0, 0, 0, 1}, {0, 1, 4, 9, 16}};

    while(n>0){  //matrix binexp
        if(n%2 == 1){
            multmat(ans, a); //multmat
        }
        multmat(a, a);
        n>>=1;
    }
    
    lli ret = 0;
    ret = (ans[0][0]+16*ans[0][1]+265*ans[0][2]+4388*ans[0][3]+72658*ans[0][4])%MOD; //los numeros son la funcion en los primeros n valores
    //
    return ret;
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1;
    //cin >> t;
    lli n;
    lli ans=0;
    while(t--){
        ans =0 ;
        cin >> n;
        for(lli i=n-44;i<=n; i++){
            if(i%10 == 0){
                ans=(ans+findans(i/10))%MOD;
            }
        }
        cout << ans << '\n';
    }
}