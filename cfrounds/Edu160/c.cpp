#include <bits/stdc++.h>
using namespace std;



int greatpo(long long int v){
    int ans=0;
    while(v>0){
        ans++;
        v/=2;
    }
    return ans;
}

void solve(){
    int maxpo;
    long long int v;
    vector<int> po(60, 0);
    vector<int> povis(60, 0);
    for(int i=0; i<60; i++) po[i] = 0;
    int m; cin >> m;
    int ti;
    int weon;
    while(m--){
        cin >> ti >> v;
        if(ti == 1){
            po[v]+=1;
            for(int i=0; i<60; i++) if(po[i]>2){
                po[i]-=2;
                po[i+1]+=1;
            }
        }
        else{
            for(int i=0; i<60; i++) povis[i] = po[i];
            //cout << po[0] << ' ' << po[1] << ' ' << po[2] << '\n';
            if(v == 0){
                cout << "YES" << '\n';
                v=-1;
            }
            while(v>=0){
                if(v == 0){
                    cout << "YES" << '\n';
                    break;
                }
                weon = greatpo(v)-1;
                if(weon<0){
                    cout << "NO" << '\n';
                    break;
                }

                if(povis[weon] > 0){
                    v-=pow(2, weon);
                    povis[weon]--;
                    continue;
                }
                
                if(weon >= 1){
                    if(povis[weon-1] > 0){
                        if(povis[weon-1] > 1){
                            v-=pow(2, weon);
                            povis[weon-1]-=2;
                        }
                        else{
                            v-=pow(2, weon-1);
                            povis[weon-1]--;
                        }
                        //cout << v << '\n';
                        continue;
                    }
                }

                cout<<"NO"<< '\n';
                break;


            }
        }
    }
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}