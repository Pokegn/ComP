#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m; cin >> n >> m;
    int a;
    //vector<int> rep(100001,0);
    vector<int> lastrep(100001);
    vector<int> alist(n);
    for(int i=0; i<n; i++){
        cin >> a;
        alist[i] = a;
        //rep[a]+=1;
        lastrep[a]=i;
    }

    vector<int> ans(n);
    int c=0;
    int nn;
    for(int i=n-1; i>=0; i--){
        nn= alist[i];
        if(lastrep[nn] == i) c++;
        ans[i]= c;
    }

    int l;
    for(int i=0; i<m; i++){
        cin >> l;
        cout << ans[l-1] << '\n';
    }
}