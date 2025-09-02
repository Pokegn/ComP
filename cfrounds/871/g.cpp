#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    long long int row=2;
    long long int newrow=1;

    vector<long long int> ans(1000001);
    for(long long int i=1; i<=1000000; i++){
        if(i==1) ans[i]=1;
        else{
            if(row*(row+1)==2*i){
                ans[i]=ans[i-row]+(long long int)(i*i);
                row+=1;
                newrow=1;
            }
            else if(newrow==1){
                ans[i]=ans[i-row+1]+(long long int)(i*i);
                newrow=0;
            }
            else{
                ans[i]=ans[i-row]-ans[i-2*row+2]+ans[i-row+1]+(long long int)(i*i);
            }
        }
    }

    for(int i=0; i<t; i++){
        long long int n; cin >> n;
        cout << ans[n] << endl;
    }
}