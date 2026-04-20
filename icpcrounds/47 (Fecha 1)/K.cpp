#include <bits/stdc++.h>

using namespace std;

#define sz(x) (x).size()
#define all(x) begin(x), end(x)
#define rep(i, a, b) for(int i = a; i < (b); ++i)
// #define endl '\n'

typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> pii;


template<class T> int sgn(T x){
    return (x>0) - (x<0);
}

template<class T> struct Point{
    typedef Point P; T x,y;
    explicit Point(T x=0, T y=0): x(x), y(y){}
    bool operator<(P p) const{return tie(x,y) < tie(p.x, p.y);}
    bool operator==(P p) const{ return tie(x,y) == tie(p.x, p.y); }
    P operator+(P p) const{ return P(x+p.x, y+p.y);}
    P operator-(P p) const{ return P(x-p.x, y-p.y);}
    P operator*(T d) const { return P(x*d, y*d);}
    T dist2() const{return x*x+y*y;}
    P perp() const {return P(-y,x);}

};

typedef Point<long double>P;
bool circleInter(P a, P b, long double r1, long double r2, pair<P,P>&out){
    if(a==b) {assert(r1 != r2); return false;}
    P vec = b-a;
    long double d2 = vec.dist2(), sum = r1+r2, dif = r1-r2;
    long double p = (d2+r1*r1-r2*r2)/(d2*2), h2 = r1*r1 - p*p*d2;
    if(sum*sum + 1e-10 < d2 || dif*dif > 1e-10 + d2) return false;
    P mid = a + vec*p, per = vec.perp() * sqrt(fmax(0, h2) / d2);
    out = {mid+per, mid-per};
    return true;
}   

long double distance(P a, P b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

bool inCircle(P center, P orig, long double r){
    if(distance(center, orig) <= r + 1e-10) return true;
    return false;
}

void solve(){
    int n; cin >> n;
    long double px, py; cin >> px >> py;
    vector<P> c(n);
    vector<long double> r(n);
    for(int i=0; i<n; i++){
        cin >> c[i].x >> c[i].y; cin >> r[i];
    }
    vector<P> pts;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            pair<P,P> out;
            if(circleInter(c[i], c[j], r[i], r[j],out)){
                pts.push_back(out.first);
                pts.push_back(out.second);
                //cout << "de " << c[i].x << ' ' << c[i].y << ' ' << r[i] << " a " << c[j].x << ' ' << c[j].y << ' ' << r[j] << ": "; 
                //cout << out.first.x << ' ' << out.first.y << " y " << out.second.x << ' ' << out.second.y << endl;
            }
        }
    }

    for(int i=0; i<n; i++){
        P X; if(inCircle(c[i], P(px, py), r[i])) continue;

        long double d1 = distance(P(px, py), c[i]);
        long double xx = (px-c[i].x);
        long double yy = (py-c[i].y);
        X.x = px+(xx * (d1 - r[i])/d1);
        X.y = py+(yy * (d1 - r[i])/d1);
        pts.push_back(X);
        //cout << "de " << px << ' ' << py << " con " << c[i].x << ' ' << c[i].y << ' ' << r[i] << ": " << X.x << ' ' << X.y << endl;
    }

    bool todos = true;
    for(int i=0; i<n; i++){
        if(!inCircle(P(px, py), c[i], r[i])) todos = false;
    }
    if(todos){
        cout << fixed << setprecision(10) << 0 << endl;
        return;
    }

    int szz = sz(pts);
    long double ans = 10000000;
    // cout <<fixed << setprecision(10) << ans<< endl;
    for(auto pt : pts){
        // cout << pt.x << ' ' << pt.y << endl;
        bool dentro = true;
        for(int i=0; i<n; i++){
            if(!inCircle(pt, c[i], r[i])) dentro = false;

        }
        if(dentro){ ans = min(ans, distance(pt, P(px, py)));
            //cout << "dentro " << pt.x << ' ' << pt.y << endl;
        }
    }
    cout <<fixed << setprecision(10) << ans << endl;
    return;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;
    // cin >> tt;
    while(tt--)
        solve();

    return 0;
}