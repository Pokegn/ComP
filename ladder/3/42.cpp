#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int n, m; cin >> n >> m;
    vector<int> f(m);
    for(int i=0; i<m; i++){
        cin >> f[i];
    }

    sort(f.begin(), f.end());

    int a=n, b=1;
    int max=f[n-1]-f[0];
    int dif=max;

    while(b<m){
        dif=f[a]-f[b];
        if(dif<max) max=dif;
        a++;
        b++;
    }

    cout << max;
}