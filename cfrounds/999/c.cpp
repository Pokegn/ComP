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
#define pb push_back
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}
#define MOD 998244353

void solve(){
    lli n; cin >> n;
    vlli a(n); forn(i,0, n) cin >> a[i];

    vector<bool> despde(n+1, false);
    vlli lasti(n+1, n-1);
    vlli cant(n+1, 0);
    lli curr = 0;

    if(a[0]!=0){
        lasti[0] = 0;
        despde[0] = true;
        curr++;
    }

    forn(i, 1, n){
        if(a[i] == curr) continue;

        if(curr>0 && despde[curr-1] == true){
            if(lasti[curr-1] == i-1){
                cout << 0 << nl;
                return;
            }
        }

        lasti[curr] = i-1;
        if(a[i] != curr+1){
            despde[curr] = true;
            lasti[curr] = i;
        }
        curr++;
    }
    lasti[curr] = n-1;
    lli ultimo = curr;

    cant[0] = lasti[0]+1;
    forn(i, 1, n){
        cant[i] = lasti[i]-lasti[i-1];
    }

    // cout << cant[0] << nl;
    // return;

    lli lastans1 = 1, lastans2 = 0;
    lli lasti1 = -2, lasti2 = -2;
    forn(i, 0, n){
        //cout << lastans1+lastans2 << ' ';
        if(cant[i]==0) continue;
        if(cant[i+1] == 0){
            if(despde[i] == false){
                lli temp1 = lastans1+lastans2;
                if(lasti[i]-lasti1 > 1) temp1+=lastans1;
                if(lasti[i]-lasti2 > 1) temp1+=lastans2;


                lastans1 = temp1%MOD;
                lastans2 = 0;
                lasti1 = lasti[i];
                lasti2 = lasti[i]+1;
            } //klaldkjsad
            else{
                lli temp = 0;
                if(lasti[i]-lasti1 > 1) temp+=lastans1;
                if(lasti[i]-lasti2 > 1) temp+=lastans2;

                lastans1 = temp%MOD;
                lastans2 = 0;
                lasti1 = lasti[i];
                lasti2 = -1;
            }
            continue;
        }

        if(despde[i] == true){
            lli temp = 0;
            if(lasti[i]-lasti1 > 1) temp+=lastans1;
            if(lasti[i]-lasti2 > 1) temp+=lastans2;

            lastans1 = temp%MOD;
            lastans2 = 0;
            lasti1 = lasti[i];
            lasti2 = -1;
        }

        else{
            lli temp1 = 0;
            lli temp2 = 0;
            if(lasti[i]-lasti1 > 1) temp1+=lastans1;
            if(lasti[i]-lasti2 > 1) temp1+=lastans2;
            
            if(lasti[i]+1-lasti1 > 1) temp2+=lastans1;
            if(lasti[i]+1-lasti2 > 1) temp2+=lastans2;

            lastans1 = temp1%MOD;
            lastans2 = temp2%MOD;
            lasti1 = lasti[i];
            lasti2 = lasti[i]+1;
        }

    }

    lli ans = lastans1+lastans2;
    cout << (ans+MOD)%MOD << nl;



}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}