#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int n, m; cin >> n >> m;
    int pos=1;
    vector<int> a(m+1);
    long long int dis=0;

    for(int i=1;  i<=m; i++){
        cin >> a[i];
        if(pos==a[i]) dis=dis;
        else if(pos<a[i]) dis+=(a[i]-pos);
        else dis+=(n-pos+a[i]);
        pos=a[i];
    }

    cout << dis;
}