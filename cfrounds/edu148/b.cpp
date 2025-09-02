#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0)->sync_with_stdio(false);
 
    int t; cin >> t;
 
    for (int i=0; i<t; i++){

        int n,k; cin >> n >> k;
        vector<int> v(n);
        long long int ans=0;
        for(int j=0; j<n; j++){
            cin >> v[j];
        }

        sort(v.begin(), v.end());

        int left=2*k-1;
        int right=n-1;
        long long int sum=0;
        for(int j=0; j<2*k; j++){
            sum+=v[j];
        }
        ans=sum;
        for(int j=0; j<k; j++){
             sum-=(v[left]+v[left-1]);
             sum+=v[right];
             left-=2; right-=1;
             if(sum<ans) ans=sum;
        }

        long long int total=0;
        for(int j=0; j<n; j++){
            total+=v[j];
        }

        ans=total-ans;

        cout << ans << endl;
    }
}