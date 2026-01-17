#include <iostream>
#include <vector>
using namespace std;

void mulMat(vector<vector<int>>& m1, vector<vector<int>>& m2, 
            vector<vector<int>>& res) {
    int r1 = m1.size();
    int c1 = m1[0].size();
    int r2 = m2.size();
    int c2 = m2[0].size();

    if (c1 != r2) {
        cout << "Invalid Input" << endl;
        exit(EXIT_FAILURE);
    }

    // Resize result matrix to fit the result dimensions
    res.resize(r1, vector<int>(c2, 0)); 
  
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                res[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

// Driver code
int main() {
    vector<vector<int>> m1 = { {1, 1}, {2, 2} };
    vector<vector<int>> m2 = { {1, 1}, {2, 2} };
    vector<vector<int>> res;

    mulMat(m1, m2, res);

    cout << "Multiplication of given two matrices is:\n";
    for (const auto& row : res) {
        for (int val : row) {
            cout << val << "\t";
        }
        cout << endl;
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

template<class Info>
struct SegmentTree {
    int n;
    vector<Info> info;

    SegmentTree() : n(0) {}

    SegmentTree(int n_, Info v_ = Info()) {
        init(n_, v_);
    }

    template<class T>
    SegmentTree(vector<T> init_) {
        init(init_);
    }

    void init(int n_, Info v_ = Info()) {
        init(vector<Info>(n_, v_));
    }

    template<class T>
    void init(vector<T> init_) {
        n = init_.size();
        int sz = (1 << (__lg(n - 1) + 1));
        info.assign(sz * 2, Info());
        function<void(int, int, int)> build = [&](int v, int l, int r) {
            if (l == r) {
                info[v] = init_[l];
                return;
            }
            int m = (l + r) / 2;
            build(v + v, l, m);
            build(v + v + 1, m + 1, r);
            info[v] = info[v + v] + info[v + v + 1];
        };
        build(1, 0, n - 1);
    }

    Info rangeQuery(int v, int l, int r, int tl, int tr) {
        if (r < tl || l > tr) {
            return Info();
        }
        if (l >= tl && r <= tr) {
            return info[v];
        }
        int m = (l + r) / 2;
        return rangeQuery(v + v, l, m, tl, tr) + rangeQuery(v + v + 1, m + 1, r, tl, tr);
    }

    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n - 1, l, r);
    }

    void modify(int v, int l, int r, int i, const Info &x) {
        if (l == r) {
            info[v] = x;
            return;
        }
        int m = (l + r) / 2;
        if (i <= m) {
            modify(v + v, l, m, i, x);
        } else {
            modify(v + v + 1, m + 1, r, i, x);
        }
        info[v] = info[v + v] + info[v + v + 1];
    }

    void modify(int i, const Info &x) {
        modify(1, 0, n - 1, i, x);
    }

    Info query(int v, int l, int r, int i) {
        if (l == r) {
            return info[v];
        }
        int m = (l + r) / 2;
        if (i <= m) {
            return query(v + v, l, m, i);
        } else {
            return query(v + v + 1, m + 1, r, i);
        }
    }

    Info query(int i) {
        return query(1, 0, n - 1, i);
    }
};

const int INF = 1E9;

struct Info {
    int min1, min2, max1, max2, ans1, ans2;

    Info() : min1(INF), min2(INF), max1(-INF), max2(-INF), ans1(0), ans2(0) {}

    Info(pair<int, int> x) : min1(x.first), min2(x.second), max1(x.first), max2(x.second), ans1(0), ans2(0) {}
};

Info operator+(const Info &a, const Info &b) {
    Info res;
    res.min1 = min(a.min1, b.min1);
    res.min2 = min(a.min2, b.min2);
    res.max1 = max(a.max1, b.max1);
    res.max2 = max(a.max2, b.max2);
    res.ans1 = max({a.ans1, b.ans1, b.max1 - a.min1});
    res.ans2 = max({a.ans2, b.ans2, a.max2 - b.min2});
    return res;
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<pair<int, int>> t(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        t[i] = {a[i] - i, a[i] + i - n + 1};
    }
    SegmentTree<Info> st(t);
    auto query = [&]() {
        return max(st.info[1].ans1, st.info[1].ans2);
    };
    cout << query() << "\n";
    for (int i = 0; i < q; i++) {
        int p, x;
        cin >> p >> x;
        p--;
        t[p] = {x - p, x + p - n + 1};
        st.modify(p, t[p]);
        cout << query() << "\n";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}