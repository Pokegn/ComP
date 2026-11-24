#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i=a; i<(b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define fi first
#define se second
#define endl '\n'
#define pb push_back
typedef long double ld;
typedef vector<int> vi;

void solve(){
    freopen("NAME _CVRP_10_manual (1).txt", "r", stdin);
    
    int n = 0, cap = 0, depot = 1;
    string token;
    vector<pair<ld, ld>> coords;
    vi demand;

    while(cin >> token){
        if(token == "DIMENSION"){
            cin >> token >> n;
            coords.resize(n + 1);
            demand.resize(n + 1);
        } else if(token == "CAPACITY"){
            cin >> token >> cap;
        } else if(token == "NODE_COORD_SECTION"){
            rep(i, 0, n){
                int id; ld x, y;
                cin >> id >> x >> y;
                coords[id] = {x, y};
            }
        } else if(token == "DEMAND_SECTION"){
            rep(i, 0, n){
                int id, d;
                cin >> id >> d;
                demand[id] = d;
            }
        } else if(token == "DEPOT_SECTION"){
            cin >> depot;
            break;
        }
    }

    vector<vector<ld>> dist(n + 1, vector<ld>(n + 1, 0.0));
    rep(i, 1, n + 1){
        rep(j, 1, n + 1){
            dist[i][j] = hypot(coords[i].fi - coords[j].fi, coords[i].se - coords[j].se);
        }
    }

    vi clients;
    rep(i, 1, n + 1){
        if(i != depot) clients.pb(i);
    }
    sort(all(clients));

    ld best_cost = 1e18;
    vi best_perm;

    //Hacemos las (n-1)! permutaciones 
    do {
        ld current_cost = 0;
        int current_load = 0;
        int prev = depot;

        for(int u : clients){
            if(current_load + demand[u] > cap){
                // Regresar al depósito e iniciar nueva ruta
                current_cost += dist[prev][depot];
                prev = depot;
                current_load = 0;
            }
            current_cost += dist[prev][u];
            current_load += demand[u];
            prev = u;
        }
        current_cost += dist[prev][depot];

        if(current_cost < best_cost){
            best_cost = current_cost;
            best_perm = clients;
        }
    } while(next_permutation(all(clients)));

    cout << fixed << setprecision(5);
    cout << "Costo minimo total: " << best_cost << endl;

    int route_num = 1, load = 0, prev = depot;
    vi current_route = {depot};

    for(int u : best_perm){
        if(load + demand[u] > cap){
            current_route.pb(depot);
            cout << "Ruta #" << route_num++ << " (Carga: " << load << "/" << cap << "): ";
            rep(i, 0, sz(current_route)) cout << current_route[i] << (i + 1 < sz(current_route) ? " -> " : "");
            cout << endl;

            current_route = {depot};
            load = 0;
        }
        current_route.pb(u);
        load += demand[u];
    }
    current_route.pb(depot);
    cout << "Ruta #" << route_num << " (Carga: " << load << "/" << cap << "): ";
    rep(i, 0, sz(current_route)) cout << current_route[i] << (i + 1 < sz(current_route) ? " -> " : "");
    cout << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    auto start = chrono::high_resolution_clock::now();
    solve();
    auto end = chrono::high_resolution_clock::now();
    
    chrono::duration<double, milli> duration = end - start;
    cerr << "Tiempo de ejecucion: " << duration.count() << " ms" << endl;
    return 0;
}