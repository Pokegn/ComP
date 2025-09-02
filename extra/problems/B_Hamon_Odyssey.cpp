#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0)->sync_with_stdio(false);
 
    int t; cin >> t;
 
    for (int uuu=0; uuu<t; uuu++){
        int n; cin >> n;
        vector<int> a(n);
        for(int i=0; i<n; i++) cin >> a[i];

        int i=0;
        int curr=a[0];
        int count=1;

        while(i<n-1){
            if(curr!=0){
                curr=curr&a[i+1];
            }
            else{
                count++;
                curr=a[i+1];
            }
            i++;
        }
        
        if(curr!=0 and count!=1) count--;
        cout << count << endl;
    }
}