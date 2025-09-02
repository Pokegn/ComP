#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){
    ll n; cin >> n;
    vector<ll> d(n+1, 0);
    vector<ll> e(n+1, 0);
    for(int i=1; i<n; i++) cin >> e[i]; //verticales, y unen i e i+1
    for(int i=1; i<n; i++) cin >> d[i]; //horizontales, x

    //for(int i=0; i<n; i++) cout << e[i]<<' ';
    //return;

    vector<ll> dcoor(n+1, 0);
    for(int i=2; i<=n; i++){
        dcoor[i] = dcoor[i-1]+d[i-1];
    }

    vector<ll> ecoor(n+1, 0);
    for(int i=2; i<=n; i++){
        ecoor[i] = ecoor[i-1]+e[i-1];
    }

    vector<ll> closest1l(n+1, 1e10); //la distancia a la calle mas cercana con 1
    vector<ll> closest1r(n+1, 1e10);
    vector<ll> closest1u(n+1, 1e10);
    vector<ll> closest1d(n+1, 1e10);

    for(int i=2; i<=n; i++){ 
        closest1l[i] = closest1l[i-1]+1;
        if(e[i-1]==1) closest1l[i] = 1;
    }
    for(int i=n-1; i>=1; i--){
        closest1r[i] = closest1r[i+1]+1;
        if(e[i]==1) closest1r[i] = 1;
    }
    
    for(int i=2; i<n+1; i++){
        closest1d[i] = closest1d[i-1]+1;
        if(d[i-1]==1) closest1d[i] = 1;
    }
    for(int i=n-1; i>=1; i--){
        closest1u[i] = closest1u[i+1]+1;
        if(d[i]==1) closest1u[i] = 1;
    }
    // for(int i=1; i<=n; i++){
    //     cout << closest1l[i] << ' ' << closest1r[i] << '\n';
    // }

    ll q; cin >> q;
    while(q--){
        ll ax,ay,bx,by; cin >> ax >> ay >> bx >> by; 
        ll dif = abs(ax-bx) - abs(ay-by);
        ll ans = abs(ecoor[ax]-ecoor[bx])+abs(dcoor[ay]-dcoor[by]);
 
        ll desviaciones = abs(abs(ax-bx) - abs(ay-by))/2;
        if(desviaciones == 0){
            cout << ans << '\n';
            continue;
        }
        ll maxx = max(ax, bx);
        ll minx = min(ax, bx);
        ll maxy = max(ay, by);
        ll miny = min(ay, by);
        
        if(abs(ax-bx) < abs(ay-by)){
            if(ecoor[maxx]-ecoor[minx]<5*(maxx-minx)){
                cout << ans+2*desviaciones << '\n';
                continue;
            }
            
            ll mindis = min(closest1l[minx], closest1r[maxx]);
            // cout << desviaciones << ' ' << mindis << '\n';
            // cout << minx << ' ' << maxx << '\n';
            // cout << closest1r[maxx] << ' ' << closest1l[minx] << '\n';
            
            
            if(desviaciones-mindis+1 > 0){
                cout << ans+10*(mindis-1)+2*(desviaciones-mindis+1) << '\n';
                continue;
            }
            else cout << ans+10*desviaciones << '\n';
            continue;
        }
        else{
            if(dcoor[maxy]-dcoor[miny]<5*(maxy-miny)){
                cout << ans+2*desviaciones << '\n';
                continue;
            }

            ll mindis = min(closest1u[maxy], closest1d[miny]);
            
            if(desviaciones-mindis+1 > 0){
                cout << ans+10*(mindis-1)+2*(desviaciones-mindis+1) << '\n';
                continue;
            }
            else cout << ans+10*desviaciones << '\n';
            continue;
        }
    }

}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}