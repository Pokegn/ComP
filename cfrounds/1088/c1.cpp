#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
#define rep(i, a, b) for(int i=a; i<(b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define endl '\n'
#define pb push_back
typedef long long ll;
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    int n, k; cin >> n >> k;
    vector<int> a(n); rep(i, 0, n) cin >> a[i];
    vector<int> b(n); rep(i, 0, n) cin >> b[i];
    //bool ciclo = true;
    vector<bool> ciclo(k, true);
    rep(i, 0, k){
        for(int j = i+k; j<n; j+=k){
            if(a[j] != a[j-k]) ciclo[i] = false;
        }
    } //los que no estan en ciclo o si

    rep(i, 0, n){ //los que no son ciclo
        if(ciclo[i%k]) continue;
        if(b[i]!=-1 && a[i]!=b[i]){
            cout << "NO" << endl;
            return;
        }
    }

    vector<int> cicrep(n+1, 0);
    rep(i, 0, k){
        if(ciclo[i]){
            cicrep[a[i]]++;
        }
    }

    vector<int> c(k, -1);
    //cout << "xd";
    rep(i, 0, n){ //cada valor que si es ciclo debe tener un valor de -1 o ya asignado
        if(!ciclo[i%k]) continue;
        if(b[i] != -1){
            if(c[i%k]!=-1 && c[i%k]!=b[i]){
                //cout << "xd";
                cout << "NO" << endl;
                return;
            }
            c[i%k] = b[i];
        }
    } //ya tengo que debe valer cada uno


    vector<int> ccount(n+1, 0);
    rep(i, 0, k){
        if(ciclo[i] && c[i]!=-1) ccount[c[i]]++;
    }
    
    rep(i, 0, n+1){
        if(ccount[i] > cicrep[i]){
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
    return;
    

    //una permutacion de los primeros cic1, y otra es de los siguientes cic2
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}