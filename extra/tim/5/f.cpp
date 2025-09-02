#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
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
#define forn(i, a, b) for(lli i = a; i < b; i++)
#define rof(i, a, b) for(lli i = a; i >= b; i--)
#define nl '\n'
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

vector<vector<lli>> grafo;

void solve(){
    lli N; cin >> N;
	grafo.assign(N+1, {});
    vector<lli> negros(0);
    vector<lli> blancos(0);

	for(lli i = 0; i < N-1; i++) {
		lli u, v; cin >> u >> v;
		grafo[u].push_back(v);
		grafo[v].push_back(u);
	}
    
    if(N == 1){
        cout << 1 << nl << 1 << nl;
        return;
    }
    if(N == 2){
        cout << 1 << ' ' << 2 << nl << 1 << ' ' << 2 << nl;
        return;
    }
    
	vector<bool> bfs_vis(N+1, false);
	queue<lli> bfs; bfs.push(1); bfs_vis[1] = true;
	lli depth = 0;
	while(!bfs.empty()) {
		lli bfssz = bfs.size();
		while(bfssz--) {
			lli u = bfs.front();
            if(depth %2 == 0) blancos.push_back(u);
            else negros.push_back(u);
			bfs.pop();

			for(lli v : grafo[u])
				if(!bfs_vis[v]) {
					bfs.push(v);
					bfs_vis[v] = true;
				}
		}
		depth++;
	}

    lli esblanco = 0;
    lli grande = 0;
    lli chico1 = 0;
    lli chico2 = 0;
    lli x = blancos.size();
    lli y = negros.size();
    bool flag = false;
    for(lli k=0; k<x; k++){
        if(__gcd(y, x-k)==1 && __gcd(y, k)==1){ //esblanco 1 signficia negros son grande
            esblanco = 1;
            grande = y;
            chico1 = min(k, x-k);
            chico2 = max(k, x-k);
            flag = true;
        } 
    }
    for(lli k=0; k<y; k++){
        if(__gcd(y-k, x)==1 && __gcd(x, k)==1){ //grande son blancos
            esblanco = 0;
            grande = x;
            chico1 = min(k, y-k);
            chico2 = max(k, y-k);
            flag = true;
        } 
    }

    if(flag == false){
        while(true){
            negros[1000] = 0;
        } 
        negros[1000] = 0;
        cin >> negros[1000];
    }

    //cout << grande << ' ' << chico1 << ' ' << chico2 << nl;

    lli bi = 0;
    lli ni = 0;
    vector<lli> a(N+1, 0);
    vector<lli> perm(N+1, 0);


    // if(chico1 == 0 || chico2 == 0){
    //     forn(i, 1, x+1){
    //         a[i] = blancos[i-1];
    //         perm[i] = i-1;
    //     }
    //     perm[1] = x;



    //     forn(i, 1, y+1){
    //         a[i+x] = negros[i-1];
    //         perm[i+x] = x+i-1;
    //     }
    //     perm[1+x] = N;



    //     forn(i, 1, N+1) cout << a[i] << ' ';
    //     cout << nl;
    //     forn(i, 1, N+1) cout << perm[i] << ' ';
    //     cout << nl;
    //     return;
    // }

    if(chico1 >1){
        for(lli i=2; i<chico1+1; i++){
                                                    perm[i] = i+1;
            if(!esblanco){
                a[i] = negros[ni];
                ni++;
            } 
            else{
                a[i] = blancos[bi];
                bi++;
            } 
        }
                                                    perm[chico1+1] = 2;
        
        if(!esblanco){
            a[chico1+1] = negros[ni];
            ni++;
        } 
        else{
            a[chico1+1] = blancos[bi];
            bi++;
        }
    }
    else if(chico1 == 1){
                                                    perm[2] = 2;
        
        if(!esblanco){
            a[2] = negros[ni];
            ni++;
        } 
        else{
            a[2] = blancos[bi];
            bi++;
        }
    }
    
    if(grande == 1){
                                                    perm[1] = 1;
        if(!esblanco){
            a[1] = blancos[bi];
            bi++;
        } 
        else{
            a[1] = negros[ni];
            ni++;
        }
    }
    else if(grande>1){

        for(lli i=chico1+2; i<chico1+grande; i++){
                                                    perm[i] = i+1;
            if(!esblanco){
                a[i] = blancos[bi];
                bi++;
            } 
            else{
                a[i] = negros[ni];
                ni++;
            }
        
        }
                                                    perm[1] = chico1+2;
                                                    perm[chico1+grande] = 1;
        if(!esblanco){
            a[1] = blancos[bi];
            bi++;
            a[chico1+grande] = blancos[bi];
            bi++;
        } 
        else{
            a[1] = negros[ni];
            ni++;
            a[chico1+grande] = negros[ni];
            ni++;
        }
    }

    if(chico2 >1){

        for(lli i = chico1+grande+1; i<N; i++){
            perm[i] = i+1;
            if(!esblanco){
                a[i] = negros[ni];
                ni++;
            } 
            else{
                a[i] = blancos[bi];
                bi++;
            }
        }

        perm[N] = chico1+grande+1;
        if(!esblanco){
            a[N] = negros[ni];
            ni++;
        } 
        else{
            a[N] = blancos[bi];
            bi++;
        }
    }
    else if(chico2 == 1){
        perm[N] = N;
        if(!esblanco){
            a[N] = negros[ni];
            ni++;
        } 
        else{
            a[N] = blancos[bi];
            bi++;
        }
    }


    forn(i, 1, N+1){
        cout << a[i] << ' ';
        if(perm[i] == 0) while(true) a[N+10] = 0;
    }
    cout << nl;
    forn(i, 1, N+1){
        cout << perm[i] << ' ';
    }
    cout << nl;

}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    lli t=1;
    while(t--) solve();
    return 0;
}