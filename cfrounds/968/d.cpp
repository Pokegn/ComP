#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
using lli = long long int;
using vi = vector<int>;
using vlli = vector<lli>;
using vvi = vector<vi>;
using vvlli = vector<vlli>;
#define forn(i, a, b) for(lli i = a; i < b; i++)
#define rof(i, a, b) for(lli i = a; i >= b; i--)
#define nl '\n'
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    lli n, m; cin >> n >> m;
    lli li;
    lli xd;
    vvlli a(n, vlli (0));
    forn(i, 0, n){
        cin >> li;
        forn(j, 0, li){
            cin >> xd;
            a[i].push_back(xd);
        }
        sort(a[i].begin(), a[i].end());
    }

    vector<pair<lli, lli>> huecos(n, {-1,-1});
    forn(i, 0, n){
        lli j = 0; //indice
        lli k = 0; //entero
        lli sz = a[i].size();
        while(huecos[i].second == -1){
            if(j>=sz){
                if(huecos[i].first == -1){
                    huecos[i].first = k;
                    huecos[i].second = k+1;
                }
                else{
                    huecos[i].second = k;
                }
                continue;
            }

            if(a[i][j] > k){
                if(huecos[i].first == -1) huecos[i].first = k;
                else huecos[i].second = k;
                k++;
                continue;
            }

            if(a[i][j] == k) k++;
            j++;
        }   
    }


    sort(huecos.begin(), huecos.end());
    map<lli, lli> ans;
    lli minans = 0;
    map<lli, bool> vis;

    forn(i, 0, n){
        minans = max(minans, huecos[i].first);
        if(vis[huecos[i].first]){   
            minans = max(minans, huecos[i].second);
            vis[huecos[i].second] = true;
        } 
        vis[huecos[i].first] = true;
    }
    rof(i, n-1, 0){
        ans[huecos[i].first] = max(ans[huecos[i].first], huecos[i].second);
        if(ans[huecos[i].second] > 0){
            ans[huecos[i].first] = max(ans[huecos[i].first], ans[huecos[i].second]);
        }
    }

    lli res = 0;
    res+=minans*minans;
    res-=((minans-1)*minans)/2;
    res+=(m*(m+1))/2;
    // cout << res << nl;
    // return;

    if(minans >= m){
        res = minans*(m+1);
    }
    cout << ans[0] << ' ' << ans[1] << nl;


    map<lli, bool> checado;
    forn(i, 0, n){
        lli ind = huecos[i].first;
        if(checado[ind] == true) continue;
        if(ind>=minans){
            res-=ind;
        }
        else res-=minans;
        res+= max(minans, ans[ind]);
        checado[ind] = true;
        //cout << ind << ' ' <<  ans[ind] << nl;
    }

    cout << res << nl;
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}