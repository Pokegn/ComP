#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    vector<int> a(n);

    cin >> a[0];
    int min=a[0];
    int max=a[0];
    int minpos=0;
    int maxpos=0;

    for(int i=1; i<n; i++){
        cin >> a[i];
        if(max<a[i]){
            max=a[i];
            maxpos=i;
        } 
        if(min>=a[i]){
            min=a[i];
            minpos=i;
        } 
    }
    if(minpos<maxpos) maxpos-=1;
    cout << n-1-minpos+maxpos;

}