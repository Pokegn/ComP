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

void solve(){
    lli n; cin >> n;
    vlli a(n); forn(i, 0, n) cin >> a[i];
    vvlli valores(n+1, vlli(0));
    forn(i, 0, n) valores[a[i]].push_back(i);

    vlli score(n, 0);
    forn(i, 1, n){
        score[i] = score[i-1];
        if(a[i]==a[i-1]) score[i]++;
    }

    lli sz;
    lli maxans = score[n-1];
    forn(i, 1, n+1){ //calcula la mayor respuesta checando cuando quitamos entre consecutivos
        sz = valores[i].size();
        forn(j, 1, sz){
            if(valores[i][j] == valores[i][j-1]+1) continue;
            maxans = max(maxans, score[n-1]-(score[valores[i][j]]-score[valores[i][j-1]])+1);
        }
    }

    lli maxquita = 0;
    lli lans, rans;
    forn(i, 1, n+1){ //checa el mayor rango cuando quitas entre consecutivos
        sz = valores[i].size();
        forn(j, 1, sz){
            if(valores[i][j] == valores[i][j-1]+1) continue;
            if(score[n-1]-(score[valores[i][j]]-score[valores[i][j-1]])+1 == maxans){
                if(maxquita < valores[i][j] - valores[i][j-1] - 1){
                    maxquita =  valores[i][j] - valores[i][j-1] - 1;
                    lans = valores[i][j-1]+1;
                    rans = valores[i][j]-1;
                }
            }
        }
    }

    if(maxans == score[n-1]){ //si no ocupas quitar entre consecutivos a fuerzas checa el mayor rango en el que quitar
        bool flag = true;
        lli l=0, r=0;
        forn(i, 0, n){
            flag = true;
            if(i>0 && a[i]==a[i-1]){
                flag = false;
            }
            if(i<n-1 && a[i]==a[i+1]){
                flag = false;
            }
            if(flag){
                r=i;
                cout << l << ' ' << r << nl;
                if(r-l+1 > maxquita){
                    rans = r;
                    lans = l;
                    maxquita = r-l+1;
                }
            }
            else{
                l = i+1;
                r = i+1;
            }
        }
    }

    if(maxquita == 0){
        cout << 0 << nl;
    }
    else{
        cout << lans+1 << ' ' << rans+1 << nl;
    }

}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}