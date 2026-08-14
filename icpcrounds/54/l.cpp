#include <bits/stdc++.h>
using namespace std;
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
#define rep(i, a, b) for(int i=a; i<(b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define endl '\n'
#define pb push_back
#define fi first
#define se second
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}

const ld PI = acos(-1.0);

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
    typedef Point P;
    T x, y;
    explicit Point(T x=0, T y=0) : x(x), y(y) {}
    bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
    bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
    P operator+(P p) const { return P(x+p.x, y+p.y); }
    P operator-(P p) const { return P(x-p.x, y-p.y); }
    P operator*(T d) const { return P(x*d, y*d); }
    P operator/(T d) const { return P(x/d, y/d); }
    T dot(P p) const { return x*p.x + y*p.y; }
    T cross(P p) const { return x*p.y - y*p.x; }
    T cross(P a, P b) const { return (a-*this).cross(b-*this); }
    T dist2() const { return x*x + y*y; }
    ld dist() const { return sqrt(dist2()); }
    // angle to x=axis in interva l [=pi , pi ]
    ld angle() const { return atan2(y, x); }
    P unit() const { return *this/dist(); } // makes d is t ()=1
    P perp() const { return P(-y, x); } // rotates +90 degrees
    P normal() const { return perp().unit(); }
    // returns point rotated ’a ’ radians ccw around the origin
    P rotate(double a) const {
    return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
    friend ostream& operator<<(ostream& os, P p) {
    return os << "(" << p.x << "," << p.y << ")"; }
};


vector<Point<ld>> allpts;
vector<pair<ld, int>> allangles;
ld r;
const ld eps = 1e-7;

struct cmp { //rogelio guerrero reyes ceo of sex
    bool operator()(ld a, ld b)const{ return (a + eps < b); }
}; 

void order(vector<Point<ld>> &pts){
    //confia
}

ll mostIn(Point<ld> P){
    allangles = vector<pair<ld, int>> (0);
    ll inside = 1;
    for(auto Q: allpts){
        if((Q-P).dist() > 2*r + eps) continue;
        if(P == Q) continue;
        auto alpha = (Q-P).angle();

        ld arg = (Q-P).dist() / (2.0 * r);
        arg = min((ld)1.0, max((ld)-1.0, arg));
        ld angulo_de_mierda = acos(arg);
        
        ld angulo_de_mierda = acos((Q-P).dist()/(2.0*r));
        angulo_de_mierda = min((ld)1.0, max((ld)-1.0, angulo_de_mierda));
        
        ld enter, exit;
        exit = (alpha + (angulo_de_mierda) + eps);
        enter = (alpha - (angulo_de_mierda) - eps);

        while(enter < 0) enter += 2*PI;
        while(enter >= 2*PI) enter -= 2*PI;

        while(exit < 0) exit += 2*PI;
        while(exit >= 2*PI) exit -= 2*PI;

        if(enter > exit) inside++;

        allangles.push_back({enter, -1});
        allangles.push_back({exit, +1});
    }

    std::sort(all(allangles));

    //:(

    ll ret = 1;
    rep(i, 0, allangles.size()){
        inside -= allangles[i].second;
        ret = max(ret, inside);
    }

    return ret;
}

void solve(){
    ll n; cin >> n;
    cin >> r;
    allpts = vector<Point<ld>> (n);

    rep(i, 0, n){
        ld x,y; cin >> x >> y; 
        allpts[i] = Point<ld>((ld)x, (ld)y);
    }
    
    ll ans = 0;

    rep(i, 0, n){
        ans = max(ans, mostIn(allpts[i]));
    }

    cout << ans << endl;
    return;
}


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1; 
    //cin >> t;
    while(t--) solve();
    return 0;
}