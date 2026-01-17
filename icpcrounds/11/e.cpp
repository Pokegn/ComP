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

    //intenta hacer de abajo arriba izq a derecha
    ll r = n-1;
    ll c = 0;
    ll curr = 0;
    //bool flag;
    for(ll r = n-1; r >=0; r--){
        for(ll c = (n-1)-r; c<= (2*n-2)-(n-1)+r; c++){ //de c = 0 a 
            if(a[r][c] == '#') continue;
            //flag = false;
            if(a[r][c] == 'C'){
                if(curr<count/2){
                    a[r][c] = 'A';
                }
                else{
                    a[r][c] = 'B';
                }
                curr++;
                
            }
            else{
                if(curr<count/2){
                    a[r][c] = 'A';
                }
                else a[r][c] = 'B';
            }
            
        }
    }

    ll rmala = -1;
    for(int i=1; i<n; i++){
        if(a[i][n-1+i] == 'B' && a[i][n-2+i] == 'A') rmala = i;
    }

    if(rmala == -1){
        for(int i=0; i<n; i++){
            cout << a[i] << nl;
        }
        return;
    }

    //cout <<rmala<< nl;
    //return;

    if(original[rmala][2*n-2-(n-1)+rmala] == '.'){ //si lo podemos nomas tomar todo
        a[rmala][2*n-2-(n-1)+rmala] = 'A';
        for(int i=0; i<n; i++){
            cout << a[i] << nl;
        }
        return;
    }
    // cout << "xd"; 
    // return;

    ll rcount = 0;
    for(int i=0; i<2*n-1; i++){
        if(original[rmala][i] == 'C') rcount++;
    }
    if(original[rmala][2*n-2] == 'C') rcount--; //ocupo agarrar rcount

    if(rmala != n-1){
        r = rmala;
        curr = 0;
        for(int i=r; i>=1; i--){
            c = n-1-i;
            if(original[r][c] == 'C'){
                if(curr<rcount){
                    a[r][c] = 'A';
                }
                else{
                    a[r][c] = 'B';
                }
                curr++;
                
            }
            else{
                if(curr<rcount){
                    a[r][c] = 'A';
                }
                else a[r][c] = 'B';
            }

            c = n-1+i;
            if(original[r][c] == 'C'){
                if(curr<rcount){
                    a[r][c] = 'A';
                }
                else{
                    a[r][c] = 'B';
                }
                curr++;
                
            }
            else{
                if(curr<rcount){
                    a[r][c] = 'A';
                }
                else a[r][c] = 'B';
            }
        }
        a[r][n-1] = 'B';

        for(int i=0; i<n; i++){
            cout << a[i] << nl;
        }
        return;
    }

    //ahora se que esta en la ultima fila alaberga
    //y que hay al menos 5 cuadritos ahi abajo
    //y que no jala agarrarme todo

    curr = 0;
    for(int i=2*n-2; i>=0; i--){
        r = n-1;
        c = i;
        if(original[n-1][c] == 'C'){
                if(curr<count/2){
                    a[r][c] = 'A';
                }
                else{
                    a[r][c] = 'B';
                }
                curr++;
                
            }
            else{
                if(curr<count/2){
                    a[r][c] = 'A';
                }
                else a[r][c] = 'B';
            }
    }

    if(a[n-1][0] != 'B' || a[n-1][1] != 'A'){
        for(int i=0; i<n; i++){
            cout << a[i] << nl;
        }
        return;
    }

    curr = 0;
    //viborita a la izquierda
    for(int i=0; i<n; i++) a[i] = original[i];
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

    for(int i=0; i<n; i++) a[i] = original[i];
    for(int i=0; i<n; i++) reverse(a[i].begin(), a[i].end());
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
            reverse(a[i].begin(), a[i].end());
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