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

vector<long double>x,y;

long double areaT(int a, int b, int c){
    return abs(x[a]*y[b]-x[b]*y[a]
    +x[b]*y[c]-x[c]*y[b]
    +x[c]*y[a]-x[a]*y[c])/2;
}

bool fitsin(int p, int q, int x){
    if(p==q){
        if(x!=p){
            return false;
        }
        return true;
    }
    if(p<q){
        if(x<=q){
            if(x>=p) return true;
            return false;
        }
        return false;
    }
    else{
        return !fitsin(q+1, p-1, x);
    }
}

void solve(){
    ll n,m; cin >> n >> m;
    x = vector<long double>(n+1); y = vector<long double>(n+1);
    vector<pair<ll, ll>> z;
    for(int i=0; i<n; i++){
        cin >> x[i] >> y[i]; //vertices en orden
    }
    x[n] = x[0];
    y[n] = y[0];
    ll xi,yi;
    for(int i=0; i<m; i++){
        cin >> xi >> yi;
        z.push_back({xi-1,yi-1});
        z.push_back({yi-1, xi-1});
    }
    sort(z.begin(), z.end()); //popcorners

    ll areatotal = 0;
    for(int i=0; i<n; i++){
        areatotal+=x[i]*y[i+1];
        areatotal-=x[i+1]*y[i];
    }
    areatotal = abs(areatotal)/2;
                                                                                    //cout << "area " << areatotal << endl;
    int vera = 0;
    int verb = 1;
    long double currA = 0;
    vector<int> reach(n);
    while(currA*2<=areatotal){
        currA += areaT(vera, verb, (verb+1)%n);
        verb++;
    }
    verb--;
    currA -= areaT(vera,verb,(verb+1)%n); //mayor poligono con vertice en 0 y area menor a A/2
    reach[0] = verb; //el mayor empieza en 0, y se va en ese orden hasta verb

    while(vera+1<n){
        currA -= areaT(vera, vera+1, verb);
        vera++;
        while(currA*2<=areatotal){
            currA += areaT(vera, verb, (verb+1)%n);
            verb++;
            verb%=n;
        }
        verb--;
        verb=(verb+n)%n;
        currA -= areaT(vera,verb,(verb+1)%n); //mayor poligono con vertice en vera y area menor a A/2
        reach[vera] = verb; //el mayor empieza en vera, y se va en ese orden hasta verb
    }

                                                                    // cout << "reach" << endl;
                                                                    // for(int i=0; i<n; i++) cout << i << ' ' << reach[i] << endl;
                                                        

    vector<pair<ll, ll>> z2; //filtrar a los que se pasan de la mitad del area
    // if(fitsin(4, reach[4], 1)) cout << "fitsin 4 1 " << endl;
    // if(fitsin(1, reach[1], 4)) cout << "fitsin 1 4 " << endl;

    for(auto pr: z){
        ll f = pr.first, s = pr.second;
        if(!fitsin(f, reach[f], s)) continue;
        z2.push_back({f, s});
    }   
    vector<pair<ll, ll>> pairs; //las parejas de lados de manera que no se contengan ni madres asi menos posiblemente la ultima

                                                                    // cout << "z2" << endl;
                                                                    // for(auto x: z2){
                                                                    //     cout << x.first << ' ' << x.second << endl;

                                                                    // }

    pairs.push_back(z2[0]);
    for(int i=1; i<z2.size(); i++){ //filtrar a los que estan contenidos en el anterior
        auto pr = z2[i];
        ll f = pr.first, s = pr.second;

        if(fitsin(z2[i-1].first, z2[i-1].second, z2[i].first) && fitsin(z2[i-1].first, z2[i-1].second, z2[i].second)) continue;
        pairs.push_back({f, s});
    }   

                                                                    // cout << "pairs";
                                                                    // cout << endl;
                                                                    // for(auto x: pairs){
                                                                    //     cout << x.first << ' ' << x.second << endl;

                                                                    // }
    currA = 0;
    vera = pairs[0].first;
    verb = pairs[0].second;
    for(int i=(pairs[0].first+1)%n; (n+i+1)%n<=pairs[0].second; i++){
        currA+=areaT(pairs[0].first, i, i+1);
    }
    long double ans = currA;

    //cout << "starting currA: " << currA << endl;

    for(int i=1; i<pairs.size(); i++){
        while(verb!=pairs[i].second){
            currA += areaT(vera, verb, (verb+1)%n);
            verb++;
            verb%=n;
            //cout << "a " << verb << ' ' << pairs[i].second;
        }
        while(vera!=pairs[i].first){
            currA -= areaT(vera, (vera+1)%n, verb);
            vera++;
            vera%=n;
            //cout << "b";
        }
        ans = max(currA, ans);
    }

    cout << setprecision(11) << ans << endl;


}

int main(){
    //cin.tie(0)->sync_with_stdio(false);
    ll t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}