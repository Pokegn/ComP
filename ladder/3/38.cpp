#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int a,b,c; cin >> a >> b >> c;
    cout << (sqrt(a*b/c) + sqrt(a*c/b) + sqrt(b*c/a))*4;
}