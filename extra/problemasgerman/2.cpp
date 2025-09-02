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
int msb(long long int x) { return 63 - __builtin_clzll(x);}
long long int pow2_lb(long long int x) { return (x == (x&-x) ? x : (2 << msb(x)));}



void solve(){
    int n, m, q; cin >> n >> m >> q;
    vvi a(q, vi(4));
    forn(i, 0, q) cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3];
    lli maxv = 0;
    lli tempv = 0;
    vlli A(12);

    forn(i1, 1, m+1){
    forn(i2, i1, m+1){
    forn(i3, i2, m+1){
    forn(i4, i3, m+1){
    forn(i5, i4, m+1){
    forn(i6, i5, m+1){
    forn(i7, i6, m+1){
    forn(i8, i7, m+1){
    forn(i9, i8, m+1){
    forn(i10, i9, m+1){
        A[1] = i1; A[2] = i2; A[3] = i3; A[4] = i4; A[5] = i5; A[6] = i6; A[7] = i7; A[8] = i8; A[9] = i9; A[10] = i10;
        tempv = 0;
        forn(i, 0, q) if(A[a[i][1]]-A[a[i][0]] == a[i][2]) tempv+=a[i][3];
        maxv = max(maxv, tempv);
    }}}}}}}}}}    
    cout << maxv << nl;
}

 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}