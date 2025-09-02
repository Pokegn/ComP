#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
 
    int t; cin >> t;
 
    for (int i=0; i<t; i++){
 
        int n;
        cin >> n;
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
 
        int minx1 = min(x1, n+1-x1);
        int miny1 = min(y1, n+1-y1);
        int minx2 = min(x2, n+1-x2);
        int miny2 = min(y2, n+1-y2);
 
        int aro1 = min(minx1,miny1);
        int aro2 = min(minx2, miny2);
 
        int dif = abs(aro1 - aro2);
 
        cout << dif << endl;
 
    }
        
}