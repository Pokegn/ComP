#include <bits/stdc++.h>
 
using namespace std;
 
long long int suma(int l, int r, bool x, int p[], int m){
    if (l==r) return 0;
    if (x==1) return -10000000;
    long long int a=0;
    int j;
    int s=0;
    for(j=l; j<=(r+l-1)/2; j++){
        if(p[j]>p[r]){
            s=1;
            a+=p[j];
            a-=p[j+(r-l+1)/2];
            a-=(r-l+1)/2;
        }
        if(p[j]<p[r]){
            a-=p[j];
            a+=p[j+(r-l+1)/2];
            a-=(r-l+1)/2;
        }
    }
    if (a!=0){
      x=1;
      return -100000000;
    } 
    else {
    if (x==1) return -100000000;
    return s+suma(l,(l+r-1)/2,x,p,m)+suma((l+r+1)/2,r,x,p,m);
    }
}
 
int main(){
    int t, i; cin >> t;
    for(i=0; i<t; i++){
        int m; cin >> m;
        int p[m];
        int j;
        for(j=0; j<m; j++) cin >> p[j];
        bool x=0;
        int s;
        int r;
        r=suma(0,m-1,x,p,m);
        if(r>=0) cout << r << endl;
        if(r<0) cout << -1 << endl;
    }
}