#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0)->sync_with_stdio(false);
 
    int t; cin >> t;
 
    for (int i=0; i<t; i++){
        string s1, s2; cin >> s1 >> s2;

        int s, q; cin >> s >> q;
        int sz = s1.size();
        vector<int> block(q,-1);
        int qt; //query type
        int time=0;
        bool isequal;
        int unequal=0;
        int x,y; 
        int pos1, pos2;
        
        for(int j=0; j<sz; j++){
            if(s1[j]!=s2[j]) unequal+=1;
        }

        for(int j=0; j<q; j++){
            cin >> qt;

            if(j>=s){
                if(block[j-s]!=-1){
                    if(s1[block[j-s]]!=s2[block[j-s]]) unequal+=1;
                }
            }

            if(qt==1){
                cin >> x;
                block[time]=x;
            }

            if(qt==2){
                cin >> x;
                cin >> y;
                if(x==1 and y==1){
                    if(s1[pos1]!=s1[pos2]){
                        if(s2[pos1]==s1[pos2]) unequal-=1;
                        if(s2[pos2]==s1[pos1]) une
                    }
                }
                if(x==1 and y==2){
                    
                }
                if(x==2 and y==1){
                    
                }
                if(x==2 and y==2){
                    
                }
            }

            if(qt==3){
                isequal=true;
                for(int j=0; j<sz; j++){
                    if(block[j]>=time-s && s1[i]!=s2[i]) isequal=false;
                }
                if(isequal) cout << "YES";
                else cout << "NO";
            }
            time+=1;
        }
    }
}