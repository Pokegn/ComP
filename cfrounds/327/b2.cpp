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

double gss(double a, double b, double (*f)(double));

pair<double, double> point(double vmax, double theta){
    double x = cos(theta) * sqrt(vmax);
    double y = sin(theta) * sqrt(vmax);
    return {x,y};
}

double tmin(double x, double y, double vmax, double vx, double vy){ //tiempo requerido para moverse en direccion x,y con velocidad maxima vmax y viento en vx,vy
    //ternary search para encontrar el mejor angulo que tomar
}

//double (){
    //cada angulo al que dirigirse tiene una respuestaz
//}
//tengo una funcion que me da el minimo tiempo requerido
//esa funcion usa una funcion que mee da el minimo tiempo requerido al final si empieza en cierta direccion
//esa funcion tiene una funcion que me da el minimo tiempo requerido si 

void solve(){
    double x1,y1,x2,y2,vmax,t,vx, vy, wx, wy;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    cin >> t;
    while(t--) solve();
    return 0;
}