#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; 
    for(int i=0; i<t; i++){
        int n, m; cin >> n >> m;
        vector<vector<int>> g(n, (m));
        vector<int> curr(0);
        int sum=0;
        int ans=0;

        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                cin >> g[j][k];
            }
        }

        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                if(g[j][k]!=0){
                    if(curr.size==0 or g[j][k-1]==0){

                    }
                    curr.push_back(k);
                    sum+=g[j][k];
                }
                if(g[j][k]==0){
                    curr.clear();
                    for(int a=0; a<curr.size(), a++){
                        g[j][curr[a]]=sum;
                    }
                    if(ans<sum) ans=sum;
                }
            }
            curr.clear();
        }
    }
}