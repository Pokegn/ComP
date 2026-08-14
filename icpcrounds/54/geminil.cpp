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

const ld PI = acos(-1);
const ld eps = 1e-7;

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
    double dist() const { return sqrt((double)dist2()); }
    double angle() const { return atan2(y, x); }
    P unit() const { return *this/dist(); } 
    P perp() const { return P(-y, x); } 
    P normal() const { return perp().unit(); }
    P rotate(double a) const {
        return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); 
    }
    friend ostream& operator<<(ostream& os, P p) {
        return os << "(" << p.x << "," << p.y << ")"; 
    }
};

vector<Point<ld>> allpts;
ld r;

void order(vector<Point<ld>> &pts){
    //confia
}

ll mostIn(Point<ld> P){
    vector<pair<ld, int>> events;
    ll inside = 0; 
    
    for(auto Q: allpts){
        ld d = (Q-P).dist();
        
        // If the point is P itself or an exact duplicate, it's unconditionally inside
        if(d <= eps) { 
            inside++;
            continue;
        }
        
        // Maximum distance between two points in the same circle is 2*r
        if(d > 2.0 * r + eps) continue;
        
        ld alpha = (Q-P).angle();
        // Calculate the angular offset for the sweep using trig
        ld delta = acos(max((ld)-1.0, min((ld)1.0, d / (2.0 * r))));
        
        // Expand the valid angle interval slightly by eps.
        // This guarantees that points which mathematically touch on the circle boundary
        // will physically overlap in our floating point event sweep.
        ld enter = alpha - delta - eps;
        ld exit = alpha + delta + eps;
        
        // Normalize angles to [0, 2*PI)
        while(enter < 0) enter += 2 * PI;
        while(enter >= 2 * PI) enter -= 2 * PI;
        while(exit < 0) exit += 2 * PI;
        while(exit >= 2 * PI) exit -= 2 * PI;
        
        events.push_back({enter, -1});
        events.push_back({exit, 1});
        
        if(enter > exit) {
            inside++;
        }
    }

    sort(all(events));

    ll ret = inside;
    for(auto e : events){
        inside -= e.second; // Subtracting the marker (-1 adds to inside, 1 subtracts)
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
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t = 1; 
    //cin >> t;
    while(t--) solve();
    return 0;
}