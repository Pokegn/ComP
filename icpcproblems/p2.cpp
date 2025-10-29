#include <bits/stdc++.h> //Problema D de 2017-2018 ACM-ICPC Latin American Regional Programming Contest
using namespace std;

struct Segment {
    int l, r, c; // intervalo [l, r] con color c
    bool operator<(const Segment& other) const {
        return l < other.l; // ordenar por el inicio del intervalo
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int L, C, N;
    cin >> L >> C >> N;

    set<Segment> S;
    S.insert({0, L - 1, 1}); // inicialmente todo color 1
    vector<long long> cnt(C + 1, 0);
    cnt[1] = L;

    for (int i = 0; i < N; ++i) {
        int P, X;
        long long A, B;
        cin >> P >> X >> A >> B;

        long long Scolor = cnt[P];
        long long M1 = (A + Scolor * Scolor) % L;
        long long tmp = Scolor + B;
        long long M2 = (A + tmp * tmp) % L;
        int l = (int)min(M1, M2);
        int r = (int)max(M1, M2);

        // =========================
        // SPLIT r+1 (límite superior)
        // =========================
        set<Segment>::iterator itR;
        int posR = r + 1;
        if (posR <= 0) {
            itR = S.begin();
        } else if (posR >= L) {
            itR = S.end();
        } else {
            itR = S.lower_bound({posR, 0, 0});
            if (itR != S.end() && itR->l == posR) {
                // ya hay segmento que empieza en posR
            } else {
                // tenemos que partir el intervalo que contiene posR
                --itR;
                int l0 = itR->l, r0 = itR->r, c0 = itR->c;
                S.erase(itR);
                S.insert({l0, posR - 1, c0});
                itR = S.insert({posR, r0, c0}).first;
            }
        }

        // =========================
        // SPLIT l (inicio del rango)
        // =========================
        set<Segment>::iterator itL;
        int posL = l;
        if (posL <= 0) {
            itL = S.begin();
        } else if (posL >= L) {
            itL = S.end();
        } else {
            itL = S.lower_bound({posL, 0, 0});
            if (itL != S.end() && itL->l == posL) {
                // ya hay segmento que empieza en posL
            } else {
                --itL;
                int l0 = itL->l, r0 = itL->r, c0 = itL->c;
                S.erase(itL);
                S.insert({l0, posL - 1, c0});
                itL = S.insert({posL, r0, c0}).first;
            }
        }

        // =========================
        // BORRAR intervalos en [l, r] y actualizar contadores
        // =========================
        for (auto it = itL; it != itR; ) {
            cnt[it->c] -= (it->r - it->l + 1);
            it = S.erase(it);
        }

        // =========================
        // INSERTAR nuevo intervalo [l, r] con color X
        // =========================
        S.insert({l, r, X});
        cnt[X] += (r - l + 1);
    }

    // =========================
    // IMPRIMIR respuesta final
    // =========================
    cout << *max_element(cnt.begin() + 1, cnt.end()) << "\n";
    return 0;
}
