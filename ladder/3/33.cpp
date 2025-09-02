#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int n; cin >> n;
    vector<int> a(n);
    int sum=0;

    for(int i=0; i<n; i++){
        cin >> a[i];
        sum+=a[i];
    }

    int hs=(sum%2==0 ? sum/2 - 1 : sum/2);
    sort(a.begin(), a.end());

    int sum=0;
    int coins=0;
    for(int i=0; i<n; i++){
        if(sum<=hs){
            sum+=a[i];
            coins+=1;
        }
    }
    coins-=1;

    cout << n-coins;
}