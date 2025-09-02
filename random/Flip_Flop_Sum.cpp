//https://codeforces.com/contest/1774/problem/C
#include <iostream>
 
using namespace std;
 
int main(){
    int t,n,i;
    cin >> t;
    for(i=0; i<t; i++){
        cin >> n;
        if (n%2!=0){
            cout << -1 << endl;
        }
        else{
            cout << 1 << ' ' << n/2 << endl;
        }
    }
}