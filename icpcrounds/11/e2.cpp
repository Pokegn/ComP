#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
using ll = long long;
using vi = vector<int>;
using vlli = vector<ll>;
using vvi = vector<vi>;
using vvlli = vector<vlli>;
#define forn(i, a, b) for(lli i = a; i < b; i++)
#define rof(i, a, b) for(lli i = a; i >= b; i--)
#define nl '\n'
#define pb push_back
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    ll n; cin >> n;
    vector<string> a(n);
    ll count = 0;
    for(int i=0; i<n; i++){
        cin >> a[i];
        for(int j=0; j<2*n-1; j++){
            if(a[i][j] == 'C') count++;
        }
    }
    vector<string> original(n);
    for(int i=0; i<n; i++) original[i] = a[i];

    if(count%2 == 1){
        cout << "impossible" << nl;
        return;
    }

    if(n==2){
        if(a[0] == "#C#"){
            if(a[1] == "CCC"){
                cout << "impossible" << nl;
                return;
            }
        }
    }

    ll curr = 0;
    for(int c=0; c<=2*n-2; c++){
        if(a[n-1][c] == 'C') curr++;
    }
    if(curr<=count/2){
        for(int c=0; c<=2*n-2; c++){
            a[n-1][c] = 'A';
        }
        for(int r = n-2; r>=0; r--){
            ll dmax = r;
            for(int d = dmax; d>0; d--){
                if(a[r][n-1+d] == 'C') curr++;
                if(curr>count/2){
                    a[r][n-1+d] = 'B';
                }
                else{
                    a[r][n-1+d] = 'A';
                }

                if(a[r][n-1-d] == 'C') curr++;
                if(curr>count/2){
                    a[r][n-1-d] = 'B';
                }
                else{
                    a[r][n-1-d] = 'A';
                }
            }
   
            if(a[r][n-1] == 'C') curr++;
            if(curr>count/2){
                a[r][n-1] = 'B';
            }
            else{
                a[r][n-1] = 'A';
            }
        }
        for(int i=0; i<n; i++){
            cout << a[i] << nl;
        }
        return;
    }

    curr = 0;
    for(int r = n-1; r>0; r--){
        if(a[r][n-1-r] == 'C') curr++;
        if(a[r][n-1-r+1] == 'C') curr++;
    }
    if(a[0][n-1] == 'C') curr++;

    if(curr<=count/2){
        for(int r = n-1; r>0; r--){
            a[r][n-1-r] ='A';
            a[r][n-1-r+1] = 'A';
        }
        a[0][n-1] = 'A';

        for(int c=2; c<n; c++){
            for(int r = n-1-c+2; r<=n-1; r++){
                if(a[r][c] == 'C') curr++;
                if(curr <= count/2) a[r][c] = 'A';
                else a[r][c] = 'B';
            }
        }
        for(int c=n; c<=2*n-2; c++){
            for(int r = c-n+1; r<=n-1; r++){
                if(a[r][c] == 'C') curr++;
                if(curr <= count/2) a[r][c] = 'A';
                else a[r][c] = 'B';
            }
        }

        for(int i=0; i<n; i++){
            cout << a[i] << nl;
            
        }
        return;
    }

    for(int i=0; i<n; i++){
        reverse(a[i].begin(), a[i].end());
    }

    curr = 0;
    for(int r = n-1; r>0; r--){
        if(a[r][n-1-r] == 'C') curr++;
        if(a[r][n-1-r+1] == 'C') curr++;
    }
    if(a[0][n-1] == 'C') curr++;

    if(curr<=count/2){
        for(int r = n-1; r>0; r--){
            a[r][n-1-r] ='A';
            a[r][n-1-r+1] = 'A';
        }
        a[0][n-1] = 'A';

        for(int c=2; c<n; c++){
            for(int r = n-1-c+2; r<=n-1; r++){
                if(a[r][c] == 'C') curr++;
                if(curr <= count/2) a[r][c] = 'A';
                else a[r][c] = 'B';
            }
        }
        for(int c=n; c<=2*n-2; c++){
            for(int r = c-n+1; r<=n-1; r++){
                if(a[r][c] == 'C') curr++;
                if(curr <= count/2) a[r][c] = 'A';
                else a[r][c] = 'B';
            }
        }

        for(int i=0; i<n; i++) reverse(a[i].begin(), a[i].end());
        for(int i=0; i<n; i++){
            cout << a[i] << nl;
            
        }
        return;
    }

    cout << "impossible" << nl;
    return;

}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}