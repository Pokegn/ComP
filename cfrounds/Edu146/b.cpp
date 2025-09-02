#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0)->sync_with_stdio(false);
 
    int t; cin >> t;
 
    for (int i=0; i<t; i++){
        long long int a,b; cin >> a >> b;
        long long int min = a+b, x, y, z;

        for(int j=1; j<50000; j++){
            x = j-1;
            x += floor(a/(j)) + floor(b/j);
            if(a%j !=0) x+=1;
            if(b%j !=0) x+=1;

            if (min > x) min = x;
        }
        cout << min << endl;
    }
}