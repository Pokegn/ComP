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

vector<lli> depth;
vlli parent;
vector<pair<lli, lli>> son;

void filldepth(lli pot, lli i, lli j){
    if(j==pot-1) return;
    lli extra = 1;
    extra<<=pot-1-j;
    filldepth(pot, i+1, j+1);
    parent[i+1] = i;
    son[i].first = i+1;

    filldepth(pot, i+extra, j+1);
    parent[i+extra] = i;
    son[i].second = i+extra;
}

void solve(){
    lli n, q; cin >> n >> q;
    vlli a(n, -1);
    forn(i, 1, n) cin >> a[i];
    vlli p(n); forn(i, 0, n) cin >>p[i];

    parent.assign(n, -1);
    son.assign(n, {-1, -1});
    lli temp = n;
    lli pot = 0;
    while(temp>0){
        temp/=2;
        pot++;
    }
    vector<bool> gut(n, true);
    filldepth(pot, 0, 0);
    lli howmanygut = n-1;

    forn(i, 1, n){
        if(p[parent[i]] != (lli)(p[i]/2)){
            gut[i] = false;
            howmanygut--;
        }
    }

    lli x, y;
    while(q--){
        cin >> x >> y;
        if(parent[x-1] != -1 && gut[x-1] == true) howmanygut--;
        if(parent[y-1] != -1 && gut[y-1] == true) howmanygut--;
        if((son[x-1].first != -1 && son[x-1].first != y-1) && gut[son[x-1].first] == true) howmanygut--;
        if((son[x-1].first != -1 && son[x-1].second != y-1) && gut[son[x-1].second] == true) howmanygut--;
        if((son[y-1].first != -1 && son[y-1].first != x-1) && gut[son[y-1].first] == true) howmanygut--;
        if((son[y-1].first != -1 && son[y-1].second != x-1) && gut[son[y-1].second] == true) howmanygut--;

        swap(p[x-1], p[y-1]);
        if(parent[x-1]>=0 && p[parent[x-1]] == (lli)(p[x-1]/2)){
            gut[x-1] = true;
            howmanygut++;
        }
        else gut[x-1] = false;

        if(son[x-1].first != -1){
            if(son[x-1].first != y-1){
                if(p[x-1] == (lli)(p[son[x-1].first]/2)){
                    gut[son[x-1].first] = true;
                    howmanygut++;
                }
                else gut[son[x-1].first] = false;
            }

            if(son[x-1].second != y-1){
                if(p[x-1] == (lli)(p[son[x-1].second]/2)){
                    gut[son[x-1].second] = true;
                    howmanygut++;
                }
                else gut[son[x-1].second] = false;
            }
        }

        if(parent[y-1]>=0 && p[parent[y-1]] == (lli)(p[y-1]/2)){
                gut[y-1] = true;
                howmanygut++;
        }
        else gut[y-1] = false;

        if(son[y-1].first != -1){
            if(son[y-1].first != x-1){
                if(p[y-1] == (lli)(p[son[y-1].first]/2)){
                    gut[son[y-1].first] = true;
                    howmanygut++;
                }
                else gut[son[y-1].first] = false;
            }
            
            if(son[y-1].second != x-1){
                if(p[y-1] == (lli)(p[son[y-1].second]/2)){
                    gut[son[y-1].second] = true;
                    howmanygut++;
                }
                else gut[son[y-1].second] = false;
            }
        }


        if(howmanygut == n-1) cout << "YES" << nl;
        else cout << "NO" << nl;
    }
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}