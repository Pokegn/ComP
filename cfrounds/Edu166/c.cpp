#include <bits/stdc++.h>
using namespace std;
template <typename T, int D>
struct Vector : public vector<Vector<T, D - 1>> {
    static_assert(D > 0);
    template<typename... Args>
    Vector(int sz = 0, Args... args) : vector<Vector<T, D - 1>>(sz, Vector<T, D - 1>(args...)) {}
};
template <typename T>
struct Vector<T, 1> : public vector<T> {
    Vector(int sz = 0, const T& val = T()) : vector<T>(sz, val) {}
};

template <typename T>
struct Matrix : public vector<vector<T>> {
    Matrix(int hei = 0, int wid = 0, const T& val = T()) : vector<vector<T>>(hei, vector<T>(wid, val)) {}
};
using lli = long long int;
using vi = vector<int>;
using vlli = vector<lli>;
using vvi = vector<vi>;
using vvlli = vector<vlli>;
#define forn(i, a, b) for(int i = a; i < b; i++)
#define rof(i, a, b) for(int i = a; i >= b; i--)
#define nl '\n'
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

void solve(){
    lli n, m; cin >> n >> m;
    vlli prog(n+m+1); 
    vlli test(n+m+1);
    vlli a(n+m+1); 
    vlli b(n+m+1);
    forn(i, 0, n+m+1){
        cin >> a[i];
    }
    forn(i, 0, n+m+1){
        cin >> b[i];
    }


    lli proers;
    lli testers;
    proers = 0;
    testers = 0;
    forn(i, 0, n+m+1){ //1 es ser prog  y 2 es ser test

        if(proers == n+1){
            prog[i] = 2;
            testers++;
            continue;
        }
        if(testers == m){
            prog[i] = 1;
            proers++;
            continue;
        }

        if(a[i] > b[i]){
            prog[i] = 1;
            proers++;
            continue;
        }

        prog[i] = 2;
        testers++;

    }

    proers = 0;
    testers = 0;
    forn(i, 0, n+m+1){ //1 es ser prog  y 2 es ser test

        if(proers == n){
            test[i] = 2;
            testers++;
            continue;
        }
        if(testers == m+1){
            test[i] = 1;
            proers++;
            continue;
        }

        if(a[i] > b[i]){
            test[i] = 1;
            proers++;
            continue;
        }

        test[i] = 2;
        testers++;
    }

    vlli changestoprog(n+m+1, -1);
    vlli changestotest(n+m+1, -1);
    vlli couldbeaprog(n+m+1, -1);
    vlli couldbeatest(n+m+1, -1);
    vlli couldbebprog(n+m+1, -1);
    vlli couldbebtest(n+m+1, -1);

    forn(i, 0, n+m+1){
        if(test[i] == 1 && a[i]<b[i]) couldbebtest[i] == 1;
        if(test[i] == 2 && a[i]>b[i]) couldbeatest[i] == 1;
        if(prog[i] == 1 && a[i]<b[i]) couldbebprog[i] == 1;
        if(prog[i] == 2 && a[i]>b[i]) couldbeaprog[i] == 1;
    }

    lli curr = -1;
    rof(i, n+m, 0){
        if(curr == -1) continue;
        if(couldbebtest[i] == 1){
            curr = i;
            continue;
        }
        if(test[i] == 2) changestotest[i] = curr;
    }

    curr = -1;
    rof(i, n+m, 0){
        if(curr == -1) continue;
        if(couldbeatest[i] == 1){
            curr = i;
            continue;
        }
        if(test[i] == 1) changestotest[i] = curr;
    }

    curr = -1;
    rof(i, n+m, 0){
        if(curr == -1) continue;
        if(couldbeaprog[i] == 1){
            curr = i;
            continue;
        }
        if(prog[i] == 1) changestoprog[i] = curr;
    }

    curr = -1;
    rof(i, n+m, 0){
        if(curr == -1) continue;
        if(couldbebprog[i] == 1){
            curr = i;
            continue;
        }
        if(prog[i] == 2) changestoprog[i] = curr;
    }

    lli valueprog = 0;
    lli valuetest = 0;
    lli howmany1 = 0;
    lli howmany2 = 0;
    forn(i, 0, n+m+1){
        if(prog[i] == 2 && howmany2<=m+1){
            valueprog+=b[i];
            howmany2++;
            continue;
        }
        if(prog[i] == 1 && howmany1<=n){
            valueprog+=a[i];
            howmany1++;
        }
    }

    howmany1 = 0;
    howmany2 = 0;
    forn(i, 0, n+m+1){
        if(test[i] == 2 && howmany2<=m){
            valuetest+=b[i];
            howmany2++;
            continue;
        }
        if(test[i] == 1 && howmany1<=n+1){
            valuetest+=a[i];
            howmany1++;
        }
    }

    //cout << valueprog << ' ' << valuetest << nl;
    //forn(i, 0, n+m+1) cout << test[i] << ' ' << prog[i] << nl;
    forn(i, 0, n+m+1){
        if(test[i] != prog[i]){
            cout << valueprog - a[i] << ' ';
            continue;
        }
        if(prog[i] == 1){
            if(changestoprog[i] == -1){
                cout << valueprog - a[i] << ' ';
                continue;
            }
            cout << valueprog - a[i] + a[changestoprog[i]] - b[changestoprog[i]] << ' ';
            continue;
        }
        if(changestotest[i] == -1){
                cout << valuetest - b[i] << ' ';
                continue;
            }
        cout << valuetest - b[i] + b[changestotest[i]] - a[changestotest[i]] << ' ';
    }
    cout << nl;
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}