#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    int i; for (i=0; i<t; i++){
        int n, q; cin >> n >> q;
        long long int a[n];
        long long int b[n];
        long long int c[n];
        long long int s=0; //suma
        long long int m=0; //mayor
        long long int k=0; //conteo
        long long int e;


        int j; for (j=0; j<n; j++){
            cin >> e;
            if (e>m){
                a[k]=e;
                b[k]=j;
                k++;
                m=e;
            }
            c[j]=s+e;

            if (a[j]>m) m=a[j]; //el mayor escalon hasta ahora

            b[j]=m;
        }
    }
}