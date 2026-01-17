#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
using ll = long long int;
using vi = vector<int>;
using vlli = vector<ll>;
using vvi = vector<vi>;
using vvlli = vector<vlli>;
#define forn(i, a, b) for(ll i = a; i < b; i++)
#define rof(i, a, b) for(ll i = a; i >= b; i--)
#define nl '\n'
#define endl '\n'
#define pb push_back
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    ll n, k; cin >> n >> k;
    if(k%2 == 1){
        for(int i=0; i<k; i++) cout << n << ' ';
        cout << endl;
    }
    else{
        vector<ll> ans(k, 0);
        ll curr = k-1;
        ll sb = 1<<(63 - __builtin_clzll(n));
        vector<ll> malardo(k, 0);

        for(ll i = sb; i>0; i/=2){
            if((n&i)>0){ //si es un 1

                if(curr>=0){  //el que quiero hacer malardo
                    for(int j=0; j<k; j++){ //todos se prenden
                        ans[j]+=i;
                    }
                    ans[curr]-=i; //menos el i
                    malardo[curr] = 1; //el i ahora es malardo
                    curr--;
                    //for(int j = 0; j<k; j++) cout << ans[j] << endl;
                }

                else{ //si ya todos son malardos nomas me agarro k-1 y les pongo un 1
                    for(int j=0; j<k-1; j++){
                        ans[j]+=i;
                    }
                }

            }
            else{ //es 0
                ll malos = 0;
                for(int j=0; j<k; j++){
                    if(malardo[j] == 1){
                        ans[j]+=i;
                        malos++;
                    }
                }
                if(malos%2 == 1) ans[k-1]-=i;
            }

        }
        
        for(int i=0; i<k; i++){
            cout << ans[i] << ' ';
        }
        cout << endl;
        return;
    }
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}