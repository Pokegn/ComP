#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int n, m; cin >> n >> m; // n students, m subjects
    vector<vector<char>> a(n, vector<char>(m));
    vector<pair<char, int>> cali(n);
    set<int> suc;
 
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];
            //cout << a[i][j] << ' ';
        }
        //cout << endl;
        
    }
 
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cali[j].first=a[j][i];
            cali[j].second=j;
        }
 
        sort(cali.begin(), cali.end(), greater<>());
        char f=cali[0].first;
        for(int j=0; j<n; j++){
            if(cali[j].first==f){
                suc.insert(cali[j].second); 
                //cout << cali[j].first << ' ';
            }
        }
        //cout << endl;
 
    }
 
    cout << suc.size();
}