#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
using ll = long long;
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
    vector<vector<ll>> permutations;
    
    for(int i=1; i<=8; i++){
        permutations.push_back({0,i});
    }
    for(int xd =0; xd<7; xd++){
        vector<vector<ll>> newperm(0, vector<ll>(0));
        for(auto v: permutations){
            vector<ll> present(9, 0);
            for(auto x: v){
                present[x] = 1;
            }
            v.push_back(0);
            ll sz = v.size();
            for(int i=1; i<=8; i++){
                if(present[i]!=1){
                    v[sz-1] = i;
                    newperm.push_back(v);
                }
            }
        }
        permutations = newperm;
    }

    vector<long double> a(9, 0.0);
    vector<long double> b(9, 0.0);
    //cout << endl;
    for(int i=1; i<=8; i++){
        cin >> a[i] >> b[i];
        //cout << a[i] << ' ' << b[i] << endl;
    }
    //return;



    long double ans = 0;
    for(auto v: permutations){
        vector<long double> prob1(9, 0);
        vector<long double> prob2(9, 0);
        vector<long double> prob3(9, 0);

        ll p1 = 1, p2 = 2;
        prob1[v[p1]] = (a[v[p1]])/(a[v[p1]]+b[v[p2]]); //probabilidades de que sigan vivos despues de cuartos
        prob1[v[p2]] = 1-prob1[v[p1]];
        //cout << a[v[p1]] << ' ' << (a[v[p1]]+b[v[p2]]) << ' ' <<  prob1[v[p1]] << endl;
        p1 = 3, p2 = 4;
        prob1[v[p1]] = (a[v[p1]])/(a[v[p1]]+b[v[p2]]);
        prob1[v[p2]] = 1-prob1[v[p1]];
        p1 = 5, p2 = 6;
        prob1[v[p1]] = (a[v[p1]])/(a[v[p1]]+b[v[p2]]);
        prob1[v[p2]] = 1-prob1[v[p1]];
        p1 = 7, p2 = 8;
        prob1[v[p1]] = (a[v[p1]])/(a[v[p1]]+b[v[p2]]);
        prob1[v[p2]] = 1-prob1[v[p1]];

        

        p1 = 1, p2 = 3;
        prob2[v[p1]] += prob1[v[p1]]*prob1[v[p2]]*(a[v[p1]])/(a[v[p1]]+b[v[p2]]); //probabilidades de que sigan vivos despues de semis
        p1 = 1, p2 = 4;
        prob2[v[p1]] += prob1[v[p1]]*prob1[v[p2]]*(a[v[p1]])/(a[v[p1]]+b[v[p2]]); 
        p1 = 2, p2 = 3;
        prob2[v[p1]] += prob1[v[p1]]*prob1[v[p2]]*(a[v[p1]])/(a[v[p1]]+b[v[p2]]); 
        p1 = 2, p2 = 4;
        prob2[v[p1]] += prob1[v[p1]]*prob1[v[p2]]*(a[v[p1]])/(a[v[p1]]+b[v[p2]]); 
        p1 = 3, p2 = 1;
        prob2[v[p1]] += prob1[v[p1]]*prob1[v[p2]]*(b[v[p1]])/(b[v[p1]]+a[v[p2]]);
        p1 = 3, p2 = 2;
        prob2[v[p1]] += prob1[v[p1]]*prob1[v[p2]]*(b[v[p1]])/(b[v[p1]]+a[v[p2]]);
        p1 = 4, p2 = 1;
        prob2[v[p1]] += prob1[v[p1]]*prob1[v[p2]]*(b[v[p1]])/(b[v[p1]]+a[v[p2]]);
        p1 = 4, p2 = 2;
        prob2[v[p1]] += prob1[v[p1]]*prob1[v[p2]]*(b[v[p1]])/(b[v[p1]]+a[v[p2]]);
        

        p1 = 1, p2 = 3;   p1+=4; p2+=4;
        prob2[v[p1]] += prob1[v[p1]]*prob1[v[p2]]*(a[v[p1]])/(a[v[p1]]+b[v[p2]]); //probabilidades de que sigan vivos despues de semis
        p1 = 1, p2 = 4;   p1+=4; p2+=4;
        prob2[v[p1]] += prob1[v[p1]]*prob1[v[p2]]*(a[v[p1]])/(a[v[p1]]+b[v[p2]]); 
        p1 = 2, p2 = 3;   p1+=4; p2+=4;
        prob2[v[p1]] += prob1[v[p1]]*prob1[v[p2]]*(a[v[p1]])/(a[v[p1]]+b[v[p2]]); 
        p1 = 2, p2 = 4;   p1+=4; p2+=4;
        prob2[v[p1]] += prob1[v[p1]]*prob1[v[p2]]*(a[v[p1]])/(a[v[p1]]+b[v[p2]]); 
        p1 = 3, p2 = 1;   p1+=4; p2+=4;
        prob2[v[p1]] += prob1[v[p1]]*prob1[v[p2]]*(b[v[p1]])/(b[v[p1]]+a[v[p2]]);
        p1 = 3, p2 = 2;   p1+=4; p2+=4;
        prob2[v[p1]] += prob1[v[p1]]*prob1[v[p2]]*(b[v[p1]])/(b[v[p1]]+a[v[p2]]);
        p1 = 4, p2 = 1;   p1+=4; p2+=4;
        prob2[v[p1]] += prob1[v[p1]]*prob1[v[p2]]*(b[v[p1]])/(b[v[p1]]+a[v[p2]]);
        p1 = 4, p2 = 2;   p1+=4; p2+=4;
        prob2[v[p1]] += prob1[v[p1]]*prob1[v[p2]]*(b[v[p1]])/(b[v[p1]]+a[v[p2]]);
        
        
        

        vlli mitad1 = {1,2,3,4};
        vlli mitad2 = {5,6,7,8};
        for(auto x: mitad1){
            for(auto y: mitad2){
                p1 = x, p2 = y;
                prob3[v[p1]] += prob2[v[p1]]*prob2[v[p2]]*(a[v[p1]])/(a[v[p1]]+b[v[p2]]);
                p1 = y, p2 = x;
                prob3[v[p1]] += prob2[v[p1]]*prob2[v[p2]]*(b[v[p1]])/(b[v[p1]]+a[v[p2]]);
            }
        }

        ans = max(ans, prob3[1]);
        // cout << "Lista:" << endl;
        // for(auto x: prob1) cout << x << endl;
        // cout << endl;
        // for(auto x: prob2) cout << x << endl;
        // cout << endl;
        // for(auto x: prob3) cout << x << endl;
        // cout << endl;
        
        
    }
    cout << setprecision(11) << ans << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    ll t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}