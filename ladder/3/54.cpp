#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(false);

    int n,m,k; cin >> n >> m >> k;
    vector<vector<int>> mat(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> mat[i][j];
        }
    }
    vector<int> col(m);
    vector<int> fil(n);
    for(int i=0; i<m; i++){
        col[i]=i;
    }
    for(int i=0; i<n; i++){
        fil[i]=i;
    }

    char get;
    int t,x,y;
    for(int i=0; i<k; i++){
        cin >> get;
        cin >> x >> y;
        switch (get)
        {
        case 'g':
        cout << mat[fil[x-1]][col[y-1]]<< '\n';
        break;

        
        case 'c':
        t=col[x-1];
        col[x-1]=col[y-1];
        col[y-1]=t;
        break;


        case 'r':
        t=fil[x-1];
        fil[x-1]=fil[y-1];
        fil[y-1]=t;
        break;

        }
    }

}