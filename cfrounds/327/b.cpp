#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
#define rep(i, a, b) for(int i=a; i<(b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define endl '\n'
#define pb push_back
#define fi first
#define se second
typedef long double ld;
typedef long long ll;
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

ld x1,x2,yi,y2,vmax,t,vx,vy,wx,wy;
pair<ld, ld> dist(ld time){
    //cout << "llamada con " << time << endl;
    pair<ld, ld> ret;
    if(time < t){
        ret.fi = (time)*vx;
        ret.se = (time)*vy;
    }
    else{
        ret.fi = t*vx;
        ret.se = t*vy;
        ret.fi += (time-t)*wx;
        ret.se += (time-t)*wy;
    }
    //cout << ret.fi << ' ' << ret.se << endl;
    return ret;
}

bool able(ld time){
    ld x = x2-(x1+dist(time).fi);
    ld y = y2-(yi+dist(time).se);
    ld ti = (x*x+y*y)/(vmax*vmax);
    //cout << x << ' ' << y << endl;
    ti = sqrt(ti);
    if(ti > time) return false;
    return true;
}

void solve(){
    cin >> x1 >> yi >> x2 >> y2;
    cin >> vmax >> t;
    cin >> vx >> vy >> wx >> wy;
    ld l = 0;
    ld r = 1e8;
    ld eps = 0.0000000001;
    // if(able(4.0)) cout << "xd";
    // else cout <<"no lil bro";
    // return;
    while(r-l > eps){
        ld m = (l+r)/2;
        if(able(m)){
            r = m;
        }
        else l = m;
    }
    cout << fixed << setprecision(8) << l << endl;
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    //cin >> t;
    while(t--) solve();
    return 0;
}