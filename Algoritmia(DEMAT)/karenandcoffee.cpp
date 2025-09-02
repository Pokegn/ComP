#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cmath>
 
using namespace std;
 
int main(){
    int n, k, q; cin >> n >> k >> q;
    int posl, posr;
    vector<int> temp(200002, 0);
    vector<int> tempc(200002, 0);
    vector<int> isk(200002, 0);
    for(int i=0; i<n; i++){
        cin >> posl >> posr;
        temp[posl]++;
        temp[posr+1]--;
    }
 
    vector<int> ans(200002);
    for(int i=1; i<200002; i++){
        tempc[i] = temp[i]+tempc[i-1];
        ans[i]=ans[i-1];
        if(tempc[i]>=k){
            isk[i]=1;
            ans[i]++;
        }
    }
 
    int l, r;
    for(int i=0; i<q; i++){
        cin >> l >> r;
        cout << ans[r]-ans[l-1] << endl;
    }
}