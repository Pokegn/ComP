#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0)->sync_with_stdio(false);
 
    int t; cin >> t;
 
    for (int i=0; i<t; i++){
        int n; cin >> n;
        int b[n];
        int daysnodoc = 0;
        int avis = 0;
        int unos = 0;
        for(int j=0; j<n; j++){
            cin >> b[j];
            if (b[j] == 2){
                int x = ceil((unos-1)/2);
                avis = min(1+x,unos);
            }
            else{
                avis +=1;
                unos+=1;
            }
        }
        cout << avis << endl;
    }
}