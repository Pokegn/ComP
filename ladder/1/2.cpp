#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    bool x;
    int c;
    for(int i=0; i<25; i++){
        cin >> x;
        if (x==1) c=i+1;
    }
    int a,b;
    a=ceil(c/double(5));
    b=(c-1)%5 +1;

    cout << abs(a-3) + abs(b-3);
}