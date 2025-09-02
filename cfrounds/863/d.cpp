#include <bits/stdc++.h>
 
using namespace std;
 
vector<int> fibo(46);
 
bool solve(int x, int y, int px, int py){
    if(px<1 or py<1) return false;
    if(px==1 and py==1) return true;
    if (py>(y-x)) return solve(y-x, x, py-x, px);
    else return solve(y-x, x, py, px);
}
 
int main(){
    cin.tie(0)->sync_with_stdio(false);
 
    int t; cin >> t;
    for(int i=0; i<46; i++){
        if(i==0 or i==1) fibo[i] = 1;
        else fibo[i] = fibo[i-1] + fibo[i-2];
    }
 
    for (int i=0; i<t; i++){
 
        int n, x, y;
        cin >> n >> x >> y;
 
        if (solve(fibo[n],fibo[n+1], x, y)) cout << "YES" ;
        else cout << "NO";
        cout << endl;
 
    }
        
}