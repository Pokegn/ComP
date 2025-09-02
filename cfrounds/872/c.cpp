#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0)->sync_with_stdio(false);
 
    int t; cin >> t;
 
    for (int i=0; i<t; i++){
        int n, m; cin >> n >> m;
        int x;
        int leftC=0, rightC=0;
        vector<int> asd(m,0);
        vector<int> a(0);
        for(int j=0; j<n; j++){
            cin >> x;
            if(x==-1) leftC+=1;
            else if(x==-2) rightC+=1;
            else asd[x-1]=1;
        }

        for(int j=0; j<m; j++){
            if(asd[j]==1) a.push_back(j+1);
        }

        int S=a.size();
        sort(a.begin(), a.end());
        
        int best=0;
        for(int j=0; j<S; j++){
            best=max(best, (S+min(a[j]-1-j, leftC)+min(m-a[j]-(S-1-j), rightC)));
        }
        best=max(min(m, leftC+S), best);
        best=max(min(m, rightC+S), best);

        cout << best << endl;
    }
}